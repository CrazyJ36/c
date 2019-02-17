/* flash-if-true.c */

#include <stdio.h>
#include <bcm2835.h>

#define LED RPI_GPIO_P1_11

int main()
{
  if(!bcm2835_init()) return 1;
  bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);

  printf("If you type 'y', LED will flash, else it won't: ");
  char c = getchar();

  if(c == 'y') {
    bcm2835_gpio_set(LED);
    printf("You typed 'y', LED on for 3 seconds\n");
    delay(3000);
    bcm2835_gpio_clr(LED);
    return(0);
  } else if(c == 'n') {
      printf("You typed 'n'... Exiting\n");
      return(0);
  } else {
      printf("Invalid input... Exiting\n");
      return(0);
  }

}
