/* do-while-loop is basically another way to do while-loops, but as opposed to while-loops,
   the statements in the do {} block will execute at least once. Then the expression in
   the while() perentheses will determine if the loop should be repeated.

   syntax:
   do {
     statements;
   while (expression);
   }

*/

#include <stdio.h>

int main() {
  int count = 1;

  do {
    printf("%d\n", count);
    count++;
  } while (count < 6);

  return(0);
}
