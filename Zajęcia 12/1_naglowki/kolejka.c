#include "kolejka.h"
void dodaj_na_poczatek(node **head, int val)
{
  node *newElement = malloc(sizeof(node *));
  if (!newElement)
  {
    printf("Brak pamieci!!!\n");
    exit(1);
  }
  newElement->value = val;
  newElement->next = *head;

  *head = newElement;
}

void enqueue(node **head, int val)
{
  struct tnode *wsk = *head;
  printf("Dodaje do kolejki element: %d\n", val);
  if (!(*head))
  {
    return dodaj_na_poczatek(head, val);
  }

  while (wsk->next)
  {
    wsk = wsk->next;
  };
  node *newElement = malloc(sizeof(node *));
  if (!newElement)
  {
    printf("Brak pamieci!!!\n");
    exit(1);
  }
  
  newElement->value = val;
  newElement->next = NULL;

  wsk->next = newElement;
}

node dequeue(struct tnode **pointerToHead)
{
  struct tnode *wsk = *pointerToHead;
  struct tnode poped = *wsk;

  *pointerToHead = wsk->next;
  free(wsk);

  return poped;
}

void show_queue(struct tnode *head)
{
  struct tnode *wsk = head;

  printf("\nLista od poczatku -> {");
  while (wsk)
  {
    printf("%d, ", wsk->value);
    wsk = wsk->next;
  }
  printf("}\n");
}

void clear_queue(node **head)
{
  struct tnode *wsk = *head;
  while (wsk)
  {
    node *temp = wsk->next;
    free(wsk);
    wsk = temp;
  }
}

node *find_in_queue(node *head, int val)
{
  while (head->next && head->value != val)
  {
    head = head->next;
  }

  if (head != NULL && head->value == val)
  {
    printf("Znalazlem %d (%d) pod adresem: %p", val, head->value, head);
    return head;
  }
  else
  {
    printf("Nie znaleziono wartosci\n");
    return NULL;
  }
}
