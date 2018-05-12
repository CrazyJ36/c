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
