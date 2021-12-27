#include <stdio.h>
#include <bcm2835.h>

int main() {
  if (!bcm2835_init()) return 1;
  printf("Reseting all leds...\n");
  int leds[] = {4, 18, 6, 13};
  for (int i = 0; i < 4; i++) {
    bcm2835_gpio_fsel(leds[i], BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_clr(leds[i]);
  }
  printf("Done!\n");
  bcm2835_close();
  return 0;
}
