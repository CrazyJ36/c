/* gcc -o flash-11 flash-11.c -l bcm2835 */
#include <stdio.h>
#include <bcm2835.h>
#define PIN RPI_GPIO_P1_10 // board pin 10 is gpio 15 (my led0)

int main()
{
  if(!bcm2835_init()) return(1);
  bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP); // function select output for pin on board
  int incr = 1;
  printf("Flashing LED on gpio pin 15.\n");
  while(incr < 6) {
    printf("%d out of 5..\n", incr);
    bcm2835_gpio_write(PIN, HIGH);
    delay(200);
    bcm2835_gpio_write(PIN, LOW);
    if(incr == 5) break;
    delay(800);
    incr++;
  }
  bcm2835_close();
  printf("Done\n");
  return(0);
}
