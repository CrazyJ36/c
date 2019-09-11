#include <stdio.h>
#include <string.h>

int main() {

  // here, I couldn't just use 7 as length of array for
  // text1, unlike text2, which doesn't have A space.
  // needed several like 16, or "stack smashing detected".
  char text1[16] = "hello ";
  char text2[6] = "world";

  strcat(text1, text2);

  printf("%s\n", text1);

  return 0;

}
