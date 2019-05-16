/* The argc parameter holds the number of arguments on the command-line and is an integer.
   It will alwats be at least 1 because the name of the program qualifies as the first argument.

   The argv parameter is an array of string pointers. The most common method for declaring argv is:
   char *argv[];
   The empty brackets indicate that it is an array of undetermined length. All command-line arguments
   are passed to main() as strings. to access an individual string, index argv.
   For example, argv[0] points to the program's name and argv[1] points to the first argument.

   Simply: 'int argc' is numbered list(index) of arguments, 'char *argv[]' is string text of those arguments.
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
  printf("%s, was the command-line argument.\n", argv[1]);
  return(0);
}
