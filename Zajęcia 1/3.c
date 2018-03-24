#include <stdio.h>

int main(int argc, char const *argv[]) {
  int x;
  int *px;
  int *py;

  printf("%p %p %p \n", &x, px, py);
  //printf("%d %d %d \n", x, *px, *py); //err
  //printf("%d\n", *px); err
  //printf("%d\n", *px != NULL); err
  //printf("%d\n", *py); err
  //printf("%d\n", *py != NULL); err

  scanf("%d\n", &x);

  printf("%p %p %p \n", &x, px, py);
  //printf("%d %d %d \n", x, *px, *py); err
  //printf("%d\n", *px); err
  //printf("%d\n", *px != NULL); err
  //printf("%d\n", *py); err
  //printf("%d\n", *py != NULL); err

  *px = x;

  printf("%p %p %p \n", &x, px, py);
  //printf("%d %d %d \n", x, *px, *py);
  printf("%d\n", *px);
  printf("%d\n", *px != NULL);
  //printf("%d\n", *py); err
  //printf("%d\n", *py != NULL); err

  *py = *px;

  printf("%p %p %p \n", &x, px, py);
  printf("%d %d %d \n", x, *px, *py);
  printf("%d\n", *px);
  printf("%d\n", *px != NULL);
  printf("%d\n", *py);
  printf("%d\n", *py != NULL);

  *(*py) = 1;

  printf("%p %p %p \n", &x, px, py);
  printf("%d %d %d \n", x, *px, *py);
  printf("%d\n", *px);
  printf("%d\n", *px != NULL);
  printf("%d\n", *py);
  printf("%d\n", *py != NULL);

  return 0;
}
