/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 16 Jul 2022                                          */
/* Version     : V01                                                  */
/**********************************************************************/

#ifndef MSPI_PRIVATE_H
#define MSPI_PRIVATE_H

// SPI 1 working on APB2 ( PA4,PA5, PA6, PA7 ) OR ( PB3, PB4, PB5, PA15 ) ->address 0x40013000
// SPI 2 working on APB1 ( PB12, PB13, PB14, PB15 ) -> address 0x40003800
// there are no SPI3 or I2S in medium density MCU STM32F103C8

#define MSPI_BASE_ADD  0x40013000 // address of SPI 1

typedef struct
{
  volatile u32 MSPI_CR1     ;
  volatile u32 MSPI_CR2     ;
  volatile u32 MSPI_SR      ;
  volatile u32 MSPI_DR      ;
  volatile u32 MSPI_CRCPR   ;
  volatile u32 MSPI_RXCRCR  ;
  volatile u32 MSPI_TXCRCR  ;
  volatile u32 MSPI_I2SCFGR ;
  volatile u32 MSPI_I2SPR   ;

} MSPI_R;



#define MSPI  ((volatile MSPI_R*) MSPI_BASE_ADD)


#endif
