#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sumy(int **tab, int a){
  int i,j, sumaAll=0, sumaNad=0, sumaPrzek=0;
  for(i=0;i<a;i++){
    for(j=0;j<a;j++){
      sumaAll+=tab[i][j];
      if (i < j){
        sumaNad += tab[i][j];
      }
      else if (i == j) {
        sumaPrzek += tab[i][j];
      }
    }
  }

  printf("SumaAll: %d, SumaNad: %d, SumaPrzek: %d\n", sumaAll, sumaNad, sumaPrzek);
}

int main(int argc, char const *argv[]) {
  int **tablica;
  int i,j, a;

  srand(time(NULL));

  printf("Podaj wymiar ");
  scanf("%d", &a);

  tablica = malloc(a * sizeof(int *));
  for(i=0;i<a;i++){
    tablica[i] = malloc(a * sizeof(int *));
  }

  for(i=0;i<a;i++){
    for(j=0;j<a;j++){
      tablica[i][j] = rand()%10+1;
      printf("%d\t", tablica[i][j]);
    }
    printf("\n");
  }

  sumy(tablica, a);

  return 0;
}
