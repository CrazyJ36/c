#include <stdio.h>
#include <string.h>

int aNum();

int main() {

  printf("Returned from int aNum(): %d\n", aNum() );
  return 0;

}


int aNum() {
  int num = 4;
  return num;
}
