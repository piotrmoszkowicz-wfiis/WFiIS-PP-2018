#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *uwalmnie(int *e)
{
  char *ret;
  itoa(*e, ret, 10);
  return ret;
}

char *uwalmnieseriously(int *e)
{
  char *ret;
  int val = *e;
  int temp = val;
  int len = 0;
  int i;

  while (temp != 0)
  {
    len++;
    temp /= 10;
  }

  ret = malloc(len + 1 * sizeof(char));
  *(ret + len) = '\0';

  for (i = len - 1; i >= 0; i--)
  {
    int last = val % 10;
    char lastC = last + '0';

    *(ret + i) = lastC;
    val /= 10;
  }

  return ret;
}

int main(int argc, char const *argv[])
{
  int x = 1000;

  printf("%s\n", uwalmnie(&x));
  printf("%s\n", uwalmnieseriously(&x));

  return 0;
}
