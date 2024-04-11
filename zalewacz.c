#include "zalewacz.h"

void wpisz(FILE *zalany, char ** linie, int szerokosc)
{
    for(int i = 0;i < szerokosc; i++)
        fprintf(zalany, linie[i][1]);

        fprintf(zalany, "\n");
}

char ** podmien_linie(int szerokosc, char* nowa_linia)
{
    char linie[2048][2];

    for(int i = 0; i< szerokosc; i++)
    {
        linie[i][0] = linie[i][1];
        linie[i][1] = linie[i][2];
        linie[i][2] = nowa_linia[i];
    }

    return linie;
}

int suma(char G, char P, char D, char L)
{
    int suma = 0;

    if(G == "X")
        suma++;

    if(P == "X")
        suma++;

    if(D == "X")
        suma++;

    if(L == "X")
        suma++;
    
    return suma;
}

char ** zalanie(int szerokosc, char ** linie)
{  
    int counter = 1;

    int sum;

    while(counter != 0){

        counter = 0;

        for(int i = 1; i < szerokosc - 1; i++)
        {
            sum = suma(linie[i][0], linie[i+1][1], linie[i][2], linie[i-1][1]);

            if(sum == 3)
            {
                linie[i][1] = "X";
                counter++;
            }
        }
    }
}

FILE *zalany(FILE *plik_sf, int szerokosc)
{
    FILE *zalany = fopen("plik_zalany.txt", "w");

    for(int i = 0; i < szerokosc; i++)
        fprintf(zalany, "X");

    fprintf(zalany, "\n");

    char linie[2048][2];
    char nowa_linia[2048];

    for(int i = 0; i < 3; i++)
    {
        fgets(nowa_linia, szerokosc, plik_sf);
        
        for(int j = 0; j < szerokosc; j++)
            linie[j][i] = nowa_linia[i];
    }

    zalanie(szerokosc, linie);
    wpisz(zalany, linie, szerokosc);
    
    while(NULL !=  fgets(nowa_linia, szerokosc , plik_sf))
    {
        podmien_linie(szerokosc, nowa_linia);
        zalanie(szerokosc, linie);
        wpisz(zalany, linie, szerokosc);
    }

    for(int i = 0; i < szerokosc; i++)
        fprintf(zalany, "X");

    fprintf(zalany, "\n");

    if(zalany == NULL)
    {
        printf("bin jest pusty/n");
        return NULL;
    }

    return zalany;
}