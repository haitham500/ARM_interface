/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 21 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  MSCB_INTERFACE_H
#define  MSCB_INTERFACE_H


#define MNVIC_GROUP_4_SUB_0    0x05FA0300
#define MNVIC_GROUP_3_SUB_1    0x05FA0400
#define MNVIC_GROUP_2_SUB_2    0x05FA0500
#define MNVIC_GROUP_1_SUB_3    0x05FA0600
#define MNVIC_GROUP_0_SUB_4    0x05FA0700

#define USERSETMPEND_BIT_1_CCR        1

void MSCB_voidSetPriorityGroupControl(void);
void MSCB_voidEnableUnprivilegedSW(void);
void MSCB_voidClearSysTickPend(void);




#endif
