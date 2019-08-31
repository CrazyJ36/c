/*  ----- arg-check-null.c -----
  This program checks the first command line argument
  for A null(empty) characters as an object.

  @CrazyJ36 2019 - Open-source License.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{

  if (argv[1] == NULL) // Checking only 1st index. The null keyword
                       //  must be all caps in C.
  {
    printf("result was: null. No arguments\n");
  }
  else
  {
    printf("argv[1] not null.\n");
  }

  return(0);
}
