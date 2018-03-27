#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void filltab(float* tab, int n){
  float *wsk;
  for(wsk=tab;wsk<tab+n;wsk++){
    *wsk = rand()%1000/(float)100;
  }
}

float sum(float** tab, int tab_numer, int number_of_items){
  float sum = 0;
  float *wsk;
  for(wsk=tab[tab_numer];wsk<tab[tab_numer]+number_of_items;wsk++){
    sum += *wsk;
  }

  return sum;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  float t_1[4]={0}, t_2[6]={0}, t_3[3]={0}, t_4[2]={0}, t_5[4]={0};
  int size_of_tabs[] = {4,6,3,2,4}, i=0;

  filltab(t_1, size_of_tabs[0]);
  filltab(t_2, size_of_tabs[1]);
  filltab(t_3, size_of_tabs[2]);
  filltab(t_4, size_of_tabs[3]);
  filltab(t_5, size_of_tabs[4]);

  float **tab_wszystkie;
  tab_wszystkie = malloc(5 * sizeof(float *));

  tab_wszystkie[0] = t_1;
  tab_wszystkie[1] = t_2;
  tab_wszystkie[2] = t_3;
  tab_wszystkie[3] = t_4;
  tab_wszystkie[4] = t_5;

  for(;i<5;i++){
    float suma = sum(tab_wszystkie, i, size_of_tabs[i]);
    printf("Suma[%d] = %f\n", i, suma);
  }

  printf("%lu\n", sizeof(tab_wszystkie)/sizeof(float**));

  free(tab_wszystkie);

  return 0;
}
