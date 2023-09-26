/* 
 * Eugene Ngo 
 * 1965514 
 * 10/20/2022 
 * Main file for task 1b: LED1 is turned on when SW1 is pressed and LED2 turns on when SW2 is pressed 
 */

#include <stdint.h>
#include "task1b.h"

// defining masks to access LEDs and SWs
#define LED1MASK 0x02
#define LED2MASK 0x01
#define SW1MASK 0x01
#define SW2MASK 0x02

int main (void) {
  volatile unsigned short delay = 0 ;
  RCGCGPIO |= RCGCGPIO_J_EN; // Enable PortJ GPIO
  RCGCGPIO |= RCGCGPIO_N_EN; // Enable PortN GPIO
  delay++; // Delay 2 more cycles before access Timer registers
  delay++;
  
  GPIODIR_J = 0x0; // Set PJ0 and PJ1 to input
  GPIODIR_N = (LED2MASK | LED1MASK); // Set PN0 and PN1 to output
  
  GPIODEN_J = (SW2MASK | SW1MASK); // Set PJ0 and PJ1 to digital
  GPIODEN_N = (LED2MASK | LED1MASK); // Set PN0 and PN1 to digital
  
  GPIOPUR_J = (SW2MASK | SW1MASK); // Set up pullup resistors
  
  while (1) { // Manipulate J register data and assign to N register
    GPIODATA_N = ~((GPIODATA_J << 1) | (GPIODATA_J >> 1));
  }
  return 0;
}