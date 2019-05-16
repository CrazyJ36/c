#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep(seconds) in linux

int main() {
  char chars[6] = {'h','e','l','l','o'};
  int x = 0;
  while (x < 5) {
    printf("%c", chars[x]);
    fflush(stdout);
    sleep(1);
    x++;
  }
  printf("\n");
  exit(0);
}
