/* 
 * Eugene Ngo 
 * 1965514 
 * 11/17/2022
 * Task 2b header file which defines the macros to access the GPIO port a and macros to initialize and access UART0
 */ 

#ifndef __LAB3_2B_H__
#define __LAB3_2B_H__

// GPIO Macros
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define RCGCGPIO_A_EN 0x00000001
#define GPIODEN_A (*((volatile uint32_t *)0x4005851C))
#define GPIOPCTL_A (*((volatile uint32_t *)0x4005852C))
#define GPIOAFSEL_A (*((volatile uint32_t *)0x40058420))
#define GPIODR2R_A (*((volatile uint32_t *)0x40058500))
// GPIO Macros


// UART Macros
#define RCGCUART (*((volatile uint32_t *)0x400FE618))
#define RCGCUART_3_EN 0x8
#define UARTLCRH_8BIT 0x60
#define UARTCC_3 (*((volatile uint32_t *)0x4000FFC8))
#define UARTDR_3 (*((volatile uint32_t *)0x4000F000))
#define UARTFR_3 (*((volatile uint32_t *)0x4000F018))
#define UARTCTL_3 (*((volatile uint32_t *)0x4000F030))
#define UARTIBRD_3 (*((volatile uint32_t *)0x4000F024))
#define UARTFBRD_3 (*((volatile uint32_t *)0x4000F028))
#define UARTLCRH_3 (*((volatile uint32_t *)0x4000F02C))
// UART Macros

// return the most recently entered character to the sender
void ReturnToSender();

#endif //__LAB3_TASK2B_H__