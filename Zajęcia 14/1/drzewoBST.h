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
void showPreorder(tnode *element);
void showPostorder(tnode *element);
void freeTree(tnode *root);
tnode *FindMinIterate(tnode *root);
tnode *FindMaxRecursive(tnode *root);
tnode *SearchRecursive(int wartosc, tnode *parent);
tnode *SearchIterative(int wartosc, tnode *parent);
tnode *Successor(tnode *x);
tnode *Predecessor(tnode *x);
void showInOrderWithFunction(tnode *element, tnode *(*func)(tnode *x));
void LeftRotate(tnode **root, tnode *x);

#endif