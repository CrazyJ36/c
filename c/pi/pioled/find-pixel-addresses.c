#include <unistd.h> // for i2c.contains write(fd, buf, ...)
#include <fcntl.h>// for i2c. contains open(file, flags)
#include <sys/ioctl.h>//Needed for I2C port. this file is not found.
#include <linux/i2c-dev.h>//for i2c. contains no functions used here.
#include <stdio.h>
#include <string.h>

#define WIDTH 128
#define HEIGHT 32

static unsigned char array[1024];

void writeI2C(unsigned char* data, int bytes) {
  int i2cAddress = 0x3C;
  int i2cHandle;
  char *deviceName;

  deviceName = "/dev/i2c-1";

  if ((i2cHandle = open(deviceName, O_RDWR)) < 0) {
    printf("error opening I2C\n");
  }
  else {
    if (ioctl(i2cHandle, I2C_SLAVE, i2cAddress) < 0) {
      printf("Error with ioctl or i2c\n");
    }
    else {
      write(i2cHandle, data, bytes);
    }
    // Close the i2c device bus
    close(*deviceName);
  }
}

int main() {

  char init[26] = {0x00, 0xAE, 0xD5, 0x80,0xA8, 0x1F, 0xD3, 0x00, 0x40, 0x8D, 0x14, 0xA1, 0xC8, 0xDA, 0x02, 0x81, 0x8F, 0xD9, 0xF1, 0xDB, 0x40, 0xA4, 0xA6, 0x20, 0x00, 0xAF};
  writeI2C(init, 26);

  char start[4] = {0x00, 0x00, 0x10, 0x40};
  writeI2C(start, 4);

  char dataStream[1] = {0x40};
  for(unsigned short q=0; q<(WIDTH*HEIGHT/8); q++) {
    writeI2C(dataStream, 1);
  }

  int stuff;
  stuff = 50;
  writeI2C(stuff, 1);
}
