/* 
 * Eugene Ngo 
 * 1965514 
 * 11/7/2022 
 * Main file for task 2c: functions as a traffic light which can be turned on and off.
 * When the pedestrian inputs on the button, the traffic light will either stay on red or
 * if it is on green will go to yellow then red. With no inputs and on, the traffic light will
 * be alternating between red and green. All buttons must be held down for at least 2 seconds
 * for the system to process the button press. Each light has a delay of 5 seconds before turning.
 * The difference between this and task 1b is that this program uses interrupts.
 */

#include <stdint.h>
#include "task2c.h"

// macros for masks for buttons and LEDs
#define SW 0x01
#define Walk 0x02
#define GREEN 0x20
#define YELLOW 0x08
#define RED 0x04


enum States {SMStart, off, go, warn, stop} State;

int TimeUp = 0;

int main() {
   volatile unsigned short delay = 0;
   RCGCGPIO |= RCGCGPIO_E_EN;
   RCGCTIMER |= (RCGCTIMER_0_EN | RCGCTIMER_1_EN); // Enable timer 0 and timer 1
   delay++;
   delay++; // delay for two clock cycles before accessing registers
   Init();
   
   while (1) {
     // Implementing the state machine
     switch(State) { // next state logic
        case SMStart:
          State = off;
          break;
        
        case off:
          if (GetButton(SW)) {
            State = stop;
          } else {
            State = off;
          }
          break;
          
        case go:
          if (GetButton(SW)) {
            State = off;
          } else if (GetButton(Walk)) {
            State = warn;
          } else {
            State = stop;
          }
          break;
       
        case warn:
          if (GetButton(SW)) {
            State = off;
          } else {
            State = stop;
          }
          break;
          
        case stop:
          if (GetButton(SW)) {
            State = off;
          } else if (GetButton(Walk)){
            State = stop;
          } else {
            State = go;
          }
          break;
          
        default:
           State = SMStart;
           break;
     }
     
     switch(State) { // output logic
        case off:
          Red0();
          Yellow0();
          Green0();
          Interval();
          break;
        
        case go:
          Red0();
          Yellow0();
          Green1();
          Interval();
          break;
        
         case warn:
           Red0();
           Yellow1();
           Green0();
           Interval();
           break;
         
         case stop:
           Red1();
           Yellow0();
           Green0();
           Interval();
           break;
         
         default: break;
      }
    }
  return 0;
}

void Init() {
  InitSW();
  InitPED();
  InitRed();
  InitYellow();
  InitGreen();
  InitTimer();
}

void InitTimer() {
  GPTMIMR_0 = IMR_ENABLE; // Enable Timer 0 interruption
  EN0 = TIMER0A_INTERRUPT_EN; //| TIMER1A_INTERRUPT_EN); // Enable Timer 0A and 1A interruption
  ResetTimer0();
  ResetTimer1();
}

void ResetTimer0() {
  GPTMCTL_0 = 0x0; // Disable timer 0
  GPTMCFG_0 = CFG_32BIT; // Set 32-bit mode
  GPTMTAMR_0 |= (TAMR_ONESHOT | TAMR_COUNT_DOWN); // Set timer to oneshot and countdown
  GPTMTAILR_0 = FREQ_2S; // Set interval to 2s
}
void ResetTimer1() {
  GPTMCTL_1 = 0x0; // Disable timer 1
  GPTMCFG_1 = CFG_32BIT; // Set 32-bit mode
  GPTMTAMR_1 |= (TAMR_ONESHOT | TAMR_COUNT_DOWN); // Set timer to periodic and countdown
  GPTMTAILR_1 = FREQ_5S; // Set interval to 5s
}

void StartTimer0() {
  GPTMCTL_0 = 0x1; // Enable timer 0
}
void StartTimer1() {
  GPTMCTL_1 = 0x1; // Enable timer 1
}

void ClearFlagTimer0() {
  GPTMICR_0 = 0x01; // clear the TATORIS bit;
  GPTMICR_0 = 0x00;
}
void ClearFlagTimer1() {
  GPTMICR_1 = 0x01; // clear the TATORIS bit;
  GPTMICR_1 = 0x00;
}

void InitSW() {
  GPIOAMSEL_E &= ~SW; // disable analog function
  GPIOAFSEL_E &= ~SW; // select regular port function
  GPIODIR_E &= ~SW;   // set input direction
  GPIODEN_E |= SW;    // enable digital function
}

void InitPED() {
  GPIOAMSEL_E &= ~Walk; // disable analog function
  GPIOAFSEL_E &= ~Walk; // select regular port function
  GPIODIR_E &= ~Walk;   // set input direction
  GPIODEN_E |= Walk;    // enable digital function
}
unsigned char GetButton(unsigned char sw) {
  // reset timer when both buttons are unpressed
  if ((GPIODATA_E & Walk) == 0 && ((GPIODATA_E & SW) == 0)) { 
    TimeUp = 0;
    ResetTimer0();
  // starts timer when switch is pressed
  } else if (GPTMCTL_0 == 0x0) {
    StartTimer0();
  } 
  // return true when the switch was pressed for 2 seconds
  return ((GPIODATA_E & sw) != 0) && (TimeUp == 1);
}

void InitRed() {
  GPIOAMSEL_E &= ~RED; // disable analog function
  GPIOAFSEL_E &= ~RED; // select regular port function
  GPIODIR_E |= RED;   // set output direction
  GPIODEN_E |= RED;    // enable digital function
}
void Red1() {
  GPIODATA_E |= RED;
}
void Red0() {
  GPIODATA_E &= ~RED;
}

void InitYellow() {
  GPIOAMSEL_E &= ~YELLOW; // disable analog function
  GPIOAFSEL_E &= ~YELLOW; // select regular port function
  GPIODIR_E |= YELLOW;   // set output direction
  GPIODEN_E |= YELLOW;    // enable digital function
}
void Yellow1() {
  GPIODATA_E |= YELLOW;
}
void Yellow0() {
  GPIODATA_E &= ~YELLOW;
}

void InitGreen() {
  GPIOAMSEL_E &= ~GREEN; // disable analog function
  GPIOAFSEL_E &= ~GREEN; // select regular port function
  GPIODIR_E |= GREEN;   // set output direction
  GPIODEN_E |= GREEN;    // enable digital function
}
void Green1() {
  GPIODATA_E |= GREEN;
}
void Green0() {
  GPIODATA_E &= ~GREEN;
}

void Interval() {
  ResetTimer1();
  ClearFlagTimer1();
  TimeUp = 0;
  StartTimer1();
  while (!(GPTMRIS_1 & 0x1)) { // wait for either timeout or interruption
    if ((GetButton(SW)) || (GetButton(Walk) && (State == go))) {
      ResetTimer1();
      ClearFlagTimer1();
      return;
    }
  }
  ResetTimer1();
  ClearFlagTimer1();
}

void Timer0A_Handler() {
  TimeUp = 1;
  ResetTimer0();
  ClearFlagTimer0();
}