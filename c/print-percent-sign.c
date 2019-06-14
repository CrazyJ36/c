/* print-percent-sign.c
To format the printing of A percentage symbol,
use two percent signs - "%%", canclelling format,\
then printing the symbol.
Don't use 'normal' escape backslash '\'
in this case.
*/
#include <stdio.h>
int main() {
  printf("%%"); // or:
  // printf("%c \n", 37); // ascii percent character

  printf("\n");
  return 0;
}
