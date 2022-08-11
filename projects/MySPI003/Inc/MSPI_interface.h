/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 16 Jul 2022                                          */
/* Version     : V01                                                  */
/**********************************************************************/

#ifndef MSPI_INTERFACE_H
#define MSPI_INTERFACE_H

void MSPI_voidinit(void);
void MSPI_voidSendCharSynch(u8 MSPI_u8DataTransmit);
u8 MSPI_u8ReceiveCharSynch(void);
void MSPI_voidSetCallBack( void (*ptr) (void) );





#define MASTER     0
#define SLAVE      1

#define Full_Duplex 0
#define Half_Duplex 1

#define CRC_Disable 0
#define CRC_Enable  1

#define _8bits_Frame  0
#define _16bits_Frame 1


#define Broadcast_Disable  0
#define Broadcast_Enable   1

typedef enum
{
  CPHA,
  CPOL,
  MSTR,
  BR_0,
  BR_1,
  BR_2,
  SPE,
  LSB_FIRST,
  SSI,
  SSM,// if enabled by 1, then SSI connected internally to NSS pin and ignored
  // any values coming from other nodes , so in this case SSI should be 0
  //to select this node as slave  or you can keep it 1  as master , this way to save wires
  RX_ONLY,
  DFF,
  CRC_NEXT,
  CRC_EN,
  BIDIOE,
  BIDIMODE

}MSPI_CR1_Bits;


typedef enum
{
  RXDMAEN,
  TXDMAEN,
  SSOE,
  RES_3,
  RES_4,
  ERRIE,
  RXNEIE,
  TXEIE

}MSPI_CR2_Bits;


typedef enum
{
  RXNE,
  TXE,
  CHSIDE,
  UDR,
  CRC_ERR,
  MODF,
  OVR,
  BSY

}MSPI_SR_Bits;

#endif
