#include <stdio.h>

#define LEN 1000

int main()
{
  char* file = "file.txt";
  FILE *fp;
  char str[LEN];

  fp = fopen(file, "r");
  if (fp == NULL) {
    printf("No file named 'file.txt' in this directory!\n");
    return(1);
  }

  while (fgets(str, LEN, fp) != NULL) {
    printf("%s", str);
  }

  fclose(fp);
  return(0);
}
