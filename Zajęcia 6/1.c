#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int iteracyjnie(int max){
  int i=0, sil=1;
  for(;i<max;i++){
    sil*=i;
  }
  return sil;
}

int rekurencyjnie(int max){
  static int wynik = 1;
  printf("Wartosc k=%d, adres k=%p \n", max, &max);
  if(max == 1 || max == 0){
    return 1;
  }
  wynik = max * rekurencyjnie(max-1);
  printf("\twartosc wyn=%d, adres wyn=%p\n", wynik, &wynik);
  return wynik;
}

int main(int argc, char const *argv[]) {
  if (argc < 3){
    printf("Prosze podac poprawne argumenty - jako pierwszy liczbe, jako drugi rekurencja/iteracja\n");
    return 0;
  }

  int (*functionPtr)(int);
  int number = atoi(argv[1]);

  if (strcmp(argv[2], "rekurencja") == 0){
    functionPtr = &rekurencyjnie;
  }
  else {
    functionPtr = &iteracyjnie;
  }

  printf("Wynik: %d \n", functionPtr(number));
  return 0;
}
