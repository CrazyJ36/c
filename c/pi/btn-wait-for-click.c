/* This app waits some time for a button press,
*  lights an led if button is pressed down.
*/
#include <bcm2835.h>
#include <stdio.h>

#define BTN 17 // or like: RPI_GPIO_P1_12
#define LED 4 //

// get voltage level of pin to ground (is connected or not)
#define pin_level bcm2835_gpio_lev(BTN)

int main() {
  if (!bcm2835_init()) {
      printf("Couldn't run. Is the bcm2835 library installed from airspayce.com/mikem/bcm2835?\n");
      return(1);
  }
  bcm2835_gpio_fsel(BTN, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);

  int count = 0;

  while(count < 50) { // timed function to find out if btn has been pushed

    if(pin_level == 0) { // if btn pin has connection(0 means true), turn led on
      bcm2835_gpio_set(LED);
    } else if (pin_level == 1) { // if btn pin gets no voltage through btn, turn led off
      bcm2835_gpio_clr(LED);
    }
    delay(100); // timed wait for btn response
    printf("wait: %d out of 50\n", count); // viewable app timer
    count++;

  }

  //if (pin_level == 0) bcm2835_gpio_clr(LED); // turn off led in case it is on still
  bcm2835_close(); // deallocate functions of bcm2835 library
  return(0);
}
