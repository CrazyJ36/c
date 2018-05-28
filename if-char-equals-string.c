/* In C, single quotes('') delimit a char,
   double quotes("") are for strings only.
*/

#include <stdio.h>

int main() {
  printf("type 'y' for yes, any other character for no:\n");

  char x = getchar();
  if (x == 'y') {
    printf("yes\n");
  } else {
      printf("no\n");
  }

  return(0);
}
