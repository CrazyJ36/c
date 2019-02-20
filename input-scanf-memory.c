/* the scanf("prompt", to-variable) places the input string into a memory address location.
   to access this memory location you should use (&var) with the (&) symbol which
   means point to the memory address location of the variable. This is better for memory.
   A memory address is given as A hexadecimal number(hex a base-16 number system that uses 0
   through 9 and letters A through F(16 characters) to represent A group of four binary
   digits that can have a value from 0-15.
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
  int num;
  printf("What you input will be stored in RAM, accessible by name: num\nType A number: ");
/* scanf returns the number of items SUCCESSFULLY read.
   so this if statement returns 0 if there's no items
   entered, or if reading int(num) is unsuccessful */
  if (scanf("%d", &num) == 0) { // could also be typed with precedence in mind if ( (scanf("%d", &num) ) == 0 )
    printf("E: scanf returned non 0. Non-number or no input from user\n");
  } else {
    // %p means the memory address type reference
    printf("Local memory address of what you typed(&num): %p\n", &num);
    printf("The value(num): %d\n", num);
  }
  exit(0);
}
