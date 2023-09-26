/* 
 * Eugene Ngo 
 * 1965514 
 * 10/20/2022 
 * Header file for task 1b: includes macros to memory addresses on the TIVA board 
 */

#ifndef __TASK1B_H__
#define __TASK1B_H__

#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define RCGCGPIO_J_EN 0x00000100
#define RCGCGPIO_N_EN 0x00001000
#define GPIODIR_J (*((volatile uint32_t *)0x40060400))
#define GPIODIR_N (*((volatile uint32_t *)0x40064400))
#define GPIODATA_N (*((volatile uint32_t *)0x400643FC))
#define GPIODATA_J (*((volatile uint32_t *)0x400603FC))
#define GPIODEN_J (*((volatile uint32_t *)0x4006051C))
#define GPIODEN_N (*((volatile uint32_t *)0x4006451C))
#define GPIOPUR_J (*((volatile uint32_t *)0x40060510))

#endif //__TASK1B_H__