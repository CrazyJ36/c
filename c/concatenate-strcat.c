#include <stdio.h>
#include <string.h>

int main() {

  // can't use char format 'x' here, it would seem to show
  // as int to strcat.
  char source[2] = "x";
  char target[2] = "y";

  // x and y are now one string.
  //Like (+) in java, or 'x = x,y.' in python.
  strcat(target, source );

  printf("%s\n", target);
}
