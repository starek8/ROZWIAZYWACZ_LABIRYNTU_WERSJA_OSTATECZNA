#include "bin_to_sf.h"

FILE *StworzSf(FILE* file)
{
    struct info_lab header;
    fread(&header, 40, 1, file);


    int liczba_slow = header.counter;

    unsigned char wartosc;
    char slowo;

    char* buffer = malloc(liczba_slow * 3);

    fread(buffer, liczba_slow * 3, 1, file);

    char* pointer = buffer;

    int counter = 0;

    FILE* sf = fopen("sf.txt", "w");

    for(int i = 0; i < liczba_slow; i++)
    {
        pointer++;
        slowo = *pointer;
        pointer++;
        wartosc = *pointer;
        pointer++;

        for(int y = 0; y < wartosc+1; y++)
        {
            fprintf(sf, "%c", slowo);
            counter++;
            if(counter == header.columns)
            {
                fprintf(sf, "\n");
                counter = 0;
            }
        }
    }

    if(sf==NULL)
    {
        return NULL; // bad info
        printf("cos nie tak z plikiem sf\\n");
    }

    return sf;
}

/*
int main(int argc, char *argv[])
{
        FILE *file = fopen(argv[1], "rb"); // musialem tu zmienic na "rb" 
        if (file == NULL) {
            printf("Nie udało się otworzyć pliku!\nKoniec działania programu\n"); 
        return 1;
        }

        FILE *out = StworzSf(file);
}

Funkcja testująca oddaje plik sf :)
*/