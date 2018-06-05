#include "drzewoBST.h"

tnode* CreateLeaf(int wartosc, tnode* parent)
{
  tnode* newLeafPointer = malloc(sizeof(tnode));
  newLeafPointer->right = newLeafPointer->left = NULL;
  newLeafPointer->parent = parent;
  newLeafPointer->value = wartosc;

  return newLeafPointer;
}

void AddLeaf(int wartosc, tnode** treeRoot, tnode* current)
{
  if(*treeRoot == NULL){
    tnode *newLeafPointer = CreateLeaf(wartosc, current);
    *treeRoot = newLeafPointer;
    return;
  }

  if(current->left == NULL){
    tnode* newLeafPointer = CreateLeaf(wartosc, current);
    current->left = newLeafPointer;
    return;
  }

  if(current->right == NULL){
    tnode *newLeafPointer = CreateLeaf(wartosc, current);
    current->right = newLeafPointer;
    return;
  }

  if(wartosc < current->value){
    AddLeaf(wartosc, treeRoot, current->left);
  }
  else {
    AddLeaf(wartosc, treeRoot, current->right);
  }
}

void showInOrder(tnode *element){
  if (element != NULL){
    showInOrder(element->left);
    printf("%d\n", element->value);
    showInOrder(element->right);
  }
}

void show(tnode *element){
  if(element != NULL){
    printf("%d\n", element->value);
    show(element->left);
    show(element->right);
  }
}