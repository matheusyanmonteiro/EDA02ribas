#include <stdio.h>
#include <stdlib.h>

//macros
#define less( A, B) ( (A) < (B) )
#define lesseq( A, B ) ( (A) <= (B) )
#define exch( A, B ) { int t; t=A;A=B;B=t; }
#define cmpexch( A, B ) { if ( less( B, A ) ) exch( A, B ); }

//function
void merge( int *V, int l, int m, int r) {
  int *R = malloc( sizeof( int ) * ( r - l + 1 ) );
  int i = l, j = m + 1, k = 0;

  while( i <= m && j <= r ) {
    if ( lesseq ( V[i] , V[j] ) )
      R[k++] = V[i++];
    else
      R[k++] = V[j++];
  }

  while( i <= m )
    R[k++] = V[i++];
  while( j <= r )
    R[k++]= V[j++];
  
  k=0;

  for(i=l; i <= r; i++)
    V[i] = R[k++];
  
  free(R);
}

void mergesort(int *V, int l, int r) {
  if( l >= r)
    return;
  int half = (l + r) / 2;
  mergesort(V, l, half);
  mergesort(V, half+1, r);
  merge(V, l, half, r);
}

int binary_search(int *v,int n, int x){
    int e,d,m;
    e=-1;
    d=n;
    while(e<d-1){
        m=(e+d)/2;
        if (v[m]==x) return m;
        if(v[m]<x)e=m;
        else d=m;
    }
    return d;
}
int main() {
    int total_number; 
    int var = 0;
    int vector_prohibited[140000];
    int element;

    scanf( "%d", &total_number );
    
    for( int i = 0; i < total_number; i++ ) {
      scanf("%d", &vector_prohibited[i]);
    }
    mergesort(vector_prohibited, 0, total_number - 1);

    //printf("%d teeste\n", binary_search(vector_prohibited, total_number, 5 ));

    while( scanf("%d", &element) != EOF ) {
      var = binary_search(vector_prohibited, total_number, element);
      if(vector_prohibited[var] != element){
        printf("nao\n");
      }else{
        printf("sim\n");
      }
      var = 0;
    }
  return 0;
}