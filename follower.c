#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flooder.h"
#include "follower.h"


void follower(int szerokosc, int wysokosc, int start_x, int start_y, int koniec_x, int koniec_y){
    char **tab = (char **)malloc(szerokosc * sizeof(char *));
    for (int i = 0; i < szerokosc; i++){
        tab[i] = (char *)malloc(3 * sizeof(char));
    }

    int licznik_krokow = 0;
    char kierunek = 'N'; // N - północ, S - południe, W - zachód, E - wschód
    int x = start_x;
    int y = start_y;

    if (x == 0){
        kierunek = 'E';
    } else if (y == 0){
        kierunek = 'S';
    } else if (x == szerokosc-1){
        kierunek = 'W';
    } else if (y == wysokosc-1){
        kierunek = 'N';
    } else{
        //sprawdzenie z której strony jest wolne pole
        if (tab[x+1][1] != 'X'){
            kierunek = 'E';
        } else if (tab[x-1][1] != 'X'){
            kierunek = 'W';
        } else if (tab[x][2] != 'X'){
            kierunek = 'S';
        } else if (tab[x][0] != 'X'){
            kierunek = 'N';
        } else {
            printf("Ups, coś poszło nie tak\n");
        }
    }

    printf("Kierunek: %c\n", kierunek);

    
    while (x != koniec_x || y != koniec_y){
        wczytaj_blok(tab, "working_copy.txt", szerokosc, y-1);

        if (kierunek == 'E'){
            if (tab[x+1][1] != 'X'){
                licznik_krokow++;
                x++;
            } else{
                if (tab[x][2] != 'X'){
                    printf("kierunek: %c %d\n", kierunek, licznik_krokow);
                    kierunek = 'S';
                    licznik_krokow = 1;
                    y++;
                }else if(tab[x][0] != 'X'){
                    printf("kierunek: %c %d\n", kierunek, licznik_krokow);
                    kierunek = 'N';
                    licznik_krokow = 1;
                    y--;
                }
            }    
        } else if (kierunek == 'S'){
            if (tab[x][2] != 'X'){
                licznik_krokow++;
                y++;
            } else{
                if (tab[x-1][1] != 'X'){
                    printf("kierunek: %c %d\n", kierunek, licznik_krokow);
                    kierunek = 'W';
                    licznik_krokow = 1;
                    x--;
                } else if (tab[x+1][1] != 'X'){
                    printf("kierunek: %c %d\n", kierunek, licznik_krokow);
                    kierunek = 'E';
                    licznik_krokow = 1;
                    x++;
                }
            }
        } else if (kierunek == 'N'){
            if (tab[x][0] != 'X'){
                licznik_krokow++;
                y--;
            } else{
                if (tab[x+1][1] != 'X'){
                    printf("kierunek: %c %d\n", kierunek, licznik_krokow);
                    kierunek = 'E';
                    licznik_krokow = 1;
                    x++;
                } else if (tab[x-1][1] != 'X'){
                    printf("kierunek: %c %d\n", kierunek, licznik_krokow);
                    kierunek = 'W';
                    licznik_krokow = 1;
                    x--;
                }
            }
        } else if (kierunek == 'W'){
            if (tab[x-1][1] != 'X'){
                licznik_krokow++;
                x--;
            } else{
                if (tab[x][2] != 'X'){
                    printf("kierunek: %c %d\n", kierunek, licznik_krokow);
                    kierunek = 'S';
                    licznik_krokow = 1;
                    y++;
                } else if (tab[x][0] != 'X'){
                    printf("kierunek: %c %d\n", kierunek, licznik_krokow);
                    kierunek = 'N';
                    licznik_krokow = 1;
                    y--;
                }
            }
        }
    }

    printf("kierunek: %c %d\n", kierunek, licznik_krokow);
    free(tab);  
}