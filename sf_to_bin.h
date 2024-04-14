#ifndef BIN_TO_SF_H
#define BIN_TO_SF_H

#include <stdio.h>
#include <stdlib.h>

FILE *StworzBin(FILE *sf, int szerokosc, int wysokosc, int start_x, int start_y, int koniec_x, int koniec_y);

void wpisz_slowo(FILE *bin, short ile, char jaki, char sep);

#endif