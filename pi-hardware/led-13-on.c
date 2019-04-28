/* RPI_GPIO_P1_13 wasn't working, so I used gpio #'s here */
#include <bcm2835.h>

int main() {
  if (!bcm2835_init()) return(1);
  bcm2835_gpio_fsel(27, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_set(27);
  return(0);
}
