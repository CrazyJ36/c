/* The #define preprocessor directive. Is A way to define A constant(like 'const').
   The #define directive uses macros(fill-in variables) for defining constant(always the same) values.
   Do not put A semicolon after #define or any preprocessor directive statement.
   The value from define is assigned just before final code compilation.

   'const' uses memory (read-only memory) and '#define' does not (just byte text storage).
*/

#include <stdio.h>
#include <stdlib.h>

// define example
#define x 2  // define A variable to the whole program, and to other programs
	     // if this file is used as a header or is linked.

// ifndef example (think of the next 3 code lines as if they were a code block)
#ifndef x  /* if x is not already defined(in this case it is at the last line of code), define 'x' at the next line..
            * if x is already defined to the system, then x remains what it was.
            */
#define x 4  /* try to define x if not already defined, this is useful for working with other peoples code. */
#endif  /* end the #ifndefine (if not defined). */

int main() {
  printf("%d \n", x); /* using the first defined 'x' variable */
  exit(0);
  return(0);
}
