#include <stdio.h>

int suma (int (*tab)[2]);

int main (void) {
	int i,j;
	int tab2d[4][2]={{1,2},{3,4},{5},{6,10}};

	for(i=0;i<=3;i++) {
		for (j=0;j<=1;j++)
		printf("tab2d[%d][%d])=%d   %d    %d ",i,j,tab2d[i][j], *(tab2d[i]+j), *(*(tab2d+i)+j));
		printf ("\n");
	}
	//Poniżej poprawione:
	//printf("tab2d[%d][%d])=%d   %d    %d ",i,j,tab2d[i][j], *(tab2d[i]+j), *(*(tab2d+i)+j));

	printf ("\n tab2d[0][0]=%d  *tab2d[2]=%d  **(tab2d+2)=%d  \n",tab2d[0][0],*tab2d[2], **(tab2d+2));
	printf ("\n tab2d=%p tab2d+1=%p  \n *tab2d=%p *tab2d+1=%p *(tab2d+1)=%p \n",tab2d, tab2d+1,*tab2d, *tab2d+1, *(tab2d+1) );
	printf ("\n *(*tab2d+3)+1=%d\n *(tab2d[3]+1)=%d\n",*(*tab2d+3)+1, *(tab2d[3]+1));



	printf("\nsuma elementow tablicy: %d\n",suma (tab2d));

	return 0;
}

int suma (int (*tab)[2]) {
	int i,j,sum=0;
	for (i=0;i<=3;i++)
	 	for (j=0;j<=1;j++)
		 	sum += tab[i][j];


	return sum;
}

	/*
	tab2d <=> &tab2d[0]
	tab2d[0] <=> &tab2d[0][0]
	tab2d[0][0] = *tab2d[0] = **tab2d
	tab2d[2][0] = *tab2d[2] = **(tab2d+2)
	tab2d[3][1]= *(tab2d[3]+1)=*(*(tab2d+3)+1)



	*/
