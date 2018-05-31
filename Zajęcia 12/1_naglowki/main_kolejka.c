#include "kolejka.h"
#define DEQUEUE pop

int main(int argc, char const *argv[])
{
  node *root = NULL;
	printf("Wstawiam elementy do kolejki\n");

	enqueue(&root, 8);
	enqueue(&root, 23);
	enqueue(&root, 123);
	enqueue(&root, 423);

	printf("Wypisuje elementy kolejki");
	show_queue(root);

	printf("Usuwam elementy z kolejki\n");
	node v;
	v = dequeue(&root);
	printf("Dequeue()=%d\n", v.value);
	v = dequeue(&root);
	printf("Dequeue()=%d\n", v.value);

	printf("Wypisuje elementy kolejki");
	show_queue(root);

	enqueue(&root, 3);
	enqueue(&root, 45);
	v = dequeue(&root);
	printf("Dequeue()=%d\n", v.value);

	printf("Wypisuje elementy kolejki");
	show_queue(root);

  clear_queue(&root);

	return 0;
}
