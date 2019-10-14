#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // for system
// Seems A reliable way to clear line is with '\b' and fflush(stdout) combined.
void main() {
  system("setterm -cursor off");
  fflush(stdout);
  for (int z = 0; z < 6; z++) {
    // Some fflush() and printf("\b\b") here can be removed
    // to make some funky loading animations.
    fflush(stdout);
    printf("\b\b");
    printf(". ");
    usleep(300000);
    fflush(stdout);
    printf("\b\b");
    printf(" .");
    usleep(300000);
  }
  fflush(stdout);
  printf("\b\b");
  system("setterm -cursor on");
  exit(0);
}
