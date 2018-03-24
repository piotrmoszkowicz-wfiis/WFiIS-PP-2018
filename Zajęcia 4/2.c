#include <stdio.h>

int main(int argc, char const *argv[]) {
  int t[4][2] = {{0}};
  int a = 2, i, j;
  int (*wsk_2D)[2] = t;

  for(i=0;i<4;i++){
    for(j=0;j<2;j++){
      t[i][j] = a;
      a+=2;
      printf("t[%d][%d] = %d, adr: %p\n", i, j, t[i][j], &t[i][j]);
    }
  }

  printf("\n\n");

  printf("t[0] = %p\n", t[0]);
  printf("t[0]+1 = %p\n", t[0]+1);

  printf("\n\n");

  printf("t = %p\n", t);
  printf("t+1 = %p\n", t+1);

  printf("\n\n");

  printf("*t = %p\n", *t);
  printf("*t+1 = %p\n", *t+1);
  printf("*(t+1) = %p\n", *(t+1));

  printf("\n\n");

  for(i=0;i<4;i++){
    for(j=0;j<2;j++){
      printf("t[%d][%d] = %d, adr: %p \n", i, j, *(t[i]+j), t[i]+j);
    }
  }

  printf("\n\n");

  for(i=0;i<4;i++){
    for(j=0;j<2;j++){
      printf("t[%d][%d] = %d, adr: %p \n", i, j, *(*(t+i)+j), *(t+i)+j);
    }
  }

  printf("\n\nwsk:\n");

  for(i=0;i<4;i++){
    for(j=0;j<2;j++){
      printf("%d\n", *(*(wsk_2D+i)+j));
    }
  }



  return 0;
}
