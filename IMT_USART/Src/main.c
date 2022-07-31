/*
 * main.c
 *
 *  Created on: Jul 17, 2022
 *      Author: Haitham Hamdy
 */
#include <stdio.h>
#include <string.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_interface.h"
#include "MSCB_interface.h"
#include "MAFIO_interface.h"
#include "MSTK_interface.h"
#include "MUSART_interface.h"


int main ()
{
	u8 * arr2;

	MRCC_voidInitSysClk();
	MRCC_voidEnableAPB2Clk(IOPAEN);
	MRCC_voidEnableAPB2Clk(USART1EN);
	MRCC_voidEnableAPB2Clk(AFIOEN);
	MSTK_voidSystickInit();


	MGPIO_voidSetPinDirection(PORTA, PIN0, OUTPUT_MAX_2_MHZ, GP_PUSH_PULL_OUTPUT);
	MGPIO_voidSetPinDirection(PORTA, PIN10, INPUT_MODE, Floating_INPUT); //RX WORKING
	//MGPIO_voidSetPinDirection(PORTA, PIN10, OUTPUT_MAX_2_MHZ, AF_PUSH_PULL_OUTPUT);//RX WORKING

	MGPIO_voidSetPinDirection(PORTA, PIN9, OUTPUT_MAX_2_MHZ, AF_PUSH_PULL_OUTPUT);//TX

	MNVIC_voidSetEnableINT(37);

	MUSART_voidInit();
//	u8 arr1[20]={"hello UART\r\n"};// \r is carriage return and \n is new line or line feed
//	u8 bytelettre='0';


	while(1)
	{
//		MUSART_voidSendString(arr1);
//		MSTK_voidDelay(1000);
//	    bytelettre=MUSART_u8ReceiveChar();
//		if(bytelettre=='5')
//		{
//		  	MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_HIGH);
//		}
//		else if (bytelettre=='4')
//		{
//           MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_LOW);
//		}

	    arr2=MUSART_u8ptrReceiveString();
    	MUSART_voidSendString(arr2);
    	MUSART_voidSendString((u8 *)"  \r\n");


	    if( ( strcmp((const char *)"IMT",(const char *)arr2) ) ==0)
	    {
	    	MUSART_voidSendString((u8 *)"identical\r\n");
	    	MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_HIGH);

	    }
	    else
	    {
	    	MUSART_voidSendString((u8 *)"NOT identical\r\n");
	    	MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_LOW);

	    }




		//MUSART1_VoidSetCallBack(light_1);


	}
	return 0;
}
