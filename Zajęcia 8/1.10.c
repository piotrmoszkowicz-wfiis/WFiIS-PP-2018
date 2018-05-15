#include <stdio.h>
#include <string.h>

struct daneStudenta {
  char imie[80], nazwisko[80], wydzial[6];
  int wiek;
};


int main(int argc, char const *argv[])
{
  char* password = "HASUO";
  char podaneHaslo[80];
  int proby = 0;

  do {
    printf("Podaj haslo - pozostalych prob: %d\n", 3-proby);
    scanf("%s", podaneHaslo);

    if (strcmp(password, podaneHaslo) == 0){
      break;
    }
    proby++;
    printf("Podane bledne haslo!!\n");

    if(proby == 3){
      printf("You're out!\n");
      return 0;
    }

  }
  while(proby < 3);

  struct daneStudenta actualData;
  FILE *fp;

  printf("Podano poprawne haslo - podaj dane - najpierw imie:\n");
  scanf("%s", &(actualData.imie));

  printf("Podaj nazwisko:\n");
  scanf("%s", &(actualData.nazwisko));

  printf("Podaj skrot wydzialu (np WFIIS):\n");
  scanf("%s", &(actualData.wydzial));

  printf("Podaj wiek:\n");
  scanf("%d", &(actualData.wiek));

  printf("Podane dane:\n %s %s (%s) -> %d\n", actualData.imie, actualData.nazwisko, actualData.wydzial, actualData.wiek);

  fp = fopen("baza.txt", "a");
  fseek(fp, 0L, SEEK_END);

  fprintf(fp, "IMIE:%s|NAZWISKO:%s|WYDZIAL:%s|WIEK:%d\n", actualData.imie, actualData.nazwisko, actualData.wydzial, actualData.wiek);
  fclose(fp);

  return 0;
}
