#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TABSIZE 10

void showTab(int* t, int n){
  int *wsk;
  printf("----------\n");
  for(wsk=t;wsk<t+n;wsk++){
    printf("%d\n", *wsk);
  }
  printf("\n");
}

void sort(int *t, int n, int showResult){
  int *i, *j, temp;
  for(i=t;i<t+n;i++){
    for(j=i+1;j<t+n;j++){
      temp = *i;
      if(*i > *j){
        *i = *j;
        *j = temp;
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

  printf("Wynik: \n");
  showTab(tab, TABSIZE);

  return 0;
}
