#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>

#define PIN 27

int main() {

  FILE *fp;
  char temp_celsius[8];
  int temp_fahrenheit;
  int conversion;

  if (!bcm2835_init()) { return 1; }
  bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

  while (1) {
    // Run system command to show temp as char
    fp = popen("/bin/cat /sys/class/thermal/thermal_zone0/temp", "r");
    if (fp == NULL) { printf("Failed to run command to get cpu temp.\n"); return 1; }
    while (fgets(temp_celsius, sizeof(temp_celsius), fp) != NULL) {
      // convert celcius to fahrenheit with calculation
      temp_fahrenheit = atoi(temp_celsius) / 1000;
      conversion = (temp_fahrenheit * 1.8) + 32;
      // print temp in fahrenheit
      //printf("CPU Temperature in fahrenheit: %d\n", conversion);
      if (conversion > 99) {
        bcm2835_gpio_write(PIN, HIGH);
      }
      else {
        bcm2835_gpio_write(PIN, LOW);
      }
    }
    pclose(fp);
    delay(5000);
  }
  bcm2835_close();
  return 0;

}
