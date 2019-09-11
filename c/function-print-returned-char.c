#include <stdio.h>

char aChar();

int main() {
  printf( "char returned from aChar(): %c\n", aChar() );
  return 0;
}

char aChar() {
  char letter = 'a';
  return letter;
}
