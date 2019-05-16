/* This draws A box. */

#include <stdio.h>

int main()
{
  int count = 0;
  char object = '*';

  // top line, straight string of characters
  for (count; count < 5; count++) {
    printf("%c", object);
  }
  // sides must start on new line
  printf("\n");
  // sides, spaced char on newlines
  for (count = 0; count < 5; count++) { // reset count to 0
    printf("%c   %c\n", object, object);
  }
  // bottom line
  for (count = 0; count < 5; count++) { // reset count to 0
    printf("%c", object);
  }
  // start a new line to finish look
  printf("\n");
  return(0);
}
