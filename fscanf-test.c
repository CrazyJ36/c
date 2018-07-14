/* fscanf reads formatted output from stream.
   returns the number of characters that was read and stored.

   Syntax: int fscanf(FILE *stream, const char *format, ...)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Type some stuff:\n");

  char charVar[10];
  fscanf(stdin, "%s", charVar);

  printf("You typed: %s\n", charVar);

  exit(0);
}
