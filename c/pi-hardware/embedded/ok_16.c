// These make our 'OS' run in ram
volatile unsigned int* gpio;
volatile unsigned int tim;

int main(void) {

  gpio = (unsigned int*)0x20200000UL; // same as GPIO_BASE, GPIO peripheral using ARM Physical Address
  
/* Write 1 to the GPIO16. Using Function Select 1 GPIO
   peripheral register to enable GPIO16 as an output */
  gpio[1] |= (1 << 18); // the 1=GPIO_GPFSEL1, 18=GPFBIT 

// Override C mandatory exit with endless loop */
  while(1) {
    for(tim = 0; tim < 500000; tim++);
		
// Set the LED GPIO pin low
  gpio[10] = (1 << 16); // LED_GPCLR, LED_GPIO_BIT
  for(tim = 0; tim < 500000; tim++);

// Set the LED GPIO pin high
  gpio[7] = (1 << 16); // the 7=GPSET, 16=GPIO_BIT
 
  }
}