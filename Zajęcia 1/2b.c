#include <stdio.h>
#include <math.h>

int main (void){
 int liczba, i=0, result=0;
 scanf("%d", &liczba);

 while(liczba != 0){
   result += (liczba%2)*pow(10, i);
   liczba /= 2;
   i++;
 }

 printf("%d\n", result);

 printf("\n\n");

 return 0;
}
