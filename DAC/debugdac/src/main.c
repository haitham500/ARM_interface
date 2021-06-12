/*
 * main.c
 *
 *  Created on: Jun 12, 2021
 *      Author: Haitham Hamdy
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MRCC_interface.h"
//#include "MGPIO_interface.h"
//#include "SYSTICK_INTERFACE.h"
#include "MDAC_interface.h"


int main(void)
{
	MRCC_voidInitSysClk();
	MRCC_voidEnableAPB2Clk(IOPAEN);

	MDAC_voidInit();
	MDAC_voidPlay();


	while(1);
	return 0;
}
