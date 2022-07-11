/*
 * main.c
 *
 *  Created on: Jul 7, 2022
 *      Author: Haitham Hamdy
 */

//   u32 arr1[1000]={0};
//   u32 arr2[1000];
//
//   u32 arr3[1000]={0};
//   u32 arr4[1000];
//   // enable systick
//   // enable RCC for DMA on AHB
//   // DMA channel init
//   // enable interrupt NVIC
//   // channel start ( arr1 , arr2 , 1000)-->  DMA peripheral
//   // note : DMA should start before CPU
//   // for loop arr4[i]= arr3[i]  --> CPU

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSCB_interface.h"
#include "MNVIC_interface.h"
#include "SYSTICK_INTERFACE.h"
#include "MDMA_interface.h"

void light1 (void)
{
	MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_HIGH);

}


void light2 (void)
{
	MGPIO_voidSetPinValue(PORTA, PIN1, MGPIO_HIGH);

}
int main()
{
	u32 arr1[10]={10,20,30,40,50,10,20,30,40,50};
	u32 arr2[10];

	u32 arr3[10]={90,60,30,10,90,60,30,10,120,150};
	u32 arr4[10];

	MRCC_voidInitSysClk();
	MRCC_voidEnableAHBClk(DMA1EN);
	MRCC_voidEnableAPB2Clk(IOPAEN);
	MSTK_VidInit();

	 MGPIO_voidSetPinDirection(PORTA,PIN0, OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
	 MGPIO_voidSetPinDirection(PORTA,PIN1, OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);



	MNVIC_voidSetEnableINT(11); // DMA1_CHANNEL1_IRQHandler
	MNVIC_voidSetEnableINT(12); // DMA1_CHANNEL2_IRQHandler
	MNVIC_voidSetEnableINT(13); // DMA1_CHANNEL3_IRQHandler
	MNVIC_voidSetEnableINT(14); // DMA1_CHANNEL4_IRQHandler
	MNVIC_voidSetEnableINT(15); // DMA1_CHANNEL5_IRQHandler
	MNVIC_voidSetEnableINT(16); // DMA1_CHANNEL6_IRQHandler
	MNVIC_voidSetEnableINT(17); // DMA1_CHANNEL7_IRQHandler


	MDMA_voidCHSelect(2);

	MDMA_voidCHannelInit();
	MDMA_voidCHannelStart(arr1, arr2, 10);
	MDMA_VoidSetCallBackCH2(light1);


	MDMA_voidCHSelect(5);

		MDMA_voidCHannelInit();
		MDMA_voidCHannelStart(arr3, arr4, 10);
		MDMA_VoidSetCallBackCH5(light2);

//	for(u8 i=0; i<=10;i++)
//	{
//		arr4[i]=arr3[i];
//	}







	while(1)
	{
		//light();

		//MGPIO_voidSetPinValue(PORTA, PIN1, MGPIO_HIGH);
		//MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_HIGH);




//
//		if(arr2[2]==30)
//		{
//			MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_HIGH);
//		}
//		//MDMA_VoidSetCallBack(light, 1);
//			// MGPIO_voidSetPinValue(PORTA, PIN1, MGPIO_HIGH);
//
//			// MGPIO_voidSetPinValue(PORTA, PIN0, MGPIO_HIGH);

	}
	return 0;
}
