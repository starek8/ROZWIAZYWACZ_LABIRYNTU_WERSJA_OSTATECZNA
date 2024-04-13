#include "zalewacz.h"

int zmiany = 1;

void wpisz(FILE *out, char ** linie, int szerokosc)
{
    for(int i =0; i< szerokosc; i++)
    {
    fprintf(out, "%c", linie[1][i]);
    }
        fprintf(out, "\n");
}

char ** podmien_linie(int szerokosc, char* nowa_linia, char ** linie)
{
    for(int i = 0; i< szerokosc; i++)
    {
        linie[0][i] = linie[1][i];
        linie[1][i] = linie[2][i];
        linie[2][i] = nowa_linia[i];
    }

    return linie;
}

int suma(char G, char P, char D, char L)
{
    int suma = 0;

    if(G == 'X')
        suma++;

    if(P == 'X')
        suma++;

    if(D == 'X')
        suma++;

    if(L == 'X')
        suma++;
    
    return suma;
}

char ** zalanie_3_linii(int szerokosc, char ** linie)
{  
    int counter = 1;

    int sum;

    while(counter != 0){
    
        counter = 0;

        for(int i = 1; i < szerokosc - 1; i++)
        {
            sum = suma(linie[0][i], linie[1][1+i], linie[2][i], linie[1][i-1]);

            if(sum == 3 && linie[1][i] == ' ')
            {
                linie[1][i] = 'X';
                counter++;
                zmiany++;
            }
        }
    }
    return linie;
}

FILE *zalany_plik(FILE *plik_sf, int szerokosc)
{
    FILE *out = fopen("plik_zalany.txt", "w+");

    for(int i = 0; i < szerokosc; i++)
    {
        fprintf(out, "X");
    }

    fprintf(out, "\n");

    char ** linie = malloc(3 * sizeof(char*)); 

    for( int i = 0 ; i < 3 ; i++ )
    {
        linie[i] = malloc(szerokosc+2);
    }

    char * nowa_linia = malloc((szerokosc+2) * sizeof(char));

    for(int i = 0; i < 3; i++)
    {
        fgets(nowa_linia, szerokosc+2, plik_sf);
        
        for(int j = 0; j < szerokosc; j++)
            linie[i][j] = nowa_linia[j];
    }
        zalanie_3_linii(szerokosc, linie);

        wpisz(out, linie, szerokosc);

        while(fgets(nowa_linia, szerokosc + 2 , plik_sf))
        {
            podmien_linie(szerokosc, nowa_linia, linie);
            zalanie_3_linii(szerokosc, linie);
            wpisz(out, linie, szerokosc);
        }

    for(int i = 0; i < szerokosc; i++)
        fprintf(out, "X");

    fprintf(out, "\n");

    free(nowa_linia);
    free(linie);

    return out;
}

/*FILE *ostateczny(FILE *plik_sf,int szerokosc)
{

    int ab =0; // 0 ->a , 1->b

    FILE *plik_a = zalany_plik(plik_sf, szerokosc);

    FILE *plik_b = zalany_plik(plik_a, szerokosc);


    while(zmiany != 0)
    {
        zmiany = 0;
        if(ab == 0)
        {
            plik_b = zalany_plik(plik_a, szerokosc);
            fclose(plik_a);
            ab = 1;
        } else{
            plik_a = zalany_plik(plik_b, szerokosc);
            fclose(plik_b);
            ab = 0;
        }
    }

    return plik_b;
}

int main (int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Nie udało się otworzyć pliku!\nKoniec działania programu\n");
        return 1;
    }

    FILE *out  = ostateczny(file, 21);

    return 0;
} */