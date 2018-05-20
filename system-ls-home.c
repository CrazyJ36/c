#include <stdio.h>
#include <stdlib.h>
int main() {
  printf("Home Directory:\n");
  system("ls -a $HOME");
  return(0);
}
