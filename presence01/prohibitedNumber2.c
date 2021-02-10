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

int binary_search(int *V, int begin, int end, int item){
  int i = ( begin + end ) / 2;

  if (begin > end) 
    return -1;
  
  if (V[i] == item) 
    return i;
  
  if (V[i] < item )
    return binary_search( V, i + 1, end, item );
  
  else 
    return binary_search( V, i - 1, end, item );
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
    mergesort(vector_prohibited, 0, total_number);

     for( int i = 0; i < total_number; i++ ) {
      printf("%d ", vector_prohibited[i]);
    }
    printf("teste\n");
    /*while( scanf("%d", &element) != EOF ) {
      var = binary_search(vector_prohibited, 0, total_number, element);
      if(var == -1){
        printf("nao\n");
      }else{
        printf("sim\n");
      }
      var = 0;
    }
    */
  return 0;
}