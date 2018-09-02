/*
This program checks the first argument string (command line argument) for null(empty) characters.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{

  if (argv[1] == NULL) // Checking only argv[1] index for null. NULL is term used for null.
  {
    printf("result was: null. No arguments\n");
  }
  else
  {
    printf("%s was 1st argument.\n", argv[1]);
  }

  return(0);
}
