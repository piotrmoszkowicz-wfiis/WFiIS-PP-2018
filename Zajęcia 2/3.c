#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  float srednia = 0;
  int j=0;

  for(;j<100;j++){
    int los = rand()%100, i=rand()%100, counter=1, min=0, max=100;

    //printf("%d\n", los);

    while(los!=i){
      if (los < i){
        max = i;
      }
      else {
        min=i;
      }
      //printf("Przedzial: %d - %d\n", min, max);
      i = rand()%(max-min)+min;
      //printf("los=%d\n", i);
      counter++;
    }

    printf("%d) Ilosc prob: %d\n", j+1, counter);
    srednia+=counter;
  }

  srednia/=100;

  printf("Srednia ilosc prob: %f\n", srednia);

  return 0;
}
