#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main (int argc, char *argv[]) {

    clock_t start = clock();

    //sprawdzenie poprawności argumentu
    if (argc != 2) {
        printf("Nieprawidłowa liczba argumentów!\nPrzykład użycia: ./solver <nazwa_pliku_z_danymi.rozszerzenie>\nKoniec działania programu\n");
        return 1;
    }

    if(strcmp(argv[1] + strlen(argv[1]) - 3, "bin") == 0){
        printf("bin\n");

        FILE *file = fopen(argv[1], "rb"); // musialem tu zmienic na "rb" 
        if (file == NULL) {
            printf("Nie udało się otworzyć pliku!\nKoniec działania programu\n"); 
        return 1;
        }
        // tu idzie kod dla bin
        
    } else if(strcmp(argv[1] + strlen(argv[1]) - 3, "txt") == 0){
        printf("txt\n");

        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            printf("Nie udało się otworzyć pliku!\nKoniec działania programu\n");
        return 1;
        }
        // tu idzie kod dla txt
    } else {
        printf("Nieobsługiwany plik!\nKoniec działania programu\n");
        return 1;
    }

    //zmienne potrzebne do działania
    int szerokosc = 0;
    int wysokosc = 0;
    int start_x = 0;
    int start_y = 0;
    int koniec_x = 0;
    int koniec_y = 0;



    printf ("Czas wykonania: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
    return 0;
}