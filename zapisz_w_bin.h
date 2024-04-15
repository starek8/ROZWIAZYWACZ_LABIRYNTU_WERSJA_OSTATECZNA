#ifndef ZAPISZ_W_BIN_H
#define ZAPISZ_W_BIN_H

#include <stdio.h>
#include <stdlib.h>

void rozpocznij_zapis_w_bin(FILE *bin);

void zapisz_krok(FILE *bin, char kierunek, int liczba_krokow); // przyjmuje otwarty plik !!

void zapisz_steps(FILE *bin, int steps, long pozycja);

#endif