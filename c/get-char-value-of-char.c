#include <stdio.h>

int main() {

  char c; // setting as char returns char value on getchar().
  printf("Press any key then press enter...\n");
  for(int i = 0; i < 10; ++i) { // double limit, enter will count.
    c = getchar();

    // if c is not the decimal of line feed(which is 10),
    // because we have to reserve this for pressing enter to
    // send entered text.
    if (c != '\n') {
      printf("ASCII char value of that key is: %c\n", c);
    }

  }
  printf("Tested 5 keys. Exiting...\n");
}
