/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 21 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MSCB_INTERFACE.h"
#include "MSCB_PRIVATE.h"
#include "MSCB_config.h"

void MSCB_voidSetPriorityGroupControl(void)
{
  MSCB->MSCB_AIRCR=MNVIC_GROUP_SUB_DISTRIBUTION;
}

void MSCB_voidEnableUnprivilegedSW(void)
{
  // enable unprivileged software to access software trigger interrupt register (NVIC)

  SET_BIT(MSCB->MSCB_CCR,USERSETMPEND_BIT_1_CCR);
}

void MSCB_voidClearSysTickPend(void)
{
SET_BIT(MSCB->MSCB_ICSR,25);
}
