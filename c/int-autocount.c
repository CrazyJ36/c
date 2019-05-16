/* Increase A number, count to 10 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  int num = 0;

  for (int count = 0; count < 10; count++) {

    num = num + 1;
    printf("%d ", num);

  }
  printf("\n");
  return(0);
}
