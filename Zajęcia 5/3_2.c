#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char *txt;
  size_t text_size = 80;
  int licznik=0;

  txt = malloc(text_size * sizeof(char));

  while(getline(&txt, &text_size, stdin)){
      if (strstr(txt2, "wagon")){
        printf("%s", txt);
        licznik++;
      }

    if (feof(stdin)){
      break;
    }
  };

  printf("Ilosc wystapien wagonu: %d\n", licznik);

  return 0;
}
