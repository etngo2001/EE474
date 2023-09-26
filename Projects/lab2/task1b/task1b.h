/* 
 * Eugene Ngo 
 * 1965514 
 * 11/7/2022 
 * Header file for task 1b: Includes macros to memory addresses on the TIVA board
 * as well as the helper methods for task 1b.
 */

#ifndef __TASK1B_H__
#define __TASK1B_H__

// macros for accessing GPIO ports
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define RCGCGPIO_E_EN 0x00000010
#define GPIOAMSEL_E (*((volatile uint32_t *)0x4005C528))
#define GPIOAFSEL_E (*((volatile uint32_t *)0x4005C420))
#define GPIODIR_E (*((volatile uint32_t *)0x4005C400))
#define GPIODEN_E (*((volatile uint32_t *)0x4005C51C))
#define GPIODATA_E (*((volatile uint32_t *)0x4005C3FC))

// macros for accessing Timer 0A and Timer 1A
#define RCGCTIMER (*((volatile uint32_t *)0x400FE604))

#define RCGCTIMER_0_EN 0x01
#define RCGCTIMER_1_EN 0x02

#define GPTMCTL_0 (*((volatile uint32_t *)0x4003000C))
#define GPTMCTL_1 (*((volatile uint32_t *)0x4003100C))

#define GPTMCFG_0 (*((volatile uint32_t *)0x40030000))
#define GPTMCFG_1 (*((volatile uint32_t *)0x40031000))

#define CFG_32BIT 0x0

#define GPTMTAMR_0 (*((volatile uint32_t *)0x40030004))
#define GPTMTAMR_1 (*((volatile uint32_t *)0x40031004))

#define TAMR_ONESHOT 0x0001

#define TAMR_COUNT_DOWN 0x0000

#define GPTMTAILR_0 (*((volatile uint32_t *)0x40030028))
#define GPTMTAILR_1 (*((volatile uint32_t *)0x40031028))

#define FREQ_2S 0x1E84800
#define FREQ_5S 0x4C4B400

#define GPTMRIS_0 (*((volatile uint32_t *)0x4003001C))
#define GPTMRIS_1 (*((volatile uint32_t *)0x4003101C))

#define GPTMICR_0 (*((volatile uint32_t *)0x40030024))
#define GPTMICR_1 (*((volatile uint32_t *)0x40031024))

// Helper function: resets the timer
void ResetTimer0();
void ResetTimer1();

// Helper function: starts the timer
void StartTimer0();
void StartTimer1();

// Helper function: clears flags
void ClearFlagTimer0();
void ClearFlagTimer1();

// Helper function: Initilializes On/Off button at PE1
void InitSW();

// Helper function: Initializes Ped button at PE0
void InitPED();

// Returns the state of the switch that is given as a parameter.
// The switch must be pressed for at least two seconds to return 1, will return
// 0 otherwise.
unsigned char GetButton(unsigned char sw);

// initialize function
void Init();

// Helper functions for red LED at PE2
void InitRed(); // initialize
void Red1(); // on
void Red0(); // off

// Helper functions for yellow LED at PE3
void InitYellow(); // initialize
void Yellow1(); // on
void Yellow0(); // off

// Helper functions for green LED at PE5
void nitGreen(); // initialize
void Green1(); // on
void Green0(); // off

// 5-second interval between states.
void Interval();

#endif //__TASK2_H__