#include <stdio.h>
#include <stdlib.h>

#define lesseq(A,B) ((A) <= (B))

void merge(int *V, int l, int m, int r) {
  int *R = malloc(sizeof(int)*(r-l+1));
  int i=l, j=m+1, k=0;

  while(i<=m && j<=r) {
    if(lesseq(V[i],V[j])) R[k++]=V[i++];
    else                  R[k++]=V[j++];
  }

  while(i<=m) R[k++]=V[i++];
  while(j<=r) R[k++]=V[j++];

  k=0;
  
  for(i=l;i<=r;i++) V[i]=R[k++];

  free(R);
}

void mergesort(int *V, int l, int r) {
  if (l >= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}