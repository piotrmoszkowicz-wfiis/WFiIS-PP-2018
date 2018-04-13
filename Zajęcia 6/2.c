/* ptrfn.c */
/* Tablica wskaznikow do funkcji */
#include <stdio.h>
#include <math.h>

double ff(double x){
	return 1+x*x;
}

double xx(double x){
	return pow(x,-2);
}

int main(void){
	double (*p[])(double) = {sin,cos,ff,xx,NULL};
	double (**q)(double) = p;
	int i;
	for(i=2;i<=20;i+=2){
		printf("i = %d\n", i);
		while(*q){
			printf("%.4f\n", (*(*q++))((double)i));
		}
		q=p;
		printf("-------\n");
	}
	return 0;
}
