#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct tnode
{
  int value;
  struct tnode *next;
} node;
void dodaj_na_poczatek(node **root, int val);
void enqueue(node **root, int val);
node dequeue(node **root);
void show_queue(node *root);
void clear_queue(node **root);
node *find_in_queue(node *root, int val);
#endif
