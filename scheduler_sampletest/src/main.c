/*
 * main.c
 *
 *  Created on: Jun 7, 2021
 *      Author: Haitham Hamdy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MGPIO_private.h"

#include "SYSTICK_INTERFACE.h"

#include "OS_interface.h"


void LED1 ( void );
void LED2 ( void );
void LED3 ( void );

int main(void)
{
	MRCC_voidInitSysClk();

	MRCC_voidEnableAPB2Clk(IOPAEN); // enable clock system for port A



	MGPIO_voidSetPinDirection(PORTA, PIN0, OUTPUT_MAX_2_MHZ, GP_PUSH_PULL_OUTPUT );
	MGPIO_voidSetPinDirection(PORTA, PIN1, OUTPUT_MAX_2_MHZ, GP_PUSH_PULL_OUTPUT );
	MGPIO_voidSetPinDirection(PORTA, PIN2, OUTPUT_MAX_2_MHZ, GP_PUSH_PULL_OUTPUT );


	SOS_voidCreateTask( 0 , 1000 , LED1 , 0 );
	SOS_voidCreateTask( 1 , 2000 , LED2 , 0 );
	SOS_voidCreateTask( 2 , 3000 , LED3 , 0 );

	SOS_voidStart();


	while(1)
	{

	}
	return 0;
}



void LED1 ( void ){

	TOG_BIT( MGPIOA->MGPIOA_ODR , PIN0 );




}

void LED2 ( void ){

	TOG_BIT( MGPIOA->MGPIOA_ODR , PIN1 );

}

void LED3 ( void ){

	TOG_BIT( MGPIOA->MGPIOA_ODR , PIN2 );

}

