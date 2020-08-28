/*
 * main.c
 *
 *  Created on: Aug 18, 2020
 *      Author: DELL
 */


#include  "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "MGPIO_interface.h"

void main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); // GPIOA


	RCC_voidEnableClock(RCC_APB2,3); // GPIOB


	RCC_voidEnableClock(RCC_APB2,4); // GPIOC

	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_10MHZ_PP);// PINA0 OUT PUSH PULL 10 MHz
	MGPIO_voidSetPinDirection(GPIOA, PIN1,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN2,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN3,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN4,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN5,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN6,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN7,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN8,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN9,OUTPUT_SPEED_10MHZ_PP);


	MGPIO_voidSetPinDirection(GPIOA, PIN10,INPUT_PULL_UP_DOWN);
	MGPIO_voidSetPinValue(GPIOA, PIN10, GPIO_HIGH);// for pull-up resistor



	MGPIO_voidSetPinDirection(GPIOA, PIN11,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN12,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN13,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN14,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN15,OUTPUT_SPEED_10MHZ_PP);



	MGPIO_voidSetPinDirection(GPIOB, PIN0,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN1,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN2,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN3,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN4,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN5,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN6,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN7,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN8,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN9,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN10,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN11,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN12,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN13,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN14,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOB, PIN15,OUTPUT_SPEED_10MHZ_PP);

	u16 w = 500 ;

	while(1)
	{

		 MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_LOW);
		 MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_LOW);
		 MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOA, PIN7, GPIO_HIGH);
	//	 MGPIO_voidSetPinValue(GPIOA, PIN8, GPIO_HIGH);
	//	 MGPIO_voidSetPinValue(GPIOA, PIN9, GPIO_HIGH);
	//	 MGPIO_voidSetPinValue(GPIOA, PIN10, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOA, PIN11, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOA, PIN12, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOA, PIN13, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOA, PIN14, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOA, PIN15, GPIO_HIGH);

		 MGPIO_voidSetPinValue(GPIOB, PIN0, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN1, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN2, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN3, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN4, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN5, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN6, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN7, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN8, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN9, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN10, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN11, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN12, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN13, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN14, GPIO_HIGH);
		 MGPIO_voidSetPinValue(GPIOB, PIN15, GPIO_HIGH);


		 MGPIO_voidSetPinValue(GPIOA, PIN8, GPIO_HIGH);
		 		for(int i = 0 ; i < w ; i++ )
		 		{
		 			for(int j = 0 ; j < w ; j++ )
		 			{
		 				asm("NOP");
		 			}
		 		}
				 MGPIO_voidSetPinValue(GPIOA, PIN8, GPIO_LOW);
		 		for(int i = 0 ; i < w ; i++ )
		 		{
		 				for(int j = 0 ; j < w ; j++ )
		 				{
		 						asm("NOP");
		 				}
		 		}

		 		if(MGPIO_u8GetPinValue(GPIOA, PIN10)== 0)
		 		{
		 		 MGPIO_voidSetPinValue(GPIOA, PIN9, GPIO_HIGH);

		 		}
		 		else
		 		{
		 		 MGPIO_voidSetPinValue(GPIOA, PIN9, GPIO_LOW);
		 		}


	}

}



/*
#define  PORTA_CRL *((u32*)0x40010800)
#define  PORTA_ODR *((u32*)0x4001080C)

*/
//void main(void)
//{

	// Initialize clock system
//	RCC_voidInitSysClock();

	//enable peripheral 2 on APB2 bus(GPIOA)
	//RCC_voidEnableClock(RCC_APB2, 2);

	// Configure A0 as output push pull
	//PORTA_CRL=0x00000002;


	// configure A0 as output high
	//PORTA_ODR=0x00000001;

	//while(1)
	//{

//	}
//}

