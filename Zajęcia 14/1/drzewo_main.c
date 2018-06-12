#include "drzewoBST.h"


int main(int argc, char const *argv[])
{
  int tab[] = {15, 5, 16, 20, 3, 12, 18, 23, 10, 13, 6, 7};
  int i;

  tnode** treeRoot;
  *treeRoot = NULL;
  
  for(i=0;i<sizeof(tab)/sizeof(tab[0]);i++){
    AddLeaf(tab[i], treeRoot, *treeRoot);
  }

  showInOrder(*treeRoot);

  printf("\n--------\n");

  showPreorder(*treeRoot);

  printf("\n--------\n");

  showPostorder(*treeRoot);

  printf("\n--------\n");

  tnode *min = FindMinIterate(*treeRoot);
  tnode *max = FindMaxRecursive(*treeRoot);
  printf("Adres min: %p, wart: %d\n", min, min->value);
  printf("Adres max: %p, wart: %d\n", max, max->value);

  printf("Adres 3 (recur): %p\n", SearchRecursive(3, *treeRoot));
  printf("Adres 3 (iter): %p\n", SearchIterative(3, *treeRoot));

  printf("\n--------\n");

  printf("Nastepniki: \n\n");
  showInOrderWithFunction(*treeRoot, Successor);

  printf("\n--------\n");

  printf("Poprzedniki: \n\n");
  showInOrderWithFunction(*treeRoot, Predecessor);

  printf("\n--------\n");

  printf("Rotacja:\n");
  LeftRotate(treeRoot, *treeRoot);
  showInOrder(*treeRoot);

  printf("\n--------\n");

  printf("Czyszcze drzewo:\n");
  freeTree(*treeRoot);

  return 0;
}
