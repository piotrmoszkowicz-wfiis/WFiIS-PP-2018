#include <stdio.h>

int main(int argc, char const *argv[]) {
  char tekst[] = "Ile i które z samoglosek znajdziesz w tym zdaniu ?";
  int tab[6]={0}; //0=> a, 1=> e, 2=> i, 3=> o, 4=> u, 5=>y
  int i=0, tekstSize=sizeof(tekst)/sizeof(char), numerOfWords=0;

  while(i<tekstSize){
    switch(tekst[i]){
      case 'a':
      case 'A':
        tab[0]++;
        break;
      case 'e':
      case 'E':
        tab[1]++;
        break;
      case 'i':
      case 'I':
        tab[2]++;
        break;
      case 'o':
      case 'O':
        tab[3]++;
        break;
      case 'u':
      case 'U':
        tab[4]++;
        break;
      case 'y':
      case 'Y':
        tab[5]++;
        break;
      case ' ':
        numerOfWords++;
        break;
      default:
        break;
    }
    i++;
  }

  printf("Ilosc A: %d\n Ilosc E: %d \n Ilosc I: %d \n Ilosc O: %d \n Ilosc U: %d \n Ilosc Y: %d \n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
  printf("Ilosc samoglosek: %d\n", tab[0]+tab[1]+tab[2]+tab[3]+tab[4]+tab[5]);
  printf("Ilosc wyrazow: %d\n", numerOfWords);

  return 0;
}
