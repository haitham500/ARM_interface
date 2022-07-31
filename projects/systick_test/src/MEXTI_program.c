/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 22 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MEXTI_INTERFACE.h"
#include "MEXTI_PRIVATE.h"
#include "MEXTI_config.h"

void (* MEXTI_CALLBACK[20]) (void);


void MEXTI_voidEnableEXTILine(u8 MEXTI_LINE,u8 MEXTI_SENSE_MOOD)
{
  SET_BIT(MEXTI->MEXTI_IMR,MEXTI_LINE);
  switch (MEXTI_SENSE_MOOD)
  {
    case MEXTI_FALLING_EDGE:
    SET_BIT(MEXTI->MEXTI_FTSR,MEXTI_LINE);    break;
    case MEXTI_RISING_EDGE:
    SET_BIT(MEXTI->MEXTI_RTSR,MEXTI_LINE);    break;
    case MEXTI_ON_CHANGE:
    SET_BIT(MEXTI->MEXTI_FTSR,MEXTI_LINE);
    SET_BIT(MEXTI->MEXTI_RTSR,MEXTI_LINE);    break;
  }
}

void MEXTI_voidDisableEXTILine(u8 MEXTI_LINE)
{
  CLR_BIT(MEXTI->MEXTI_IMR,MEXTI_LINE);
}

void MEXTI_voidSoftWareTriggerEXTI(u8 MEXTI_LINE)
{
  SET_BIT(MEXTI->MEXTI_IMR,MEXTI_LINE);
  CLR_BIT(MEXTI->MEXTI_PR,MEXTI_LINE);  //IT IS CLEARED BY WRITING 1
  SET_BIT(MEXTI->MEXTI_SWIER,MEXTI_LINE);
}




void MEXTI_voidSetCallBack(void (*ptr)(void),u8 MEXTI_LINE)
{
  MEXTI_CALLBACK[MEXTI_LINE]=ptr;
}

// external interrupt handlers, it is called by hardware
void EXTI0_IRQHandler(void)
{

	MEXTI_CALLBACK[0]();
	SET_BIT( MEXTI->MEXTI_PR , 0 );

}

void EXTI1_IRQHandler(void)
{

	MEXTI_CALLBACK[1]();
	SET_BIT( MEXTI->MEXTI_PR , 1 );

}

void EXTI2_IRQHandler(void)
{

	MEXTI_CALLBACK[2]();
	SET_BIT( MEXTI->MEXTI_PR , 2 );

}

void EXTI3_IRQHandler(void)
{

	MEXTI_CALLBACK[3]();
	SET_BIT( MEXTI->MEXTI_PR , 3 );

}

void EXTI4_IRQHandler(void)
{

	MEXTI_CALLBACK[4]();
	SET_BIT( MEXTI->MEXTI_PR , 4 );

}

void EXTI5_IRQHandler(void)
{

	MEXTI_CALLBACK[5]();
	SET_BIT( MEXTI->MEXTI_PR , 5 );

}

void EXTI6_IRQHandler(void)
{

	MEXTI_CALLBACK[6]();
	SET_BIT( MEXTI->MEXTI_PR , 6 );

}

void EXTI7_IRQHandler(void)
{

	MEXTI_CALLBACK[7]();
	SET_BIT( MEXTI->MEXTI_PR , 7 );

}

void EXTI8_IRQHandler(void)
{

	MEXTI_CALLBACK[8]();
	SET_BIT( MEXTI->MEXTI_PR , 8 );

}


void EXTI9_IRQHandler(void)
{

	MEXTI_CALLBACK[9]();
	SET_BIT( MEXTI->MEXTI_PR , 9 );

}
void EXTI10_IRQHandler(void)
{

	MEXTI_CALLBACK[10]();
	SET_BIT( MEXTI->MEXTI_PR , 10 );

}

void EXTI11_IRQHandler(void)
{

	MEXTI_CALLBACK[11]();
	SET_BIT( MEXTI->MEXTI_PR , 11 );

}

void EXTI12_IRQHandler(void)
{

	MEXTI_CALLBACK[12]();
	SET_BIT( MEXTI->MEXTI_PR , 12 );

}

void EXTI13_IRQHandler(void)
{

	MEXTI_CALLBACK[13]();
	SET_BIT( MEXTI->MEXTI_PR , 13 );

}

void EXTI14_IRQHandler(void)
{

	MEXTI_CALLBACK[14]();
	SET_BIT( MEXTI->MEXTI_PR , 14 );

}

void EXTI15_IRQHandler(void)
{

	MEXTI_CALLBACK[15]();
	SET_BIT( MEXTI->MEXTI_PR , 15 );

}

void EXTI16_IRQHandler(void)
{

	MEXTI_CALLBACK[16]();
	SET_BIT( MEXTI->MEXTI_PR , 16 );

}

void EXTI17_IRQHandler(void)
{

	MEXTI_CALLBACK[17]();
	SET_BIT( MEXTI->MEXTI_PR , 17 );

}

void EXTI18_IRQHandler(void)
{

	MEXTI_CALLBACK[18]();
	SET_BIT( MEXTI->MEXTI_PR , 18 );

}

void EXTI19_IRQHandler(void)
{

	MEXTI_CALLBACK[19]();
	SET_BIT( MEXTI->MEXTI_PR , 19 );

}

