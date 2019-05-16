/* These results corespond to any acsii convertion chart. Int(10) gets converted in inline string statement.
   Data Types for printf:
   %d decimal
   %o octal
   %x hexadecimal lowercase
   %X hexadecimal capital case
   Others:
   %c single byte ascii character
   %s character string (char[] array)
   %% prints the "%" character itself, as in ("%%1", int 4) could print %4
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Number 10 in different forms:\n\n");
  int x = 10;
  printf("10 in decimal form: %d\n", x);
  printf("10 in octal form: %o\n", x);
  printf("10 in hexadecimal(lowercase): %x\n", x);
  printf("10 in hexadecimal(capital): %X\n", x);

  printf("Several ASCII Characters. 48,49,50,51 in decimal equals these ascii characters:\n");
  char y[4] = {48,49,50,51};
  printf("%s\n", y);
  exit(0);
}
