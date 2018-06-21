/* The point of pointers:
   You can have pointers and values.
   you turn a pointer into a value with *
   you turn a value in to a pointer with &
*/

#include <stdio.h>

int main() {

  int *an_address; // (* point to) A pointer to the memory address of new int variable (no assinged value)
  printf("%x\n", &an_address);  // prints the hexadecimal(%x) memory address of variable
}
