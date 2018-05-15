#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int compareLen(const void* a, const void* b){
  int lenA = strlen((char*)a);
  int lenB = strlen((char*)b);

  return lenA - lenB;
}

int compareAlfa(const void* a, const void* b){
  return strcmp((char*)a, (char*)b);
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  char tab[100][81];
  int i;

  for(i=0;i<100;i++){
    int len = rand()%80+1;
    int j;
    char* str;

    str = malloc(len * sizeof(char));
    for(j=0;j<len;j++){
      str[j] = rand()%25+97;
    }
    str[j+1] = '\0';

    strcpy(tab[i], str);
  }

  qsort(tab, 100, 81, compareLen);

  for(i=0;i<100;i++){
    printf("%s\n", tab[i]);
  }

  return 0;
}
