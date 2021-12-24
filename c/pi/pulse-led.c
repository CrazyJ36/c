#include <bcm2835.h>
#include <stdio.h>

#define LED 4

int main() {
  if (!bcm2835_init()) {
    return 1;
  }
  bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);
  int i = 0;
  int x = 1;
  // Change LED brightness by alternating on/off time over iterations.
  for(int i = 0; i < 40; i++) {
    bcm2835_gpio_write(LED, HIGH);
      delay(x - i);
    bcm2835_gpio_write(LED, LOW);
      delay(x + 1);
    x = x + 1;
  }

  bcm2835_close();
  printf("Done\n");
}
