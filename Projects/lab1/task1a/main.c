/* 
 * Eugene Ngo 
 * 1965514 
 * 10/20/2022 
 * Main file for task 1a: cycles the LEDs continuously with an interval of around 0.3 sec 
 */

#include <stdint.h>
#include "task1a.h"

// defining masks to access each LED
#define MASK1LED 0x02
#define MASK2LED 0x01
#define MASK3LED 0x10
#define MASK4LED 0x01

// Creates around a 0.3s delay interval
void interval();

int main (void) {
  volatile unsigned short delay = 0 ;
  // Enables ports
  RCGCGPIO |= RCGCGPIO_F_EN;
  RCGCGPIO |= RCGCGPIO_N_EN;
  // 2 cycle delay
  delay++;
  delay++;
  
  // Sets ports to outputs and digitals
  GPIODIR_F = (MASK4LED | MASK3LED);
  GPIODIR_N = (MASK2LED | MASK1LED);
  GPIODEN_F = (MASK4LED | MASK3LED);
  GPIODEN_N = (MASK2LED | MASK1LED);
  
  while (1) {
    GPIODATA_N = 0x0;
    GPIODATA_F = MASK4LED;
    interval();
    GPIODATA_F = MASK3LED;
    interval();
    GPIODATA_F = 0x0;
    GPIODATA_N = MASK2LED;
    interval();
    GPIODATA_N = MASK1LED;
    interval();
  }
  return 0;
}

void interval() {
  for (int j = 0; j < 1000000; j++) {}
}