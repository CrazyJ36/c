#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
  FILE * fp;
  fp = fopen ("test.txt", "w+");
  fprintf(fp, "%s", "hello world\n");
  fclose(fp);
  return(0);
}
