/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 16 Jul 2022                                          */
/* Version     : V01                                                  */
/**********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSPI_interface.h"
#include "MSPI_private.h"
#include "MSPI_config.h"

void (*MSPI_CallBack)(void);

void MSPI_voidinit(void)
{
  CLR_BIT(MSPI->MSPI_CR1,SPE);//disable SPI

  CLR_BIT(MSPI->MSPI_CR1,CPHA);//The second clock transition is(read) the first data capture edge
  // this mean that write in first transition
  CLR_BIT(MSPI->MSPI_CR1,CPOL);//idle state is high for clock
  //high state-> falling edge(write)->Low state->Rising edge(read)

  #if Master_Slave==MASTER
  SET_BIT(MSPI->MSPI_CR1,MSTR);//select as master
  SET_BIT(MSPI->MSPI_CR2, SSOE ),

  #elif Master_Slave==SLAVE
  CLR_BIT(MSPI->MSPI_CR1,MSTR);//select as slave
  #endif

  //Baud rate control =FPCLK/4 -> 0b001
  SET_BIT(MSPI->MSPI_CR1,BR_0);
  CLR_BIT(MSPI->MSPI_CR1,BR_1);
  CLR_BIT(MSPI->MSPI_CR1,BR_2);

  CLR_BIT(MSPI->MSPI_CR1,LSB_FIRST);// send MSB firstly

  CLR_BIT(MSPI->MSPI_CR1,SSM);//disable SW slave management, so SSI bit neglected
  //NSS pin working by HardWare effect

  #if CRC == CRC_Enable
  SET_BIT(MSPI->MSPI_CR1,CRC_EN);
  SET_BIT(MSPI->MSPI_CR1,CRC_NEXT);
  #elif CRC == CRC_Disable
  CLR_BIT(MSPI->MSPI_CR1,CRC_EN);
  #endif

  #if Direction==Full_Duplex
  CLR_BIT(MSPI->MSPI_CR1,BIDIMODE);
  #elif Direction==Half_Duplex
  SET_BIT(MSPI->MSPI_CR1,BIDIMODE); // you have to configure BIDIOE bit output enabled
  //to select transmit only or Receive only
  #endif

  #if Broadcasting==Broadcast_Enable
  SET_BIT(MSPI->MSPI_CR1,RX_ONLY);//connected with BIDIMODE and BIDIOE
  #elif Broadcasting==Broadcast_Disable
  CLR_BIT(MSPI->MSPI_CR1,RX_ONLY);
  #endif

  #if DataFrameFormat==_8bits_Frame
  CLR_BIT(MSPI->MSPI_CR1,DFF);
  #elif DataFrameFormat==_16bits_Frame
  SET_BIT(MSPI->MSPI_CR1,DFF);
  #endif
  ///interrupts
  SET_BIT(MSPI->MSPI_CR2,ERRIE);//enable interrupt for other errors
  SET_BIT(MSPI->MSPI_CR2,RXNEIE);//enable interrupt for Receive buffer empty
  SET_BIT(MSPI->MSPI_CR2,TXEIE);//enable interrupt for Transmit buffer empty

  SET_BIT(MSPI->MSPI_CR1,SPE);//enable SPI

}
void MSPI_voidSendCharSynch(u8 MSPI_u8DataTransmit)
{
  MSPI->MSPI_DR=(u8)MSPI_u8DataTransmit;
  while(GET_BIT(MSPI->MSPI_SR,BSY)==1);
  //Do not use the BSY flag to handle each data transmission or reception.
  // It is better to use the TXE and RXNE flags instead.
 // return (u8)MSPI->MSPI_DR;
}
u8 MSPI_u8ReceiveCharSynch(void)
{
	while(GET_BIT(MSPI->MSPI_SR,RXNE)==0);
	return (u8)MSPI->MSPI_DR;
}

void MSPI_voidSetCallBack( void (*ptr) (void) )
{
	MSPI_CallBack = ptr;
}

void SPI1_IRQHandler(void)
{
  	MSPI_CallBack();
}


//
// void MSPI_voidSendReceiveSynch (u8 MSPI_u8DataTransmit, u8 *MSPI_u8DataReceived );
// //this function will wait to receive data
//
// void MSPI_voidSendReceiveAsynch (u8 MSPI_u8DataTransmit, void (*callback)(u8 u8ReceivedData) );
// //this function will back to main code before receiving data ,where interrupt will call another function
// //to save received data
