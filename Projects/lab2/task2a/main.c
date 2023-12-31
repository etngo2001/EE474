/* 
 * Eugene Ngo 
 * 1965514 
 * 11/7/2022 
 * Main file for task 2a: cycles the LEDs continuously using GPTMs and timer
 * interruption at a rate of 1 Hz
 */

#include <stdint.h>
#include "task2a.h"

// defining masks to access LEDs
#define LED1MASK 0x02
#define LED2MASK 0x01
#define LED3MASK 0x10
#define LED4MASK 0x01

int count = 0; // cycle count

int main (void) {
  volatile unsigned short delay = 0 ;
  RCGCGPIO |= RCGCGPIO_F_EN; // Enable PortF GPIO
  RCGCGPIO |= RCGCGPIO_N_EN; // Enable PortN GPIO
  delay++; // Delay 2 more cycles before access Timer registers
  delay++;
  
  GPIOInit();
  TimerInit();
  
  while (1) {}
  return 0;
}

void GPIOInit() {
  // Set PF0 and PF4 to output
  GPIODIR_F = (LED4MASK | LED3MASK); 
  
  // Set PN0 and PN1 to output
  GPIODIR_N = (LED2MASK | LED1MASK); 
  
  // Set PF0 and PF4 to digital
  GPIODEN_F = (LED4MASK | LED3MASK); 
  
  // Set PN0 and PN1 to digital
  GPIODEN_N = (LED2MASK | LED1MASK); 
}

void TimerInit() {
  RCGCTIMER |= RCGCTIMER_0_EN; // Enable timer 0
  GPTMCTL_0 = 0x0; // Disable timer 0
  GPTMCFG_0 = CFG_32BIT; // Set 32-bit mode
  GPTMTAMR_0 |= (TAMR_PERIODIC | TAMR_COUNT_DOWN); // Set timer to periodic and countdown
  GPTMTAILR_0 = FREQ_1HZ; // Set frequency to 1Hz
  GPTMIMR_0 = IMR_ENABLE; // Enable interruption
  EN0 = TIMER0A_INTERRUPT_EN; // Enable Timer 0A interruption
  GPTMCTL_0 = 0x1; // Enable timer 0;
}

void Timer0A_Handler() {
  GPTMICR_0 = 0x01; // clear the TATORIS bit;
  GPTMICR_0 = 0x00;
  count++;
  if (count == 1) {
    GPIODATA_N = 0x0; // Turn off port N
    GPIODATA_F = LED4MASK; // Turn on LED4
  } else if (count == 2) {
    GPIODATA_F = LED3MASK; // Turn on LED3
  } else if (count == 3) {
    GPIODATA_F = 0x0; // Turn off port F
    GPIODATA_N = LED2MASK; // Turn on LED2
  } else if (count == 4) {
    GPIODATA_N = LED1MASK; // Turn on LED1
    count = 0;
  } else {
    count = 0;
  }
}