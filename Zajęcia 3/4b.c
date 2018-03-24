#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mnoz(int **tab1, int **tab2, int m, int n, int p){
  int i=0,j=0,k=0;
  int **tabWynW;

  tabWynW = malloc(m * sizeof(int *));
  for(i=0;i<m;i++){
    tabWynW[i] = malloc(p * sizeof(int *));
  }

  printf("\n");

  for(i=0;i<m;i++){
    for(j=0;j<p;j++){
      int t=0;
      for(k=0;k<n;k++){
        t += tab1[i][k] * tab2[k][j];
      }
      tabWynW[i][j] = t;
    }
  }

  for(i=0;i<m;i++){
    for(j=0;j<p;j++){
      printf("%d ", tabWynW[i][j]);
    }
    printf("\n");
  }
  free(tabWynW);
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  int m,n,p,i,j;
  int **tab1, **tab2;

  //WYMIARY MACIERZY

  printf("Podaj wymiary macierzy ");
  scanf("%d %d %d", &m, &n, &p);

  //ZAALOKUJ TABLICE

  tab1 = malloc(m * sizeof(int *));
  for(i=0;i<m;i++){
    tab1[i] = malloc(n * sizeof(int *));
  }

  tab2 = malloc(n * sizeof(int *));
  for(i=0;i<n;i++){
    tab2[i] = malloc(p * sizeof(int *));
  }

  //WYPELNIJ OBIE TABLICE

  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      tab1[i][j] = rand()%32+12;
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<p;j++){
      tab2[i][j] = rand()%32+12;
    }
  }

  //WYLICZ OBIE TABLICE

  printf("Macierz 1:\n");
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      printf("%d ", tab1[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  printf("Macierz 2:\n");
  for(i=0;i<n;i++){
    for(j=0;j<p;j++){
      printf("%d ", tab2[i][j]);
    }
    printf("\n");
  }

  mnoz(tab1, tab2, m, n, p);

  free(tab1);
  free(tab2);

  return 0;
}
