#ifndef _STOS_H_
#define _STOS_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct tnode
{
  int value;
  struct tnode *next;
} node;
void insert_item_begin(node **root, int val);
void show_stack(node *root);
void clear_stack(node **root);
node *find_in_stack(node *root, int val);
node pop(node **root);
#endif
