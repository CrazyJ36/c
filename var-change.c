#include <stdio.h>

int main(void) {
  int num = 2;  // initialize variable with single digit
  printf("%d \n", num);  // print num formatted as %d decimal number
  num = 3; /* we can reuse 'num' without re-typing data
  type 'int'. also re-assign num with 3 */
  printf("%x \n", num); /* print nums' new value
  newly formatted as %x hexadecimal number */
  return(0);
}
