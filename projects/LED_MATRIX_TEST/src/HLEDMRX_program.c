/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 22 Dec. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MSTK_interface.h"

#include "HLEDMRX_interface.h"
#include "HLEDMRX_private.h"
#include "HLEDMRX_config.h"



void HLEDMRX_voidInit(void)
{
  MGPIO_voidSetPinDirection(HLEDMRX_ROW0_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_ROW1_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_ROW2_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_ROW3_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_ROW4_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_ROW5_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_ROW6_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_ROW7_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);

  MGPIO_voidSetPinDirection(HLEDMRX_COL0_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_COL1_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_COL2_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_COL3_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_COL4_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_COL5_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_COL6_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(HLEDMRX_COL7_PIN,OUTPUT_MAX_2_MHZ,GP_PUSH_PULL_OUTPUT);

}

void HLEDMRX_voidDisplay(u8 *HLEDMRX_u8Data,u8 HLEDMRX_u8indx)
{


		for(u8 i=0;i<= HLEDMRX_u8indx;i++)
		{
			MSTK_voidSetBusyWait(20000);
			for (u8 j=0; j<8;j++)
			{
				MSTK_voidSetBusyWait(20000);

				 //column 0
				  HLEDMRX_DisableAllCOLs();
				  HLEDMRX_voidSetROWsValue(HLEDMRX_u8Data[i]);
				  MGPIO_voidSetPinValue(HLEDMRX_COL0_PIN,MGPIO_LOW);
				  MSTK_voidSetBusyWait(200);//2.5msec

				  //column 1
				  HLEDMRX_DisableAllCOLs();
				  HLEDMRX_voidSetROWsValue(HLEDMRX_u8Data[i+1]);
				  MGPIO_voidSetPinValue(HLEDMRX_COL1_PIN,MGPIO_LOW);
				  MSTK_voidSetBusyWait(200);//2.5msec

				  //column 2
				  HLEDMRX_DisableAllCOLs();
				  HLEDMRX_voidSetROWsValue(HLEDMRX_u8Data[i+2]);
				  MGPIO_voidSetPinValue(HLEDMRX_COL2_PIN,MGPIO_LOW);
				  MSTK_voidSetBusyWait(200);//2.5msec

				  //column 3
				  HLEDMRX_DisableAllCOLs();
				  HLEDMRX_voidSetROWsValue(HLEDMRX_u8Data[i+3]);
				  MGPIO_voidSetPinValue(HLEDMRX_COL3_PIN,MGPIO_LOW);
				  MSTK_voidSetBusyWait(200);//2.5msec

				  //column 4
				  HLEDMRX_DisableAllCOLs();
				  HLEDMRX_voidSetROWsValue(HLEDMRX_u8Data[i+4]);
				  MGPIO_voidSetPinValue(HLEDMRX_COL4_PIN,MGPIO_LOW);
				  MSTK_voidSetBusyWait(200);//2.5msec

				  //column 5
				  HLEDMRX_DisableAllCOLs();
				  HLEDMRX_voidSetROWsValue(HLEDMRX_u8Data[i+5]);
				  MGPIO_voidSetPinValue(HLEDMRX_COL5_PIN,MGPIO_LOW);
				  MSTK_voidSetBusyWait(200);//2.5msec

				  //column 6
				  HLEDMRX_DisableAllCOLs();
				  HLEDMRX_voidSetROWsValue(HLEDMRX_u8Data[i+6]);
				  MGPIO_voidSetPinValue(HLEDMRX_COL6_PIN,MGPIO_LOW);
				  MSTK_voidSetBusyWait(200);//2.5msec

				  //column 7
				  HLEDMRX_DisableAllCOLs();
				  HLEDMRX_voidSetROWsValue(HLEDMRX_u8Data[i+7]);
				  MGPIO_voidSetPinValue(HLEDMRX_COL7_PIN,MGPIO_LOW);
				  MSTK_voidSetBusyWait(200);//2.5msec
				  }
		}
}






static void HLEDMRX_DisableAllCOLs(void)
{
  MGPIO_voidSetPinValue(HLEDMRX_COL0_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(HLEDMRX_COL1_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(HLEDMRX_COL2_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(HLEDMRX_COL3_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(HLEDMRX_COL4_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(HLEDMRX_COL5_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(HLEDMRX_COL6_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(HLEDMRX_COL7_PIN,MGPIO_HIGH);
}

static void HLEDMRX_voidSetROWsValue(u8 HLEDMRX_u8Value)
{
  u8 Local_u8Bit;

  Local_u8Bit=GET_BIT(HLEDMRX_u8Value,0);
  MGPIO_voidSetPinValue(HLEDMRX_ROW0_PIN,Local_u8Bit);

  Local_u8Bit=GET_BIT(HLEDMRX_u8Value,1);
  MGPIO_voidSetPinValue(HLEDMRX_ROW1_PIN,Local_u8Bit);

  Local_u8Bit=GET_BIT(HLEDMRX_u8Value,2);
  MGPIO_voidSetPinValue(HLEDMRX_ROW2_PIN,Local_u8Bit);

  Local_u8Bit=GET_BIT(HLEDMRX_u8Value,3);
  MGPIO_voidSetPinValue(HLEDMRX_ROW3_PIN,Local_u8Bit);

  Local_u8Bit=GET_BIT(HLEDMRX_u8Value,4);
  MGPIO_voidSetPinValue(HLEDMRX_ROW4_PIN,Local_u8Bit);

  Local_u8Bit=GET_BIT(HLEDMRX_u8Value,5);
  MGPIO_voidSetPinValue(HLEDMRX_ROW5_PIN,Local_u8Bit);

  Local_u8Bit=GET_BIT(HLEDMRX_u8Value,6);
  MGPIO_voidSetPinValue(HLEDMRX_ROW6_PIN,Local_u8Bit);

  Local_u8Bit=GET_BIT(HLEDMRX_u8Value,7);
  MGPIO_voidSetPinValue(HLEDMRX_ROW7_PIN,Local_u8Bit);


}
