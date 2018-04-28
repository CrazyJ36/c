#include <stdio.h>
int main()
{
   char c;
   printf("Enter 1 character: ");
// getchar() gets the first character on the last line
   c = getchar();
   printf("\nYou entered: ");
// putchar() basically prints
   putchar(c);
   putchar('\n');
// return 0; and return(0); are the same
   return 0;
}
