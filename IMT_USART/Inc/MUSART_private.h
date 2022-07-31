/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 16 Jul 2022                                          */
/* Version     : V01                                                  */
/**********************************************************************/

#ifndef MUSART_PRIVATE_H
#define MUSART_PRIVATE_H

//USART 1 APB2 0x40013800 (PA9, PA10) OR (PB6,PB7)
//USART 2 APB1 0x40004400 (PA2,PA3)
//USART 3 APB1 0x40004800 (PB10, PB11)
//USART 4 APB1 0x40004C00
//USART 5 APB1 0x40005000

#define MUSART1_BASE_ADD  0x40013800

#define MUSART2_BASE_ADD  0x40004400

#define MUSART3_BASE_ADD  0x40004800

#define MUSART4_BASE_ADD  0x40004C00

#define MUSART5_BASE_ADD  0x40005000


typedef struct
{
  volatile u32 MUSART_SR     ;
  volatile u32 MUSART_DR     ;
  volatile u32 MUSART_BRR    ;
  volatile u32 MUSART_CR1    ;
  volatile u32 MUSART_CR2    ;
  volatile u32 MUSART_CR3    ;
  volatile u32 MUSART_GTPR   ;


} MUSART_R;



#define MUSART  ((volatile MUSART_R*) MUSART1_BASE_ADD)

#define MUSART2  ((volatile MUSART_R*) MUSART2_BASE_ADD)

#define MUSART3  ((volatile MUSART_R*) MUSART3_BASE_ADD)

#define MUSART4  ((volatile MUSART_R*) MUSART4_BASE_ADD)

#define MUSART5  ((volatile MUSART_R*) MUSART5_BASE_ADD)



#endif
