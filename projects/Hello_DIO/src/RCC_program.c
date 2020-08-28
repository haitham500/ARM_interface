/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 15 Aug 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/

/*0x4002 1000 - 0x4002 13FF Reset and clock control RCC Section 7.3.11 on page 121*/
#include  "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_INTERFACE.h"
#include "RCC_PRIVATE.h"
#include "RCC_CONFIG.h"

void RCC_voidInitSysClock(void)
{
  /* RCC_HSE_CRYSTAL
             RCC_HSE_RC
             RCC_HSI
             RCC_PLL

             RCC_CLOCK_TYPE */

    #if     RCC_CLOCK_TYPE==RCC_HSE_CRYSTAL
            RCC_CR=0x00010000; /* enable HSE without bypass */
            RCC_CFGR=0x00000001;

    #elif   RCC_CLOCK_TYPE==RCC_HSE_RC
            RCC_CR=0x00050000; /* enable HSE with bypass */
            RCC_CFGR=0x00000001;

    #elif   RCC_CLOCK_TYPE==RCC_HSI
            RCC_CR=0x00000081; /*  enable HSI + trimming=0*/
            RCC_CFGR=0x00000000;

    #elif   RCC_CLOCK_TYPE==RCC_PLL
          #if   RCC_PLL_INPUT==RCC_PLL_IN_HSI_DIV_2

          #elif RCC_PLL_INPUT==RCC_PLL_IN_HSE_DIV_2

          #elif RCC_PLL_INPUT==RCC_PLL_IN_HSE

          #endif


    #else
            #error ("you chosed wrong clock type")
    #endif
}

void RCC_voidEnableClock(u8 Copy_u8BusID, u8 Copy_u8PerID)
{
  if (Copy_u8BusID<=31)
  {
    switch (Copy_u8BusID)
    {
      case RCC_AHB  : SET_BIT(RCC_AHBENR,Copy_u8PerID);  break;
      case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PerID); break;
      case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PerID); break;
      default       :         break;
    }
  }
  else
  {
      /* return error */
  }
}

void RCC_voidDisableClock(u8 Copy_u8BusID, u8 Copy_u8PerID)
{
  if (Copy_u8BusID<=31)
  {
    switch (Copy_u8BusID)
    {
      case RCC_AHB  : CLR_BIT(RCC_AHBENR,Copy_u8PerID);  break;
      case RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PerID); break;
      case RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PerID); break;
      //default       :  return error                  break;
    }
  }
  else
  {
      /* return error */
  }
}
