/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 15 Aug 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/




#ifndef  RCC_PRIVATE_H
#define  RCC_PRIVATE_H


/* registers definition */
#define  RCC_CR         *((u32*)0x40021000)   /*clock-(en/dis)able CLOCK INPUT*/
#define  RCC_CFGR       *((u32*)0x40021004)   /* clock - CHOOSE CLOCK INPUT */
#define  RCC_CIR        *((u32*)0x40021008)   /* Reset */
#define  RCC_APB2RSTR   *((u32*)0x4002100C)   /* Reset */
#define  RCC_APB1RSTR   *((u32*)0x40021010)   /* Reset */
#define  RCC_AHBENR     *((u32*)0x40021014)   /* clock -enable peripherals*/
#define  RCC_APB2ENR    *((u32*)0x40021018)   /* clock -enable peripherals*/
#define  RCC_APB1ENR    *((u32*)0x4002101C)   /* clock -enable peripherals*/
#define  RCC_BDCR       *((u32*)0x40021020)   /* Reset */
#define  RCC_CSR        *((u32*)0x40021024)   /* Reset */

/* CLOCK TYPES */

#define RCC_HSE_CRYSTAL       0
#define RCC_HSE_RC            1
#define RCC_HSI               2
#define RCC_PLL               3

/* PLL options */
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        2


#endif
