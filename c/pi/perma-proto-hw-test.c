#include <bcm2835.h>
#include <stdio.h>
#include <string.h>

int leds();
int buzzer();
int buttons();

int main(int argc, char *argv[]) {
  if (!bcm2835_init()) return(1);
  printf("Type: 'leds', 'buttons', or 'buzzer' to run A test\n");
  char choice[7];
  scanf("%8s", choice);

  int choice_leds = strcmp("leds", choice);
  int choice_buttons = strcmp("buttons", choice);
  int choice_buzzer = strcmp("buzzer", choice);

  if (choice_leds == 0) {
    printf("Running test on leds...\n");
    leds();
  } else if (choice_buttons == 0) {
    printf("Test buttons.. push any..\n");
    buttons();
  } else if (choice_buzzer == 0) {
    printf("Testing buzzer..\n");
    buzzer();
  } else {
    printf("Improper choice, try again. Exiting...\n");
  }

  bcm2835_close();
  return 0;
}

int leds() {
  int pins[] = {4, 18, 24, 11, 12, 7, 16, 6};

  for (int inc = 0; inc < 8; inc++) {
    bcm2835_gpio_fsel(pins[inc], BCM2835_GPIO_FSEL_OUTP);
  }

  for (int inc = 0; inc < 8; inc++) {
    printf("pin %d\n", pins[inc]);
    bcm2835_gpio_write(pins[inc], HIGH);
    delay(200);
    bcm2835_gpio_write(pins[inc], LOW);
    delay(200);
  }
  printf("Done.\n");
  return 0;
}

int buzzer() {
  int pin = 2;
  bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_OUTP);
  for (int inc = 0; inc < 40; inc++) {
    bcm2835_gpio_write(pin, HIGH);
    delay(5);
    bcm2835_gpio_write(pin, LOW);
    delay(5);
  }
  return 0;
}

int buttons() {
  int btns[] = {23, 27, 22, 25, 9, 5, 8};

  for (int inc = 0; inc < sizeof(btns); inc++) {
    bcm2835_gpio_fsel(btns[inc], BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(btns[inc], BCM2835_GPIO_PUD_UP);
  }
  while (1) {
    if ( bcm2835_gpio_lev(btns[0]) == 0 ) {
      printf("button 1\n");
    } else if ( bcm2835_gpio_lev(btns[1]) == 0 ) {
        printf("button 2\n");
    } else if ( bcm2835_gpio_lev(btns[2]) == 0 ) {
        printf("button 3\n");
    } else if ( bcm2835_gpio_lev(btns[3]) == 0 ) {
        printf("button 4\n");
    } else if ( bcm2835_gpio_lev(btns[4]) == 0 ) {
        printf("button 5\n");
    } else if ( bcm2835_gpio_lev(btns[5]) == 0 ) {
        printf("button 6\n");
    } else if ( bcm2835_gpio_lev(btns[6]) == 0 ) {
        printf("button 7\n");
    } else {
        printf("Nothing..\n");
    }

    delay(200);
  }
  return 0;
}
