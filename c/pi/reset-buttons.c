#include <stdio.h>
#include <bcm2835.h>

int main() {
  if (!bcm2835_init()) return 1;
  printf("Reseting all buttons...\n");
  int btns[] = {17, 25, 24, 16};
  for (int i = 0; i < sizeof(btns); i++) {
    bcm2835_gpio_fsel(btns[i], BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_clr(btns[i]);
  }
  printf("Done!\n");
  bcm2835_close();
  return 0;
}
