/* 
 * Eugene Ngo 
 * 1965514 
 * 11/17/2022
 * Task 2a main file which defines the formula used to calculate board temperature and writes it to the UART module which then communicates with the computer
 */ 

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#include "Lab3_Inits.h"
#include "Lab3_2a.h"

uint32_t ADC_value;
int updateTemp = 0;

int main(void) {
  // Select system clock frequency preset
  enum frequency freq = PRESET2; // 60 MHz
  PLL_Init(freq);        // Set system clock frequency to 60 MHz
  SW_Init();             // Initialize the 2 onboard SWs (GPIO)
  ADCReadPot_Init();     // Initialize ADC0 to read from temperature sensor
  TimerADCTriger_Init(); // Initialize Timer0A to trigger ADC0
  UART_Init();           // Initialize UART0 to communicate with computer
  float temperature;
  char output[7];
  while (1) {
    updateTemp = 0;
    temperature = (float) 147.5 - ((247.5 * ADC_value) / 4096);
    temperature = roundf(temperature * 100) / 100;
    sprintf(output, "%f", temperature);
    output[5] = 0x0D; // \r in ASCII
    output[6] = 0x0A; // \n in ASCII
    for (int i = 0; i < 7; i++) {
      UARTDR_0 = output[i];
    }
    while (updateTemp != 1);
  }
  return 0;
}

void PortJ_Handler(void) {
   GPIOICR_J |= 0x3; // Clear Port J interruption
  enum frequency freq = PRESET2;
  if (GPIODATA_J == SW1MASK) {
    freq = PRESET3; // 12 MHz
  } else if (GPIODATA_J == SW2MASK) {
    freq = PRESET1; // 120 MHz
  }
  PLL_Init(freq);
}

void ADC0SS3_Handler(void) {
   ADCISC_0 |= SS3_INTERRUPT_CLEAR; // clear the interrupt flag
   GPTMICR_0 |= 0x1; // clear timer interrupt flag
   ADC_value = ADCSSFIFO3_0 & 0xFFF; // save adc value to global variable
   updateTemp = 1;
}