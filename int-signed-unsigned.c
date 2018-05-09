#include <stdio.h>

/* A Signed integer can represent negative numbers, unsigned can not.
   Unsigned numbers(int) are simply numbers that have no sign (+,-) with them,
   always positive.
   Unsigned int a = 5 // no positive or negative symbol.
   signed int b = -5 // negative symbol
   Signed integers have undefined behaviour if they orverflow, while unsigned
   integers wrap around using A modulo (A modulus formula).

   Defining A variable as signed or unsigned is not needed.
   No errors would occur if keywords 'signed' or 'unsigned' were not in the variable declaration.
   As always there is more bit-level info that can go into this for memory.
*/

int main(void) {
  signed int a = -5;
  unsigned int b = 5;
  printf("%d\n", a);
  printf("%d\n", b);
  return(0);
}
