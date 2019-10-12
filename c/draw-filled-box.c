#include <stdio.h>

void drawFourDots();
void drawLine();
char dot = '*';
int count_dots;
int count_lines;

int main() {
  for (count_lines = 0; count_lines < 3; count_lines++) {
    drawFourDots();
    drawLine();
  }
  return 0;
}

void drawFourDots() {
  for (count_dots = 0; count_dots < 3; count_dots++) {
      printf("%c", dot);
  }
}

void drawLine() {
    printf("\n");
}
