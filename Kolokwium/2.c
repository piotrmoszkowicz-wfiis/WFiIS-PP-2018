#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dodawaj(char *liczbaA, char *liczbaB, char *wyn)
{
  int len1 = strlen(liczbaA);
  int len2 = strlen(liczbaB);
  int i, przes = 0;

  printf("len1: %d len2: %d\n", len1, len2);

  if (len1 > len2)
  {
    for (i = 0; i < len1; i++)
    {
      int x;
      if (len2 - i - 1 < 0)
      {
        x = (liczbaA[len1 - i - 1] - 48) + przes;
      }
      else
      {
        x = (liczbaA[len1 - i - 1] - 48) + (liczbaB[len2 - i - 1] - 48) + przes;
      }

      przes = 0;
      if (x >= 10)
      {
        x -= 10;
        przes = 1;
      }
      wyn[len1 - i - 1] = x + 48;
    }
    wyn[len1] = '\0';
  }
  else
  {
    for (i = 0; i < len2; i++)
    {
      int x;
      if (len1 - i - 1 < 0)
      {
        x = (liczbaB[len2 - i - 1] - 48) + przes;
      }
      else
      {
        x = (liczbaA[len1 - i - 1] - 48) + (liczbaB[len2 - i - 1] - 48) + przes;
      }

      przes = 0;
      if (x >= 10)
      {
        x -= 10;
        przes = 1;
      }
      wyn[len2 - i - 1] = x + 48;
    }
    wyn[len2] = '\0';
  }

  return wyn;
}

int main(int argc, char const *argv[])
{
  char liczbaA[201];
  char liczbaB[201];
  char wynik[201];

  printf("Podaj liczbe 1\n");
  scanf("%s", liczbaA);

  printf("Podaj liczbe 2\n");
  scanf("%s", liczbaB);

  dodawaj(liczbaA, liczbaB, wynik);

  printf("%s\n", wynik);

  return 0;
}