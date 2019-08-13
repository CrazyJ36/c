#include <stdio.h>
#include <unistd.h> // _sleep(int milliseconds) in windows,
                    // for linux, use <unistd.h> sleep(int seconds)
int main() {
  printf("wait two seconds..\n");
  sleep(2);
  printf("done\n");
  return(0);
}
