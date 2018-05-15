#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main(int argc, char const *argv[])
{
  FILE *f1, *f2;

  float tab[SIZE];
  int i;
  float y;

  for(i=0;i<SIZE;i++){
    tab[i] = rand()%10000/(float)1000;
    printf("%f\n", tab[i]);
  }

  f1 = fopen("plik.txt", "w");
  f2 = fopen("plik.bin", "wb");

  if (f1 == NULL)
  {
    printf("BLAD\n");
    exit(-1);
  }

  for (i = 0; i < SIZE; i++){
    fprintf(f1, "%f\n", tab[i]);
  }
    

  if (f2 == NULL)
  {
    printf("BLAD\n");
    exit(-1);
  }

  fwrite(tab, sizeof(float), 100, f2);

  fclose(f1);
  fclose(f2);

  f1 = fopen("plik.txt", "r");
  f2 = fopen("plik.bin", "rb");

  fseek(f1, 0L, SEEK_END);
  printf("Size .txt = %ld\n", ftell(f1));
  fclose(f1);

  fseek(f2, 0L, SEEK_END);
  printf("Size .bin = %ld\n", ftell(f2));
  fclose(f2);

  return 0;
}
