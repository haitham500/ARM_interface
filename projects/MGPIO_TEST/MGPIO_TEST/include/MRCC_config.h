/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 26 Sep 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/

#ifndef MRCC_CONFIG_H
#define MRCC_CONFIG_H

/*
PERIPHERAL_CLOCK_SOURCE SHOULD BE SELECTED FROM :

HSE,
HSE_BYP,
HSI,
PLL,
*/
#define PERIPHERAL_CLOCK_SOURCE   HSE


/*
PLL_IN SHOULD BE SELECTED FROM:
HSE,
PLL_HSE_BY_2,
PLL_HSI_BY_2

*/
#define PLL_IN    PLL_HSE_BY_2


/*
RTC_CLOCK_SOURCE SHOULD BE SELECTED FROM:
LSE,
LSE_BYP,
LSI,
HSE_BY_128
*/
#define RTC_CLOCK_SOURCE  LSI


/*
MCO IS MICROCONTROLLER CLOCK OUTPUT ON PORT A PIN 8
SHOULD ACTIVATE IT FROM AFIO PERIPHERAL
CLOCK SOURCE SHOULD BE SELECTED FROM :
HSE,
HSI,
PLL_BY_2,
SYSCLK
*/
#define MCO  SYSCLK


#endif
