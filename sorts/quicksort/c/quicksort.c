#include <stdio.h>

#define less(A,B) ((A) < (B))
#define exch(A,B) { int t=A;A=B;B=t; }

int partition(int *v, int l, int r){
    int c = v[r];
    int j = l;
    for (int k=l; k<r; k++){
        if (less(v[k], c)){
            exch(v[k], v[j]);
            j++;
        }
    }

    exch(v[j], v[r]);
    return j;
}

void quicksort(int *v, int l, int r){
    if (r <= l) return;
    int j = partition(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}