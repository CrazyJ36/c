/* fprintf writes formatted output to stream.
   also fprintf returns th number of characters written.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  char text[6] = "hello";

  fprintf(stdout, "%s\n", text);
  exit(0);
}
