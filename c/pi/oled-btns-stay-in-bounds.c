#include <stdio.h>
#include <oled96.h>
#include <bcm2835.h>
#include <signal.h>

volatile sig_atomic_t stop;
void inthand(int signum) {stop = 1;}
int x_pos = 64;
int y_pos = 16;

void currentPixelOff() {
  oledSetPixel(x_pos, y_pos, 0);
}

int main(int argc, char *argv[]) {
  if (!bcm2835_init()) return 1;
  oledInit(1, 0x3c, OLED_128x32, 0, 0);
  oledFill(0);
  signal(SIGINT, inthand);

  int btns[4] = {17, 25, 24,16};
  int btn1_lev;
  int btn2_lev;
  int btn3_lev;
  int btn4_lev;
  x_pos = 64;
  y_pos = 16;

  for(int i = 0; i < 4; i++) {
    bcm2835_gpio_fsel(btns[i], BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(btns[i], BCM2835_GPIO_PUD_UP);
  }

  printf("Press Ctrl-c to turn off oled and end program.\n");
  oledWriteString(0, 0,"Press btn to move", FONT_SMALL);

  while (!stop) {
    btn1_lev = bcm2835_gpio_lev(btns[0]);
    btn2_lev = bcm2835_gpio_lev(btns[1]);
    btn3_lev = bcm2835_gpio_lev(btns[2]);
    btn4_lev = bcm2835_gpio_lev(btns[3]);
    if (btn1_lev == 0) {
      printf("left\n");
      currentPixelOff();
      x_pos = x_pos - 1;
    }
    else if (btn2_lev == 0) {
      printf("up\n");
      currentPixelOff();
      y_pos = y_pos - 1;
    }
    else if (btn3_lev == 0) {
      printf("down\n");
      currentPixelOff();
      y_pos = y_pos + 1;
    }
    else if (btn4_lev == 0) {
      printf("right\n");
      currentPixelOff();
      x_pos = x_pos + 1;
    }
    if (x_pos < 0 || x_pos > 127 || y_pos < 0 || y_pos > 31) {
      oledFill(0);
      printf("Game over...");
      oledWriteString(0, 0, "Out of bounds!", FONT_NORMAL);
      delay(3000);
      break;
    }
    oledSetPixel(x_pos, y_pos, 1);
    delay(30);
  }

  printf("Exiting...\n");
  oledShutdown();
  return 0;
}
