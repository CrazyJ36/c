#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h> // for srand() number generator
#include <unistd.h>

  int led1 = 18;
  int led2 = 4;
  int led3 = 22;
  int led4 = 23;
  int btn1 = 17;
  int btn2 = 27;
  int btn3 = 24;
  int btn4 = 5;

  int out = BCM2835_GPIO_FSEL_OUTP;
  int in = BCM2835_GPIO_FSEL_INPT;

int exit_game() {
  bcm2835_close();
  exit(0);
}

int flash(int led) {
  printf("Flashing an LED..\n");
  sleep(2);
  bcm2835_gpio_write(led, HIGH);
  sleep(3);
  bcm2835_gpio_write(led, LOW);
  sleep(2);
  return led;
}

void detect_button(int btn) {
   bcm2835_gpio_set_pud(btn, BCM2835_GPIO_PUD_UP);

   printf("Press the button that is in the same position of order with led...\n");
   printf("You will be timed:\n");
   int count = 0;
   while(count < 50) {
     if(bcm2835_gpio_lev(btn) == 0) {
       printf("Correct button %d pushed!\n", btn);
       return;
     } else if (bcm2835_gpio_lev(btn) == 1) {
         delay(500);
         printf("%d out of 50\n", count);
         count++;
     }
     //printf("You ran out of time. Exiting\n");
     //exit_game();
   }
}
int main() {
  // If bcm2835_init() fails, exit with error.
  if (!bcm2835_init()) {
    printf("bcm2835 library failed to initialize. Exiting..\n");
    return(1);
  }

  bcm2835_gpio_fsel(led1, out);
  bcm2835_gpio_fsel(led2, out);
  bcm2835_gpio_fsel(led3, out);
  bcm2835_gpio_fsel(led4, out);
  bcm2835_gpio_fsel(btn1, in);
  bcm2835_gpio_fsel(btn2, in);
  bcm2835_gpio_fsel(btn3, in);
  bcm2835_gpio_fsel(btn4, in);

  // Set max numbers
  const int order1[4] = {led1, led2, led3, led4};
  //const int order2[4] = {led3, led2, led1, led4};
  //const int order3[4] = {led2, led3, led4, led1};
  //const int order4[4] = {led4, led1, led2, led3};
  const int btn_order1[4] = {btn1, btn2, btn3, btn4};
  //const int btn_order2[4] = {btn3, btn2, btn1, btn4};
  //const int btn_order3[4] = {btn2, btn3, btn4, btn1};
  //const int btn_order4[4] = {btn4, btn1, btn2, btn4};

  //int get_led = 0;
  //for(get_led = 0; get_led > 4; get_led++) {
    /*switch ( flash(get_led) ) {
      case 17:
        detect_button(btn2);
        break;
      case 18:
        detect_button(btn1);
        break;
      case 24:
        detect_button(btn3);
        break;
      case 5:
        detect_button(btn4);
        break;
      //default:
        //printf("?\n");
        //exit_game();
    }
  }
*/
    for (int i = 0; i < 4; i++) {
      while ( flash(order1[i]) ) {
        detect_button(btn_order1[i]);
      }
      printf("You finished! Exiting..\n");
      exit_game();
    }
//}

}

