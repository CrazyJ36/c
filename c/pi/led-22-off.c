#include <bcm2835.h>
int main() {
  if (!bcm2835_init()) return(1);
  bcm2835_gpio_fsel(22, BCM2835_GPIO_FSEL_OUTP); // simple 22 represent Gpio format number, or RPI_GPIO_P1_15
  bcm2835_gpio_clr(22); // clr= clear or off, sets software gpio number to low
  return(0);
}
