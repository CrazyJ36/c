/* the scanf("text", to-variable) places the input into a memory address location.
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

  printf("This will put what you input into the same memory address as variable: int num.\nSo there is no wasted memory\nType A number: ");
  scanf("%d", &num);
  printf("memory address of what you typed: %d\n", &num);

  exit(0);
}
