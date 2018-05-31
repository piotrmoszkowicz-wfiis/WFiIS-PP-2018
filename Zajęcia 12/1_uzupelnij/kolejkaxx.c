#include <stdio.h>
#include <stdlib.h>

#define ENQUEUE insert_item_end
#define DEQUEUE pop

typedef struct _node
{
	int value;
	struct _node *next;
} node;

node *insert_item_end(node *, int);
void print_list(node *);
int pop(node **);

int main(int argc, char *argv[])
{
	node *root = NULL;
	printf("Wstawiam elementy do kolejki\n");

	root = ENQUEUE(root, 8);
	root = ENQUEUE(root, 23);
	root = ENQUEUE(root, 123);
	root = ENQUEUE(root, 423);

	printf("Wypisuje elementy kolejki");
	print_list(root);

	printf("Usuwam elementy z kolejki\n");
	int v;
	v = pop(&root);
	printf("Dequeue()=%d\n", v);
	v = pop(&root);
	printf("Dequeue()=%d\n", v);

	printf("Wypisuje elementy kolejki");
	print_list(root);

	root = ENQUEUE(root, 3);
	root = ENQUEUE(root, 45);
	v = pop(&root);
	printf("Dequeue()=%d\n", v);

	printf("Wypisuje elementy kolejki");
	print_list(root);

	return 0;
}

int pop(node **top)
{
	node *wsk = *top;
	node poped = *wsk;

	*top = wsk->next;
	free(wsk);

	return poped.value;
}

node *insert_item_end(node *head, int val)
{
	node *wsk = head;
	node *temp = (node *)malloc(sizeof(node));

	if (!temp)
	{
		printf("Brak pamieci!!!\n");
		exit(1);
	}
	printf("Dodaje do kolejki element: %d\n", val);

	temp->value = val;
	temp->next = NULL;

	if (!head)
	{
		return temp;
	}

	while (wsk->next)
	{
		wsk = wsk->next;
	};

	wsk->next = temp;

	return head;
}

void print_list(node *head)
{
	node *tmp = head;
	if (tmp)
	{
		printf("\nLista od poczatku -> {");
		printf("%d, ", head->value);

		while (head->next)
		{
			head = head->next;
			printf("%d, ", head->value);
		}
		printf("}\n");
	}
	else
		printf("\n");
}
