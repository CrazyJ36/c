#include <bcm2835.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define PIN 27

volatile sig_atomic_t stop;
void inthand(int signum) {
  stop = 1;
}

int main() {
  signal(SIGINT, inthand);

  FILE *fp;
  char temp_celsius[8];
  int temp_fahrenheit;
  int conversion;

  if (!bcm2835_init()) { return 1; }
  bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

  while (!stop) {
    // Run system command to show temp, then check to see if it ran properly.
    fp = popen("/bin/cat /sys/class/thermal/thermal_zone0/temp", "r");
    if (fp == NULL) {
      printf("Failed to run command to get cpu temp.\n");
      return 1;
    }
    // read the file output from the command and put it into char..
    while (fgets(temp_celsius, sizeof(temp_celsius), fp) != NULL) {

      // convert celcius to nice fahrenheit format using calculations.
      temp_fahrenheit = atoi(temp_celsius) / 1000;
      conversion = (temp_fahrenheit * 1.8) + 32;
      // print temp in fahrenheit, comment this out if you're running this program in background.
      //printf("CPU Temperature in fahrenheit: %d\n", conversion);

      // if fahrenheit temp is above 100, turn on fan
      if (conversion > 99 && bcm2835_gpio_lev(LOW)) {
        bcm2835_gpio_write(PIN, HIGH);
      }
      else if (conversion <= 99 && bcm2835_gpio_lev(HIGH)) {
        bcm2835_gpio_write(PIN, LOW);
      }
    }
    pclose(fp);
    sleep(5);
  }
  printf("Stopped controlling CPU temperature.\n");
  bcm2835_gpio_clr(PIN);
  bcm2835_close();
  return 0;

}
