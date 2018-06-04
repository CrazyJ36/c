/* This shows how to return A result after some calculation */
#include <stdio.h>

int aNumber();

int main() {
  int result = aNumber();
  printf("%d\n", result);
}

// In this example, this whole statement is the same as 'int x = 2;'
int aNumber(int x) {
  return(x = 2);
}
