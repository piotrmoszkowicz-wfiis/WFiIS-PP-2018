#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

struct wektor {
  int x, y, z;
};

struct abc {
  struct wektor w;
  int length;
};

int wektorLength(struct wektor w){
  int underSqrt = 0;
  underSqrt = pow(w.x, 2) + pow(w.y, 2) + pow(w.z, 2);
  return sqrt(underSqrt);
}

int compareWektorLength(const void* a, const void* b){
  struct abc wektorA = *(struct abc*)a;
  struct abc wektorB = *(struct abc*)b;
  return wektorB.length - wektorA.length;
}

int comapreWektoreLengthTen(const void* a, const void* b){
  struct abc wektorA = *(struct abc*)a;
  struct abc wektorB = *(struct abc*)b;
  
  float wekAMin, wekAMax;

  wekAMin = (float)wektorA.length * 0.99;
  wekAMax = (float)wektorA.length * 1.01;

  return (wekAMin > (float)wektorB.length || (float)wektorB.length < wekAMax);
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  struct abc wektory[10];
  struct abc *found;

  int i;

  struct abc wektor;
  wektor.w.x = 1;
  wektor.w.y = 1;
  wektor.w.z = 1;
  wektor.length = 1;

  for(i=0;i<10;i++){
    wektory[i].w.x = rand()%3;
    wektory[i].w.y = rand()%3;
    wektory[i].w.z = rand()%3;

    wektory[i].length = wektorLength(wektory[i].w);

    printf("x: %d y: %d z: %d l: %d\n", wektory[i].w.x, wektory[i].w.y, wektory[i].w.z, wektory[i].length);
  }

  found = (struct abc*) bsearch(&wektor, wektory, 10, sizeof(wektory[0]), compareWektorLength);

  if (found != NULL){
    printf("ZNALEZIONY: x: %d y: %d z: %d l: %d\n", (*found).w.x, (*found).w.y, (*found).w.z, (*found).length);
  }
  else {
    printf("Not found\n");
  }

  return 0;
}
