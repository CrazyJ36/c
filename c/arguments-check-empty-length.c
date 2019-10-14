/*  This uses if else to check if there are any command-line arguments given when running the program.
    by using if argc which is int number of arguments index list on the typed console.
    NOTE: The program name is always the 1 index unlike java or others as we use:
   ./program[0] argument[1].
    to run this.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc > 1) {
    printf("There was 1 or more arguments.\n");
  } else { // no other possibility for else if. Mathmatically impossible.
      printf("No arguments\n");
  }
  return(0);
}
