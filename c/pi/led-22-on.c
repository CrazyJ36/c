#include <bcm2835.h>
int main() {
  // Test for bcm2835 lib function in system
  if (!bcm2835_init()) return(1);

  // Select (GPIO format) pin number and set it's desired function to output(or input)
  bcm2835_gpio_fsel(22, BCM2835_GPIO_FSEL_OUTP);
  // this function sets pin to high by default
  bcm2835_gpio_set(22);

  return(0);
}
