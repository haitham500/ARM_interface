/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_INTERFACE.h"
#include "MGPIO_interface.h"
#include "MNVIC_interface.h"
#include "MSCB_interface.h"
#include "MEXTI_interface.h"
#include "MAFIO_interface.h"

#include "IR_INTERFACE.h"
#include "IR_CONFIG.h"

volatile u8  Start          =   0   ;
volatile u8  Counter         =   0   ;
volatile u32 CodeSample[100] = { 0 } ;
volatile u8  Data            =   0   ;
volatile u8  Iterator        =   0   ;

void Read_CodeCallBack ( void )
{

	if ( Start == 0 ){

		MSTK_VidStart( TIMER_VALUE );
		Start = 1;

	}
	else if ( Start == 1 ){

		CodeSample[ Counter ] = MSTK_u32GetCounterValue();
		Counter++ ;
		MSTK_VidStart( TIMER_VALUE );

	}
	if( Counter == END_OF_CODE ){

		for( Iterator = 0 ; Iterator < END_OF_CODE ; Iterator++ )
		{

			CodeSample[ Iterator ] = TIMER_VALUE - CodeSample[ Iterator ];

		}

		for( Iterator = DATA_COMMEND_START_EDGE ; Iterator < DATA_COMMEND_END_EDGE ; Iterator++ ){

			if( CodeSample[ Iterator ] >= LOGIC1_RANGE ){

				SET_BIT( Data , ( Iterator - DATA_COMMEND_START_EDGE ) );

			}

		}

		MNVIC_voidClearEnableINT(6);

		Start   = 2 ;

	}

}

void Timer_ResetCallBack ( void ){

	MSTK_VidStop();
	Start  = 0 ;
	Counter = 0 ;
	Data    = 0 ;

}

void IR_VidInit( void ){

    MGPIO_voidSetPinDirection(IR_PORT, IR_PIN, INPUT_MODE, Floating_INPUT);//set configuration for pin and port which will receive IR signal



	MSCB_voidSetPriorityGroupControl();//set groups and subpriority for interrupts , you can change from MSCB_config.h
	MNVIC_voidSetPriorityINT(6, 1, 0);// the priority of inerrupt id 6 of external interrupt line 0 will be in 2nd group id 1 and 1st subpriority id 0
	MNVIC_voidSetEnableINT(6); //enable interrupt for external line 0  EXT0 with interrupt id  = 6


	MAFIO_voidSelectEXTIPin(IR_PORT, IR_PIN);// select port and pin to activate alternative function



	MEXTI_voidSetCallBack(Read_CodeCallBack, MEXTI_LINE_0);// passing function to external interrupt handler function
	MEXTI_voidEnableEXTILine(MEXTI_LINE_0, MEXTI_FALLING_EDGE);// enable external line interrupt 0 id 6 at mood falling edge

	MSTK_VidSetCallBack         ( Timer_ResetCallBack                  );
	MSTK_VidInit                (                                      );


}

u8 IR_u8GetCode ( void ){

	u8 LOC_u8Data = 0 ;

	while( Start != 2 );

	LOC_u8Data = Data ;

	Start   = 0 ;
	Counter = 0 ;
	Data    = 0 ;

	MNVIC_voidSetEnableINT(6); // EXT0 = 6


	return LOC_u8Data ;
}

