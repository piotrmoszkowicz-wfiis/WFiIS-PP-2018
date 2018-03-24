#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TABSIZE 10

void showTab(int t[], int n){
  int i=0;
  printf("----------\n");
  for(;i<n;i++){
    printf("%d\n", t[i]);
  }
  printf("\n");
}

void sort(int t[], int n, int showResult){
  int i,j;
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      int temp;
      temp = t[i];
      if (t[i] > t[j]){
        t[i] = t[j];
        t[j] = temp;
        if(showResult){
          showTab(t, n);
        }
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  int a=5, b=15, i=0;
  int tab[TABSIZE]={0};

  int z=b-a+1;

  for(;i<sizeof(tab)/sizeof(int);i++){
    tab[i] = rand()%z+a;
    printf("%d: %d\n", i, tab[i]);
  }

  sort(tab, TABSIZE, 1);

  printf("\n\n\n");

  printf("Wynik: \n");
  showTab(tab, TABSIZE);

  return 0;
}
