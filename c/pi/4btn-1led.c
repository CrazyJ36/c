#include <bcm2835.h>
#include <stdio.h>
#include <signal.h>

volatile sig_atomic_t stop;
void signal_handler(int signum) { stop = 1; }

 // enter gpio numbers here
#define LED 16
#define BTN1 22  // btn1 is soldered onto perma-proto(from left to right) at GPIO pin 22.
#define BTN2 24
#define BTN3 25
#define BTN4 5

int main(int argc, char **argv) {

  // check if libbcm2835 works. If not, exit.
  if (!bcm2835_init()) return 1;

  // Select LED to be output
  bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);
  // Select buttons to be an input
  bcm2835_gpio_fsel(BTN1, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(BTN2, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(BTN3, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_fsel(BTN4, BCM2835_GPIO_FSEL_INPT);

  /* Pull-up resistor mode may not be necessary
     with adafruit soft buttons and resistor.
     Also this setting may be necessary when using
     these types of buttons without resistor,
     or may not matter. See what works and set accordingly.
     In this case. some btns were stuck on before the following. */
  bcm2835_gpio_set_pud(BTN1, BCM2835_GPIO_PUD_UP);
  bcm2835_gpio_set_pud(BTN2, BCM2835_GPIO_PUD_UP);
  bcm2835_gpio_set_pud(BTN3, BCM2835_GPIO_PUD_UP);
  bcm2835_gpio_set_pud(BTN4, BCM2835_GPIO_PUD_UP);

  // Instructions
  printf("Press one of four buttons and watch led. CTRL-C to exit.\n");

  signal(SIGINT, signal_handler);
  // Read button state on loop
  while (!stop) {
    int state1 = bcm2835_gpio_lev(BTN1);
    int state2 = bcm2835_gpio_lev(BTN2);
    int state3 = bcm2835_gpio_lev(BTN3);
    int state4 = bcm2835_gpio_lev(BTN4);

    if (state1 == 0) {
      int  led_count_btn1 = 0;
      while(led_count_btn1 < 1) {
        printf("btn1\n");
        bcm2835_gpio_write(LED, HIGH);
        delay(150);
        bcm2835_gpio_write(LED, LOW);
        led_count_btn1++;
      }
    }
    else if (state2 == 0) {
      printf("btn2\n");
      int led_count_btn2 = 0;
      while (led_count_btn2 < 2) {
        bcm2835_gpio_write(LED, HIGH);
        delay(150);
        bcm2835_gpio_write(LED, LOW);
        delay(150);
        led_count_btn2++;
      }
    }
    else if (state3 == 0) {
      printf("btn3\n");
      int led_count_btn3 = 0;
      while (led_count_btn3 < 3) {
        bcm2835_gpio_write(LED, HIGH);
        delay(150);
        bcm2835_gpio_write(LED, LOW);
        delay(150);
        led_count_btn3++;
      }
    }
    else if (state4 == 0) {
      printf("btn4\n");
      int led_count_btn4 = 0;
      while (led_count_btn4 < 4) {
        bcm2835_gpio_write(LED, HIGH);
        delay(150);
        bcm2835_gpio_write(LED, LOW);
        delay(150);
        led_count_btn4++;
      }
    }
  }
  printf("Exiting\n");
  bcm2835_close();
  return(0);
}
