#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a,b,c;

  printf("Podaj a,b,c ");
  scanf("%d %d %d", &a, &b, &c);

  printf("1. a = %d, b = %d, c = %d\n", a,b,c);

  if (a > b){
    int t=a;
    a=b;
    b=t;
  }

  printf("2. a = %d, b = %d, c = %d\n", a,b,c);

  if (b > c){
    int t=b;
    b=c;
    c=t;

    if (a > b){
      int t=b;
      b=a;
      a=t;
    }

    printf("3. a = %d, b = %d, c = %d\n", a,b,c);
  }
  else {
    printf("4. a = %d, b = %d, c = %d\n", a,b,c);
  }





  return 0;
}
