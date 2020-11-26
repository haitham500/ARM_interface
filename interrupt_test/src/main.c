/*
 * main.c
 *
 *  Created on: Nov 24, 2020
 *      Author: Haitham Hamdy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MAFIO_interface.h"
#include "MSCB_interface.h"
#include "MEXTI_interface.h"
#include "MNVIC_interface.h"

u16 w=500;

void lightingLED_01 ()
{
    MGPIO_voidSetPinValue(PORTA, PIN2, MGPIO_HIGH);
    	for(int i = 0 ; i < w ; i++ )
				 		{
				 			for(int j = 0 ; j < w ; j++ )
				 			{
				 				asm("NOP");
				 			}
				 		}
    MGPIO_voidSetPinValue(PORTA, PIN2, MGPIO_LOW);
    for(int i = 0 ; i < w ; i++ )
    				 		{
    				 			for(int j = 0 ; j < w ; j++ )
    				 			{
    				 				asm("NOP");
    				 			}
    				 		}



}


void lightingLED_02 ()
{
    MGPIO_voidSetPinValue(PORTA, PIN3, MGPIO_HIGH);

	for(int i = 0 ; i < w ; i++ )
				 		{
				 			for(int j = 0 ; j < w ; j++ )
				 			{
				 				asm("NOP");
				 			}
				 		}
	MGPIO_voidSetPinValue(PORTA, PIN3, MGPIO_LOW);
		for(int i = 0 ; i < w ; i++ )
					 		{
					 			for(int j = 0 ; j < w ; j++ )
					 			{
					 				asm("NOP");
					 			}
					 		}



}

int main(void)
{

	MRCC_voidInitSysClk();
	MRCC_voidEnableAPB2Clk(IOPAEN);
	MRCC_voidEnableAPB2Clk(AFIOEN);


    MSCB_voidSetPriorityGroupControl();


    MGPIO_voidSetPinDirection(PORTA, PIN2, OUTPUT_MAX_2_MHZ, GP_PUSH_PULL_OUTPUT);
    MGPIO_voidSetPinDirection(PORTA, PIN3, OUTPUT_MAX_2_MHZ, GP_PUSH_PULL_OUTPUT);
//    MGPIO_voidSetPinDirection(PORTA, PIN4, OUTPUT_MAX_2_MHZ, GP_PUSH_PULL_OUTPUT);


    MGPIO_voidSetPinDirection(PORTA, PIN0, INPUT_MODE,PU_PD_INPUT);
    MGPIO_voidSetPinDirection(PORTA, PIN1, INPUT_MODE,PU_PD_INPUT);
//    MGPIO_voidSetPinDirection(PORTA, PIN5, INPUT_MODE,PU_PD_INPUT);

    MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_HIGH);
    MGPIO_voidSetPinValue(PORTA, PIN1, MGPIO_HIGH);
//    MGPIO_voidSetPinValue(PORTA, PIN5, MGPIO_HIGH);






    MNVIC_voidSetEnableINT(6); //EXTI 0
    MNVIC_voidSetPriorityINT(6,2,0);

    MNVIC_voidSetEnableINT(7); // EXTI 1
    MNVIC_voidSetPriorityINT(7,1,0);

 // MNVIC_voidSetPendingFlagINT(6);


    MAFIO_voidSelectEXTIPin(PORTA,PIN0);
    MAFIO_voidSelectEXTIPin(PORTA,PIN1);


    MEXTI_voidEnableEXTILine(MEXTI_LINE_0,MEXTI_FALLING_EDGE);
    MEXTI_voidEnableEXTILine(MEXTI_LINE_1,MEXTI_FALLING_EDGE);


    //if any switch was pressed ,the belonged function will run
    MEXTI_voidSetCallBack(lightingLED_01,MEXTI_LINE_0); // PA0--->PA2  EXTI_0
    MEXTI_voidSetCallBack(lightingLED_02,MEXTI_LINE_1); // PA1--->PA3  EXTI_1




	while(1)
	{
	  //  MGPIO_voidSetPinValue(PORTA, PIN1, MGPIO_HIGH);
	  //  MGPIO_voidSetPinValue(PORTA, PIN2, MGPIO_HIGH);


	}

	return 0;
}
