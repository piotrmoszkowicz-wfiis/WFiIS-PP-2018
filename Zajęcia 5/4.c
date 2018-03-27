#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char txt2[80];
  int znaki[26] = {0};
  char txt;
  int i=0, licznik_znakow = 0, licznik_linii = 0;

  while(scanf("%c", &txt)){
    txt2[i] = txt;
    licznik_znakow++;
    i++;

    if(txt >= 'A' && txt <= 'Z'){
      int index = (int)txt - 65;
      znaki[index]++;
    }
    else if (txt >= 'a' && txt <= 'z'){
      int index = (int)txt - 97;
      znaki[index]++;
    }

    if (txt == '\n'){
      licznik_linii++;
      txt2[i+1] = '\0';

      for(i=0;i<80;i++){
        txt2[i] = '\0';
      }
      i=0;
    }

    if (feof(stdin)){
      break;
    }
  };

  printf("Ilosc znakow: %d\n", licznik_znakow);
  printf("Ilosc linii: %d\n", licznik_linii);

  for(i=0;i<26;i++){
    printf("Ilosc wystapien %c = %d\n", i+65, znaki[i]);
  }

  return 0;
}
