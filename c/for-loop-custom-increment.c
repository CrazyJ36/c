#include <stdio.h>

/* In for-loops, there are more options than i++ and such */

int main() {

  int num = 0;

  // Here I use increment num by 2 on every loop.
  for (num; num < 20; num = num + 2) {
    printf("%d\n", num);
  }

  return 0;
}
