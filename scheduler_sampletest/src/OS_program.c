/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 31 Dec. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_INTERFACE.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"


//array of tasks from type array of struct
static TASK SOS_TASKS[TASK_NUMBERS]={{NULL}};

void SOS_voidStart(void)
{
  MSTK_VidSetCallBack(SOS_voidSchedular);
  MSTK_VidInit();
  MSTK_VidStart(TICK_TIME);//1msec
}

void SOS_voidCreateTask (u8 SOS_u8Priority, u16 SOS_u16TaskPeriodicity,void(*ptr)(void),u16 SOS_u16FirstDelay)

{
	if( SOS_TASKS[ SOS_u8Priority ].TaskHandler == NULL ){

		SOS_TASKS[ SOS_u8Priority ].Periodicity = SOS_u16TaskPeriodicity ;
		SOS_TASKS[ SOS_u8Priority ].TaskHandler = ptr         ;
		SOS_TASKS[ SOS_u8Priority ].FirstDelay  = SOS_u16FirstDelay  ;
		SOS_TASKS[ SOS_u8Priority ].State       = TASK_READY          ;

	}
	else{

		/* Do No Thing */

	}

}
void SOS_voidSuspendTask(u8 SOS_u8TaskID)
{
  SOS_TASKS[SOS_u8TaskID].State = TASK_SUSPEND ;
}

void SOS_voidResumeTask ( u8 SOS_u8TaskID )
{
  SOS_TASKS[SOS_u8TaskID].State = TASK_READY ;
}

void SOS_voidDeleteTask (u8 SOS_u8TaskID)
{
  SOS_TASKS[SOS_u8TaskID].State = NULL ;
}


static void SOS_voidSchedular( void )
{
	u8 LOC_u8TaskCounter      ;
	for( LOC_u8TaskCounter = 0 ; LOC_u8TaskCounter < TASK_NUMBERS ; LOC_u8TaskCounter++ )
  {
		if( ( SOS_TASKS[ LOC_u8TaskCounter ].TaskHandler != NULL ) && ( SOS_TASKS[ LOC_u8TaskCounter ].State == TASK_READY ) )
    {
			if( SOS_TASKS[ LOC_u8TaskCounter ].FirstDelay == 0 )
      {
				SOS_TASKS[ LOC_u8TaskCounter ].FirstDelay = SOS_TASKS[ LOC_u8TaskCounter ].Periodicity - 1 ;
				SOS_TASKS[ LOC_u8TaskCounter ].TaskHandler();
		 	}
			else
      {
				SOS_TASKS[ LOC_u8TaskCounter ].FirstDelay--;
			}

		}
		else
    {
			/* Do No Thing */
		}

	}

}




/*
// without firstdelay
static void Scheduler(void)
{
  for(u8 i=0;i<NUMBER_OF_TASKS;i++)
  {
    if((TickCounts % SOS_TASKS[i].priodicity)==0)
    {
      SOS_TASKS[i].Fptr;
    }
    TickCounts++;
  }

 }
 */
