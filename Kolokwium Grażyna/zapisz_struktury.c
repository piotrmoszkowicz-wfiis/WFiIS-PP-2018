#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
  struct wector tabOfWectors[6];
  FILE *file1;
  int i;

  srand(time(NULL));

  printf("Podaj nazwe pliku binarnego\n");
  scanf("%s", nameOfFile);

  printf("Podana nazwa: %s\n", nameOfFile);
  file1 = fopen(nameOfFile, "wb");
  for (i = 0; i < 6; i++)
  {
    int x, y, z;

    x = rand() % 10;
    y = rand() % 10;
    z = rand() % 10;

    tabOfWectors[i].x = x;
    tabOfWectors[i].y = y;
    tabOfWectors[i].z = z;
  }

  for (i = 0; i < 6; i++)
  {
    printWector(tabOfWectors[i]);
  }

  fwrite(&tabOfWectors, sizeof(struct wector), 6, file1);

  return 0;
}
