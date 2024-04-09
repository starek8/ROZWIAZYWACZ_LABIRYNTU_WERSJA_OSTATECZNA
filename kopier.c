#include <stdio.h>
#include <stdlib.h>
#include "kopier.h"

void kopier(char* nazwa_pliku_zrodlowego){
    FILE *file = fopen(nazwa_pliku_zrodlowego, "r");
    if (file == NULL) {
        printf("Nie udało się otworzyć pliku!\nKoniec działania programu\n");
        exit(1);
    }

    FILE *working_copy = fopen("working_copy.txt", "w");
    if (working_copy == NULL) {
        printf("Nie udało się otworzyć pliku!\nKoniec działania programu\n");
        exit(1);
    }

    char c;
    while((c = fgetc(file)) != EOF){
        fputc(c, working_copy);
    }

    fclose(file);
    fclose(working_copy);

    printf("Plik roboczy został stworzony\n");
}
