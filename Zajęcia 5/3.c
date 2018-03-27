#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char txt2[80];
  char txt;
  int i=0, licznik=0;
  while(scanf("%c", &txt)){
    txt2[i] = txt;
    i++;
    if (txt == '\n'){
      txt2[i+1] = '\0';

      if (strstr(txt2, "wagon")){
        printf("%s", txt2);
        licznik++;
      }

      for(i=0;i<80;i++){
        txt2[i] = '\0';
      }
      i=0;
    }

    if (feof(stdin)){
      break;
    }
  };

  printf("Ilosc wystapien wagonu: %d\n", licznik);

  return 0;
}
