#include <stdio.h>
#include <stdlib.h>

struct tnode{
  int value;
  struct tnode* next;
};

struct tnode* dodaj_na_poczatek(struct tnode* head, int val){
  struct tnode* newElement = malloc(sizeof(struct tnode*));
  newElement->value = val;
  newElement->next = head;
  return newElement;
}

struct tnode * dodaj_na_koniec(struct tnode *head, int val)
{
  struct tnode *wsk = head;
  if(!head){
    return dodaj_na_poczatek(head, val);
  }

  while (wsk->next){
    wsk = wsk->next;
  };
  struct tnode *newElement = malloc(sizeof(struct tnode *));
  newElement->value = val;
  newElement->next = NULL;

  wsk->next = newElement;
  return head;
}

struct tnode* dodaj_do_posortowanej(struct tnode *head, int val){
  if(!head || head->value > val){
    return dodaj_na_poczatek(head, val);
  }

  struct tnode *wsk = head;
  struct tnode *nextWsk = head->next;

  while (wsk->next && wsk->value < val)
  {
    wsk = wsk->next;
    nextWsk = wsk->next;
  }

  struct tnode *newElement = malloc(sizeof(struct tnode *));
  newElement->value = val;
  newElement->next = nextWsk;

  wsk->next = newElement;

  return head;
}

void printList(struct tnode* head){
  struct tnode* wsk = head;

  while (wsk)
  {
    printf("%d\n", wsk->value);
    wsk = wsk->next;
  }
}

void clearList(struct tnode* head){
  struct tnode* wsk = head;
  while(wsk){
    struct tnode* temp = wsk -> next;
    free(wsk);
    wsk = temp;
  }
}

void findInList(struct tnode *head, int val)
{
  while (head->next && head->value != val)
  {
    head = head->next;
  }

  if (head != NULL && head->value == val)
  {
    printf("Znalazlem %d (%d) pod adresem: %p", val, head->value, head);
  }
  else
  {
    printf("Nie znaleziono wartosci\n");
  }
}

struct tnode *deleteFromList(struct tnode *head, int val)
{
  struct tnode *prevWsk = NULL;
  struct tnode *wsk = head;
  struct tnode *nextWsk = head->next;
  while (wsk->next && wsk->value != val)
  {
    prevWsk = head;
    wsk = wsk->next;
    nextWsk = wsk->next;
  }

  if (wsk != NULL)
  {
    if(wsk == head){
      free(wsk);
      return nextWsk;
    }
    prevWsk->next = nextWsk;
    free(wsk);
  }
  else {
    printf("Nie znaleziono wartosci\n");
  }
  return head;
}

int main(int argc, char const *argv[])
{
  struct tnode *headPoczatek = NULL;
  struct tnode *headKoniec = NULL;
  struct tnode *headSort = NULL;

  headPoczatek = dodaj_na_poczatek(headPoczatek, 23);
  headPoczatek = dodaj_na_poczatek(headPoczatek, 13);
  headPoczatek = dodaj_na_poczatek(headPoczatek, 67);
  headPoczatek = dodaj_na_poczatek(headPoczatek, 3);
  headPoczatek = dodaj_na_poczatek(headPoczatek, 123);

  headKoniec = dodaj_na_koniec(headKoniec, 23);
  headKoniec = dodaj_na_koniec(headKoniec, 13);
  headKoniec = dodaj_na_koniec(headKoniec, 67);
  headKoniec = dodaj_na_koniec(headKoniec, 3);
  headKoniec = dodaj_na_koniec(headKoniec, 123);

  headSort = dodaj_do_posortowanej(headSort, 23);
  headSort = dodaj_do_posortowanej(headSort, 13);
  headSort = dodaj_do_posortowanej(headSort, 67);
  headSort = dodaj_do_posortowanej(headSort, 3);
  headSort = dodaj_do_posortowanej(headSort, 123);

  printf("\nLista dodawanie poczatek: \n");
  printList(headPoczatek);
  clearList(headPoczatek);

  printf("\nLista dodawanie koniec: \n");
  printList(headKoniec);
  printf("\nSzukam w liscie 3: \n");
  findInList(headKoniec, 3);
  printf("\nSzukam w liscie 666: \n");
  findInList(headKoniec, 666);
  clearList(headKoniec);

  printf("\nLista dodawanie sort: \n");
  printList(headSort);
  printf("\nUsuwam z listy 3: \n");
  headSort = deleteFromList(headSort, 3);
  printf("\nLista dodawanie sort po usunieciu: \n");
  printList(headSort);
  clearList(headSort);

  return 0;
}
