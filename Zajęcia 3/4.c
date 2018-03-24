#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 8

void mnoz(int (*tab1)[N], int (*tab2)[N], int m, int n){
  int i=0,j=0,k=0;
  int tabWynW[N][N]={0};

  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      int t=0;
      for(k=0;k<n;k++){
        t += tab1[i][k] * tab2[k][j];
      }
      tabWynW[i][j] = t;
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d ", tabWynW[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  int tab1[8][8], tab2[8][8];
  int i,j;

  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      tab1[i][j] = rand()%32+12;
      tab2[i][j] = rand()%32+12;
    }
  }

  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      printf("%d ", tab1[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      printf("%d ", tab2[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  mnoz(tab1, tab2, 8, 8);

  return 0;
}
