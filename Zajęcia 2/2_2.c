#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N1 10
#define N2 10

void sort(float *t, int n){
  float *i, *j, temp;
  for(i=t;i<t+n;i++){
    for(j=i+1;j<t+n;j++){
      temp = *i;
      if(*i > *j){
        *i = *j;
        *j = temp;
      }
    }
  }
}

void zamiana(float* elem1, float* elem2){
  float temp=*elem1;
  *elem1 = *elem2;
  *elem2 = temp;
}

void odwroc(float* tab, int n){
  int i=0;
  for(;i<n/2;i++){
    zamiana(tab+i, tab+n-i-1);
  }
}

void wymien_tablice(float* tab, float* tab_2, int n){
  int i=0;
  for(;i<n;i++){
    zamiana(tab+i, tab_2+i);
  }
}

void merge_sort(float* tab, float* tab_2, float* tab_res, int l1, int l2){
  int i=0, j=0, k=0, l=l1+l2;
  while(i<l1 && j<l2){
    if(*(tab+i) < *(tab_2+j)){
      *(tab_res+k) = *(tab+i);
      i++;
    }
    else {
      *(tab_res+k) = *(tab_2+j);
      j++;
    }
    k++;
  }

  if(i>j){
    for(;k<l;k++){
      *(tab_res+k) = *(tab_2+j);
      j++;
    }
  }
  else {
    for(;k<l;k++){
      *(tab_res+k) = *(tab+i);
      i++;
    }
  }
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  float tab[N1], tab_2[N2], tab_res[N1+N2];
  float *p=NULL;

  printf("TAB:\n");

  for(p=tab;p<tab+N1;p++){
    int r=rand()%100;
    *p = (float)r/(float)100;
    printf("%f\n", *p);
  }

  printf("\n\n");

  printf("TAB2:\n");

  for(p=tab_2;p<tab_2+N2;p++){
    int r=rand()%100;
    *p = (float)r/(float)100;
    printf("%f\n", *p);
  }

  printf("\n\n");

  sort(tab, N1);
  sort(tab_2, N2);

  printf("TAB posortowane:\n");

  for(p=tab;p<tab+N1;p++){
    printf("%f\n", *p);
  }

  printf("\n\n");
  printf("TAB_2 posortowane:\n");

  for(p=tab_2;p<tab_2+N2;p++){
    printf("%f\n", *p);
  }

  merge_sort(tab, tab_2, tab_res, N1, N2);

  printf("\n\n");
  printf("TAB_2 zamiana 0 z 5 posortowane:\n");
  zamiana(tab_2, tab_2+5);

  for(p=tab_2;p<tab_2+N2;p++){
    printf("%f\n", *p);
  }

  printf("\n\n");
  printf("TAB_2 odwrocone:\n");
  odwroc(tab_2, N2);

  for(p=tab_2;p<tab_2+N2;p++){
    printf("%f\n", *p);
  }

  printf("\n\n");
  printf("Zamiana tablic - TAB:\n");

  wymien_tablice(tab, tab_2, N1);

  for(p=tab;p<tab+N1;p++){
    printf("%f\n", *p);
  }

  printf("Zamiana tablic - TAB_2:\n");

  for(p=tab_2;p<tab_2+N2;p++){
    printf("%f\n", *p);
  }

  printf("\n\n");
  printf("Merge Sort:\n");
  for(p=tab_res;p<tab_res+N1+N2;p++){
    printf("%f\n", *p);
  }

  return 0;
}
