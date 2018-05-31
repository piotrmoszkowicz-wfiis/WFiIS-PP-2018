#include "stos.h"
#define PUSH insert_item_begin

int main(int argc, char const *argv[])
{
  node *top = NULL;

	printf("Wstawiam elementy na stos.\n");
	PUSH(&top, 8);
	PUSH(&top, 23);
	PUSH(&top, 123);

	printf("Wypisuje zawartosc stosu.\n");
	show_stack(top);

	printf("Usuwam elementy ze stosu.\n");
	node v;
	v = pop(&top);
	printf("Pop()=%d\n", v.value);

	printf("Wypisuje zawartosc stosu.\n");
	show_stack(top);

	printf("Usuwam element ze stosu.\n");
	v = pop(&top);
	printf("Pop()=%d\n", v.value);

	printf("Wypisuje zawartosc stosu.\n");
	show_stack(top);

	PUSH(&top, 1223);
	PUSH(&top, 12);
	PUSH(&top, 787);

	printf("Wypisuje zawartosc stosu.\n");
	show_stack(top);
  return 0;
}
