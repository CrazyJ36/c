#include <stdio.h>
#include <stdlib.h> // _sleep(int milliseconds) in windows,
                    // for linux, use <unistd.h> sleep(int seconds)
int main() {
  printf("wait..\n");
  _sleep(1000);
  printf("done\n");
  exit(0);
}
