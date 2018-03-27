#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int i=0;
  for(;i<argc;i++){
    printf("Argument [%d] = %s\n", i, argv[i]);
  }

  int integer = atoi(argv[2]);
  float floatNumber = atof(argv[3]);

  printf("Integer: %d, Float: %0.2f\n", integer, floatNumber);
  return 0;
}
