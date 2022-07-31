/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: Haitham Hamdy
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSTK_interface.h"
#include "HSTP_interface.h"

int main()
{

  MRCC_voidInitSysClk();
  MRCC_voidEnableAPB2Clk(IOPAEN);
  MSTK_voidSystickInit();

  MGPIO_voidSetPinDirection(PORTA,PIN0, OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(PORTA,PIN1, OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(PORTA,PIN2, OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);

  //HSTP_VoidSendSynchronus(0xAA);

  u8 i=0;


	while(1)
	{
		for(i=0;i<8;i++)
		{
			HSTP_VoidSendSynchronus(1<<i);
			   MSTK_voidDelay(300000);


		}

	}
	return 0;
}
