/* The #define preprocessor directive. Is A way to define A constant(like 'const').
   The #define directive uses macros for defining constant values.
   Do not put A semicolon after #define or any perprocessor directive.
   The value from define is assigned just before final code compilation.

   'const' uses memory (read-only memory) and '#define' does not (it is text).
*/

#include <stdio.h>
#include <stdlib.h>

// define example
#define x 2  // define A variable to the whole program, and to other programs
	     // if this file is used as a header.

// ifndef example (think of the next 3 code lines as if they were a code block)
#ifndef x  // if x is not already defined(in this case it is at the last line of code), define 'x' at the next line..
#define x 4  // try to redefine x if not already defined.
#endif  // end the #ifndefine (if not defined)

int main() {
  printf("%d \n", x); // using the first defined 'x' variable
  exit(0);
  return(0);
}
