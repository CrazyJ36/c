/* Logical Operators && (and), || (or).
   Used to form an in-line compound boolean expression tests.
   (!)(is not) is used to reverse the state A boolean expression.
   && will be evaluated first(higher precendence).
   Certain expressions can be evaluated first by using perentheses.
   In C, any non-zero value is considered true and A 0 is false.
   The logical operator therefore converts A true value to 0 and
   false to 1.
*/

#include <stdio.h>

int main() {
  int num = 3;
  if (num > 0 && num < 5) { // If both expressions are true.
    printf("3 is greater than 0, 3 is less than 5\n");
  } else {
    printf("number is not between 0 and 5.\n");
  }
  char letter = 'c'; // seems index (letter[2]) not needed for one character, or in general.
  if (letter == 'c' || letter == 'd') { // chars need only '' not "".
    printf("letter is c or d\n");
  } else {
    printf("letter is not c or d\n");
  }
  int num2 = 1;
  if (!num2 == 2 || num2 < 2) { // !(not) operator
    printf("done\n");
  }

}
