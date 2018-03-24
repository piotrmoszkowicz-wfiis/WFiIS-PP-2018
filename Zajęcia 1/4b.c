#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define TABSIZE 10

float suma (float t[], int n, float* min, float* max, float* avg, float* maxDev, float* minDev) {
  int i=0;
  float sum=0;

  for(;i<n;i++){
    sum+=t[i];

    if(*max < t[i]){
      *max = t[i];
    }

    if (*min > t[i]){
      *min = t[i];
    }
  }

  *avg = sum/n;
  *maxDev = fabs(*max - *avg);
  *minDev = fabs(*min - *avg);

  return sum;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  int a=5, b=15, i=0;
  float tab[TABSIZE]={0};

  float min=0, max=0, avg=0, maxDev=0, minDev=0, sum;

  int z=b-a;

  for(;i<sizeof(tab)/sizeof(float);i++){
    tab[i] = rand()%z+a;
    printf("%d: %f\n", i, tab[i]);
  }

  min=tab[0];

  sum = suma(tab, TABSIZE, &min, &max, &avg, &maxDev, &minDev);

  printf("Sum: %f\n", sum);
  printf("Min: %f\n", min);
  printf("Max: %f\n", max);
  printf("Avg: %f\n", avg);
  printf("MaxDev: %f\n", maxDev);
  printf("MinDev: %f\n", minDev);

  return 0;
}
