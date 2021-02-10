#include <stdio.h>
#include <stdlib.h>

#define comp(A,B) ((A) < (B))
#define exch(A,B) { int t=A; A=B; B=t; }
#define cmpexch(A,B) { if(comp(B,A)) exch(A,B); }

typedef int Item;

void insertionSort(Item *v, int l, int r){
    for (int i=r; i>l; i--)
        cmpexch(v[i-1], v[i]);

    for (int i=l+2; i<=r; i++){
        int j=i;
        Item tmp=v[j];

        while(comp(tmp, v[j-1])){
            v[j]=v[j-1];
            j--;
        }

        v[j] = tmp;
    }
}

void dummyInsertionSort(Item *v,int l,int r){
  for(int i=l+1;i<=r;i++)
    for(int j=i;j>l;j--)
        cmpexch(v[j-1],v[j]);
}


int main() {
    Item *v;

    v = malloc(5*sizeof(Item));

    v[0]=5; v[1]=2; v[2]=3; v[3]=1; v[4]=4;

    printf("Vetor antes da ordenação: ");
    for (int i=0; i<5; i++) printf("%d ", v[i]);
    printf("\n");

    insertionSort(v, 0, 4);
    printf("Vetor depois da ordenação: ");
    for (int i=0; i<5; i++) printf("%d ", v[i]);
    printf("\n");

    v[0]=5; v[1]=2; v[2]=3; v[3]=1; v[4]=4;

    dummyInsertionSort(v, 0, 4);
    printf("Vetor depois da ordenação lenta: ");
    for (int i=0; i<5; i++) printf("%d ", v[i]);
    printf("\n");


    free(v);
    return 0;
}