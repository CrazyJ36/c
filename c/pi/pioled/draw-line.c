#include <unistd.h>//Needed for I2C port
#include <fcntl.h>//Needed for I2C port
#include <sys/ioctl.h>//Needed for I2C port
#include <linux/i2c-dev.h>//Needed for I2C port
#include <stdio.h>
#include <string.h>



void writeI2C(unsigned char* data, int bytes) {
  int i2cAddress = 0x3C;
  int i2cHandle;

  char *deviceName = (char*)"/dev/i2c-1";
  if ((i2cHandle = open(deviceName, O_RDWR)) < 0) {
    printf("error opening I2C\n");
  }
  else {
    if (ioctl(i2cHandle, I2C_SLAVE, i2cAddress) < 0) {
      printf("Error at ioctl\n");
    }
    else {
      write(i2cHandle, data, bytes);
    }
    // Close the i2c device bus
      close(*deviceName);
    }
}


int main() {
    // Init sequence from datasheet
    //unsigned char init[24] = {0xAE, 0xD5, 0xA8, 0xD3, 0x40, 0x14, 0xA1, 0xC8, 0xDA, 0x81, 0xF1, 0xDB, 0xA4, 0xA6, 0xAF};
    //writeI2C(init, 24);

    // writing to the same address many times shows long line.
    // 0x40 is top-left? Specified as 'Set Display Start Line' in datasheet.
    char line[28] = {0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
      0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
      0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40};
    writeI2C(line, 28);

    sleep(1);

    // Each time I write 1 byte to 0x40 it adds new pixels on the same line in page(horizontal section out of 8)
    char lineAgain[28] = {0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
      0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
      0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40};
    writeI2C(lineAgain, 28);

    //set the range we want to use (whole display)
    //unsigned char setFullRange[7] = {0x00,0x21,0x00,0x7F,0x22,0x00,0x07};
    //writeI2C(setFullRange,7);
}
