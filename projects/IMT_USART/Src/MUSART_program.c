/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 17 Jul 2022                                          */
/* Version     : V01                                                  */
/**********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MUSART_interface.h"
#include "MUSART_private.h"
#include "MUSART_config.h"

//https://www.youtube.com/playlist?list=PLtVUYRe-Z-mcjXXFBte61L8SjyI377VNq STM32F1 Tutorial

void (*MUSART1_CallBack)(void);
void (*MUSART2_CallBack)(void);
void (*MUSART3_CallBack)(void);

u8 DataString[20];
#define THRESHOLD_VALUE  9000000UL




void MUSART_voidInit(void)
{
	MUSART->MUSART_SR=0x0;


	CLR_BIT(MUSART->MUSART_CR1,M);  // word length 8

	CLR_BIT(MUSART->MUSART_CR1,PCE);// disable parity control check

	CLR_BIT(MUSART->MUSART_CR2,STOP_0);//Select stop bits for 1 one stop bit
	CLR_BIT(MUSART->MUSART_CR2,STOP_1);//Select stop bits for 1 one stop bit

	CLR_BIT(MUSART->MUSART_CR2,CLK_EN);// disable clock



	CLR_BIT(MUSART->MUSART_CR1,TXEIE); // disable interrupt for transmission register empty
	CLR_BIT(MUSART->MUSART_CR1,TCIE);  // disable interrupt for transmission complete
	CLR_BIT(MUSART->MUSART_CR1,RXNEIE);// disable interrupt for receiver register not empty

	MUSART->MUSART_BRR = 0x341; // baud rate for 9600bps / 8 MHz

	SET_BIT(MUSART->MUSART_CR1,TE); // transmitter enable , you have to configure pin as AF_PP_output
	SET_BIT(MUSART->MUSART_CR1,RE); // receiver enable , you have to configure pin as input

	SET_BIT(MUSART->MUSART_CR1,UE); // enable MUSART


}

void MUSART_voidSendChar (u8 MUSART_u8CharData)
{
	MUSART->MUSART_DR=MUSART_u8CharData;
	while( (GET_BIT(MUSART->MUSART_SR,TC)==0) );

	CLR_BIT(MUSART->MUSART_SR,TC);// clear bit of transmission complete

}
void MUSART_voidSendString (u8 * MUSART_ptrString)
{
	u8 LOC_u8Iterator = 0 ;

	while ( MUSART_ptrString[ LOC_u8Iterator ] != '\0' ){

		MUSART_voidSendChar( MUSART_ptrString[ LOC_u8Iterator ] );
		LOC_u8Iterator++ ;

	}
}

u8 MUSART_u8ReceiveChar (void)
{
	u8 _u8LocalData=0;
	u32 LOC_TimeOut = 0 ;
	CLR_BIT(MUSART->MUSART_SR,RXNE);

	while( (GET_BIT(MUSART->MUSART_SR,RXNE)==0)&& ( LOC_TimeOut < THRESHOLD_VALUE ) ) // wait till receiver data register not empty (complete)
	{
		LOC_TimeOut++;
	}
	if( LOC_TimeOut == THRESHOLD_VALUE )
	{
		_u8LocalData = 255;
	}
	else
	{

		_u8LocalData=MUSART->MUSART_DR;
	}

	return _u8LocalData;

}
u8 * MUSART_u8ptrReceiveString (void)
{
	u8 LOC_u8Iterator = 0 ;
	u8 LOC_u8DataCome;
	while (  ( LOC_u8DataCome= MUSART_u8ReceiveChar() )  != 13)
	{
		DataString[LOC_u8Iterator]=LOC_u8DataCome;
		LOC_u8Iterator++;
	}
	DataString[LOC_u8Iterator]='\0';
	return (DataString);

}



////////////////////////////ch 1  interrupt handler ///////////////////
void MUSART1_VoidSetCallBack( void (*ptr) (void) )
{
	MUSART1_CallBack = ptr ;
}

void USART1_IRQHandler(void)
{
	MUSART->MUSART_SR = 0x0 ;
	MUSART1_CallBack();
}

////////////////////////////ch 2  interrupt handler ///////////////////
void MUSART2_VoidSetCallBack( void (*ptr) (void) )
{
	MUSART2_CallBack = ptr ;
}

void USART2_IRQHandler(void)
{
	MUSART->MUSART_SR = 0x0 ;
	MUSART2_CallBack();
}
////////////////////////////ch 3  interrupt handler ///////////////////
void MUSART3_VoidSetCallBack( void (*ptr) (void) )
{
	MUSART3_CallBack = ptr ;
}

void USART3_IRQHandler(void)
{
	MUSART->MUSART_SR = 0x0 ;
	MUSART3_CallBack();
}



//
// void MUSART_voidInit(void)
// {
//   // 8MHz/ 9600   -> BRR= 0x342
//   // 8,000,000/(16*9600)=52.083333 => [DIV_Mantissa 0d52->0x34] & [DIV_Fraction 0.083333*16=1.333~= 0d1->0x1]
//   // USARTDIV = 0x341
//   // 8MHz/115200 -> BRR= 0x45
//
//   MUSART->MUSART_BRR = 0x341;
//   // enable TX
//   // enable RX
//   // enable MUSART
//   SET_BIT(MUSART->MUSART_CR1,2);
//   SET_BIT(MUSART->MUSART_CR1,3);
//   SET_BIT(MUSART->MUSART_CR1,13);
//   //status register cleared
//   MUSART->MUSART_SR=0x0;
// }
// void MUSART_voidTransmit (u8 arr[])
// {
//   u8 i =0;
//   while(arr[i] !='\0')
//   {
//     MUSART->MUSART_DR=arr[i];
//     while(GET_BIT(MUSART->MUSART_SR,6)==0); //transmittion complete
//     i++;
//   }
//
// }
// u8   MUSART_u8Receive (void)
// {
//   while(GET_BIT(MUSART->MUSART_SR,5)==0); //receive complete
//   return (0xFF & (MUSART->MUSART_DR));// masking to ensure that value has been returne in u8 type
//
// }
