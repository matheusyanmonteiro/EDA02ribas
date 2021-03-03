#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student {
  int activities;
  char name[21];
} Student;


void insertionsortActivities( Student *pointer, int l, int r ) {
    int i, j;
    Student aux;
    for( i = l+1; i<= r; i++){
      aux = pointer[i];
      for( j = i; (j > 0) && (aux.activities < pointer[j-1].activities); j--)
        pointer[j] = pointer[j-1];
      pointer[j] = aux;
    }
}

void insertionsortNames( Student *pointer, int l, int r ) {
    int i, j;
    Student aux;
    for( i = l+1; i<= r; i++){
      aux = pointer[i];
      for( j = i; (j > 0) && (strcmp(aux.name, pointer[j-1].name) > 0); j--)
        pointer[j] = pointer[j-1];
      pointer[j] = aux;
    }
}

int main() {
  Student vector[100];
  int number_Std;
  int inst = 1;
  int aux = 0;
  
  while (scanf("%d", &number_Std) != EOF) {
    for( int i = 0; i < number_Std; i++){
      scanf("%s", vector[i].name);
      scanf("%d", &vector[i].activities);
    }

    insertionsortNames(vector, 0, number_Std - 1);
    insertionsortActivities(vector, 0, number_Std - 1);
    printf("Instancia %d\n", inst);
    printf("%s\n", vector[0].name);
    printf("\n");

    inst++;
  }


  return 0;
}