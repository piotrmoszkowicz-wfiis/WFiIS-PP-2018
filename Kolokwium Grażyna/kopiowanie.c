#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  FILE *file1;
  FILE *file2;
  int sizeOfPlik = 0;
  char *contentOfPlik;

  file1 = fopen("binarny1.bin", "rb");

  if (!file1)
  {
    exit(0);
  }

  file2 = fopen("binarny2.bin", "wb");

  if (!file2)
  {
    exit(0);
  }

  fseek(file1, 0L, SEEK_END);
  sizeOfPlik = ftell(file1);
  fseek(file1, 0L, SEEK_SET);

  contentOfPlik = malloc(sizeOfPlik * sizeof(char));

  if (!contentOfPlik)
  {
    exit(0);
  }

  fread(contentOfPlik, sizeof(char), sizeOfPlik, file1);
  fwrite(contentOfPlik, sizeof(char), sizeOfPlik, file2);

  return 0;
}
