#ifndef _TREE_H_
#define _TREE_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
  int value;
  struct tnode* left;
  struct tnode* right;
  struct tnode* parent;
} tnode;

tnode *CreateLeaf(int wartosc, tnode *parent);
void AddLeaf(int wartosc, tnode **treeRoot, tnode *current);
void showInOrder(tnode *element);
void show(tnode *element);

#endif