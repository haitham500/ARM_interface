/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 31 Dec. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/


#ifndef SOS_PRIVATE_H
#define SOS_PRIVATE_H

#define NULL      (void *)0



////////////////////////////////////
typedef struct
{

	u16  Periodicity               ;
	void ( *TaskHandler )( void )  ;
	u16  FirstDelay                ;
	u8   State                     ;

}TASK;

#define TASK_READY       0
#define TASK_SUSPEND     1

static void SOS_voidSchedular( void );

//static volatile u16 TickCounts=0 ; used for SOS_voidSchedular function without FirstDelay


#endif
