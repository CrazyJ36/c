/* In the category of Conditionals:
   The if statement is A conditinal control structure
   or decision structure because it executes
   statements when an expression is (and only when) true.

   This shows basics of if, else if, else.
   brackets {} are not necessary if only one statement is executed in if block.
   if multiple statements are to be executed in an if block, the code may continue
   all over the place, not knowing where to break.

*/


#include <stdio.h>
#include <stdlib.h>
int main()
{
  int number;
  printf("Enter your weight(number of pounds): ");
  scanf("%d", &number);
  if (number >  249) {
    printf("You may be Obese.\n");
  } else if (number < 100) {
    printf("Your either young or to skinny.\n");
  } else if (number > 150 || number < 200) {
    printf("You seem healthy.\n");
  } else {
    printf("I don't know what to say.\n");
  }
  return(0);
  exit(0);
}
