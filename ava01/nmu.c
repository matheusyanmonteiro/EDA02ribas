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
  int *vector, *vector_aux;
  int aux = 1;
  int cleyton;
  int n; 
  int elements; 
  int sum = 0;

  scanf("%d", &n);

  vector = malloc(sizeof(int)*n);
  vector_aux = malloc(sizeof(int)*n*2);

  

  for (int i = 0; i < n; i++) {
    scanf("%d", &elements);
    vector[i] = elements;
  }
  
  mergesort(vector, 0, n - 1);
  /*
  puts("print merge");
  for (int i = 0; i < n; i++) {
    printf("%d ", vector[i]);
  }
  printf("\n");
  */
  vector_aux[0] = vector[0];
  for( int i = 1; i < n; i++) {
    if(vector[i] != vector[i-1]){
      vector_aux[aux] = vector[i];
      aux++;
    }
  }
  /* 
  puts("vetor auxiliar");
 for (int i = 0; i < aux; i++) {
    printf("%d ", vector_aux[i]);
  }
  printf("\n");
   */
  if(aux % 2 != 0 ) {
    vector_aux[aux] = 1000000000;
    aux ++;
  }

   /*
   puts("vetor auxiliar + 1000");
 for (int i = 0; i < aux; i++) {
    printf("%d ", vector_aux[i]);
  }
  printf("\n");
   */
  cleyton = aux;
  for(int i = 0; i < aux; i+=2) {
    sum = vector_aux[i] + vector_aux[i+1];
    if(vector_aux[binary_search(vector_aux, aux-1, sum)] != sum){
      vector_aux[cleyton] = sum;
      cleyton++;
    }
  }

  mergesort(vector_aux, 0, cleyton - 1);
  /*
  puts("print de pois do merge aux ");
  for (int i = 0; i < aux; i++) {
    printf("%d ", vector_aux[i]);
  }
  printf("\n");
  */
  for (int i = 0; i < cleyton; i+=4) {
    printf("%d\n", vector_aux[i]);
  }
  printf("Elementos: %d\n",cleyton);
  /*
  puts("vect aqui");
  for (int i = 0; i < n; i++) {
    printf("%d ", vector[i]);
  }
  printf("\n");

  for (int i = 0; i < aux; i++) {
    printf("%d ", vector_aux[i]);
  }
  printf("\n");
  */
 /*
  for (int i = 0; i < aux; i++) {
    printf("%d ", vector_aux[i]);
  }
  printf("\n");
 */
  free(vector);
  free(vector_aux);
  return 0;
}