#include <stdio.h>

int main () {
  int var;
  int plus = 0;
  while (scanf("%d", &var) != EOF) {
  plus++;
  }
  printf("%d\n",plus);
  return 0;
}