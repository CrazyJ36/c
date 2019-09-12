#include <unistd.h>
#include <stdio.h>
#include <signal.h>

volatile sig_atomic_t stop;

void inthand(int signum) {
  stop = 1;
}

int main(int argc, char **argv) {

  signal(SIGINT, inthand);

  while (!stop) {
    pause();
  }

  printf("Safely exiting past ctrl-c, done..\n");
  return 0;
}
