/* The Switch statement does program control by matching the result
   of an expression with a constant 'case' value.
   The switch statement often provides A more elegant solution
   to nested if statements.
   'break;' must be used to end the switch statement at needed parts.
   The Expression must be one that can be expressed as integral(int or char).
   There may be multiple cases before statements are executed, like
   nested if statements:
   switch (expression) {
     case 1:
     case 2:
       printf("expression equals case 1 or 2\n");
       break;
     default:
       printf("Other\n");
       break;
   }
*/

#include <stdio.h>

int main() {
  int num = 2;

  // Switch/case using the value of num, as-in 'if the case of num is..'
  switch (num) {
    case 1:
      printf("num is 1\n");
      break;
    case 2:
      printf("num is 2\n");
      break;
    case 3:
      printf("num is 3\n");
      break;
    default:
      printf("num is other\n");
  }
}
