#include <stdio.h>
#include <stdlib.h>

int main() {
  char chars[6] = {'h','e','l','l','o'};
  int x = 0;
  while (x < 6) {
    printf("%c", chars[x]);
    _sleep(300);
    x++;
  }
  exit(0);
}