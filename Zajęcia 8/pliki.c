/*
 tryb fopen --> "w" - zapisywanie, "r" - czytanie, "a" - dane dopisywanie na koncu pliku
np. "wb" - w trybie binarnym,
"w+", "r+", "a+" - + otwarty plik w tzw. dostepie swobodnym - uaktualnienie
(moze tez byc "wb+", "rb+" itd.)

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

int main(void)
{
	int tab[SIZE];
	int i,x,y;
	FILE *fp;
	
	srand(time(NULL));
	
	for(i=0;i<SIZE;i++)
		tab[i] = rand()%200;
	
	
	fp = fopen("dane.dat","w");	
	
	if(fp==NULL)
	{
		printf("BLAD\n");
		exit(-1);
	}
	
	for(i=0;i<SIZE;i++)
		fprintf(fp,"%d, %d\n",i,tab[i]);
	
	fclose(fp);
	
	fp = fopen("dane.dat","r");
	
	if(fp==NULL)
	{
		printf("BLAD\n");
		exit(-1);
	}
	
	for(i=0;i<SIZE;i++)
	{
		fscanf(fp,"%d, %d",&tab[SIZE-i],&y);
		printf("tab[%d] = %d\n",tab[SIZE-i],y);
	}
	return 0;
}
