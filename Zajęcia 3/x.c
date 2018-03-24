#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rozmiar,x;
    int *tablica, *tab2;
    printf("Podaj wysokosc trojkata Pascala: ");
    scanf("%d", &rozmiar);
    //zaalokowanie dynamicznie dwoch tablic o odpowiedniej dlugosci
    rozmiar++;
    tablica = (int*) malloc(rozmiar * sizeof(*tablica));
    tab2 = (int*) malloc(rozmiar * sizeof(*tab2));
    //zeruje tablice
    *tablica = 0;
    *tab2 = 0;
    //elementowi pierwszej tablicy o pierwszym indeksie przypisuje 1
    tablica[1] = 1;

    for (int j = 0; j < rozmiar-1; j++)
    {

        for (int i = 1; i < rozmiar; i++){
          tab2[i] = tablica[i] + tablica[i-1];
        }


        for(int i = j; i < rozmiar; i++)
              printf(" ");
        //wypisuje wartosc tablicy az do napotkania zerowego elementu
        for (int i = 1; i < rozmiar; i++)
        {
            if (tablica[i] == 0)
                break;
            printf("%d ", tablica[i]);
        }
        //przepisuje tablice
        for (int i = 0; i < rozmiar; i++)
            tablica[i] = tab2[i];

        printf("\n");
    }

    printf("\n");

    free(tablica);
    free(tab2);
    return 0;
}
