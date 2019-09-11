/* This app waits some time for a button press,
*  lights an led if button is pressed down
*  This probably does not work with adafruit
*  soft tactile buttons.Those don't give the
*  best connection when pressed due to the ruuber
*  that connects the switchs' terminals.
*/
#include <bcm2835.h>
#include <stdio.h>

#define BTN RPI_GPIO_P1_11 // or just gpio #
#define LED RPI_GPIO_P1_12 //

// get voltage level of pin to ground (is connected or not)
#define pin_level bcm2835_gpio_lev(BTN)

int main() {
  if (!bcm2835_init()) {
      printf("Is bcm2835 library installed?\n");
      return(1);
  }
  bcm2835_gpio_fsel(BTN, BCM2835_GPIO_FSEL_INPT); // set pin with button as input
  bcm2835_gpio_set_pud(BTN, BCM2835_GPIO_PUD_UP); // enable pull-up control on btn pin to make input act as button
  bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP); // let pin with led attached as output

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

  if (pin_level == 0) bcm2835_gpio_clr(LED); // turn off led in case it is on still
  bcm2835_close(); // deallocate functions of bcm2835 library
  return(0);
}
