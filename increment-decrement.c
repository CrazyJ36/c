/* x++ increments the value of variable x AFTER processing the current statement.

   ++x increments the value of variable x BEFORE processing the current statement.

   Using either is A choice dependent on what logic you need to accomplish.

*/

#include <stdio.h>

int main() {
  // increment int
  int x = 3;
  x++;
  printf("int x = 3;\nx++;\nx is now: %d\n", x);
  // decrement int
  int nx = 4;
  nx--;
  printf("int ex = 4;\nex--;\nex is now: %d\n", nx);
  printf("\n");

  int y = 4;
  int z;
  z = ++y;
  printf("y is 4\nz is y++.\nz is now: %d\n", z);
  return(0);
}
