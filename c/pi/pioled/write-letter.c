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
    char letterB[5] = {0x40, 0x7E, 0x4a, 0x4a, 0x34};
    writeI2C(letterB, 5);
}
