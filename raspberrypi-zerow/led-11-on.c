#include <bcm2835.h>
int main() {
  if (!bcm2835_init()) return(1);
  // the next two lines represent the same gpio/pin
  // RPI_GPIO_P1_11 means hardware pin position
  bcm2835_gpio_fsel(RPI_GPIO_P1_11, BCM2835_GPIO_FSEL_OUTP); //hardware pin number
  // optionally use the software-assigned - gpio number
  bcm2835_gpio_set(17); // sets gpio number 17 to high
  return(0);
}
