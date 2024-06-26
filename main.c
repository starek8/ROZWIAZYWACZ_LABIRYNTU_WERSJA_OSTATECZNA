#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "kopier.h"
#include "SFinfo.h"
#include "flooder.h"
#include "follower.h"
#include "sf_to_bin.h"
#include "bin_to_sf.h"


int main (int argc, char *argv[]) {

    clock_t start = clock();

    //sprawdzenie poprawności argumentu
    if (argc != 2) {
        printf("Nieprawidłowa liczba argumentów!\nPrzykład użycia: ./solver <nazwa_pliku_z_danymi.rozszerzenie>\nKoniec działania programu\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r+b");
    if (file == NULL) {
        printf("Nie udało się otworzyć pliku!\nKoniec działania programu\n");
        return 1;
    }

    FILE *bin_do_oddania;
    FILE* working_copy;

    //zmienne potrzebne do działania
    int szerokosc = 0;
    int wysokosc = 0;
    int start_x = 0;
    int start_y = 0;
    int koniec_x = 0;
    int koniec_y = 0;


    if(strcmp(argv[1] + strlen(argv[1]) - 3, "bin") == 0){
        printf("Typ pliku żródłowego: bin\n");
        // tu idzie kod dla bin

         //krok 1 stowrzenie working copy
        
        working_copy = StworzSf(file);

        wstaw_PK(working_copy, file);
        fclose(working_copy);

        // krok 2 wyciagniecie informacji
        szerokosc = sprawdz_szerokosc("working_copy.txt");
        wysokosc = sprawdz_wysokosc("working_copy.txt");
        znajdz_konce("working_copy.txt", szerokosc, wysokosc, &start_x, &start_y, &koniec_x, &koniec_y);

        printf("Szerokość: %d\nWysokość: %d\n", szerokosc, wysokosc);

        printf("Start: %d %d\n", start_x, start_y);
        printf("Koniec: %d %d\n", koniec_x, koniec_y);

        printf("Rozpoczęto zalewanie\n");
        flooder(szerokosc, wysokosc, start_x, start_y, koniec_x, koniec_y);
        printf("Zakończono zalewanie\n");
        follower(file, szerokosc, wysokosc, start_x, start_y, koniec_x, koniec_y);
        printf("Zakończono śledzenie\n");
        
    } else if(strcmp(argv[1] + strlen(argv[1]) - 3, "txt") == 0){
        printf("Typ pliku żródłowego: txt\n");
        // tu idzie kod dla txt

        //krok 1 - stworzenie kopii roboczej pliku źródłowego
        kopier(argv[1]);

        //krok 2 - wyciągnięcie informacji na temat labiryntu
        szerokosc = sprawdz_szerokosc(argv[1]);
        wysokosc = sprawdz_wysokosc(argv[1]);

        printf("Szerokość: %d\nWysokość: %d\n", szerokosc, wysokosc);

        znajdz_konce("working_copy.txt", szerokosc, wysokosc, &start_x, &start_y, &koniec_x, &koniec_y);

        printf("Start: %d %d\n", start_x, start_y);
        printf("Koniec: %d %d\n", koniec_x, koniec_y);

        //krok 3 - utworzenie pliku bin

        bin_do_oddania = StworzBin(file, szerokosc, wysokosc, start_x, start_y, koniec_x, koniec_y); 

        printf("Rozpoczęto zalewanie\n");
        flooder(szerokosc, wysokosc, start_x, start_y, koniec_x, koniec_y);
        printf("Zakończono zalewanie\n");
        follower_nowy(bin_do_oddania, szerokosc, wysokosc, start_x, start_y, koniec_x, koniec_y);
        printf("Zakończono śledzenie\n");

        
    } else {
        printf("Nieobsługiwany plik!\nKoniec działania programu\n");
        return 1;
    }

    //rozwiązanie labiryntu
    

    remove("working_copy.txt");
    printf ("Czas wykonania: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
    return 0;


}
