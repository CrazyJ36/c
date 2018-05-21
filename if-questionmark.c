/* Be careful any expressinon that evaluates to A non-zero vaule is considered true.
   even if you made up a statment. This may cause confusion.
*/

#include <stdio.h>

int main() {
  /* Syntax:

     conditionalExpression ? expression1 : expression2

  */

  int x = 1;
  int y;

  //y is 2 if x is 1 else y is 1. or: if x is 1 then y is 2 else y is 1
  y = (x == 1) ? 2 : 1;
  printf("%d\n", y);
}
