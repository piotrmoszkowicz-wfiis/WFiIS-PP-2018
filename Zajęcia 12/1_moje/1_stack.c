#include <stdio.h>
#include <stdlib.h>

struct tnode
{
  int value;
  struct tnode *next;
};

struct tnode *push(struct tnode *head, int val)
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

struct tnode pop(struct tnode **pointerToHead)
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

  head = push(head, 5);
  head = push(head, 6);
  head = push(head, 10);

  printList(head);

  elem = pop(&head);
  printf("Wyciagniety element ze stosu:\n");
  printf("Val: %d\n", elem.value);

  printList(head);

  return 0;
}
