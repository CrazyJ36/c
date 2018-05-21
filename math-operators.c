#include <stdio.h>

int main() {
  // Addition
  printf("%d\n", 2+3);
  // Subtraction
  printf("%d\n", 5-2);
  // Multiplication
  printf("%d\n", 2*3);

  // Integer Division (not recommended, as integers are intended for counting; they're not'real numbers'.
  printf("%d\n", 6/3); // does integer division(or truncated division, when both operands(6,3) are integers(rounded down, removing decimal remainder).


  //  Float or Double Division
  float n1 = 5;
  float n2 = 2;
  float result = n1 / n2;
  printf("%f\n", result);
  // simpler: printf("%f", 2.6);

  // Modulus Operaator returns the remainder of integer division, to retrive digits from A number.
  printf("%f\n", 2.654);
  return(0);
}
