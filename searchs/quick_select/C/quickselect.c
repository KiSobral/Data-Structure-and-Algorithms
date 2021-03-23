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

int quickselect(int *v, int l, int r, int pos){
    int j = partition(v, l, r);

    if (j > pos)      return quickselect(v, l, j-1, pos);
    else if (j < pos) return quickselect(v, j+1, r, pos);   
    else              return j;
}