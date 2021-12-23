/* flash-if-true.c */

#include <stdio.h>
#include <bcm2835.h>
#include <stdlib.h> // for exit()

#define LED 4

void end();

int main()
{
  if(!bcm2835_init()) return 1;
  bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);

  int place;
  printf("Enter 1 (flase) or 0 (true), then press enter.\nIf true, led will flash.\n");
  place = getchar();
  if (place == '0') {
    printf("True, flashing led for 3 seconds...\n");
    bcm2835_gpio_set(LED);
    delay(3000);
    bcm2835_gpio_clr(LED);
    printf("Exiting..\n");
    end();
  }
  else if (place == '1') {
    printf("False, no flash. Exiting..\n");
    end();
  }
  else {
    printf("Error: Didn't get expected '1' or '0'.\nExiting..\n");
    end();
  }

}


void end() {
  bcm2835_close();
  exit(0);
}
