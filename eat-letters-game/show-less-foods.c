/* A similar thing:
   printf("%*d", count, 0); // this prints zeros by count
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  char arr[6] = {'-','-','-','-','-'};
  int count;
  char achar = '-';
  for (count = 5; count > 0; count--) {
    int pattern = arr[1] * count; // this point i have a changing value to work with
    fflush(stdout);
    printf("%d", pattern);
    usleep(300000);
  }
  return(0);
}
