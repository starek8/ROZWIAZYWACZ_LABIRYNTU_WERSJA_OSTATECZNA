#ifndef ZALEWACZ_H
#define ZALEWACZ_H

#include <stdio.h>
#include <stdlib.h>

void wpisz(FILE *zalany, char ** linie, int szerokosc);

char ** podmien_linie(int szerokosc, char* nowa_linia, char** linie);

char ** zalanie_3_lini(int szerokosc, char ** linie);

int suma(char G, char P, char D, char L);

FILE *zalany_plik(FILE *plik_sf,int szerokosc);

//FILE *ostateczny(FILE *plik_sf,int szerokosc);

#endif