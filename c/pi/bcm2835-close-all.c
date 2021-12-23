/* This will close any Raspberry PI gpio's operations left running in bcm2835. */
#include <stdio.h>
#include <bcm2835.h>

void main() {
  if (! bcm2835_init() ) printf("libbcm2835 not found!");
  bcm2835_close();
}
