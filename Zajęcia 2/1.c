#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int suma(const int* tab, const int* p){
  int suma=0;
  for(p=tab;p<tab+N;p++){
    suma += *p;
  }
  return suma;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  int tab[N];
  int *p=NULL;

  for(p=tab;p<tab+N;p++){
    *p = rand()%28+7;
    printf("p[%d] = %d\n", p-tab, *p);
  }

  printf("\n");

  int sum = suma(tab, p);
  printf("su=%d\n",sum);

  return 0;
}
