/*
 * main.c
 *
 *  Created on: May 24, 2021
 *      Author: Haitham Hamdy
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
//#include "MNVIC_interface.h"
//#include "MSCB_interface.h"
//#include "MEXTI_interface.h"
//#include "MAFIO_interface.h"



#include "IR_INTERFACE.h"

int main( void ){

	u8 LOC_u8DataCome = 0 ;

	MRCC_voidInitSysClk();
	MRCC_voidEnableAPB2Clk(IOPAEN); // enable clock system for port A
	MRCC_voidEnableAPB2Clk(IOPBEN); // enable clock system for port B
    MRCC_voidEnableAPB2Clk(AFIOEN); // enable clock system for alternative function IO




	MGPIO_voidSetPinDirection(PORTB, PIN5, OUTPUT_MAX_2_MHZ, GP_PUSH_PULL_OUTPUT ); //  red light of RGB LED
	MGPIO_voidSetPinDirection(PORTB, PIN6, OUTPUT_MAX_2_MHZ, GP_PUSH_PULL_OUTPUT ); //  green light of RGB LED
	MGPIO_voidSetPinDirection(PORTB, PIN7, OUTPUT_MAX_2_MHZ, GP_PUSH_PULL_OUTPUT ); //  blue light of RGB LED

	MGPIO_voidSetPinDirection(PORTB, PIN8, OUTPUT_MAX_2_MHZ, GP_PUSH_PULL_OUTPUT ); // normal LED
	MGPIO_voidSetPinDirection(PORTB, PIN9, OUTPUT_MAX_2_MHZ, GP_PUSH_PULL_OUTPUT ); // normal LED

	IR_VidInit                   (                                     );

	while(1){

		LOC_u8DataCome = IR_u8GetCode();

		switch( LOC_u8DataCome ){

		case POWER_BUTTON :

			MGPIO_voidSetPinValue(PORTB, PIN5, MGPIO_LOW);
			MGPIO_voidSetPinValue(PORTB, PIN6, MGPIO_LOW);
			MGPIO_voidSetPinValue(PORTB, PIN7, MGPIO_LOW);
			MGPIO_voidSetPinValue(PORTB, PIN8, MGPIO_LOW);
			MGPIO_voidSetPinValue(PORTB, PIN9, MGPIO_LOW);

			break;

		case ONE_BUTTON   : MGPIO_voidSetPinValue(PORTB, PIN8, MGPIO_HIGH);break;
		case TWO_BUTTON   : MGPIO_voidSetPinValue(PORTB, PIN9, MGPIO_HIGH);break;

		case THREE_BUTTON   : MGPIO_voidSetPinValue(PORTB, PIN8, MGPIO_LOW);break;
		case FOUR_BUTTON    : MGPIO_voidSetPinValue(PORTB, PIN9, MGPIO_LOW);break;

		case ZER0_BUTTON    :
			MGPIO_voidSetPinValue(PORTB, PIN5, MGPIO_HIGH);
			MGPIO_voidSetPinValue(PORTB, PIN6, MGPIO_LOW);
			MGPIO_voidSetPinValue(PORTB, PIN7, MGPIO_LOW);
			break;
		case RPT_BUTTON   :
			MGPIO_voidSetPinValue(PORTB, PIN5, MGPIO_LOW);
			MGPIO_voidSetPinValue(PORTB, PIN6, MGPIO_HIGH);
			MGPIO_voidSetPinValue(PORTB, PIN7, MGPIO_LOW);
			break;
		case USD_BUTTON   :
			MGPIO_voidSetPinValue(PORTB, PIN5, MGPIO_LOW);
			MGPIO_voidSetPinValue(PORTB, PIN6, MGPIO_LOW);
			MGPIO_voidSetPinValue(PORTB, PIN7, MGPIO_HIGH);
			break;

		}


	}

	return 0 ;

}
