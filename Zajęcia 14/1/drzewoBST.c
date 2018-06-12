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
  else {
    if ((*treeRoot)->value > wartosc)
    {
      AddLeaf(wartosc, &(*treeRoot)->left, *treeRoot);
    }
    else
    {
      AddLeaf(wartosc, &(*treeRoot)->right, *treeRoot);
    }
  }  
}

void showInOrder(tnode *element){
  if (element != NULL){
    showInOrder(element->left);
    printf("%d (%p)\n", element->value, element);
    showInOrder(element->right);
  }
}

void showPreorder(tnode *element){
  if(element != NULL){
    printf("%d\n", element->value);
    showPreorder(element->left);
    showPreorder(element->right);
  }
}

void showPostorder(tnode *element){
  if (element != NULL)
  {
    showPostorder(element->left);
    showPostorder(element->right);
    printf("%d\n", element->value);
  }
}

void freeTree(tnode *root){
  if(root != NULL){
    freeTree(root->right);
    freeTree(root->left);
    free(root);
  }
}

tnode *FindMinIterate(tnode *root){
  while(root->left){
    root = root->left;
  }

  return root;
}

tnode *FindMaxRecursive(tnode *root){
  if(!root->right){
    return root;
  }
  return FindMaxRecursive(root->right);
}

tnode *SearchRecursive(int wartosc, tnode *parent){
  if (!parent){
    return NULL;
  }
  if (wartosc == parent->value){
    return parent;
  }
  if (wartosc > parent->value){
    return SearchRecursive(wartosc, parent->right);
  }
  else {
    return SearchRecursive(wartosc, parent->left);
  }
}

tnode *SearchIterative(int wartosc, tnode *parent){
  if (!parent){
    return NULL;
  }
  while(wartosc != parent->value){
    if (wartosc > parent->value){
      parent = parent->right;
    }
    else {
      parent = parent->left;
    }
  }
  return parent;
}

void showInOrderWithFunction(tnode *element, tnode *(*func)(tnode *x)){
  if (element != NULL) {
    showInOrderWithFunction(element->left, func);
    tnode* searchingElement = func(element);
    printf("%d -> jego szukany: %p\n", element->value, searchingElement);
    showInOrderWithFunction(element->right, func);
  }
}

tnode *Successor(tnode *x){
  if (!x){
    return NULL;
  }

  if ((x->right) != NULL){
    return FindMinIterate(x->right);
  }

  tnode* y = x->parent;

  while (y != NULL && (x == y->right)){
    x = y;
    y = y->parent;
  }

  return y;
}

tnode *Predecessor(tnode *x){
  if (!x){
    return NULL;
  }

  if ((x->left) != NULL){
    return FindMaxRecursive(x->left);
  }

  tnode* y = x->parent;

  while (y != NULL && (x == y->left))
  {
    x = y;
    y = y->parent;
  }
  return y;
}

void LeftRotate(tnode **root, tnode *x){
  tnode* y;
  y = x->right;
  x->right = y->left;

  if (y->left != NULL){
    y->left->parent = x;
  }

  y->parent = x->parent;

  if (x->parent == NULL){
    *root = y;
  }
  else if (x == x->parent->left){
    x->parent->left = y;
  }
  else {
    x->parent->right = y;
  }

  y->left = x;
  x->parent = y;
}