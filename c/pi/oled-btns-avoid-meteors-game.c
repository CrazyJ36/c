#include <stdio.h>
#include <oled96.h>
#include <bcm2835.h>
#include <signal.h>

volatile sig_atomic_t stop;
void inthand(int signum) {stop = 1;}

int main(int argc, char *argv[]) {
  if (!bcm2835_init()) return 1;
  oledInit(1, 0x3c, OLED_128x32, 0, 0);
  oledFill(0);
  signal(SIGINT, inthand);

  int btns[4] = {17, 25, 24,16};
  int leds[4] = {4, 18, 6, 13};
  int led_iter = 0;
  int btn1_lev;
  int btn2_lev;
  int btn3_lev;
  int btn4_lev;
  int enemy_x = 25;
  int enemy_y = 11;
  int x_pos = 64;
  int y_pos = 16;
  int buzzer_pin = 21;
  int buzzer_repeater = 0;

  bcm2835_gpio_fsel(buzzer_pin, BCM2835_GPIO_FSEL_OUTP);
  for(int i = 0; i < 4; i++) {
    bcm2835_gpio_fsel(btns[i], BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(btns[i], BCM2835_GPIO_PUD_UP);
  }

  printf("Press Ctrl-c to end game.\n");

  oledWriteString(1, 1,"Avoid meteors!", FONT_SMALL);
  delay(600);
  oledFill(0);
  for (led_iter; led_iter < 4; led_iter++) {
    bcm2835_gpio_fsel(leds[led_iter], BCM2835_GPIO_FSEL_OUTP);
  }
  int line_right = 0;
  while (line_right < 32) {
    oledSetPixel(127, line_right, 1);
    line_right++;
  }
  int line_left = 0;
  while (line_left < 32) {
    oledSetPixel(0, line_left, 1);
    line_left++;
  }
  int line_top = 0;
  while (line_top < 128) {
    oledSetPixel(line_top, 0, 1);
    line_top++;
  }
  int line_bottom = 0;
  while (line_bottom < 128) {
    oledSetPixel(line_bottom, 31, 1);
    line_bottom++;
  }

  while (!stop) {
    btn1_lev = bcm2835_gpio_lev(btns[0]);
    btn2_lev = bcm2835_gpio_lev(btns[1]);
    btn3_lev = bcm2835_gpio_lev(btns[2]);
    btn4_lev = bcm2835_gpio_lev(btns[3]);
    if (btn1_lev == 0) {
      printf("left\n");
      oledSetPixel(x_pos, y_pos, 0);
      x_pos = x_pos - 1;
    }
    if (btn2_lev == 0) {
      printf("up\n");
      oledSetPixel(x_pos, y_pos, 0);
      y_pos = y_pos - 1;
    }
    if (btn3_lev == 0) {
      printf("down\n");
      oledSetPixel(x_pos, y_pos, 0);
      y_pos = y_pos + 1;
    }
    if (btn4_lev == 0) {
      printf("right\n");
      oledSetPixel(x_pos, y_pos, 0);
      x_pos = x_pos + 1;
    }
    if (x_pos < 1 || x_pos > 126 || y_pos < 1 || y_pos > 30) {
      while (buzzer_repeater < 2) {
        bcm2835_gpio_write(buzzer_pin, HIGH);
        delay(100);
        bcm2835_gpio_write(buzzer_pin, LOW);
        delay(100);
        buzzer_repeater++;
      }
      oledFill(0);
      printf("Out of bounds. Game over!\n");
      oledWriteString(0, 0, "Out of bounds!", FONT_NORMAL);
      delay(3000);
      break;
    }
    oledSetPixel(x_pos, y_pos, 1);

    oledSetPixel(enemy_x, enemy_y, 0);
    if (enemy_x >= 127) {
      enemy_x = 0;
    }
    if (enemy_y >= 31) {
      enemy_y = 1;
    }
    enemy_x++;
    enemy_y++;
    if (enemy_x == x_pos && enemy_y == y_pos ||
        enemy_x == x_pos - 2 && enemy_y == y_pos - 2 ||
        enemy_x == x_pos - 1 && enemy_y == y_pos - 1 ||
        enemy_x == x_pos + 1 && enemy_y == y_pos + 1 ||
        enemy_x == x_pos + 2 && enemy_y == y_pos + 2) {
      printf("Meteor hit you! Game over!\n");
      oledFill(0);
      oledWriteString(0, 0, "You're hit!", FONT_NORMAL);
      led_iter = 0;
      for (led_iter; led_iter < 4; led_iter++) {
        bcm2835_gpio_write(leds[led_iter], HIGH);
        delay(80);
        bcm2835_gpio_write(leds[led_iter], LOW);
        delay(80);
      }
      delay(3000);
      break;
    }
    oledSetPixel(enemy_x, enemy_y, 1 );
    delay(10);
  }
  printf("Exiting...\n");
  oledShutdown();
  bcm2835_close();
  return 0;
}
