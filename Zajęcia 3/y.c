#include <stdio.h>
#include <stdlib.h>



int main(void)
{
  int n;
  printf("Podaj wielkosc trojkata : ");
  scanf("%d",&n);

  int *tab1 = malloc((n+1) * sizeof(int));
  int *tab2 = malloc((n+1) * sizeof(int));
  int *wsk,*wsk2;


  *tab1 = 0;
  *tab2 = 0;
  *(tab1+1) = 1;

  for(int i = 0;i<n;i++)
    {
      wsk2 = tab2+1;

      for(wsk=tab1+1;wsk<tab1+n+1;wsk++,wsk2++)
        {
          *(wsk2) = *(wsk-1) + *wsk;
        }
      for(int j=i;j<n;j++)
        {
          printf(" ");
        }
      for(wsk = tab1+1;*wsk>0;wsk++)
        {
          /* if(*wsk==0) */
          /*   { */
          /*     break; */
          /*   } */
          printf("%d ",*wsk);
        }
      for(wsk = tab1,wsk2 = tab2;wsk<=tab1+n;wsk++,wsk2++)
        {
          *wsk = *wsk2;
        }
      printf("\n");
    }

  free(tab1);
  free(tab2);
}
