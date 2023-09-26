/* 
 * Eugene Ngo 
 * 1965514 
 * 10/20/2022 
 * Header file for task 1a: includes macros to memory addresses on the TIVA board 
 */

#ifndef __TASK1A_H__
#define __TASK1A_H__

#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define RCGCGPIO_F_EN 0x00000020
#define RCGCGPIO_N_EN 0x00001000
#define GPIODEN_N (*((volatile uint32_t *)0x4006451C))
#define GPIODIR_N (*((volatile uint32_t *)0x40064400))
#define GPIODATA_N (*((volatile uint32_t *)0x400643FC))
#define GPIODATA_F (*((volatile uint32_t *)0x4005D3FC))
#define GPIODIR_F (*((volatile uint32_t *)0x4005D400))
#define GPIODEN_F (*((volatile uint32_t *)0x4005D51C))

// fixed interval function
void interval();

#endif //__TASK1A_H__