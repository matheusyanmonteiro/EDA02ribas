#include <stdio.h>

int plus(int a, int b) {
  return a + b;
}

int main() {
  int x,y;
  
  scanf("%d %d", &x, &y);
  
  printf("%d \n", plus(x,y));

  return 0;
}