/* 
 * Eugene Ngo 
 * 1965514 
 * 11/17/2022
 * Task 1a header file which defines the macros to access the on-board LEDs, the timer, and the on-board ADC
 */ 

#ifndef __TASK1A_H__
#define __TASK1A_H__

// GPIO Macros
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define RCGCGPIO_F_EN 0x00000020
#define RCGCGPIO_N_EN 0x00001000
#define RCGCGPIO_E_EN 0x00000010
#define GPIODIR_F (*((volatile uint32_t *)0x4005D400))
#define GPIODEN_F (*((volatile uint32_t *)0x4005D51C))
#define GPIODATA_F (*((volatile uint32_t *)0x4005D3FC))
#define GPIODIR_N (*((volatile uint32_t *)0x40064400))
#define GPIODEN_N (*((volatile uint32_t *)0x4006451C))
#define GPIODATA_N (*((volatile uint32_t *)0x400643FC))
#define GPIODIR_E (*((volatile uint32_t *)0x4005C400))
#define GPIODEN_E (*((volatile uint32_t *)0x4005C51C))
#define GPIODATA_E (*((volatile uint32_t *)0x4005C3FC))
#define GPIOAMSEL_E (*((volatile uint32_t *)0x4005C528))
#define GPIOAFSEL_E (*((volatile uint32_t *)0x4005C420))

#define LED1MASK 0x02
#define LED2MASK 0x01
#define LED3MASK 0x10
#define LED4MASK 0x01
#define PE0 0x01
// GPIO Macros

//Timer Macros
#define RCGCTIMER_0_EN 0x01
#define RCGCTIMER (*((volatile uint32_t *)0x400FE604))
#define GPTMCTL_0 (*((volatile uint32_t *)0x4003000C))
#define TAOTE 0x20
#define GPTMCFG_0 (*((volatile uint32_t *)0x40030000))
#define CFG_32BIT 0x00
#define TAMR_COUNT_DOWN 0x0000
#define TAMR_PERIODIC 0x0002
#define GPTMTAMR_0 (*((volatile uint32_t *)0x40030004))
#define GPTMTAILR_0 (*((volatile uint32_t *)0x40030028))
#define FREQ_1HZ 0xF42400
#define GPTMICR_0 (*((volatile uint32_t *)0x40030024))
#define GPTMRIS_0 (*((volatile uint32_t *)0x4003001C))
#define GPTMADCEV_0 (*((volatile uint32_t *)0x40030070))
#define TATOADCEN 0x1
// Timer Macros

// ADC Macros
#define RCGCADC_0_EN 0x1
#define RCGCADC (*((volatile uint32_t *)0x400FE638))
#define ADCCC_ALTCLKCFG 0x1
#define ADCCC_0 (*((volatile uint32_t *)0x40038FC8))
#define ASEN3 0x00000008
#define ADCACTSS_0 (*((volatile uint32_t *)0x40038000))
#define EM3_TIMER 0x5000
#define ADCEMUX_0 (*((volatile uint32_t *)0x40038014))
#define AIN3 0x3
#define ADCSSEMUX3 (*((volatile uint32_t *)0x400380B8))
#define ADCSSMUX3 (*((volatile uint32_t *)0x400380A0))
#define SS3_INTERRUPT_EN 0x4
#define ADCSSCTL3 (*((volatile uint32_t *)0x400380A4))
#define SS3_IM 0x8
#define ADCIM_0 (*((volatile uint32_t *)0x40038008))
#define EN0 (*((volatile uint32_t *)0xE000E100))
#define ADCSS3_INTERRUPT_EN 0x00020000
#define SS3_INTERRUPT_CLEAR 0x8
#define ADCISC_0 (*((volatile uint32_t *)0x4003800C))
#define ADCSSFIFO3_0 (*((volatile uint32_t *)0x400380A8))
// ADC Macros

#endif //__LAB3_TASK1A_H__