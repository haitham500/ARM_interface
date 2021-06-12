/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "TYPES.h"

#include "RCC_INTERFACE.h"

#include "DAC_INTERFACE.h"

//  1-Connect PORTA LOW with 8Bit DAC
//  2-Connect The Output Of the DAC  To The POT
//  3-Connect the Divider Of The POT To The input of amplifier
//  4-Connect The Output Of The Amplifier To The bread board
//  5-Then We Connect The Left & Right headphone Pins With The Output Of The Amplifier In The BreadBoard


//                             DAC CODE 2amren Dol Wla 3neh Song


int main (void){

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOA_RCC );

	MDAC_VidInit();

	MDAC_VidPlay();

	while(1);

	return 0;
}


