/* Header files can be used as A shortcut to functions
   that have already been written.
   The first line points to where I already have A
   file with a function that prints A new line.

   Once compiled, the main program(this one) doesn't need
   to know where the header file is. The newlines' function
   code gets built into this file during compilation.
*/

#include "/home/thomas/development/c/header-files/newline.h"

#include <stdio.h>
#include <stdlib.h>

void main()
{
  printf("testing my newline header file:");
  newline();  // this function is form another file.
  printf("A new line should have just been made.");
  newline();
  exit(0);
}
