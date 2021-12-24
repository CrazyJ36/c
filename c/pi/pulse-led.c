#include <bcm2835.h>
#include <stdio.h>

#define LED 4

int main() {
  if (!bcm2835_init()) {
    return 1;
  }
  bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);
  int i = 0;
  // Creating A fake PWM signal to change LED brightness over time.
  for(int x = 0; x < 50; x++) {
    bcm2835_gpio_write(LED, HIGH);
    if(i % 2 == 0) {
      delay(i + 1);
    }
    bcm2835_gpio_write(LED, LOW);
    if (i % 2 == 0) { // get divisors of 2 (even number or iterations) to make light turn off less while it gets brighter.
      delay(i + 1);
    }
    i = i + 1;
  }
  bcm2835_close();
  printf("Done\n");
}
