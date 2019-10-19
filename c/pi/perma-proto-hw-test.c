#include <bcm2835.h>
#include <stdio.h>

int main() {
  if (!bcm2835_init()) return(1);

  struct leds {
    int led1;
    int led2;
    int led3;
    int led4;
    int led5;
    int led6;
    int led7;
    int led8;
  };

  struct leds pins = {4, 18, 24, 11, 12, 7, 16, 6};

  for (int inc = 0; inc < sizeOf(pins); inc++) {
    printf("led1: %d\n", pins.[inc]);
  }

  return 0;
}
