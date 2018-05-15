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
    //printf("%f\n", tab[i]);
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

  printf("%d", sizeof(tab) / sizeof(float));

  fwrite(tab, sizeof(float), sizeof(tab) / sizeof(float), f2);

  fclose(f1);
  fclose(f2);

  f1 = fopen("plik.txt", "r");

  if (f1 == NULL)
  {
    printf("BLAD\n");
    exit(-1);
  }

  fseek(f1, 0L, SEEK_END);
  printf("Size .txt = %ld\n", ftell(f1));
  fseek(f1, 0, SEEK_SET);

  fclose(f1);

  f2 = fopen("plik.bin", "rb+");
  float t[100];

  fread(t, sizeof(float), 100, f2);
  for(i=0;i<100;i++){
    printf("%f\n", t[i]);
  }

  fclose(f2);

  f2 = fopen("plik.bin", "rb+");

  if (f2 == NULL)
  {
    printf("BLAD\n");
    exit(-1);
  }

  fseek(f2, 0L, SEEK_END);
  long int sizeBin = ftell(f2);
  printf("Size .bin = %ld\n", sizeBin);
  fseek(f2, 0, SEEK_SET);

  float zero = 0.0;

  for(i=5;i<=100;i+=5){
    fseek(f2, sizeof(float)*4, SEEK_CUR);
    fwrite(&zero, sizeof(float), 1, f2);
  }

  fclose(f2);

  f2 = fopen("plik.bin", "rb+");
  float ta[100];

  fread(ta, sizeof(float), 100, f2);
  for (i = 0; i < 100; i++)
  {
    printf("%f\n", ta[i]);
  }

  fclose(f2);

  return 0;
}
