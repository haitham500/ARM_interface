/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 17 Jul 2022                                          */
/* Version     : V01                                                  */
/**********************************************************************/

#ifndef MUSART_INTERFACE_H
#define MUSART_INTERFACE_H

void MUSART_voidInit(void);

void MUSART_voidSendChar (u8 MUSART_u8CharData);
void MUSART_voidSendString (u8 * MUSART_ptrString);

u8 MUSART_u8ReceiveChar (void);
u8 * MUSART_u8ptrReceiveString (void);

void MUSART1_VoidSetCallBack( void (*ptr) (void) );
void MUSART2_VoidSetCallBack( void (*ptr) (void) );
void MUSART3_VoidSetCallBack( void (*ptr) (void) );


typedef enum
{
  PE,
  FE,
  NE,
  ORE,
  IDLE,
  RXNE,
  TC,
  TXE,
  LBD,
  CTS

}MUSART_SR_Bits;
//
// #typedef enum
// {
// //DR[0:8]
// }MUSART_DR_bits;

// #typedef enum
// {
//   //BRR_Fraction[0:3]
//   //BRR_Mantissa[4:15]
// }MUSART_BRR_Bits;

typedef enum
{
  SBK,
  RWU,
  RE,
  TE,
  IDLEIE,
  RXNEIE,
  TCIE,
  TXEIE,
  PEIE,
  PS,
  PCE,
  WAKE,
  M,
  UE

}MUSART_CR1_Bits;

typedef enum
{
  ADD_bit_0,
  ADD_bit_1,
  ADD_bit_2,
  ADD_bit_3,
  CR2_RES_4,
  LBDL,
  LBDIE,
  CR2_RES_7,
  LBCL,
  CPHA,
  CPOL,
  CLK_EN,
  STOP_0,
  STOP_1,
  LINEN

}MUSART_CR2_Bits;


#endif
