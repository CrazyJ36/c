#include <stdio.h>

int main() {
  int x = 3;
  int a = x += 1; // Adds 1, then re-assigns x. same as: x = x + 1;
  int b = x -= 1;
  int c = x *= 2;
  float d = x /= 2;
  int e = x %= 1;
  int f = x += 3 * 2; // same as x = x + (3 * 2);

  printf("%d %d %d %f %d %d\n", a, b, c, d, e, f);

  return(0);
}
