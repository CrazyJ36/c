#include <stdio.h>
int main() {
  printf("printing at columns:\n");

  printf("1\n");

  /* %2d specifies width of area to print to,
     as right-justified, and to allow 2 spacess
     that may need to be filled. */
  printf("%2d\n", 2);

  return 0;
}
