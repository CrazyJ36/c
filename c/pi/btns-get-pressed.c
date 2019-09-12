#include <stdio.h>
#include <bcm2835.h>

int main() {
  if (!bcm2835_init()) return 1;

  // array of all buttons
  int btns[4] = {17, 27, 24, 5};

  // set button-occupied gpios' as input buttons
  for(int i = 0; i < 4; i++) {
    bcm2835_gpio_fsel(btns[i], BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(btns[i], BCM2835_GPIO_PUD_UP);
  }

  printf("Push any button. To exit, press ctrl-c.\n");

  // This can get any button, also multiple buttons at one time.
  while (1) {
    if (bcm2835_gpio_lev(btns[0]) == 0) printf("Button 1 pushed.\n");
    if (bcm2835_gpio_lev(btns[1]) == 0) printf("Button 2 pushed.\n");
    if (bcm2835_gpio_lev(btns[2]) == 0) printf("Button 3 pushed.\n");
    if (bcm2835_gpio_lev(btns[3]) == 0) printf("Button 4 pushed.\n");
    delay(300);
  }

  bcm2835_close();
  return 0;

}
