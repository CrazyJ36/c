#include <stdio.h>
#include <bcm2835.h>

// Initialize pins
//int led1 = RPI_GPIO_P1_12; // this calls board number, gpio num is 18
//btn1=17;btn2=27;btn3=24;btn4 =5;

// initialize A function to use
//void myFunc(char func_version);

int main() {
  if (!bcm2835_init()) return 1;

  // array of all buttons
  int btns[4] = {17, 27, 24, 5};

  // set button-occupied gpios' as input buttons
  for(int x = 0; x < sizeof(btns); x++) {
    bcm2835_gpio_fsel(btns[x], BCM2835_GPIO_FSEL_INPT);
    //if (x == 0) {
    //} else {
      bcm2835_gpio_set_pud(btns[x], BCM2835_GPIO_PUD_UP);
    //}
  }

  printf("Push any button. To exit, press ctrl-c.\n");

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

//void myFunc(func_verion)
