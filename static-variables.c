/* static variables are available to the whole program.

*/
#include <stdio.h>

void say_hello();

int main() {
  int i;

  for (i = 0; i < 5; i++) {
    say_hello();
  }

  return(0);
}

void say_hello() {
  static int num_calls = 1; // when static, this variable can be used in the main() loop statement.

  printf("number %d\n", num_calls);
  num_calls++;
}
