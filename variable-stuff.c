/* Use global variables with caution to avoid incorrect results.
   They shouldd be initialized before using to avoid unexpected
   errors. And because they can be changed anywhere in the program,
   global variables can lead to hard-to-detect errors.

   Static variables have A local scope but are not destroyed when A
   function is exited. Therefore, A static variable retains its value for
   the life of the program and can be accessed every time the function
   is re-entered. Uses the prefix 'static'.
*/

#include <stdio.h>

int main(void) {
  // Changing variables
  int num = 2;  // initialize variable with single digit
  printf("%d \n", num);  // print num formatted as %d decimal number
  num = 3; /* we can reuse 'num' without re-typing data
  type 'int'. also re-assign num with 3 */
  printf("%x \n", num); /* print nums' new value
  newly formatted as %x hexadecimal number */
  return(0);
}
