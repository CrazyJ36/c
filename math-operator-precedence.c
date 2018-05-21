#include <stdio.h>

int main() {
  /* Operator precedence has to do with which operators come first in an equation expression.
     + and - are equal in precedence, as are *,/,%. equal-precedence operators are read form left-to-right.
     If combinations of non-equal precedence operators need to evaluated as they are, without confusion
     use perenthesis, making it read from right-to-left instead of left-to-right (seemingly).
  */
  int a = 2;
  int b = 3;
  int c = 4;

  // equal
  printf("Normal 2+3+4: %d\n", a+b+c);

  // An order of evaluating. Simply gets evaluated from left to right.
  int result = 2 + 3 * 4;
  printf("Evaluated right-to-left, as 3*4, then + 2:    2+3*4: %d\n", result);

  // C
  int result1 = ( 2 + 3 ) * 4;
  printf("Evaluated left-to-right, as 2+3, then * 4:    (2+3)*4: %d\n", result1);

  return(0);
}
