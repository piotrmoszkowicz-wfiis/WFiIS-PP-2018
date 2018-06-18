#include <stdio.h>
#include <stdlib.h>

struct tnode
{
  int value;
  struct tnode *next;
};

struct tnode *dodaj_na_poczatek(struct tnode *head, int val)
{
  struct tnode *newElement = malloc(sizeof(struct tnode *));
  newElement->value = val;
  newElement->next = head;
  return newElement;
}

struct tnode *cyklDeleteMinus(struct tnode *head)
{
  struct tnode *curElement = head;
  struct tnode *nextElement = head->next;
  struct tnode *lastElement;

  while (nextElement != NULL)
  {
    if (nextElement->value < 0)
    {
      curElement->next = nextElement->next;
      free(nextElement);
    }
    curElement = curElement->next;
    nextElement = curElement->next;
  }

  lastElement = curElement;
  printf("lev: %d\n", lastElement->value);

  if (head->value < 0)
  {
    curElement = head->next;
    free(head);
    head = curElement;
  }

  lastElement->next = head;

  return head;
}

void printList(struct tnode *head)
{
  struct tnode *wsk = head;

  while (wsk)
  {
    printf("%d\n", wsk->value);
    wsk = wsk->next;
  }
}

int main(int argc, char const *argv[])
{
  struct tnode *headPoczatek = NULL;

  headPoczatek = dodaj_na_poczatek(headPoczatek, 23);
  headPoczatek = dodaj_na_poczatek(headPoczatek, 13);
  headPoczatek = dodaj_na_poczatek(headPoczatek, -8);
  headPoczatek = dodaj_na_poczatek(headPoczatek, 3);
  headPoczatek = dodaj_na_poczatek(headPoczatek, -5);

  printf("\nLista dodawanie poczatek: \n");
  printList(headPoczatek);

  headPoczatek = cyklDeleteMinus(headPoczatek);

  printf("\nLista dodawanie poczatek: \n");
  printList(headPoczatek);

  return 0;
}
