/*
 * main.c
 *
 *  Created on: Aug 21, 2020
 *      Author: DELL
 */





#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"



int main(void)
{
	RCC_voidInitSysClock();
	/*Enable RCC for GPIOA*/
	RCC_voidEnableClock(RCC_APB2 , 2);
	/*Enable RCC for GPIOB*/
	RCC_voidEnableClock(RCC_APB2 , 3);
	/*Enable RCC for GPIOC*/
	RCC_voidEnableClock(RCC_APB2 , 4);

	 /*PINA0 output push pull  10 MHz*/
	MGPIO_VidSetPinDirection(GPIOA , PIN0 , INPUT_PULLUP_PULLDOWN);
	/*	For Pull-up	*/
	MGPIO_VidSetPinValue(GPIOA , PIN0 , HIGH);


	MGPIO_VidSetPinDirection(GPIOA , PIN1 , OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA , PIN2 , OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA , PIN3 , OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA , PIN4 , OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA , PIN5 , OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA , PIN6 , OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA , PIN7 , OUTPUT_SPEED_10MHZ_PP);

u16 w = 500 ;
	while(1)
	{

		if(MGPIO_u8GetPinValue(GPIOA , PIN0) == 0)
		{
			MGPIO_VidSetPinValue(GPIOA , PIN1 , HIGH);
		}
		else
		{
			MGPIO_VidSetPinValue(GPIOA , PIN1 , LOW);
		}


		MGPIO_VidSetPinValue(GPIOA , PIN2 , HIGH);
		for(int i = 0 ; i < w ; i++ )
		{
			for(int j = 0 ; j < w ; j++ )
			{
				asm("NOP");
			}
		}
		MGPIO_VidSetPinValue(GPIOA , PIN2 , LOW);
		for(int i = 0 ; i < w ; i++ )
		{
				for(int j = 0 ; j < w ; j++ )
				{
						asm("NOP");
				}
		}

	}
	return 0 ;
}
