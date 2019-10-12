#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // for system or exit()

int main() {
  system("setterm -cursor off");
  char dot = '.';
  char space = ' ';

  for (int z = 0; z < 3; z++) {

    for (int x = 0; x < 4; x++) {
      if (x == 0) {
        printf("%c%c", dot, space);
      } else {
        fflush(stdout);
        printf("\b\b%c%c", dot, space);
        usleep(300000);
        fflush(stdout);
        printf("\b\b%c%c", space, dot);
      }
    }

  }
  printf("\n");
  system("setterm -cursor on");
  exit(0);
}
