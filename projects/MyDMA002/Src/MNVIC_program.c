/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 14 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MNVIC_INTERFACE.h"
#include "MNVIC_PRIVATE.h"
#include "MNVIC_config.h"

void MNVIC_voidSetEnableINT(u8 MNVIC_InterruptID)
{
  if (MNVIC_InterruptID<=31)
  {
    SET_BIT(MNVIC_ISER_STRUCT->MNVIC_ISER[0],MNVIC_InterruptID);
  }
  else if (MNVIC_InterruptID>=32 && MNVIC_InterruptID<=63)
  {
    SET_BIT(MNVIC_ISER_STRUCT->MNVIC_ISER[1],MNVIC_InterruptID-32);
  }
  else if (MNVIC_InterruptID>=64 && MNVIC_InterruptID<=80)
  {
    SET_BIT(MNVIC_ISER_STRUCT->MNVIC_ISER[2],MNVIC_InterruptID-64);
  }
}


void MNVIC_voidClearEnableINT(u8 MNVIC_InterruptID)
{
  if ( MNVIC_InterruptID<=31)
  {
    SET_BIT(MNVIC_ICER_STRUCT->MNVIC_ICER[0],MNVIC_InterruptID);
  }
  else if (MNVIC_InterruptID>=32 && MNVIC_InterruptID<=63)
  {
    SET_BIT(MNVIC_ICER_STRUCT->MNVIC_ICER[1],MNVIC_InterruptID-32);
  }
  else if (MNVIC_InterruptID>=64 && MNVIC_InterruptID<=80)
  {
    SET_BIT(MNVIC_ICER_STRUCT->MNVIC_ICER[2],MNVIC_InterruptID-64);
  }
}


void MNVIC_voidSetPendingFlagINT(u8 MNVIC_InterruptID)
{
  if (MNVIC_InterruptID<=31)
  {
    SET_BIT(MNVIC_ISPR_STRUCT->MNVIC_ISPR[0],MNVIC_InterruptID);
  }
  else if (MNVIC_InterruptID>=32 && MNVIC_InterruptID<=63)
  {
    SET_BIT(MNVIC_ISPR_STRUCT->MNVIC_ISPR[1],MNVIC_InterruptID-32);
  }
  else if (MNVIC_InterruptID>=64 && MNVIC_InterruptID<=80)
  {
    SET_BIT(MNVIC_ISPR_STRUCT->MNVIC_ISPR[2],MNVIC_InterruptID-64);
  }
}

void MNVIC_voidClearPendingFlagINT(u8 MNVIC_InterruptID)
{
  if (MNVIC_InterruptID<=31)
  {
    SET_BIT(MNVIC_ICPR_STRUCT->MNVIC_ICPR[0],MNVIC_InterruptID);
  }
  else if (MNVIC_InterruptID>=32 && MNVIC_InterruptID<=63)
  {
    SET_BIT(MNVIC_ICPR_STRUCT->MNVIC_ICPR[1],MNVIC_InterruptID-32);
  }
  else if (MNVIC_InterruptID>=64 && MNVIC_InterruptID<=80)
  {
    SET_BIT(MNVIC_ICPR_STRUCT->MNVIC_ICPR[2],MNVIC_InterruptID-64);
  }
}


u8 MNVIC_u8GetActiveBitFlagINT(u8 MNVIC_InterruptID)
{
  u8 Local_u8Result=0;
  if (MNVIC_InterruptID<=31)
  {
    Local_u8Result=GET_BIT(MNVIC_IABR_STRUCT->MNVIC_IABR[0],MNVIC_InterruptID);
  }
  else if (MNVIC_InterruptID>=32 && MNVIC_InterruptID<=63)
  {
    Local_u8Result=GET_BIT(MNVIC_IABR_STRUCT->MNVIC_IABR[1],(MNVIC_InterruptID-32));
  }
  else if (MNVIC_InterruptID>=64 && MNVIC_InterruptID<=80)
  {
    Local_u8Result=GET_BIT(MNVIC_IABR_STRUCT->MNVIC_IABR[2],(MNVIC_InterruptID-64));
  }
  return Local_u8Result;
}

void MNVIC_voidSetPriorityINT(u8 MNVIC_InterruptID,u8 MNVIC_Group,u8 MNVIC_SUBPriority)
{
  if (MNVIC_InterruptID<60)
  {
    PUT_VAL_HIGHER_NIBBLE(MNVIC_IPR_STRUCT->MNVIC_IPR[MNVIC_InterruptID],(MNVIC_Group<<(2+MNVIC_SUBPriority)));

  }
  else
  {
    /* ERROR */
  }
}
