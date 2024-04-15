#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flooder.h"
#include "follower.h"
#include "zapisz_w_bin.h"


void follower(FILE* bin, int szerokosc, int wysokosc, int start_x, int start_y, int koniec_x, int koniec_y){
    char **tab = (char **)malloc(szerokosc * sizeof(char *));
    for (int i = 0; i < szerokosc; i++){
        tab[i] = (char *)malloc(3 * sizeof(char));
    }

    int steps = -1;
    rozpocznij_zapis_w_bin(bin);
    long pozycja = ftell(bin);
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
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'S';
                    licznik_krokow = 0;
                    y++;
                }else if(tab[x][0] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'N';
                    licznik_krokow = 0;
                    y--;
                }
            }    
        } else if (kierunek == 'S'){
            if (tab[x][2] != 'X'){
                licznik_krokow++;
                y++;
            } else{
                if (tab[x-1][1] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'W';
                    licznik_krokow = 0;
                    x--;
                } else if (tab[x+1][1] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'E';
                    licznik_krokow = 0;
                    x++;
                }
            }
        } else if (kierunek == 'N'){
            if (tab[x][0] != 'X'){
                licznik_krokow++;
                y--;
            } else{
                if (tab[x+1][1] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'E';
                    licznik_krokow = 0;
                    x++;
                } else if (tab[x-1][1] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'W';
                    licznik_krokow = 0;
                    x--;
                }
            }
        } else if (kierunek == 'W'){
            if (tab[x-1][1] != 'X'){
                licznik_krokow++;
                x--;
            } else{
                if (tab[x][2] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'S';
                    licznik_krokow = 0;
                    y++;
                } else if (tab[x][0] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'N';
                    licznik_krokow = 0;
                    y--;
                }
            }
        }
    }

    zapisz_krok(bin, kierunek, licznik_krokow);
    steps++;

    zapisz_steps(bin, steps, pozycja -1); 
    
    free(tab);  
}

void follower_nowy(FILE* bin, int szerokosc, int wysokosc, int start_x, int start_y, int koniec_x, int koniec_y){
    char **tab = (char **)malloc(szerokosc * sizeof(char *));
    for (int i = 0; i < szerokosc; i++){
        tab[i] = (char *)malloc(3 * sizeof(char));
    }

    int steps = -1;
    rozpocznij_zapis_w_nowym_bin(bin);
    long pozycja = ftell(bin);
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
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'S';
                    licznik_krokow = 0;
                    y++;
                }else if(tab[x][0] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'N';
                    licznik_krokow = 0;
                    y--;
                }
            }    
        } else if (kierunek == 'S'){
            if (tab[x][2] != 'X'){
                licznik_krokow++;
                y++;
            } else{
                if (tab[x-1][1] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'W';
                    licznik_krokow = 0;
                    x--;
                } else if (tab[x+1][1] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'E';
                    licznik_krokow = 0;
                    x++;
                }
            }
        } else if (kierunek == 'N'){
            if (tab[x][0] != 'X'){
                licznik_krokow++;
                y--;
            } else{
                if (tab[x+1][1] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'E';
                    licznik_krokow = 0;
                    x++;
                } else if (tab[x-1][1] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'W';
                    licznik_krokow = 0;
                    x--;
                }
            }
        } else if (kierunek == 'W'){
            if (tab[x-1][1] != 'X'){
                licznik_krokow++;
                x--;
            } else{
                if (tab[x][2] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'S';
                    licznik_krokow = 0;
                    y++;
                } else if (tab[x][0] != 'X'){
                    zapisz_krok(bin, kierunek, licznik_krokow);
                    steps++;
                    kierunek = 'N';
                    licznik_krokow = 0;
                    y--;
                }
            }
        }
    }

    zapisz_krok(bin, kierunek, licznik_krokow);
    steps++;

    zapisz_steps(bin, steps, pozycja -1); 
    
    free(tab);  
}

