#include <stdio.h>
#include <stdarg.h>

struct pair {
  float x;
  char z;
};

char max_chr_flt(int counter, ...){
  int i;

  struct pair biggestPair;
  biggestPair.x = 0;
  biggestPair.z = 'a';

  struct pair tempPair;

  va_list ap;

  if (counter == 0 || counter % 2 != 0)
  {
    printf("Nie podane zadnych arguemntow lub podano bledna ilosc!\n");
  }

  va_start(ap, counter);
  for(i = counter; i >= 0;i = i - 2){
    tempPair = va_arg(ap, struct pair);

    if(tempPair.x > biggestPair.x){
      biggestPair.x = tempPair.x;
      biggestPair.z = tempPair.z;
    }
  }
  
  va_end(ap);

  return biggestPair.z;
}

int main(int argc, char const *argv[])
{
  struct pair p1, p2, p3, p4;

  p1.x = 11.34;
  p1.z = 'a';

  p2.x = 122.0;
  p2.z = 'f';

  p3.x = 10.12;
  p3.z = 'x';

  p4.x = 1.67;
  p4.z = 'd';

  char znak = max_chr_flt(4, p1, p2, p3, p4);

  printf("znak = %c\n", znak);

  return 0;
}
