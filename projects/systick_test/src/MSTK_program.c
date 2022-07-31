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

static void (*MSTK_CALLBACK) (void);
static volatile u8 countflag=0;
static volatile u32 count=0;


void MSTK_voidInitSysTick(void)
{
  /*
  https://developer.arm.com/documentation/dui0552/a/cortex-m3-peripherals/system-timer--systick/systick-usage-hints-and-tips
  correct initialization sequence for the SysTick counter is:
   1-Program reload value.
   2-Clear current value.
   3-Program Control and Status register.
*/
  MSTK->MSTK_LOAD=0;
  MSTK->MSTK_VAL =0;
CLR_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Disable systick peripheral
CLR_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_BIT_CTRL); // Disable interrupt of systick
CLR_BIT(MSTK->MSTK_CTRL,MSTK_CLKSOURCE_BIT_CTRL); // set clock source AHB/8
}

void MSTK_voidSetBusyWait(u32 MSTK_u32Ticks)
{
  MSTK->MSTK_LOAD =MSTK_u32Ticks;
  MSTK->MSTK_VAL =0;

  SET_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Enable systick peripheral
 // leave disable interrupt of systick, i don't need it here
  MSTK->MSTK_LOAD =MSTK_u32Ticks;
  while(!GET_BIT(MSTK->MSTK_CTRL,MSTK_COUNTFLAG_BIT_CTRL));

// STOP SYSTICK TIMER
  MSTK->MSTK_LOAD =0;
  MSTK->MSTK_VAL =0;
  CLR_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Disable systick peripheral

}

void MSTK_voidSetIntervalSingle(u32 MSTK_u32Ticks,void (*ptr)(void))
{
  MSTK->MSTK_LOAD =MSTK_u32Ticks;
  MSTK->MSTK_VAL =0;
  SET_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Enable systick peripheral
  SET_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_BIT_CTRL); // Enable interrupt of systick
  MSTK_CALLBACK=ptr;
  count= MSTK_u32Ticks;


}
void MSTK_voidSetIntervalPeriodic (u32 MSTK_u32Ticks,void (*ptr)(void))
{
  MSTK->MSTK_LOAD =MSTK_u32Ticks-1;
  MSTK->MSTK_VAL =0;
  SET_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Enable systick peripheral
  SET_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_BIT_CTRL); // Enable interrupt of systick
  MSTK_CALLBACK=ptr;
  count= MSTK_u32Ticks;

}
void MSTK_voidStopInterval(void)
{
  MSTK->MSTK_LOAD=0;
  MSTK->MSTK_VAL =0;
  CLR_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Disable systick peripheral
  CLR_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_BIT_CTRL); // Disable interrupt of systick

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
  if (count==MSTK->MSTK_LOAD)// single interval timer
  {
    MSTK->MSTK_LOAD=0;
    MSTK->MSTK_VAL =0;
    CLR_BIT(MSTK->MSTK_CTRL,MSTK_ENABLE_BIT_CTRL); // Disable systick peripheral
    CLR_BIT(MSTK->MSTK_CTRL,MSTK_TICKINT_BIT_CTRL); // Disable interrupt of systick

  }

  MSTK_CALLBACK();
  countflag=GET_BIT(MSTK->MSTK_CTRL,MSTK_COUNTFLAG_BIT_CTRL);
  // clear flag of register by reading or writing(o or 1) or interrupt
}
