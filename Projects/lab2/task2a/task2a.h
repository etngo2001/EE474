/* 
 * Eugene Ngo 
 * 1965514 
 * 11/7/2022 
 * Header file for task 2a: includes macros to memory addresses on the TIVA board
 * and confiures the GPTMs on the TIVA board. Enables the Timer 0A interruption.
 * Also includes the helper functions used in task 2a.
 */

#ifndef __TASK2A_H__
#define __TASK2A_H__

#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))

#define RCGCGPIO_F_EN 0x00000020
#define RCGCGPIO_N_EN 0x00001000

#define GPIODIR_F (*((volatile uint32_t *)0x4005D400))
#define GPIODEN_F (*((volatile uint32_t *)0x4005D51C))
#define GPIODATA_F (*((volatile uint32_t *)0x4005D3FC))

#define GPIODIR_N (*((volatile uint32_t *)0x40064400))
#define GPIODEN_N (*((volatile uint32_t *)0x4006451C))
#define GPIODATA_N (*((volatile uint32_t *)0x400643FC))

#define RCGCTIMER (*((volatile uint32_t *)0x400FE604))

#define RCGCTIMER_0_EN 0x01

#define GPTMCTL_0 (*((volatile uint32_t *)0x4003000C))

#define GPTMCFG_0 (*((volatile uint32_t *)0x40030000))

#define CFG_32BIT 0x00

#define GPTMTAMR_0 (*((volatile uint32_t *)0x40030004))

#define TAMR_PERIODIC 0x0002

#define TAMR_COUNT_DOWN 0x0000

#define GPTMTAILR_0 (*((volatile uint32_t *)0x40030028))

#define FREQ_1HZ 0xF42400

#define GPTMRIS_0 (*((volatile uint32_t *)0x4003001C))

#define GPTMICR_0 (*((volatile uint32_t *)0x40030024))

#define GPTMIMR_0 (*((volatile uint32_t *)0x40030018))

#define IMR_ENABLE 0x01

#define EN0 (*((volatile uint32_t *)0xE000E100))

#define TIMER0A_INTERRUPT_EN 0x00080000

// helper function to initialize GPIO
void GPIOInit();

// helper function to initialize Timer
void TimerInit();

// Timer's ISR
void Timer0A_Handler();

#endif //__TASK2A_H__