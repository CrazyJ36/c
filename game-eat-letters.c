/* Remember printf can loop and print to every new line,
   but if you want to printf onto the same line, you'll
   you'll want to fflush(stdout) before every printf().
*/

#include <stdio.h>

int main() {
  char sprite = '0';
  char food = '-';



// show sprite every time
  for (int faster = 20; faster > 0; faster--) {
    printf("%c", sprite);
  }
}
