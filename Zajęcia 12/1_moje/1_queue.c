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
  if (!newElement)
  {
    printf("Brak pamieci!!!\n");
    exit(1);
  }
  newElement->value = val;
  newElement->next = head;
  return newElement;
}

struct tnode *enqueue(struct tnode *head, int val)
{
  struct tnode *wsk = head;
  if (!head)
  {
    return dodaj_na_poczatek(head, val);
  }

  while (wsk->next)
  {
    wsk = wsk->next;
  };
  struct tnode *newElement = malloc(sizeof(struct tnode *));
  if (!newElement)
  {
    printf("Brak pamieci!!!\n");
    exit(1);
  }
  newElement->value = val;
  newElement->next = NULL;

  wsk->next = newElement;
  return head;
}

struct tnode dequeue(struct tnode **pointerToHead)
{
  struct tnode *wsk = *pointerToHead;
  struct tnode poped = *wsk;

  *pointerToHead = wsk->next;
  free(wsk);

  return poped;
}

void printList(struct tnode *head)
{
  struct tnode *wsk = head;

  while (wsk)
  {
    printf("%p -> %d\n", wsk, wsk->value);
    wsk = wsk->next;
  }
}

int main(int argc, char const *argv[])
{
  struct tnode *head = NULL;
  struct tnode elem;

  head = enqueue(head, 5);
  head = enqueue(head, 6);
  head = enqueue(head, 10);

  printList(head);

  elem = dequeue(&head);
  printf("Wyciagniety element z kolejki:\n");
  printf("Val: %d\n", elem.value);

  printList(head);

  return 0;
}
