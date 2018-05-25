/* Using getchar() to write words.
   It's best to type 4 characters on one line.*/

#include <stdio.h>

int main() {
  printf("Enter 5 characters:\n");
  char arr[5];

  for (int i = 0; i < 5; i++) {  // on every loop put the entered char into an array index.
    arr[i] = getchar();
  }

  printf("\nThe result:\n");

  for (int j = 0; j < 5; j++) {  // on every loop print the arrays' index number
    printf("%c", arr[j]);
  }

  printf("\n");
}
