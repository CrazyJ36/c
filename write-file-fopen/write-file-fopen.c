#include <stdio.h>

int main() {
  FILE * fp;
  fp = fopen ("file.txt", "w+");
  fprintf(fp, "%s", "This file was wirtten from 'fopen-write-file'.\n");
  fclose(fp);
  return(0);
}
