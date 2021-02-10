#include <stdio.h>
#include <stdlib.h>

//macros by brunoribas ordenamacros.h
#define less( A, B) ( (A) < (B) )
#define lesseq( A, B ) ( (A) <= (B) )
#define exch( A, B ) { int t; t=A;A=B;B=t; }
#define cmpexch( A, B ) { if ( less( B, A ) ) exch( A, B ); }

//functions
void insertionsort( int *pointer, int l, int r ) {
    for( int i = r; i > l; i--)
      cmpexch( pointer[i-i], pointer[i]);
    
    for( int i = l + 2; i < r; i++) {
      int j = i;
      int temp = pointer[j];
      while( less( temp, pointer[j-1]) ) {
        pointer[j] = pointer[j-1];
        j--;
      }
      pointer[j] = temp;
    }
}

//Main 
int main() {
    int vector[1000];
    int right = 0;
    int left = 0 ;
    int var;

    while( scanf( "%d", &var ) != EOF ) {
        vector[right] = var;
        right++;
    }

    insertionsort( vector, left, right );

    for(int i = 0; i < right; i++){
        if(i == 0)
            printf( "%d", vector[i] );
        else
            printf( " %d", vector[i]);
    }
    printf("\n");

    //free ( vector );
  return 0;
}