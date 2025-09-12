#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char bar[6] = "---";
  int i = 0;

  while(i < 5) {

    printf("\r%s%s", bar, " ");
    fflush(stdout);

    usleep(500000);

    printf("\r%s%s", " ", bar);
    fflush(stdout);

    usleep(500000);

    i++;
  }

  printf("\n");
}
