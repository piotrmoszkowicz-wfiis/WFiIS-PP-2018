#include <stdio.h>
#include <string.h>

struct klient
{
  char imie[20];
  char nazwisko[32];
  char postcode[7];
  int wiek;
};

int compare(const void *a, const void *b)
{
  struct klient clientA = *(struct klient *)a;
  struct klient clientB = *(struct klient *)b;

  int cmp = strcmp(clientA.nazwisko, clientB.nazwisko);

  if (cmp == 0)
  {
    return strcmp(clientA.imie, clientB.imie);
  }
  return cmp;
}

int main(int argc, char const *argv[])
{
  struct klient clients[5];
  int i = 0;

  while (i < 5)
  {
    struct klient client;
    scanf("%s", client.imie);
    scanf("%s", client.nazwisko);
    scanf("%s", client.postcode);
    scanf("%d", &client.wiek);

    clients[i] = client;
    i++;
  }

  qsort(clients, 5, sizeof(clients[0]), compare);

  for (i = 0; i < 5; i++)
  {
    printf("im: %s nazw: %s kod: %s wiek: %d\n", clients[i].imie, clients[i].nazwisko, clients[i].postcode, clients[i].wiek);
  }

  return 0;
}
