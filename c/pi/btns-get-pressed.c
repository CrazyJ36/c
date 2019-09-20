#include <stdio.h>
#include <bcm2835.h>

int main() {
  if (!bcm2835_init()) return 1;

  int btns[8] = {23, 27, 22, 25, 9, 5, 8};
  for(int i = 0; i < 8; i++) {
    bcm2835_gpio_fsel(btns[i], BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(btns[i], BCM2835_GPIO_PUD_UP);
  }

  printf("Push any button. To exit, press 'ctrl-c'.\n");

  while (1) {
    // 'for' loops through all buttons(on every while loop) to catch if any btn is pressed.
    for(int x = 0; x <= 8; x++) {
      if (bcm2835_gpio_lev(btns[x]) == 0) {
        printf("Button %d pushed.\n", btns[x]);
      }
    }

    delay(250);
  }

}
