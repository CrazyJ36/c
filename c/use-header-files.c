/* Header files can be used as A shortcut to functions
   that have already been written.
   The first line points to where I already have A
   file with a function that prints A new line.

   Once compiled, the main program(this one) doesn't need
   to know where the header file is. The newlines' function
   code gets built into this file during compilation.
*/

// include personal header files for your program: "file.h"
#include "header-files/newline.h"

// include system header files as: <file.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
  printf("testing custom newline.h header file which does:\nprintf(\"\\n\"); as newline();\n");
  newline();  // this function is from another file.
  newline();
  printf("2 newlines above\n");
  newline();newline();newline();
  printf("3 newlines above\n");
  exit(0);
}
