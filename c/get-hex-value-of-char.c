#include <stdio.h>

int main() {
  printf("Enter A character and press enter. ctrl-c to quit.\n");
  char c;

  while (1) {
    c = getchar();
    if (c != '\n') {
      // %x returns the char in hexadecimal form.
      printf("Hex value of that character is: %x\n", c);
      printf("Go again, or ctrl-c to quit\n");
    }
  }

  return 0;
}
