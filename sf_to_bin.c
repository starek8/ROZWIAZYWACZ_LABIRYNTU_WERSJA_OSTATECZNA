#include "sf_to_bin.h"

void wpisz_slowo(FILE *bin, short ile, char jaki, char sep)
{
    fwrite(&sep,1,1,bin);
    fwrite(&jaki,1,1,bin);
    fwrite(&ile,1,1,bin);
}

FILE *StworzBin(FILE *sf, int szerokosc, int wysokosc, int start_x, int start_y, int koniec_x, int koniec_y, int solu_offset)
{
    FILE *bin = fopen("nowy.bin", "wb");

    int FILE_ID = 0x52524243; //hard-code file_id
    char ESC =  0x1B; // hard_code znak esc
    char puste = 0;

    fwrite(&FILE_ID, 4, 1, bin);
    fwrite(&ESC, 1, 1, bin);

    short szer = szerokosc;
    short wys = wysokosc;
    short st_x = start_x;
    short st_y = start_y;
    short kon_x = koniec_x;
    short kon_y = koniec_y;

    fwrite(&szer, 2,1,bin); 
    fwrite(&wys, 2, 1, bin);
    fwrite(&st_x, 2,1,bin); 
    fwrite(&st_y, 2, 1, bin);
    fwrite(&kon_x, 2,1,bin); 
    fwrite(&kon_y, 2, 1, bin);

    for(int i = 0; i< 16; i++)
    {
        fwrite(&puste, 1,1,bin); // przestrzen zarezwerowoana + miejsce na COUNTER
    }

    int offset = solu_offset;
    fwrite(&offset, 4, 1, bin);

    char SEPARATOR = '#';//HARD_code cz2
    char WALL = 'X';
    char PATH = ' ';

    fwrite(&SEPARATOR, 1,1,bin);
    fwrite(&WALL, 1,1,bin);
    fwrite(&PATH, 1,1,bin);

    //koniec header
    int ilosc_slow = -1;
    short counter = -1;
    char akt_symb;
    char poprz_symb = 'X';

    while( EOF != ( akt_symb = fgetc(sf)))
    {
        if(akt_symb == 'P' ||  akt_symb == 'K')
        {
            akt_symb = ' ';
        }

        if(counter == 255)
        {
            wpisz_slowo(bin,counter,poprz_symb, SEPARATOR);
            counter = -1;
            ilosc_slow ++;
        }

        if( akt_symb != '\n')
        {
            if(akt_symb == poprz_symb)
            {
                counter++;
            }else
            {
                wpisz_slowo(bin,counter,poprz_symb, SEPARATOR);
                ilosc_slow++;
                counter = 0;
                poprz_symb = akt_symb;
            }
        }
    }

    wpisz_slowo(bin,counter,poprz_symb, SEPARATOR);
    ilosc_slow++;

    fseek(bin, 29, SEEK_SET);
    fwrite(&ilosc_slow, 4,1,bin);

    if(bin == NULL)
    {
        printf("bin jest pusty/n");
        return NULL;
    }

    return bin;
}

/*

Maly test dla labiryntu 21x21 (znaczy 10x10 z generatora)

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Nie udało się otworzyć pliku!\nKoniec działania programu\n");
        return 1;
    }

    FILE *bin = StworzBin(file, 21 , 21 , 1 , 2, 21, 20, 0);

    return 0;

}*/