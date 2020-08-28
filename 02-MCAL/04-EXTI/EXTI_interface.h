/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 24 Aug 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/


#ifndef  EXTI_INTERFACE_H
#define  EXTI_INTERFACE_H

void MEXTI_voidInit();// inputs are line and mode
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);


#endif
