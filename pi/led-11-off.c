#include <bcm2835.h>
int main() {
  if (!bcm2835_init()) return(1);
  bcm2835_gpio_fsel(RPI_GPIO_P1_11, BCM2835_GPIO_FSEL_OUTP); // hardware position
  bcm2835_gpio_clr(17); // clr= clear or off, sets software gpio number to low
  return(0);
}
