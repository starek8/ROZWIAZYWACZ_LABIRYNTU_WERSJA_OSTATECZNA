#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flooder.h"

void wczytaj_blok(char **tab, char *nazwa_pliku, int szerokosc, int linia_poczatkowa){
    FILE *file = fopen(nazwa_pliku, "r");
    if (file == NULL){
        printf("Nie udało się otworzyć pliku!\n");
        return;
    }

    
    for (int i = 0; i < 3; i++){
        fseek(file, linia_poczatkowa *(szerokosc+1) + i * (szerokosc + 1), SEEK_SET);
        for (int j = 0; j < szerokosc; j++){
            tab[j][i] = fgetc(file);
        }
    }
    fclose(file);
}

int suma(char **tab, int szerokosc, int x){
    int suma = 0;

    if (tab[x][1] == 'X'){
        return 0;
    }

    if (tab[x][0] == 'X'){
        suma++;
    }
    if (tab[x][2] == 'X'){
        suma++;
    }
    if (tab[x-1][1] == 'X'){
        suma++;
    }
    if (tab[x+1][1] == 'X'){
        suma++;
    }

    return suma;
}

int flood (char **tab, int szerokosc){
    int counter = 1;
    int czy_zmiana = 0;
    while(counter != 0){
        counter = 0;
        for (int i = 1; i < szerokosc-1; i++){
            if (suma(tab, szerokosc, i) >= 3){
                tab[i][1] = 'X';
                czy_zmiana += 1;
            }
        }
    }
    return czy_zmiana;
}

void wypisz_tablice(char **tab, int szerokosc){
    for(int i = 0; i < 3; i++){
        printf("%i: ", i);
        for(int j = 0; j < szerokosc; j++){
            printf("%c", tab[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

void zapisz_zmiany(char **tab, int szerokosc, int linia_poczatkowa){
    FILE *file = fopen("working_copy.txt", "r+");
    if (file == NULL){
        printf("Nie udało się otworzyć pliku!\n");
        return;
    }

    for (int i = 0; i < 3; i++){
        fseek(file, linia_poczatkowa *(szerokosc+1) + i * (szerokosc + 1), SEEK_SET);
        for (int j = 0; j < szerokosc; j++){
            fputc(tab[j][i], file);
        }
    }
    fclose(file);
}

void flooder (int szerokosc, int wysokosc, int start_x, int start_y, int koniec_x, int koniec_y){

    //tworzenie tablicy dwuwymiarowej char o wymiarach szerokosc na 3
    char **tab = (char **)malloc(szerokosc * sizeof(char *));
    for (int i = 0; i < szerokosc; i++){
        tab[i] = (char *)malloc(3 * sizeof(char));
    }

    int counter = 1;

    while (counter != 0){
        counter = 0;
        
        for (int i = 0; i < wysokosc - 2; i++){
            wczytaj_blok(tab, "working_copy.txt", szerokosc, i);
            counter += flood(tab, szerokosc);
            zapisz_zmiany(tab, szerokosc, i);
        }

    }
    free(tab);
}