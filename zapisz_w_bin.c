#include "zapisz_w_bin.h"

void rozpicznij(FILE *bin, int steps)
{
    fseek(bin, 0, SEEK_END);

    int FILE_ID = 0x52524243; //hard-code file_id
    char ste = (char)steps; 
    fwrite(&FILE_ID, 4, 1, bin);
    fwrite(&ste, 1, 1, bin); //miejce na counter 
}

void zapisz_krok(FILE *bin, char kierunek, int liczba_krokow)
{

    char max = 255;

    if(liczba_krokow <= 255)
    {
        char ilosc = (char)liczba_krokow;
        fprintf(&kierunek, 1,1, bin);
        fprintf(&ilosc,1,1,bin);
    }else if(liczba_krokow > 255 && liczba_krokow <= 511)
    {

        liczba_krokow = liczba_krokow - 255;

        fprintf(&kierunek, 1,1, bin);
        fprintf(&max,1,1,bin);

        fprintf(&kierunek, 1,1, bin);
        fprintf(&liczba_krokow,1,1,bin);
        
    }else if (liczba_krokow > 511 && liczba_krokow <= 767)
    {

        liczba_krokow = liczba_krokow - 511;

        for(int i = 0; i< 2; i++){
            fprintf(&kierunek, 1,1, bin);
            fprintf(&max,1,1,bin);
        }

        fprintf(&kierunek, 1,1, bin);
        fprintf(&liczba_krokow,1,1,bin);
        
    }else if (liczba_krokow > 767 && liczba_krokow <= 1023)
    {
        liczba_krokow = liczba_krokow - 767;

        for(int i = 0; i< 3; i++){
            fprintf(&kierunek, 1,1, bin);
            fprintf(&max,1,1,bin);
        }

        fprintf(&kierunek, 1,1, bin);
        fprintf(&liczba_krokow,1,1,bin);
    }else if (liczba_krokow > 1023 && liczba_krokow <= 1279)
    {
        liczba_krokow = liczba_krokow - 1023;

        for(int i = 0; i< 4; i++){
            fprintf(&kierunek, 1,1, bin);
            fprintf(&max,1,1,bin);
        }

        fprintf(&kierunek, 1,1, bin);
        fprintf(&liczba_krokow,1,1,bin);
    }else if (liczba_krokow > 1279 && liczba_krokow <= 1535)
    {
        liczba_krokow = liczba_krokow - 1279;

        for(int i = 0; i< 5; i++){
            fprintf(&kierunek, 1,1, bin);
            fprintf(&max,1,1,bin);
        }

        fprintf(&kierunek, 1,1, bin);
        fprintf(&liczba_krokow,1,1,bin);
    }else if (liczba_krokow > 1535 && liczba_krokow <= 1791)
    {
        liczba_krokow = liczba_krokow - 1535;

        for(int i = 0; i< 6; i++){
            fprintf(&kierunek, 1,1, bin);
            fprintf(&max,1,1,bin);
        }

        fprintf(&kierunek, 1,1, bin);
        fprintf(&liczba_krokow,1,1,bin);
    }else if (liczba_krokow > 1791 && liczba_krokow <= 2049)
    {
        liczba_krokow = liczba_krokow - 1791;

        for(int i = 0; i< 7; i++){
            fprintf(&kierunek, 1,1, bin);
            fprintf(&max,1,1,bin);
        }

        fprintf(&kierunek, 1,1, bin);
        fprintf(&liczba_krokow,1,1,bin);
    }


}
