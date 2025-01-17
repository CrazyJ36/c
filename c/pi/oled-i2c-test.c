#include <stdio.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static int file_i2c = 0;
static unsigned char ucScreen[1024];
static int iScreenOffset;

void oledWriteCommand(unsigned char c) {
  unsigned char buf[2];
  buf[0] = 0x00; // command introducer
  buf[1] = c;
  write(file_i2c, buf, 2);
}

void oledWriteDataBlock(unsigned char *ucBuf, int iLen) {
  unsigned char ucTemp[129];
  ucTemp[0] = 0x40; // data command
  memcpy(&ucTemp[1], ucBuf, iLen);
  write(file_i2c, ucTemp, iLen+1);
  //memcpy(&ucScreen[iScreenOffset], ucBuf, iLen); // keep a copy in local buffer.
  iScreenOffset += iLen;
}

void oledSetPosition(int x, int y) {
  iScreenOffset = (y*128) + x;
  oledWriteCommand(0xb0 | y); // go to page Y
  oledWriteCommand(0x00 | (x & 0xf)); // // lower col addr
  oledWriteCommand(0x10 | ((x >> 4) & 0xf)); // upper col addr
}


void oledFill(unsigned char ucData) {
  unsigned char temp[128];
  memset(temp, ucData, 128);
  for (int y = 0; y < 4; y++) {
    oledSetPosition(0, y);
    oledWriteDataBlock(temp, 128);
  }
}

void oledSetPixel(int x, int y, unsigned char ucColor) {
  int i;
  unsigned char uc, ucOld;
  i = ((y >> 3) * 128) + x;
  uc = ucOld = ucScreen[i];
  uc &= ~(0x1 << (y & 7));
  if (ucColor) {
    uc |= (0x1 << (y & 7));
  }
  if (uc != ucOld) { // pixel changed
    oledSetPosition(x, y >> 3);
    oledWriteDataBlock(&uc, 1);

  }
}

int main(int argc, char *argv[]) {
  if (!argv[1] || !argv[2]) {
    printf("Enter 2 numbers (x & y pixel position) as arguments.\n");
    return 1;
  }

  int arg1 = atoi(argv[1]);
  int arg2 = atoi(argv[2]);

  if (arg1 < 0 || arg1 > 127 ||
    arg2 < 0 || arg2 > 31) {
      printf("Some entered coordinates are off screen. My Adafriut PiOled screen is 128(x) by 32(y)\n");
      return 1;
  }

  if ( (file_i2c = open("/dev/i2c-1", O_RDWR) ) < 0) {
    printf("Failed to open i2c bus: /dev/i2c-1\n");
    file_i2c = 0;
    return 1;
  }
  if (ioctl(file_i2c, I2C_SLAVE, 0x3c) < 0) {
    printf("Failed to talk to i2c device\n");
    file_i2c = 0;
    return 1;
  }

  const unsigned char oled32_initbuf[] = {
    0x00,0xae,0xd5,0x80,0xa8,0x1f,0xd3,0x00,0x40,0x8d,0x14,0xa1,0xc8,0xda,0x02,
    0x81,0x7f,0xd9,0xf1,0xdb,0x40,0xa4,0xa6,0xaf
  };

  write(file_i2c, oled32_initbuf, sizeof(oled32_initbuf));
  oledFill(0x00); // fill black
  oledSetPixel(arg1, arg2, 1);

  sleep(2);

  oledWriteCommand(0xaE); // shutdown
  close(file_i2c);
  file_i2c = 0;
  return 0;
}
