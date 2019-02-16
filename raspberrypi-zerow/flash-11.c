/* gcc -o flash-11 flash-11.c -l bcm2835 */
#include <stdio.h>
#include <bcm2835.h>
#define PIN RPI_GPIO_P1_11
int main()
{
  if(!bcm2835_init()) return(1); // attempt initialize library functions
  bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP); // select pin and output, pin num is as ordered on board
  int incr = 1;
  printf("Flashing LED on bcm pin 11.\n");
  while(incr < 6) {
    printf("%d out of 5..\n", incr);
    bcm2835_gpio_write(PIN, HIGH);
    delay(200);
    bcm2835_gpio_write(PIN, LOW);
    if(incr == 5) break;
    delay(800);
    incr++;
  }
  printf("Done\n");
  return(0);
}
