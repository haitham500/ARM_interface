/*
 * main.c
 *
 *  Created on: Dec 24, 2020
 *      Author: Haitham Hamdy
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSTK_interface.h"

#include "HLEDMRX_interface.h"


//u8 DataArray0[8]= {0, 126, 24, 126, 0, 126, 18, 126};//H and A
//u8 DataArray1[8]={0, 126, 18, 126, 0, 66, 126, 66};//A and I
//u8 DataArray2[8]={0, 66, 126, 66, 0, 2, 126, 2};//I and T
//u8 DataArray3[8]={0, 2, 126, 2, 0, 126, 24, 126};//T and H
//u8 DataArray4[8]={0, 126, 24, 126, 0, 126, 18, 126};//H and A
//u8 DataArray5[8]={0, 126, 10, 126, 0, 126, 2, 126};//A and part of M
//u8 DataArray6[8]={0, 0, 0, 126, 2, 126, 2, 126};//M

u8 DataArray[47]={0, 126, 24, 24, 126, 0, 0, 126, 18, 18, 126, 0, 0, 66, 66, 126, 66, 66, 0, 0, 2, 2, 126, 2, 2, 0, 0, 126, 24, 24, 126, 0, 0, 126, 18, 18, 126, 0, 0, 126, 2, 6, 60, 6, 2, 126, 0};


int main(void)
{
	MRCC_voidInitSysClk();
	MRCC_voidEnableAPB2Clk(IOPAEN);
	MRCC_voidEnableAPB2Clk(IOPBEN);

	MSTK_voidInitSysTick();

	HLEDMRX_voidInit();





	while(1)
	{

 HLEDMRX_voidDisplay(DataArray,47);





	}
	return 0;

}
