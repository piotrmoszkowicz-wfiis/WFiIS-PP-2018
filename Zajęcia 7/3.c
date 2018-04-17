#include <stdio.h>
#include <time.h>
#include <stdlib.h>

union Value {
  int b;
  float c;
};

struct liczba {
  char zmZnakowa;
  union Value wart;
};

void printTableElement(struct liczba l){
  if (l.zmZnakowa == 'i'){
    printf("Typ: int; Wartosc: %d\n", l.wart.b);
  }
  else {
    printf("Typ: float; Wartosc: %f\n", l.wart.c);
  }
}

void sort(struct liczba *tab){
  int i=0, j=0;

  for(i=0;i<10;i++){
    for(j=0;j<10;j++){
      if(tab[i].zmZnakowa == 'i' && tab[j].zmZnakowa == 'd'){
        struct liczba temp;
        temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
      }
      else {
        if (tab[i].zmZnakowa == 'i' && tab[j].zmZnakowa == 'i'){
          if (tab[i].wart.b < tab[j].wart.b){
            struct liczba temp;
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
          }
        }
        else {
          if (tab[i].wart.c < tab[j].wart.c){
            struct liczba temp;
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
          }
        }
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  struct liczba *tab;
  struct liczba *wsk;

  tab = (struct liczba*) malloc(10 * sizeof(struct liczba));

  for(wsk=tab;wsk<tab+10;wsk++){
    int probability = rand()%2;
    if (probability == 1){
      (*wsk).zmZnakowa = 'i';
      (*wsk).wart.b = rand()%100;
    }
    else {
      (*wsk).zmZnakowa = 'd';
      (*wsk).wart.c = rand()%100/(float)10;
    }
  }

  for(wsk=tab;wsk<tab+10;wsk++){
    printTableElement(*wsk);
  }

  printf("---------\n");

  sort(tab);

  for(wsk=tab;wsk<tab+10;wsk++){
    printTableElement(*wsk);
  }


  return 0;
}
