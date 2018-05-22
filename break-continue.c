/* The break statement can be used to imediatly exit A loop.
   The continue statement can be used to 'skip' a loop iteration.
   
*/
#include <stdio.h>

int main() {
  int num = 5;

  while (num > 0) {
    if (num == 3)  // add an if statement to evaluate another condition.
      break; // if num gets to three, break and end the loop. Stop at three
    printf("%d\n", num);
    num--;
  }
  printf("next\n\n");
  int num2 = 6;
  while (num2 > 0) {
    num2--;  // if this was after continue, an infinite loop would be created.
    if (num2 == 3) // if num3 gets to 3, skip this and continue.
      continue;
    printf("%d\n", num2);
  }
}
