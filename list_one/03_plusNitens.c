#include <stdio.h>

int main() {
  int aux, var;
  int plus = 0;

  scanf("%d", &aux);
  
  for(int i = 0; i < aux; i++){
    scanf("%d", &var);
    plus += var;
  }

  printf("%d\n",plus);
  return 0;
}