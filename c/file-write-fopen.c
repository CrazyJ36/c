#include <stdio.h>

int main() {
  FILE * fp;
  fp = fopen ("file.txt", "w+");
  fprintf(fp, "%s", "This file was written from 'file-write-fopen.c.\n");
  fclose(fp);
  return(0);
}
