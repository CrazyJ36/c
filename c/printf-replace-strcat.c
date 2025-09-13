// Avoiding strcat

#include <stdio.h>

int main() {

  char letter = 'a';
  char base[9] = "letter is";

  printf("%s: %c\n", base, letter);

  return 0;

}
