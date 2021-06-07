/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 31 Dec. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/

#ifndef SOS_INTERFACE_H
#define SOS_INTERFACE_H

void SOS_voidStart(void);
void SOS_voidCreateTask (u8 SOS_u8Priority, u16 SOS_u16TaskPeriodicity,void(*ptr)(void),u16 SOS_u16FirstDelay);
void SOS_voidDeleteTask (u8 SOS_u8TaskID);
void SOS_voidSuspendTask(u8 SOS_u8TaskID);
void SOS_voidResumeTask ( u8 SOS_u8TaskID );


#endif
