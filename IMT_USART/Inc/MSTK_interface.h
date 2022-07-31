/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 04 Dec. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  MSTK_INTERFACE_H
#define  MSTK_INTERFACE_H

//BITS OF SysTick control and status register (STK_CTRL)
#define MSTK_ENABLE_BIT_CTRL     0
#define MSTK_TICKINT_BIT_CTRL    1
#define MSTK_CLKSOURCE_BIT_CTRL  2
#define MSTK_COUNTFLAG_BIT_CTRL  16

void MSTK_voidSystickInit(void);
void MSTK_voidDelay(u32 MSTK_u32Ticks);
void MSTK_voidOneShot(u32 MSTK_u32Ticks,void (*Fptr)(void));
void MSTK_voidMultiShot(u32 MSTK_u32Ticks,void (*Fptr)(void));
void MSTK_voidStop(void);
u32 MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);




#endif
