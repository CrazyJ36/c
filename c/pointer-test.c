/* The point of pointers:
   You can have pointers and values.
   you turn a pointer into a value with *
   you turn a value in to a pointer with &

   A pointer can be used to hold arrays as opossed to variables,
   pass arrays to functions and back,
   return arrays using *function() {}.
*/

#include <stdio.h>

int main() {

  int *an_address; // (* point to) A pointer to the memory address of new int variable (no assinged value)
  printf("Hexadecimal form of address: %x\n", &an_address);  // prints the hexadecimal(%x) memory address of variable
  printf("Pointer address: %p\n", &an_address);
  return(0);
}
