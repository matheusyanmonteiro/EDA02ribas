#include <stdio.h>

#define less( A, B) ( (A) < (B) )
#define lesseq( A, B ) ( (A) <= (B) )
#define exch( A, B ) { int t; t=A;A=B;B=t; }
#define cmpexch( A, B ) { if ( less( B, A ) ) exch( A, B ); }

void insertionsort( int *pointer, int l, int r ) {
    for( int i = r; i > l; i--)
      cmpexch( pointer[i-1], pointer[i]);
    
    for( int i = l + 2; i <= r; i++) {
      int j = i;
      int temp = pointer[j];
      while( less( temp, pointer[j-1]) ) {
        pointer[j] = pointer[j-1];
        j--;
      }
      pointer[j] = temp;
    }
}

int main () {
  int vector[10000];
  int elements;
  int cont = 0;
  int n;
  scanf("%d", &n);
  
  
  for(int i = 0; i < n; i++) {
    scanf("%d", &elements);
    vector[i] = elements;
  }

  if(n == 1){
    cont = 1;
    printf("%d", cont);
  } else {
  insertionsort(vector, 0, n-1);
  
  for(int i = 0; i < n; i ++) {
     if(vector[i] == vector[i+1])
      cont++;

  }

  printf("%d\n",n-cont);
  }
  return 0;
}