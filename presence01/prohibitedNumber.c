#include <stdio.h>
#include <stdlib.h>

int main() {
    int total_number; 
    int prohibited_number;
    int aux = 0;
    int vector_prohibited[140000];
    int vector_aux[140000];

    scanf( "%d", &total_number );
    
    for( int i = 0; i < total_number; i++ )
      scanf("%d", &vector_prohibited[i]);
    
    while( scanf("%d", &vector_aux[aux]) != EOF )
      aux++;

    for ( int i = 0; i < aux; i++ ) {
      int var = 0;
      for ( int j = 0; j < total_number; j++ ){
        if ( vector_aux[i] == vector_prohibited[j] )
          var++;
      } 
      if(var > 0) 
        printf("sim\n");
      else
        printf("nao\n");
    }

  return 0;
}