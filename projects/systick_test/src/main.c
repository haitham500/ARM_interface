/*
 * main.c
 *
 *  Created on: Dec 9, 2020
 *      Author: Haitham Hamdy
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSTK_interface.h"
#include "MAFIO_interface.h"
#include "MEXTI_interface.h"
#include "MNVIC_interface.h"
#include "MSCB_interface.h"

void LightLEDLeftToRight(void)
{
	MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_HIGH);
	MSTK_voidSetBusyWait(200000);
	MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_LOW);
	MSTK_voidSetBusyWait(200000);

	MGPIO_voidSetPinValue(PORTA, PIN1, MGPIO_HIGH);
	MSTK_voidSetBusyWait(200000);
	MGPIO_voidSetPinValue(PORTA, PIN1, MGPIO_LOW);
	MSTK_voidSetBusyWait(200000);


	MGPIO_voidSetPinValue(PORTA, PIN2, MGPIO_HIGH);
	MSTK_voidSetBusyWait(200000);
	MGPIO_voidSetPinValue(PORTA, PIN2, MGPIO_LOW);
	MSTK_voidSetBusyWait(200000);

	MGPIO_voidSetPinValue(PORTA, PIN3, MGPIO_HIGH);
	MSTK_voidSetBusyWait(200000);
	MGPIO_voidSetPinValue(PORTA, PIN3, MGPIO_LOW);
	MSTK_voidSetBusyWait(200000);

	MGPIO_voidSetPinValue(PORTA, PIN4, MGPIO_HIGH);
	MSTK_voidSetBusyWait(200000);
	MGPIO_voidSetPinValue(PORTA, PIN4, MGPIO_LOW);
	MSTK_voidSetBusyWait(200000);

	MGPIO_voidSetPinValue(PORTA, PIN5, MGPIO_HIGH);
	MSTK_voidSetBusyWait(200000);
	MGPIO_voidSetPinValue(PORTA, PIN5, MGPIO_LOW);
	MSTK_voidSetBusyWait(200000);

	MGPIO_voidSetPinValue(PORTA, PIN6, MGPIO_HIGH);
	MSTK_voidSetBusyWait(200000);
	MGPIO_voidSetPinValue(PORTA, PIN6, MGPIO_LOW);
	MSTK_voidSetBusyWait(200000);

	MGPIO_voidSetPinValue(PORTA, PIN7, MGPIO_HIGH);
	MSTK_voidSetBusyWait(200000);
	MGPIO_voidSetPinValue(PORTA, PIN7, MGPIO_LOW);
	MSTK_voidSetBusyWait(200000);

}

void LightLEDInOut(void)
{
	MGPIO_voidSetPinValue(PORTA, PIN3, MGPIO_HIGH);
	MGPIO_voidSetPinValue(PORTA, PIN4, MGPIO_HIGH);
	MSTK_voidSetBusyWait(200000);

	MGPIO_voidSetPinValue(PORTA, PIN2, MGPIO_HIGH);
	MGPIO_voidSetPinValue(PORTA, PIN5, MGPIO_HIGH);
	MSTK_voidSetBusyWait(200000);

	MGPIO_voidSetPinValue(PORTA, PIN1, MGPIO_HIGH);
	MGPIO_voidSetPinValue(PORTA, PIN6, MGPIO_HIGH);
	MSTK_voidSetBusyWait(200000);

	MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_HIGH);
	MGPIO_voidSetPinValue(PORTA, PIN7, MGPIO_HIGH);
	MSTK_voidSetBusyWait(200000);


	MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_LOW);
	MGPIO_voidSetPinValue(PORTA, PIN7, MGPIO_LOW);
	MSTK_voidSetBusyWait(200000);


	MGPIO_voidSetPinValue(PORTA, PIN1, MGPIO_LOW);
	MGPIO_voidSetPinValue(PORTA, PIN6, MGPIO_LOW);
	MSTK_voidSetBusyWait(200000);


	MGPIO_voidSetPinValue(PORTA, PIN2, MGPIO_LOW);
	MGPIO_voidSetPinValue(PORTA, PIN5, MGPIO_LOW);
	MSTK_voidSetBusyWait(200000);

	MGPIO_voidSetPinValue(PORTA, PIN3, MGPIO_LOW);
	MGPIO_voidSetPinValue(PORTA, PIN4, MGPIO_LOW);
	MSTK_voidSetBusyWait(200000);
}

void LightLEDFlashing(void)
{
	MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_HIGH);
	MGPIO_voidSetPinValue(PORTA, PIN1, MGPIO_HIGH);
	MGPIO_voidSetPinValue(PORTA, PIN2, MGPIO_HIGH);
	MGPIO_voidSetPinValue(PORTA, PIN3, MGPIO_HIGH);
	MGPIO_voidSetPinValue(PORTA, PIN4, MGPIO_HIGH);
	MGPIO_voidSetPinValue(PORTA, PIN5, MGPIO_HIGH);
	MGPIO_voidSetPinValue(PORTA, PIN6, MGPIO_HIGH);
	MGPIO_voidSetPinValue(PORTA, PIN7, MGPIO_HIGH);
	MSTK_voidSetBusyWait(500000);


	MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_LOW);
	MGPIO_voidSetPinValue(PORTA, PIN1, MGPIO_LOW);
	MGPIO_voidSetPinValue(PORTA, PIN2, MGPIO_LOW);
	MGPIO_voidSetPinValue(PORTA, PIN3, MGPIO_LOW);
	MGPIO_voidSetPinValue(PORTA, PIN4, MGPIO_LOW);
	MGPIO_voidSetPinValue(PORTA, PIN5, MGPIO_LOW);
	MGPIO_voidSetPinValue(PORTA, PIN6, MGPIO_LOW);
	MGPIO_voidSetPinValue(PORTA, PIN7, MGPIO_LOW);
	MSTK_voidSetBusyWait(500000);



}




int main(void)
{

	MRCC_voidInitSysClk();
	MRCC_voidEnableAPB2Clk(IOPAEN);
	MRCC_voidEnableAPB2Clk(IOPBEN);

	MSTK_voidInitSysTick();


	MGPIO_voidSetPinDirection(PORTA, PIN0, OUTPUT_MAX_10_MHZ, GP_PUSH_PULL_OUTPUT);
	MGPIO_voidSetPinDirection(PORTA, PIN1, OUTPUT_MAX_10_MHZ, GP_PUSH_PULL_OUTPUT);
	MGPIO_voidSetPinDirection(PORTA, PIN2, OUTPUT_MAX_10_MHZ, GP_PUSH_PULL_OUTPUT);
	MGPIO_voidSetPinDirection(PORTA, PIN3, OUTPUT_MAX_10_MHZ, GP_PUSH_PULL_OUTPUT);
	MGPIO_voidSetPinDirection(PORTA, PIN4, OUTPUT_MAX_10_MHZ, GP_PUSH_PULL_OUTPUT);
	MGPIO_voidSetPinDirection(PORTA, PIN5, OUTPUT_MAX_10_MHZ, GP_PUSH_PULL_OUTPUT);
	MGPIO_voidSetPinDirection(PORTA, PIN6, OUTPUT_MAX_10_MHZ, GP_PUSH_PULL_OUTPUT);
	MGPIO_voidSetPinDirection(PORTA, PIN7, OUTPUT_MAX_10_MHZ, GP_PUSH_PULL_OUTPUT);

	MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_HIGH);




	while(1)
	{

		u8 local_count;
		for(local_count=0;local_count<=3;++local_count)
		{
			LightLEDLeftToRight();
		}


		for(local_count=0;local_count<=3;++local_count)
		{
			LightLEDInOut();
		}


		for(local_count=0;local_count<=7;++local_count)
		{
			LightLEDFlashing();
		}



	}
	return 0;
}
