#include <stdio.h>
#include <string.h>

int main() {
  char source[2] = "x";
  char target[2] = "y";

  strcat(target, source ); // x and y are now one string. Like (+) in java, or 'x = x,y.' in python.

  printf("%s\n", target);
}
