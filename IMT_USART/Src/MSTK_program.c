/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 04 Dec. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MSTK_INTERFACE.h"
#include "MSTK_PRIVATE.h"
#include "MSTK_config.h"

static void (*MSTK_CALLBACK) (void);// pointer to func used to pass any func
// to systick interrupt handler
volatile u8 OneSysTickFired; //A global software flag to
                         // indicate SysTickAlarm executed for one shot

volatile u32 MultiSysTickFired; //A global software flag to indicate SysTickAlarm
// executed for Multi shot

void MSTK_voidSystickInit(void)
{

    CLR_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Disable systick peripheral
    CLR_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_BIT_CTRL); // Disable interrupt of systick
    CLR_BIT(MSTK->MSTK_CTRL,MSTK_CLKSOURCE_BIT_CTRL); // set clock source AHB/8

    MSTK->MSTK_LOAD=0;
    MSTK->MSTK_VAL=0;

}

void MSTK_voidDelay(u32 MSTK_u32Ticks)
{
  CLR_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Disable systick peripheral
  CLR_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_BIT_CTRL); // Disable interrupt of systick
  //CLR_BIT(MSTK->MSTK_CTRL,MSTK_CLKSOURCE_BIT_CTRL); // set clock source AHB/8

  MSTK->MSTK_LOAD=MSTK_u32Ticks;
  MSTK->MSTK_VAL=0;

  SET_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Enable systick peripheral
  while (GET_BIT(MSTK->MSTK_CTRL,MSTK_COUNTFLAG_BIT_CTRL)==0);
  CLR_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Disable systick peripheral
}

void MSTK_voidOneShot(u32 MSTK_u32Ticks,void (*Fptr)(void))
{
  CLR_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Disable systick peripheral
  CLR_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_BIT_CTRL); // Disable interrupt of systick

  MSTK->MSTK_LOAD=MSTK_u32Ticks-12; // Minus 12 because of exception latency
  MSTK->MSTK_VAL=0;

  OneSysTickFired=0; // Setup software flag to zero
  MSTK_CALLBACK=Fptr;

  SET_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Enable systick peripheral
  SET_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_BIT_CTRL); // Enable interrupt of systick

  while(OneSysTickFired==0); // Wait until software flag is set by SYSTICK handler

}


void MSTK_voidMultiShot(u32 MSTK_u32Ticks,void (*Fptr)(void))
{
  CLR_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Disable systick peripheral
  CLR_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_BIT_CTRL); // Disable interrupt of systick


  MSTK->MSTK_LOAD=MSTK_u32Ticks; // Minus(1+12=13) 12 because of exception latency
  //and 1 for mutli-shot
  MSTK->MSTK_VAL=0;

  MultiSysTickFired=0; // Setup software flag to zero
  MSTK_CALLBACK=Fptr;

  SET_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Enable systick peripheral
  SET_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_BIT_CTRL); // Enable interrupt of systick

  while(MultiSysTickFired==0); // Wait until software flag is set by SYSTICK handler
  CLR_BIT(MSTK->MSTK_CTRL,MSTK_COUNTFLAG_BIT_CTRL);

}

void MSTK_voidStop(void)
{
  CLR_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Disable systick peripheral
  CLR_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_BIT_CTRL); // Disable interrupt of systick
  MSTK->MSTK_LOAD=0;
  MSTK->MSTK_VAL =0;

}

u32 MSTK_u32GetElapsedTime(void)
{
  u32 local_elapsedtime=0;
  local_elapsedtime=(MSTK->MSTK_LOAD)-(MSTK->MSTK_VAL);
  return local_elapsedtime;
}


u32  MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime=0;
	Local_u32RemainTime = MSTK->MSTK_VAL ;
	return Local_u32RemainTime;
}


void SysTick_Handler(void)
{
  if (OneSysTickFired==0)
  {
    CLR_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Disable systick peripheral
    CLR_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_BIT_CTRL); // Disable interrupt of systick
    MSTK_CALLBACK();
    OneSysTickFired=1;
  }

    MSTK_CALLBACK();
    MultiSysTickFired++;
    //Clear interrupt flag

}
