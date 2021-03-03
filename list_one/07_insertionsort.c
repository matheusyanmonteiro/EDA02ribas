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

//Main 
int main() {
    int vector[50000];
    int right = 0;
    int left = 0 ;
    int var;

    while( scanf( "%d", &var ) != EOF ) {
        vector[right] = var;
        right++;
    }

    insertionsort( vector, left, right-1 );

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

/*INSERÇÃO
Simples! Apenas ordene os números lidos da entrada padrão utilizando o Algoritmo de Ordenação INSERÇÃO. Não tente trapacear rodando outra função pronta ou outro algoritmo de ordenação. Eu posso ver o seu código 8^)

ENTRADA
A entrada possui um único caso de teste com uma quantidade arbitrária de números, a entrada termina quando o arquivo terminar (EOF). Os números cabem em um inteiro de 32bits.

Sabemos que cada caso de teste não possui mais que 1000 elementos.

SAÍDA
Imprima os mesmos números ordenados de forma não decrescente. Os números devem ser separados por espaço e não deve sobrar espaço após o último número que deve ter uma quebra de linha.

EXEMPLO
Exemplo de Entrada
7 3 2 5 4 3
Saída para o exemplo de entrada acima
2 3 3 4 5 7 */