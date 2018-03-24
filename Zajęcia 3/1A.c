#include <stdio.h>
#include <stdlib.h>
#define N 7

int main(){

    int n;
    printf("Podaj liczbe : ");
    scanf("%d", &n);

    int *tab1 = malloc((n+2)*sizeof(int));
    int *tab2 = malloc((n+2)*sizeof(int));
    int x;

    for(int i = 0; i<n+2; i++){
        tab1[i] = 0;
        tab2[i] = 0;
    }

    tab1[1]=1;
    for(int j = 0; j<=n; j++){
        for(int i = 0; i<n+1; i++){
        tab2[i+1]=tab1[i]+tab1[i+1];
        }
        for(int k = n-j+1; k>0; k--){
            printf(" ");
        }
        x=1;
        while(tab1[x]!=0){
            printf("%d ", tab1[x]);
            x++;
        }
        printf("\n");
        for(int k = 0; k<n+2; k++){
            tab1[k]=tab2[k];
            //printf("tab1: %d tab2: %d\n", tab1[k], tab2[k]);
        }
    }

    free(tab1);
    free(tab2);
    return 0;
}
