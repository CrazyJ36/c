#include <stdio.h>
#include <unistd.h>

int main() {

  printf("This is some text");
  fflush(stdout);

  usleep(500000);

  printf("\r\033[K");
  fflush(stdout);

  printf("This is new text.");
  fflush(stdout);

  usleep(500000);

  printf("\n");

}
