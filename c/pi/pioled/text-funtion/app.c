
#include <ctype.h>
#include "charmap.h"
#include "unistd.h"
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for exit()

void setDisplayRange(int line);
int addFontBytes(int curr, unsigned char c);
void updateDisplayFull();
void initDisplay();
void writeI2C(unsigned char* data, int bytes);

// displayLines was 8
unsigned char displayLines[1][128];
int i2cHandle = -1;
int i2cAddress = 0x3c;
unsigned char initSequence[26] = {0x00, 0xAE, 0xD5,
    0x80,0xA8, 0x1F, 0xD3, 0x00, 0x40, 0x8D, 0x14, 0xA1, 0xC8, 0xDA, 0x02, 0x81, 0x8F, 0xD9, 0xF1, 0xDB, 0x40,
    0xA4, 0xA6, 0x20, 0x00, 0xAF};
unsigned char setFullRange[7] = {0x00,0x21,0x00,0x7F,0x22,0x00,0x07};

void initDisplay() {
  writeI2C(initSequence, 26);
}

void textDisplay(const char *message) {
  initDisplay();
  int currByteCount = 0;
  for(int i=0; i<strlen(message); i++) {
    int bytesAdded = addFontBytes(currByteCount, message[i]);
    if(bytesAdded > 0) {
        currByteCount += bytesAdded;
    }
  }
  updateDisplayFull();
}

void clearDisplay() {
  // was i < 1
  for(int i=0; i<1; i++) {
    for(int j=0; j<128; j++) {
      displayLines[i][j] = 0;
    }
  }
  updateDisplayFull();
}

int addFontBytes(int curr, unsigned char c) {
  c = toupper(c); // we only support UPPERCASE letters
  int letterIdx = (c - ' ');
  if(letterIdx > 64) {
    letterIdx = 65;
  }
  int letterBytes = fontData[letterIdx][0];
  if((curr + letterBytes + 1) > 127 ) {
    return 0;
  }
  else {
    for(int i=0; i<letterBytes; i++) {
      displayLines[0][curr + i] = fontData[letterIdx][1 + i];
    }
    displayLines[0][curr + letterBytes++] = 0x00;  // single byte space / seperator
    return letterBytes;
  }
}

void setDisplayRange(int line) {
// -1 = full range
// 0..7 = line
  if(line == -1) {
    // was setFullRange, 7
    writeI2C(setFullRange, 1);
  }
}

void updateDisplayFull() {
 setDisplayRange(-1);
  // line < 4 was line < 8
  for(int line=0; line < 1; line++) {
    unsigned char buffer[129] = {0};
    buffer[0] = 0x40;
    for(int i=0; i < 128; i++) {
      buffer[1 + i] = displayLines[line][i];
    }
    writeI2C(buffer, 129);
  }
}

void writeI2C(unsigned char* data, int bytes) {
  char *deviceName;
  deviceName = (char*)"/dev/i2c-1";
  if ( (i2cHandle = open(deviceName, O_RDWR) ) < 0) {
    printf("error opening I2C\n");
  }
  else {
    if (ioctl(i2cHandle, I2C_SLAVE, i2cAddress) < 0) {
      printf("Error at ioctl\n");
    }
    else {
      for(int i=0; i<bytes; i++) {
        write(i2cHandle, data, bytes);
      }
    close(i2cHandle);
    }
  }

}

int main() {
  textDisplay("HELLO WORLD"); // capital only
  sleep(1);
  clearDisplay();
  return 0;

}

