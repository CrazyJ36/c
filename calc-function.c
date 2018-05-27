#include <stdio.h>
#include <stdlib.h>

int add_calc();

int main() {
  add_calc(2,4);
  exit(0);
}
int add_calc(int a, int b) {
  printf("%d\n", a + b);
}
