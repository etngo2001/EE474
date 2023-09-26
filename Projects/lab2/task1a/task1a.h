/* 
 * Eugene Ngo 
 * 1965514 
 * 11/7/2022 
 * Header file for task 1a: includes macros to memory addresses on the TIVA board
 * and confiures the GPTMs on the TIVA board 
 */

#ifndef __TASK1A_H__
#define __TASK1A_H__

// helper function to initialize GPIO
void GPIOInit();

// helper function to initialize Timer
void TimerInit();

#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define RCGCGPIO_F_EN 0x00000020
#define GPIODIR_F (*((volatile uint32_t *)0x4005D400))
#define GPIODEN_F (*((volatile uint32_t *)0x4005D51C))
#define GPIODATA_F (*((volatile uint32_t *)0x4005D3FC))
#define RCGCGPIO_N_EN 0x00001000
#define GPIODIR_N (*((volatile uint32_t *)0x40064400))
#define GPIODEN_N (*((volatile uint32_t *)0x4006451C))
#define GPIODATA_N (*((volatile uint32_t *)0x400643FC))
#define RCGCTIMER (*((volatile uint32_t *)0x400FE604))
#define RCGCTIMER_0_EN 0x01
#define GPTMTAMR_0 (*((volatile uint32_t *)0x40030004))
#define GPTMCTL_0 (*((volatile uint32_t *)0x4003000C))
#define GPTMCFG_0 (*((volatile uint32_t *)0x40030000))
#define CFG_32BIT 0x00
#define TAMR_COUNT_DOWN 0x0000
#define TAMR_PERIODIC 0x0002
#define GPTMTAILR_0 (*((volatile uint32_t *)0x40030028))
#define FREQ_1HZ 0xF42400
#define GPTMRIS_0 (*((volatile uint32_t *)0x4003001C))
#define GPTMICR_0 (*((volatile uint32_t *)0x40030024))

#endif //__TASK1A_H__