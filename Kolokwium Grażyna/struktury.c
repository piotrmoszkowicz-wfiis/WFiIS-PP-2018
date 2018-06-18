#include <stdio.h>
#include <stdlib.h>

struct wector
{
  int x, y, z;
};

void printWector(struct wector w)
{
  printf("x = %d, y = %d, z = %d\t", w.x, w.y, w.z);
}

int main(int argc, char const *argv[])
{
  char nameOfFile[50];
  struct wector tabOfWectors[2][3];
  FILE *file1;
  int i, j;

  printf("Podaj nazwe pliku binarnego\n");
  scanf("%s", nameOfFile);

  printf("Podana nazwa: %s\n\n", nameOfFile);
  file1 = fopen(nameOfFile, "rb");
  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 3; j++)
    {
      fread(&tabOfWectors[i][j], sizeof(struct wector), 1, file1);
    }
  }

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printWector(tabOfWectors[i][j]);
    }
    printf("\n");
  }

  return 0;
}
