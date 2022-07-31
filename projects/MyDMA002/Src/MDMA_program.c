/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 04 Jul 2022                                          */
/* Version     : V01                                                  */
/**********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MDMA_interface.h"
#include "MDMA_private.h"
#include "MDMA_config.h"

void (*MDMA_callBackCH1)(void);
void (*MDMA_callBackCH2)(void);
void (*MDMA_callBackCH3)(void);
void (*MDMA_callBackCH4)(void);
void (*MDMA_callBackCH5)(void);
void (*MDMA_callBackCH6)(void);
void (*MDMA_callBackCH7)(void);

//u32 CH_REG[4];
volatile u32 *MDMA_CCR  ;
volatile u32 *MDMA_CNDTR;
volatile u32 *MDMA_CPAR ;
volatile u32 *MDMA_CMAR ;


void MDMA_voidCHSelect (u8 CHannel_ID)
{
  switch (CHannel_ID)
   {
     case 1:
     MDMA_CCR  =& MDMA->MDMA_CCR1;
     MDMA_CNDTR=& MDMA->MDMA_CNDTR1;
     MDMA_CPAR =& MDMA->MDMA_CPAR1;
     MDMA_CMAR =& MDMA->MDMA_CMAR1;
     break;
     case 2:
     MDMA_CCR  =& MDMA->MDMA_CCR2;
     MDMA_CNDTR=& MDMA->MDMA_CNDTR2;
     MDMA_CPAR =& MDMA->MDMA_CPAR2;
     MDMA_CMAR =& MDMA->MDMA_CMAR2;
     break;
     case 3:
     MDMA_CCR  =& MDMA->MDMA_CCR3;
     MDMA_CNDTR=& MDMA->MDMA_CNDTR3;
     MDMA_CPAR =& MDMA->MDMA_CPAR3;
     MDMA_CMAR =& MDMA->MDMA_CMAR3;
     break;
     case 4:
     MDMA_CCR  =& MDMA->MDMA_CCR4;
     MDMA_CNDTR=& MDMA->MDMA_CNDTR4;
     MDMA_CPAR =& MDMA->MDMA_CPAR4;
     MDMA_CMAR =& MDMA->MDMA_CMAR4;
     break;
     case 5:
     MDMA_CCR  =& MDMA->MDMA_CCR5;
     MDMA_CNDTR=& MDMA->MDMA_CNDTR5;
     MDMA_CPAR =& MDMA->MDMA_CPAR5;
     MDMA_CMAR =& MDMA->MDMA_CMAR5;
     break;
     case 6:
     MDMA_CCR  =& MDMA->MDMA_CCR6;
     MDMA_CNDTR=& MDMA->MDMA_CNDTR6;
     MDMA_CPAR =& MDMA->MDMA_CPAR6;
     MDMA_CMAR =& MDMA->MDMA_CMAR6;
     break;
     case 7:
     MDMA_CCR  =& MDMA->MDMA_CCR7;
     MDMA_CNDTR=& MDMA->MDMA_CNDTR7;
     MDMA_CPAR =& MDMA->MDMA_CPAR7;
     MDMA_CMAR =& MDMA->MDMA_CMAR7;
     break;
     default:
    	 break;

   }

}

void MDMA_voidCHannelInit(void)
{

  CLR_BIT(*MDMA_CCR,EN);// disable channel
 // while(GET_BIT(*MDMA_CCR,EN)==1);
  SET_BIT(*MDMA_CCR,TCIE);// enable complete transfer interrupt
  SET_BIT(*MDMA_CCR,HTIE);// enable half transfer interrupt
  SET_BIT(*MDMA_CCR,TEIE);// enable error transfer interrupt
  SET_BIT(*MDMA_CCR,DIR); // read from memory

  CLR_BIT(*MDMA_CCR,CIRC), // disable circular transfer

  SET_BIT(*MDMA_CCR,PINC);// enable peripheral increment mode
  SET_BIT(*MDMA_CCR,MINC);// enable memory increment mode

  CLR_BIT(*MDMA_CCR,PSIZE_0);// assign size 32 bit for peripheral PSIZE=10
  SET_BIT(*MDMA_CCR,PSIZE_1);

  CLR_BIT(*MDMA_CCR,MSIZE_0);// assign size 32 bit for memory MSIZE=10
  SET_BIT(*MDMA_CCR,MSIZE_1);

  SET_BIT(*MDMA_CCR,PL_0);// set priority level very high PL = 11
  SET_BIT(*MDMA_CCR,PL_1);//

  SET_BIT(*MDMA_CCR,MEM2MEM);// enable memory to memory mode MEM2MEM=1

  SET_BIT(*MDMA_CCR,EN);


}

void MDMA_voidCHannelStart( u32 * MDMA_u32PtrSrcAdd, u32 * MDMA_u32PtrDestAdd ,u16 MDMA_u16BlockLength )
{
    //disable channel before start by clear bit in CCR
    // assign addresses of source and destination in CPAR and MDMA_CMAR
    // assign block length in CNDTR
    // enable the channel at the end

  CLR_BIT(*MDMA_CCR,EN); // disable channel
  *MDMA_CNDTR=MDMA_u16BlockLength;
  *MDMA_CMAR=(volatile u32 )MDMA_u32PtrSrcAdd;
  *MDMA_CPAR=(volatile u32 )MDMA_u32PtrDestAdd;

  SET_BIT(*MDMA_CCR,EN);

}

void MDMA_VoidSetCallBackCH1(void (*ptr)(void))
{
  MDMA_callBackCH1=ptr;
}

void DMA1_Channel1_IRQHandler(void)
{
  SET_BIT(MDMA->MDMA_IFCR,CGIF1);
  SET_BIT(MDMA->MDMA_IFCR,CTCIF1);
  SET_BIT(MDMA->MDMA_IFCR,CHTIF1);
  SET_BIT(MDMA->MDMA_IFCR,CTEIF1);
  CLR_BIT(*MDMA_CCR,EN); // disable channel


  MDMA_callBackCH1();
}


void MDMA_VoidSetCallBackCH2(void (*ptr)(void))
{
  MDMA_callBackCH2=ptr;
}


void DMA1_Channel2_IRQHandler (void)
{
	MDMA_callBackCH2();
  SET_BIT(MDMA->MDMA_IFCR,CGIF2);
  SET_BIT(MDMA->MDMA_IFCR,CTCIF2);
  SET_BIT(MDMA->MDMA_IFCR,CHTIF2);
  SET_BIT(MDMA->MDMA_IFCR,CTEIF2);
  CLR_BIT(*MDMA_CCR,EN); // disable channel


}


void MDMA_VoidSetCallBackCH3(void (*ptr)(void))
{
  MDMA_callBackCH3=ptr;
}

void DMA1_Channel3_IRQHandler (void)
{
	SET_BIT(MDMA->MDMA_IFCR,CGIF3);
	SET_BIT(MDMA->MDMA_IFCR,CTCIF3);
	SET_BIT(MDMA->MDMA_IFCR,CHTIF3);
	SET_BIT(MDMA->MDMA_IFCR,CTEIF3);
    CLR_BIT(*MDMA_CCR,EN); // disable channel


  MDMA_callBackCH3();
}


void MDMA_VoidSetCallBackCH4(void (*ptr)(void))
{
  MDMA_callBackCH4=ptr;
}

void DMA1_Channel4_IRQHandler (void)
{
	SET_BIT(MDMA->MDMA_IFCR,CGIF4);
	SET_BIT(MDMA->MDMA_IFCR,CTCIF4);
	SET_BIT(MDMA->MDMA_IFCR,CHTIF4);
	SET_BIT(MDMA->MDMA_IFCR,CTEIF4);
	CLR_BIT(*MDMA_CCR,EN); // disable channel


  MDMA_callBackCH4();
}


void MDMA_VoidSetCallBackCH5(void (*ptr)(void))
{
  MDMA_callBackCH5=ptr;
}

void DMA1_Channel5_IRQHandler (void)

{
  SET_BIT(MDMA->MDMA_IFCR,CGIF5);
  SET_BIT(MDMA->MDMA_IFCR,CTCIF5);
  SET_BIT(MDMA->MDMA_IFCR,CHTIF5);
  SET_BIT(MDMA->MDMA_IFCR,CTEIF5);
  CLR_BIT(*MDMA_CCR,EN); // disable channel

  MDMA_callBackCH5();
}


void MDMA_VoidSetCallBackCH6(void (*ptr)(void))
{
  MDMA_callBackCH6=ptr;
}

void DMA1_Channel6_IRQHandler (void)
{
  SET_BIT(MDMA->MDMA_IFCR,CGIF6);
  SET_BIT(MDMA->MDMA_IFCR,CTCIF6);
  SET_BIT(MDMA->MDMA_IFCR,CHTIF6);
  SET_BIT(MDMA->MDMA_IFCR,CTEIF6);
  CLR_BIT(*MDMA_CCR,EN); // disable channel

  MDMA_callBackCH6();
}


void MDMA_VoidSetCallBackCH7(void (*ptr)(void))
{
  MDMA_callBackCH7=ptr;
}

void DMA1_Channel7_IRQHandler (void)
{
  SET_BIT(MDMA->MDMA_IFCR,CGIF7);
  SET_BIT(MDMA->MDMA_IFCR,CTCIF7);
  SET_BIT(MDMA->MDMA_IFCR,CHTIF7);
  SET_BIT(MDMA->MDMA_IFCR,CTEIF7);
  CLR_BIT(*MDMA_CCR,EN); // disable channel

  MDMA_callBackCH7();
}

//
// void MDMA_voidCHannelInit(void)
// {
//   /*
//   1- mem to mem
//   2- priority very high
//   3  source size and destination size = 32 bit
//   4- MINC , PINC activated
//   5- no circular
//   6- direction
//   7- transfer interrupt enable
//
//   */
//   // CCR = > VALUE to configure each channel
//
// }
//
// void MDMA_voidCHannelStart(u32 * MDMA_u32PtrSrcAdd, u32 * MDMA_u32PtrDestAdd ,u16 MDMA_u16BlockLength )
// {
//   // disable channel before start by clear bit in CCR
//   // assign addresses of source and destination in CPAR and MDMA_CMAR
//   // assign block length in CNDTR
//   // enable the channel at the end
//
// }
//
// void DMA1_CHANNEL1_IRQHandler (void)
// {
//   /*
//   clear GIF , TCI
//   make break point to test which one is faster DMA or CPU
//
//   */
// }
//
// int main()
// {
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
//     while(1)
//   {
//
//   }
//   return 0;
// }
