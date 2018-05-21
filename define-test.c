/* The #define preprocessor directive. Is A way to define A constant(like 'const').
   The #define directive uses macros for defining constant values.
   Do not put A semicolon after #define or any perprocessor directive.
   The value from define is assigned just before final code compilation.

   'const' uses memory (read-only memory) and '#define' does not (it is text).
*/

#include <stdio.h>
#include <stdlib.h>

#define x 2

int main() {
  printf("%d \n", x);
  exit(0);
  return(0);
}
