#include <stdio.h>

#define BINSIZE 3

int main (void){
 int liczba;
 scanf("%d", &liczba);
 char tab[BINSIZE]="\0";

 printf("Reprezentacja binarnia: \n");

 //o jeden mniej, gdyz ostanim znakiem jest \0
 int licznik=BINSIZE-1;

 while(liczba != 0){
   tab[licznik] = (liczba%2)+'0';
   liczba = liczba>>1;
   licznik--;
 }
 printf("%s\n",tab);
 return 0;
}
