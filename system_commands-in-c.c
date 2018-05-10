/* Using system commands in linux is easy using '#include <stdlib.h>'.
   In PC linux, use 'man system' for some detailed info. 'man man'
   is also very informative.
   Usage:
   int varName = system("command");
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Running 'ls -a' as in bash prompt:\n\n");
  system("ls .");
}
