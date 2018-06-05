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

  show(*treeRoot);

  return 0;
}
