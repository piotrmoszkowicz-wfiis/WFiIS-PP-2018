#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TABSIZE 10

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  int a=5, b=15, i=0;
  int tab[TABSIZE]={0};

  int z=b-a+1;

  for(;i<sizeof(tab)/sizeof(int);i++){
    tab[i] = rand()%z+a;
    printf("%d: %d\n", i, tab[i]);
  }

  return 0;
}
