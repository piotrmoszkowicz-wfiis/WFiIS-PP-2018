#include <stdio.h>

int add2(int* a, int* b){
  return *a + *b;
}

int comp2(int* a, int* b){
  return *a - *b;
}

int add2_or_comp2(int a, int b, int (*functionPtr)(int*, int*)){
  return functionPtr(&a, &b);
}

int main(int argc, char const *argv[]) {
  int a,b;
  printf("Podaj a i b\n");
  scanf("%d %d", &a, &b);

  printf("Suma = %d\n", add2_or_comp2(a, b, &add2));
  printf("Roznica = %d\n", add2_or_comp2(a, b, &comp2));
  return 0;
}
