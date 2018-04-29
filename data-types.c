#include <stdio.h>

static int nln();  //for function nln() to run without warning, it should be declared as static (constant, viewable, defined) to the file.

int main() {
  int num = 2;  // initialize variable with single digit
  printf("%d", num);  // print num formatted as %d decimal number
  nln(); // run custom new line function
  num = 3; // we can reuse 'num' without re-typing data type 'int'. also re-assign num with 3
  printf("%x", num); // print nums' new value newly formatted as %x hexadecimal number
  nln();
}

int nln() {
  printf("\n"); //reusable nln() function to auto type a new line anywhere in main
}
