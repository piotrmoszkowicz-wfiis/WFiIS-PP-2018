#include <stdio.h>
#include <stdlib.h>
#define PUSH insert_item_begin

typedef struct tnode
{
	int value;
	struct tnode *next;
} node;

node *insert_item_begin(node *, int);
void print_list(node *);
int pop(node **);

int main(int argc, char *argv[])
{
	node *top = NULL;

	printf("Wstawiam elementy na stos.\n");
	top = PUSH(top, 8);
	top = PUSH(top, 23);
	top = PUSH(top, 123);

	printf("Wypisuje zawartosc stosu.\n");
	print_list(top);

	printf("Usuwam elementy ze stosu.\n");
	int v;
	v = pop(&top);
	printf("Pop()=%d\n", v);

	printf("Wypisuje zawartosc stosu.\n");
	print_list(top);

	printf("Usuwam element ze stosu.\n");
	v = pop(&top);
	printf("Pop()=%d\n", v);

	printf("Wypisuje zawartosc stosu.\n");
	print_list(top);

	top = PUSH(top, 1223);
	top = PUSH(top, 12);
	top = PUSH(top, 787);

	printf("Wypisuje zawartosc stosu.\n");
	print_list(top);
}

node *insert_item_begin(struct tnode *head, int val)
{
	printf("Wstawiam na stos element %d.\n", val);
	node *newElement = malloc(sizeof(struct tnode *));
	if (!newElement)
	{
		printf("Brak pamieci!!!\n");
		exit(1);
	}
	newElement->value = val;
	newElement->next = head;
	return newElement;
}

int pop(node **pointerToHead)
{
	node *wsk = *pointerToHead;
	node poped = *wsk;

	*pointerToHead = wsk->next;
	free(wsk);

	return poped.value;
}

void print_list(node *head)
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
