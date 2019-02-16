#include <bcm2835.h>
int main() {
  if (!bcm2835_init()) return(1);
  bcm2835_gpio_fsel(RPI_GPIO_P1_13, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_clr(27);
  return(0);
}
