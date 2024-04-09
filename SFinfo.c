#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SFinfo.h"

int sprawdz_szerokosc(char *nazwa_pliku){
    FILE *plik = fopen(nazwa_pliku, "r");
    if (plik == NULL){
        printf("Nie udało się otworzyć pliku\n");
        return 1;
    }
    int szerokosc = 0;
    char znak;
    while (fscanf(plik, "%c", &znak) != EOF){
        if (znak == '\n'){
            break;
        }
        szerokosc++;
    }
    fclose(plik);
    return szerokosc;
}

int sprawdz_wysokosc(char *nazwa_pliku){
    FILE *plik = fopen(nazwa_pliku, "r");
    if (plik == NULL){
        printf("Nie udało się otworzyć pliku\n");
        return 1;
    }
    int wysokosc = 0;
    char znak;
    while (fscanf(plik, "%c", &znak) != EOF){
        if (znak == '\n'){
            wysokosc++;
        }
    }
    fclose(plik);
    return wysokosc;
}


void znajdz_konce(char *nazwa_pliku, int szerokosc, int wysokosc, int *start_x, int *start_y, int *koniec_x, int *koniec_y){
    FILE *plik = fopen(nazwa_pliku, "r");
    if (plik == NULL){
        printf("Nie udało się otworzyć pliku\n");
        return;
    }

    char znak;
    int x = 0;
    int y = 0; 

    while (fscanf(plik, "%c", &znak) != EOF){
        if (znak == 'P'){
            *start_x = x;
            *start_y = y;
        } else if (znak == 'K'){
            *koniec_x = x;
            *koniec_y = y;
        }
        if (znak == '\n'){
            x = 0;
            y++;
        } else {
            x++;
        }
    }

    fclose(plik);
}

