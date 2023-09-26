/* 
 * Eugene Ngo 
 * 1965514 
 * 11/17/2022
 * Task 2b main file which reads user input and returns that information to the sender
 */ 

#include <stdint.h>
#include "Lab3_Inits.h"
#include "Lab3_2b.h"


int main(void) {
  // Select system clock frequency preset
  enum frequency freq = PRESET2; // 60 MHz
  PLL_Init(freq);        // Set system clock frequency to 60 MHz
  UART_Init();           // Initialize UART3 to communicate with computer
  while (1) {
    ReturnToSender();
  }
  return 0;
}

void ReturnToSender() {
  char input;
  while ((UARTFR_3 & 0x40) == 0x0); // wait for Rx to be full
  input = UARTDR_3;
  while ((UARTFR_3 & 0x80) == 0x0); // wait for Tx to be empty
  UARTDR_3 = input;
  if (input == '\r') {
    UARTDR_3 = '\n';
  }
}