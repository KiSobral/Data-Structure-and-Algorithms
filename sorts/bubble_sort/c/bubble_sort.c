#include <stdio.h>

#define comp(A,B) ((A) < (B))
#define exch(A,B) { int t=A; A=B; B=t; }
#define cmpexch(A,B) { if(comp(B,A)) exch(A,B); }


void bubbleSort(int *v, int l, int r) {
    for (int i=l; i<r; i++)
        for (int j=l+1; j<=r; j++)
            cmpexch(v[j-1], v[j]);
}

void bubbleSortRec(int *v, int n) {
    if (n==1) return;

    for (int i=1; i<n; i++)
        cmpexch(v[i-1], v[i]);
    
    bubbleSortRec(v, n-1);
}

int main() {
    int v[5] = {3, 5, 1, 2, 4};

    printf("Vetor Inicial: ");
    
    for (int i=0; i<5; i++) printf("%d ", v[i]);
    printf("\n");
    printf("Vetor Ordenado: ");

    bubbleSort(v, 0, 4);

    for (int i=0; i<5; i++) printf("%d ", v[i]);
    printf("\n");

    v[0]=3; v[1]=5; v[2]=1; v[3]=2; v[4]=4;
    bubbleSortRec(v, 5);

    printf("Vetor Ordenado com Recursão: ");
    for (int i=0; i<5; i++) printf("%d ", v[i]);
    printf("\n");

    return 0;
}