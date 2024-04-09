#ifndef KOPIER_H
#define KOPIER_H

int sprawdz_szerokosc (char *nazwa_pliku);

int sprawdz_wysokosc (char *nazwa_pliku);

void znajdz_konce(char *nazwa_pliku, int szerokosc, int wysokosc, int *start_x, int *start_y, int *koniec_x, int *koniec_y);

#endif 