#include <stdio.h>

int main() {
  printf("Operator precedence has to do with deciding which values\n");
  printf("come first in an equation expression with operators.\n");
  printf("+ and - are equal in precedence, as are *,/,%%\n");
  printf("Equal-precedence operators are read form left-to-right.\n");
  printf("If combinations of non-equal precedence operators\n");
  printf("need to evaluated as they are, without confusion\n");
  printf("use perenthesis, making it read from right-to-left\n");
  printf("instead of left-to-right (seemingly).\n");
  printf("If evaluating comes out imprpper due to ordering further,\n");
  printf("you can break the equation into seperate statements.\n");
  printf("Precedence can occur in if statements and other functions as well.\n\n");

  int a = 2, b = 3, c = 4;
  printf("simple math, plus' using equal precedence:\n");
  printf("Normal 2+3+4: %d\n\n", a + b + c);

  printf("evaluated based on operators default precedence:\n");
  int result = 2 + 3 * 4;
  printf("3*4, then + 2:    2+3*4: %d\n\n", result);

  int result1 = ( 2 + 3 ) * 4;
  printf("Evaluated in perentheses first:\n");
  printf("2+3, then * 4:    (2+3)*4: %d\n", result1);

  return(0);
}
