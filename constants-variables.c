/* A constant stores A value that cannot be changed from its initial assisgnment.
   constants must include A value when declared.
   common practice is to use UPPER case names for constants.
   one way to use A constant is the 'const' keyword
   another is the '#define name value' preprocessor directive.
   The difference is that const uses memory, and #define does not.
*/

#include <stdio.h>
#include <stdlib.h>

#define ONE_NUMBER 1 //  Preproccessed during compilation for performance. Available to entire file from here.

int TWO_NUMBER = 2; // defined before main(), initialized at runtime.

int main() {

  const int three_number = 3; // Another constant, not preproccessed, value does not change, initialized at runtime.

  printf("%d %d %d\n", ONE_NUMBER, TWO_NUMBER, three_number);

  exit(0);
}
