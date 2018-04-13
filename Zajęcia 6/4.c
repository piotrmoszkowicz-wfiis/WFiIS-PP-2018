#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
  return *((int*)b) - *((int*)a);
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  int tab[1000];
  int *wsk;

  int a,b;
  printf("Podaj zakres\n");
  scanf("%d %d", &a, &b);

  for(wsk=tab;wsk<tab+1000;wsk++){
    *wsk = rand()%(b-a)+a;
    printf("%d\n", *wsk);
  }

  printf("-----[SORTUJE]------\n");

  qsort(tab, 1000, sizeof(int), &compare);

  for(wsk=tab;wsk<tab+1000;wsk++){
    printf("%d\n", *wsk);
  }

  return 0;
}
