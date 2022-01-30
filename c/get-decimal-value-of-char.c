#include <stdio.h>

int main() {

  int c; // setting as int will return decimal value on getchar().
  printf("Press any key then press enter...\n");
  for(int i = 0; i < 10; ++i) { // double limit, enter will count.
    c = getchar();

    // if c is not the decimal of line feed(which is 10),
    // because we have to reserve this for pressing enter to
    // send entered text.
    if (c != 10) {
      printf("ASCII Decimal value of that key is: %d\n", c);
    }

  }
  printf("Tested 5 keys. Exiting...\n");
}
