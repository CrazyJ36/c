/* The Switch statement does program control by matching the result
   of an expression with a constant 'case' value.
   The switch statement often provides A more elegant solution
   to nested if statements.

*/

#include <stdio.h>

int main() {
  int num = 2;
  
  switch (num) {
    case 1:
      printf("num is 1");
      break;
    case 2:
      printf("num is 2");
      break;
    case 3:
      printf("num is 3");
      break;
    default:
      printf("num is other");
  }  
}
