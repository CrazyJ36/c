/* This prints the number of args from:
   main(int argc, ...
   simply returns that int number of argc, as argc is meant to be the return the actual number
   of arguments passed to the program(main) from the command line.
*/

#include <stdio.h>
int main(int argc, char *argv[])
{
  printf("Number of args: %d\n", argc);
  return(0);
}
