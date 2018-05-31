#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int compareLen(const void *a, const void *b)
{
  int lenA = strlen((char *)a);
  int lenB = strlen((char *)b);

  return lenA - lenB;
}

int compareAlfa(const void *a, const void *b)
{
  const char *pa = *(const char **)a;
  const char *pb = *(const char **)b;

  return strcmp(pa, pb);
}

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  char **tab;
  int i;

  tab = malloc(100 * sizeof(char *));
  if (!tab)
  {
    printf("Brak pamieci!!!\n");
    exit(1);
  }
  for (i = 0; i < 100; i++)
  {
    tab[i] = malloc(81 * sizeof(char));
    if (!tab[i])
    {
      printf("Brak pamieci!!!\n");
      exit(1);
    }
  }

  for (i = 0; i < 100; i++)
  {
    int len = rand() % 80 + 1;
    int j;
    char *str;

    str = malloc((len + 1) * sizeof(char));
    if (!str)
    {
      printf("Brak pamieci!!!\n");
      exit(1);
    }

    for (j = 0; j < len; j++)
    {
      int x = rand() % 25 + 'a';
      str[j] = x;
    }
    str[j] = '\0';

    strcpy(tab[i], str);
    free(str);
  }

  for (i = 0; i < 100; i++)
  {
    printf("%d: %s [%p]\n", i, tab[i], &tab[i]);
  }

  qsort(tab, 100, sizeof(char *), compareAlfa);

  for (i = 0; i < 100; i++)
  {
    printf("%s\n", tab[i]);
  }

  free(tab);

  return 0;
}
