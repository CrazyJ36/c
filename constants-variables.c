/* A constant stores A value that cannot be changed from its initial assisgnment.
   constants must include A value when declared.
   common practice is to use UPPER case names for constants.
   one way to use A constant is the 'const' keyword
   another is the '#define name value' preprocessor directive.
   The difference is that const uses memory, and #define does not.
*/

#include <stdio.h>
#include <stdlib.h>

int global_variable = 0; // variable available to entire file from here.

int main() {
  const int x = 4; //declaring int number as constant variable
  printf("%d \n",x);
  //x = 5; // trying to reassign the value causes read-only error
  exit(0);
}
