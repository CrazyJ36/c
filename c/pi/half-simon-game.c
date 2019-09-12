#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int led1 = 18; // gpio number, board number is RPI_GPIO_P1_12
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
  printf("Flashing an LED..\n\n");
  sleep(1);
  bcm2835_gpio_write(led, HIGH);
  sleep(1);
  bcm2835_gpio_write(led, LOW);
}

int detect_button(int btn) {
  //bcm2835_gpio_set_pud(btn, BCM2835_GPIO_PUD_UP);
  int count = 0;
  if (bcm2835_gpio_lev(btn) == 1 ) {
    delay(100);
    count++;
  }
}

int main() {
  if (!bcm2835_init()) {
    printf("bcm2835 failed to load.\n");
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

  int order1[4] = {led1, led2, led3, led4};
  int btn_order1[4] = {btn1, btn2, btn3, btn4};

  for (int i = 0; i != 4; i++) {
    flash(order1[i]);
    printf("Press button that corresponds to led - left-to-right...\n");
    detect_button(btn_order1[i]);
  }

}
