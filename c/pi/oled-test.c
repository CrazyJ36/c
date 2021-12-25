#include <stdio.h>
#include <oled96.h>

int main(int argc, char *argv[]) {

  /* To test for i2c channels and try to init each, use A loop like:
    while (i != 0 && int channel < 2), i++, if (i == 0) { channel++; i = oledInit() } // try I2C channel 0 through 2
  */

  /* oledInit(channel, i2c_address, iOledType, flip, invert);
  params: channel: in linux run 'ls /dev/' to find i2c device channels. Find A device like 'i2c-1', 1 is channel.
  address: run i2cdetect -y 1 to find the device address. Typically 0x3c for ssd1306.
  iOledType: Probably OLED_128x32 or OLED_128x64, depends on your screens' pixels.
  flip: 0 for normal, 1 for upside down.
  invert: 0 for black background, 1 for white background with black items. */
  oledInit(1, 0x3c, OLED_128x32, 0, 0);
  oledFill(0); // fill with black

  // oledWriteString(x_pos, y_pos, string, size) is based on the start point of spaces for insertion
  // ofcharacters, so x axis can be 0-15(16 characters display). Shows from left to right.
  // y signifies 4 horizontal rows, 0-3 for normal font size..
  // font sizes: FONT_SMALL - 8x8, FONT_BIG - 16x24, FONT_SMALL - 6x8,
  //changing sizes can cause moving of characters into unwanted places.
  oledWriteString(7, 0,"a", FONT_NORMAL);
  oledWriteString(7, 1, "b", FONT_NORMAL);
  oledWriteString(7, 2, "c", FONT_NORMAL);
  oledWriteString(7, 3, "d", FONT_NORMAL);

  // oledSetPixel(x_pos, y_pos, color)
  // Use screen size -1 to prevent going off screen, as pixel 0 counts.
  oledSetPixel(0,0, 1);
  oledSetPixel(127, 31, 1);
  oledSetPixel(0, 31, 1);
  oledSetPixel(127, 0, 1);

  // draw by adding pixels in a loop:
  int line_length = 16;
  int x_pos = 84; // will constantly add line to this x axis the whole loop.
  int y_start_pos = 24; // will add from this vertical pixel using in + or - for up/down.
  for (int i=0; i< line_length; i++) {
    // y pixels' would increase by 1(- adds pixels upwards on y axis, + adds downward) on each loop iteration of i.
    oledSetPixel(x_pos, y_start_pos - i, 1);
  }

  printf("Items shown, press ENTER to turn off led and end program.\n");
  getchar();
  oledShutdown();
  return 0;
}
