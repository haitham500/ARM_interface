/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 24 Aug 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/


#ifndef  NVIC_INTERFACE_H
#define  NVIC_INTERFACE_H

u8   MNVIC_u8EnableInterrupt   (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority(s8 Copy_s8IntID, u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority, u32 Copy_u32GROUP);

#define GROUP3    0x05FA0300     // 4 bits for (IPR) => group
 #define GROUP4    0x05FA0400    // 3 bits for group and 1 bit for subgroups
#define GROUP5    0x05FA0500     // 2 bits for group and 2 bit for subgroups
#define GROUP6    0x05FA0600     // 1 bits for group and 3 bit for subgroups
#define GROUP7    0x05FA0700     // 0 group and 4 bits for subgroups

#endif
