/*
* aluna: Giovanna Borges Bottino
* matricula: 170011267
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, i, numero, numerobase = 11, instacia=1;
    char name[21], namebase[21];
    while(scanf(" %d", &n) != EOF){
        for (i = 0; i < n; i++){
            scanf("%s %d", name, &numero);
            if (numero < numerobase){
                strncpy(namebase, name, 21);
                numerobase = numero;
            }
            if (numero == numerobase && strcmp(name, namebase) > 0 ){
                strncpy(namebase, name, 21);
            }
        }

        printf("Instancia %d\n", instacia);
        printf("%s\n", namebase);
        printf("\n");
        numerobase = 11;
        strncpy(namebase, " ", 21);
        instacia++;
    }
    return 0;
}
