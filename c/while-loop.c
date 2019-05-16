/* The while statement is called A loop structure because it executres statements
   repeatedly while an expression remains true, looping. When the loop finds the
   expression is false after looping, the expression has evaluated to
   false and the loop ends. The while loop evaluates the expression before
   loop is entered, making it possible that the while statements never execute.
   An Infinite Loop is one that continues indefinitly due to the condition(expression)
   never evaluating to false. The may cause A runtime-error.
   Can be A single statement(with no curly braces).
   syntax:

   while(expressionToFollow) {
     statementsToDo;
   }
*/

#include <stdio.h>

int main() {
  int count = 1;
  while (count < 6) {
    printf("%d\n", count);
    count++;
  }
  return(0);
}
