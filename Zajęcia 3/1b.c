#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int triangleSize, i=0, j=0;
  int *tab1, *wsk;

  printf("Podaj wielkosc trojkata ");
  scanf("%d", &triangleSize);

  tab1 = malloc(sizeof(int));

  *tab1 = 1;

  for(;i<triangleSize;i++){
    for(wsk=tab1+i-1;wsk>=tab1+1;wsk--){
      *wsk += *(wsk-1);
    }
    for(j=i;j<5;j++){
      printf(" ");
    }
    for(wsk=tab1;wsk<=tab1+i;wsk++){
      printf("%d ", *wsk);
      tab1 = realloc(tab1, i+1 * sizeof(int));
      *(tab1+i+1) = 1;
    }

    printf("\n");
  }

  printf("\n");

  free(tab1);


  return 0;
}
