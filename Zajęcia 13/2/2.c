#include <stdio.h>
#include <stdarg.h>

void showVariables(int counter, ...){
  va_list ap;

  if(counter == 0){
    printf("Nie podane zadnych arguemntow!\n");
  }

  int i = counter;
  double dbl;
  char c;
  int val;

  va_start(ap, counter);

  while(i--){
    int argType = i%3;
    switch(argType){
      case 0:
        dbl = va_arg(ap, double);
        printf("Double: %f\n", dbl);
        break;
      case 1:
        val = va_arg(ap, int);
        printf("Int: %d\n", val);
        break;
      case 2:
        c = va_arg(ap, int);
        printf("Char: %c\n", c);
        break;
      default:
        printf("Blad w trakcie definicji typu parametru\n");
        break;
    }
  }

  va_end(ap);
}


int main(int argc, char const *argv[])
{
  showVariables(6, 'a', 5, 4.54, 'b', 6, 5.43);
  return 0;
}


