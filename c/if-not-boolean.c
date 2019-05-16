/* If not boolean. typed as:

   if (!(expression)) {
   }

   Put the '!' expression in perenthesis
   due to precedence.
*/

#include <stdio.h>

int main()
{
  int x = 2;
  printf("x is 2\n");

  if (!(x < 1)) {
    printf("x is not less than 1\n");
  }
}
