#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int triangleSize, i=0, j=0;
  int *tab1, *tab2, *wsk, *wsk2;

  printf("Podaj wielkosc trojkata ");
  scanf("%d", &triangleSize);

  tab1 = malloc(triangleSize * sizeof(int));
  tab2 = malloc(triangleSize * sizeof(int));

  *tab1 = 0;
  *tab2 = 0;
  *(tab1+1) = 1;

  for(;i<triangleSize;i++){
    wsk2=tab2+1;

    for(wsk=tab1+1;wsk<=tab1+triangleSize;wsk++){
      *wsk2 = *(wsk-1) + *wsk;
      wsk2++;
    }

    for(j=i;j<5;j++){
      printf(" ");
    }

    for(wsk=tab1+1;wsk<=tab1+triangleSize;wsk++){
      if(*wsk == 0){
        break;
      }
      printf("%d ", *wsk);
    }

    wsk2=tab2;
    for(wsk=tab1;wsk<=tab1+triangleSize;wsk++){
      *wsk = *wsk2;
      wsk2++;
    }

    printf("\n");
  }

  printf("\n");

  free(tab1);
  free(tab2);


  return 0;
}
