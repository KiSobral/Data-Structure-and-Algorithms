#include <stdio.h>
#include <stdlib.h>

#define comp(A,B) ((A) < (B))
#define exch(A,B) { int t=A;A=B;B=t; }

void selectionSort(int *v, int l, int r){
    for (int i=l; i<r; i++){
        int min=i;
        
        for (int j=1+i; j<=r; j++)
            if (comp(v[j], v[min]))
                min=j;
        
        exch(v[i], v[min]);
    }
}

int main(){
    int i=0;
    int *v;
    
    v = malloc(1000*sizeof(int));

    while (scanf("%d", &v[i]) != EOF){
        i++;
    }
    i--;

    printf("Vetor antes da ordenação: ");
    for (int j=0; j<=i; j++) printf("%d ", v[j]);
    printf("\n");

    selectionSort(v, 0, i);

    printf("Vetor depois da ordenação: ");
    for (int j=0; j<=i; j++) printf("%d ", v[j]);
    printf("\n");

    free(v);

    return 0;
}