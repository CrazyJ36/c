#include <stdio.h>
#include <bcm2835.h>

#define BTN 17

int main() {
  if (!bcm2835_init()) return 1;

  bcm2835_gpio_fsel(BTN, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_set_pud(BTN, BCM2835_GPIO_PUD_UP);

  printf("Push desired button, console will show feedback. To exit, press 'ctrl-c'.\n");

  while (1) {
    if ( bcm2835_gpio_lev(BTN) == 0 ) {
      printf("Button pushed.\n");
      bcm2835_close();
      return 0;
    }
  }

}
