#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sumSr(int* tab, int n, int *sr){
  int sum=0;
  int *wsk;
  for(wsk=tab;wsk<tab+n;wsk++){
    sum += (*wsk);
  }
  *sr = sum/n;
  return sum;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  int i,j, sumW=0, sumK=0, sumT=0;

  int tab[5][5]={0};
  int sw[5]={0}, sk[5]={0};

  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      tab[i][j] = rand()%20+10;
      sumT+=tab[i][j];
      printf("%d ", tab[i][j]);
    }
    printf("\n");
  }

  for(i=0;i<5;i++){
    sumW += sumSr(tab[i], 5, sw+i);
  }

  printf("\n");

  for(i=0;i<5;i++){
    for(j=i;j<5;j++){
      int t=tab[j][i];
      tab[j][i] = tab[i][j];
      tab[i][j] = t;
    }
  }

  for(i=0;i<5;i++){
    sumK += sumSr(tab[i], 5, sk+i);
  }

  printf("srednie: \n");
  for(i=0;i<5;i++){
    printf("sw[%d] = %d\n", i, sw[i]);
  }
  for(i=0;i<5;i++){
    printf("sk[%d] = %d\n", i, sk[i]);
  }

  printf("w: %d k:%d t:%d\n", sumW, sumK, sumT);

  return 0;
}
