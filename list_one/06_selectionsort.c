#include <stdio.h>
#include <stdlib.h>

//macros by brunoribas ordenamacros.h
#define less( A, B) ( (A) < (B) )
#define lesseq( A, B ) ( (A) <= (B) )
#define exch( A, B ) { int t; t=A;A=B;B=t; }
#define cmpexch( A, B ) { if ( less( B, A ) ) exch( A, B ); }

//functions
void selectionsort( int *pointer, int l, int r ) {
    for( int i = l; i < r; i++ ) {
        int min = i;
        for( int j = i+1; j < r; j++ )
          if( less( pointer[j], pointer[min] ) )
            min = j;
        exch( pointer[i], pointer[min] )
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

    selectionsort( vector, left, right );

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