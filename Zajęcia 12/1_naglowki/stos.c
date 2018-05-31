#include "stos.h"

void insert_item_begin(node **head, int val)
{
  printf("Wstawiam element na stos element %d.\n", val);
  struct tnode *newElement = malloc(sizeof(struct tnode *));
  if (!newElement)
  {
    printf("Brak pamieci!!!\n");
    exit(1);
  }
  newElement->value = val;
  newElement->next = *head;

  *head = newElement;
}

void show_stack(node *head)
{
  node *wsk = head;

  printf("Lista od poczatku {");
  while (wsk)
  {
    printf("%d, ", wsk->value);
    wsk = wsk->next;
  }
  printf("}\n");
}

node pop(node **pointerToHead)
{
	node *wsk = *pointerToHead;
	node poped = *wsk;

	*pointerToHead = wsk->next;
	free(wsk);

	return poped;
}

void clear_stack(node **head)
{
  node *wsk = *head;
  while (wsk)
  {
    node *temp = wsk->next;
    free(wsk);
    wsk = temp;
  }
}

node *find_in_stack(node *head, int val)
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
