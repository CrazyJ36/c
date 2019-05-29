#include <bcm2835.h>
int main() {
  if (!bcm2835_init()) return(1);
  bcm2835_gpio_fsel(21, BCM2835_GPIO_FSEL_OUTP); // hardware position
  bcm2835_gpio_clr(21); // clr= clear or off, sets software gpio number to low
  return(0);
}
