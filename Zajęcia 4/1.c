#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int a, i, j, il=0, p=1;
  int *tablica, *wsk;

  printf("Podaj zakres liczbe ");
  scanf("%d", &a);

  tablica = malloc(a * sizeof(int));

  *tablica=0;

  tablica[1] = 1;

  for(i=1;p<sqrt(a);i++){
    if(tablica[i] == 1){
      continue;
    }

    p = i;

    for(j=i+1;j<a;j++){
      if (j%i == 0){
        tablica[j] = 1;
      }
    }
  }

  for(i=1;i<a;i++){
    if (tablica[i] == 1){
      continue;
    }
    printf("Liczba pierwsza: %d\n", i);
    il++;
  }

  printf("Ilosc: %d\n", il);

  return 0;
}
