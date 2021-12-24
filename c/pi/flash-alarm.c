#include <bcm2835.h>
#include <stdio.h>

#define LED1 4
#define LED2 18

int main() {
  if (!bcm2835_init()) {
    return 1;
  }
  bcm2835_gpio_fsel(LED1, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(LED2, BCM2835_GPIO_FSEL_OUTP);
  printf("Flashing two leds like an alarm...\n");
  for (int i = 0; i < 4; i++) {
    bcm2835_gpio_write(LED1, HIGH);
    delay(500);
    bcm2835_gpio_write(LED1, LOW);

    bcm2835_gpio_write(LED2, HIGH);
    delay(500);
    bcm2835_gpio_write(LED2, LOW);
  }
  bcm2835_close();
  printf("Done\n");
}
