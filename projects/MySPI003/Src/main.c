/*
 * main.c
 *
 *  Created on: Aug 2, 2022
 *      Author: Haitham Hamdy
 *      project: draw image from Blue pill Board STM32F103C8T6 to
 *      TFT Display 1.8" ST7735S through SPI protocol communication
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MAFIO_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_interface.h"
#include "MRCC_interface.h"
#include "MSCB_interface.h"
#include "MSPI_interface.h"
#include "MSTK_interface.h"

#include "HTFT_interface.h"
#include "Images.h"

int main(void)
{
	MRCC_voidInitSysClk();
	MRCC_voidEnableAPB2Clk(IOPAEN);
	MRCC_voidEnableAPB2Clk(SPI1EN);


	MGPIO_voidSetPinDirection(PORTA, PIN5, OUTPUT_MAX_10_MHZ, AF_PUSH_PULL_OUTPUT);
	MGPIO_voidSetPinDirection(PORTA, PIN7, OUTPUT_MAX_10_MHZ, AF_PUSH_PULL_OUTPUT);

	MGPIO_voidSetPinDirection(PORTA, PIN1, OUTPUT_MAX_10_MHZ, GP_PUSH_PULL_OUTPUT);
	MGPIO_voidSetPinDirection(PORTA, PIN2, OUTPUT_MAX_10_MHZ, GP_PUSH_PULL_OUTPUT);




	MSTK_voidSystickInit();
	MSPI_voidinit();
	HTFT_voidInit();
	HTFT_voidFillImage(image);




	while(1)
	{

	}
	return 0;
}
