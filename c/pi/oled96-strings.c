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

  // oledWriteString(x_pos, y_pos, string, size) is based on spaces for insertion
  // of characters, so x axis can be 0-15(for 16 characters, on my Adafruit 128x32 oled display, using FONT_NORMAL).
  // Shows from left to right.
  // y signifies 4 horizontal rows, 0-3 for normal and small font size.
  // space available in font sizes: FONT_NORMAL - 16x4, FONT_BIG - 8x1, FONT_SMALL - 21x4.
  // const values of font sizes are: FONT_NORMAL - 0, FONT_BIG - 1, FONT_SMALL - 2.
  oledWriteString(0, 0, "123456789012345678901", FONT_SMALL); // 21 characters in string.
  oledWriteString(0, 1, "123456789012345678901", FONT_SMALL);
  oledWriteString(0, 2, "123456789012345678901", FONT_SMALL);
  oledWriteString(0, 3, "123456789012345678901", FONT_SMALL);


  printf("FONT_NORMAL const value: %d\n", FONT_NORMAL); // 0
  printf("FONT_BIG const value: %d\n", FONT_BIG); // 1
  printf("FONT_SMALL const value: %d\n", FONT_SMALL); // 2


  printf("Showing on display, press ENTER to turn off led and end program.\n");
  getchar();
  oledShutdown();
  return 0;
}
