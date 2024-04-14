#include "zapisz_w_bin.h"

void rozpocznij_zapis_w_bin(FILE *bin)
{
    fseek(bin, 0, SEEK_END);

    int FILE_ID = 0x52524243; //hard-code file_id
    char ste = 0;
    fwrite(&FILE_ID, 4, 1, bin);
    fwrite(&ste, 1, 1, bin); //miejce na counter 
}

void zapisz_steps(FILE *bin, int steps)
{
    long ile =(int)steps * (-1);
    char ste =(char)steps;
    fseek(bin, ile, SEEK_END);
}

void zapisz_krok(FILE *bin, char kierunek, int liczba_krokow)
{
    unsigned char max = 255;

    if(liczba_krokow <= 255)
    {
        unsigned char ilosc = (unsigned char)liczba_krokow;
        fwrite(&kierunek, 1,1, bin);
        fwrite(&ilosc,1,1,bin);
    }else if(liczba_krokow > 255 && liczba_krokow <= 511)
    {

        liczba_krokow = liczba_krokow - 255;
        unsigned char ilosc = (unsigned char)liczba_krokow;

        fwrite(&kierunek, 1,1, bin);
        fwrite(&max,1,1,bin);

        fwrite(&kierunek, 1,1, bin);
        fwrite(&liczba_krokow,1,1,bin);
        
    }else if (liczba_krokow > 511 && liczba_krokow <= 767)
    {

        liczba_krokow = liczba_krokow - 511;
        unsigned char ilosc = (unsigned char)liczba_krokow;

        for(int i = 0; i< 2; i++){
            fwrite(&kierunek, 1,1, bin);
            fwrite(&max,1,1,bin);
        }

        fwrite(&kierunek, 1,1, bin);
        fwrite(&liczba_krokow,1,1,bin);
        
    }else if (liczba_krokow > 767 && liczba_krokow <= 1023)
    {
        liczba_krokow = liczba_krokow - 767;
        unsigned char ilosc = (unsigned char)liczba_krokow;

        for(int i = 0; i< 3; i++){
            fwrite(&kierunek, 1,1, bin);
            fwrite(&max,1,1,bin);
        }

        fwrite(&kierunek, 1,1, bin);
        fwrite(&liczba_krokow,1,1,bin);
    }else if (liczba_krokow > 1023 && liczba_krokow <= 1279)
    {
        liczba_krokow = liczba_krokow - 1023;
        unsigned char ilosc = (unsigned char)liczba_krokow;

        for(int i = 0; i< 4; i++){
            fwrite(&kierunek, 1,1, bin);
            fwrite(&max,1,1,bin);
        }

        fwrite(&kierunek, 1,1, bin);
        fwrite(&liczba_krokow,1,1,bin);
    }else if (liczba_krokow > 1279 && liczba_krokow <= 1535)
    {
        liczba_krokow = liczba_krokow - 1279;
        unsigned char ilosc = (unsigned char)liczba_krokow;

        for(int i = 0; i< 5; i++){
            fwrite(&kierunek, 1,1, bin);
            fwrite(&max,1,1,bin);
        }

        fwrite(&kierunek, 1,1, bin);
        fwrite(&liczba_krokow,1,1,bin);
    }else if (liczba_krokow > 1535 && liczba_krokow <= 1791)
    {
        liczba_krokow = liczba_krokow - 1535;
        unsigned char ilosc = (unsigned char)liczba_krokow;

        for(int i = 0; i< 6; i++){
            fwrite(&kierunek, 1,1, bin);
            fwrite(&max,1,1,bin);
        }

        fwrite(&kierunek, 1,1, bin);
        fwrite(&liczba_krokow,1,1,bin);
    }else if (liczba_krokow > 1791 && liczba_krokow <= 2049)
    {
        liczba_krokow = liczba_krokow - 1791;
        unsigned char ilosc = (unsigned char)liczba_krokow;

        for(int i = 0; i< 7; i++){
            fwrite(&kierunek, 1,1, bin);
            fwrite(&max,1,1,bin);
        }

        fwrite(&kierunek, 1,1, bin);
        fwrite(&liczba_krokow,1,1,bin);
    }


}
