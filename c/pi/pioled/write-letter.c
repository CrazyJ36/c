#include <unistd.h> // for i2c.contains write(fd, buf, ...)
#include <fcntl.h>// for i2c. contains open(file, flags)
#include <sys/ioctl.h>//Needed for I2C port. this file is not found.
#include <linux/i2c-dev.h>//for i2c. contains no functions used here.
#include <stdio.h>
#include <string.h>

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

  char draw_letter1[5] = {0x40, 0x7e, 0x42, 0x42, 0x42}; // makes A 'C' at top left.
  writeI2C(draw_letter1, 5);

  // Using 2 bytes, drawing A 'space' at top left:
  char draw_letter2[3] = {0x40, 0x00, 0x00};
  writeI2C(draw_letter2, 3);
  // Using 2 bytes you can draw an exclamation point by using {0x40, 0x5E}
  //   in that case, 0x40 appears to be the top-left pixel.
  char draw_letter3[2] = {0x40, 0x5E};
  writeI2C(draw_letter3, 2);


  // Using 2 bytes, drawing A 'space':
  char draw_letter4[3] = {0x40, 0x00, 0x00};
  writeI2C(draw_letter4, 3);
  // Using 2 bytes, drawing A 'space':
  char draw_letter5[3] = {0x40, 0x00, 0x00};
  writeI2C(draw_letter5, 3);

  // dot
  char draw_letter6[2]= {0x40, 0x02};
  writeI2C(draw_letter6, 2);
}
