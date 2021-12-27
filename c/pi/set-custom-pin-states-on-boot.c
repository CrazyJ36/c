#include <bcm2835.h>
int main() {
  if (!bcm2835_init()) return(1);
  bcm2835_gpio_fsel(4, BCM2835_GPIO_FSEL_OUTP); // simple 22 represent Gpio format number, or RPI_GPIO_P1_15
  bcm2835_gpio_fsel(6, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_clr(4); // clr= clear or off, sets software gpio number to low
  bcm2835_gpio_clr(6);

  bcm2835_close();
  return(0);
}
