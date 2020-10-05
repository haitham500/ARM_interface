/*
 * main.c
 *
 *  Created on: Oct 4, 2020
 *      Author: DELL
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"

	u16 w = 500 ;

int main (void)
{


	 MRCC_voidInitSysClk();

	MRCC_voidEnableAPB2Clk(IOPAEN);
	MRCC_voidEnableAPB2Clk(IOPBEN);
	MRCC_voidEnableAPB2Clk(IOPCEN);


		MGPIO_voidSetPinDirection(PORTA,PIN0, INPUT_MODE,PU_PD_INPUT);
        MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_HIGH);

        MGPIO_voidSetPinDirection(PORTA,PIN1, OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
		MGPIO_voidSetPinDirection(PORTA,PIN2, OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
		MGPIO_voidSetPinValue(PORTA, PIN1, MGPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA, PIN2, MGPIO_HIGH);









	while(1)
	{

		MGPIO_voidSetPinValue(PORTA, PIN1, MGPIO_HIGH);
		for(int i = 0 ; i < w ; i++ )
			 		{
			 			for(int j = 0 ; j < w ; j++ )
			 			{
			 				asm("NOP");
			 			}
			 		}

		if(MGPIO_u8GetPinValue(PORTA, PIN0)==0)
		{
			MGPIO_voidSetPinValue(PORTA, PIN2, MGPIO_HIGH);

		}
		else
		{
			MGPIO_voidSetPinValue(PORTA, PIN2, MGPIO_LOW);

		}

	}
	return 0;
}

