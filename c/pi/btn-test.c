#include <bcm2835.h>
#include <stdio.h>

 // enter buttons' gpio number here
#define BTN 23  // btn1 on perma-proto1

int main(int argc, char **argv) {
  if (!bcm2835_init()) return 1;

  bcm2835_gpio_fsel(BTN, BCM2835_GPIO_FSEL_INPT);
  /* IMPORTANT!
     Pull-up resistor mode may not be necessary
     with adafruit soft buttons and resistor.
     Also this setting may be necessary when using
     these types of buttons without resistor,
     or may not matter. See what works and SET ACCORDINGLY */
  //bcm2835_gpio_set_pud(BTN, BCM2835_GPIO_PUD_UP);

  while (1) {
   int value = bcm2835_gpio_lev(BTN);
   printf("Press chosen btn, 1 is off(not pressed) and 0 is on: %d\n", value);
   delay(200);
  }

  bcm2835_close();
  return 0;

}
