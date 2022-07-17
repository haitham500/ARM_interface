/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 26 Sep 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "MRCC_interface.h"
#include "MRCC_private.h"
#include "MRCC_config.h"

void MRCC_voidInitSysClk(void)
{
  #if PERIPHERAL_CLOCK_SOURCE==HSE
   SET_BIT(MRCC->CR,HSEON);
   SET_BIT(MRCC->CFGR,SW_0);
   CLR_BIT(MRCC->CFGR,SW_1);
  #elif PERIPHERAL_CLOCK_SOURCE==HSE_BYP
  SET_BIT(MRCC->CR,HSEON);
  SET_BIT(MRCC->CR,HSEBYP);
  SET_BIT(MRCC->CFGR,SW_0);
  CLR_BIT(MRCC->CFGR,SW_1);
  #elif PERIPHERAL_CLOCK_SOURCE==HSI
  SET_BIT(MRCC->CR,HSION);// ENABLE HSI
  // HSI CALIBRATION
  CLR_BIT(MRCC->CR,HSITRIM_3);
  CLR_BIT(MRCC->CR,HSITRIM_4);
  CLR_BIT(MRCC->CR,HSITRIM_5);
  CLR_BIT(MRCC->CR,HSITRIM_6);
  SET_BIT(MRCC->CR,HSITRIM_7);
  // HSI SELECTED AS SOURCE
  CLR_BIT(MRCC->CFGR,SW_0);
  CLR_BIT(MRCC->CFGR,SW_1);
  #elif PERIPHERAL_CLOCK_SOURCE==PLL
    #if PLL_IN==HSE
    SET_BIT(MRCC->CR,HSEON);
    SET_BIT(MRCC->CR,PLLON);
    SET_BIT(MRCC->CFGR,PLLSRC);//SET BIT BY 1 TO SELECT HSE
    CLR_BIT(MRCC->CFGR,PLLXTPRE);//CLR BIT TO 0 TO SELECT HSE NOT DIVIDED BY 2
    //MULTIPLY HSE BY 2
    CLR_BIT(MRCC->CFGR,PLLMUL_18);
    CLR_BIT(MRCC->CFGR,PLLMUL_19);
    CLR_BIT(MRCC->CFGR,PLLMUL_20);
    CLR_BIT(MRCC->CFGR,PLLMUL_21);
    //SELECT PLL AS SOURCES
    CLR_BIT(MRCC->CFGR,SW_0);
    SET_BIT(MRCC->CFGR,SW_1);
    #elif PLL_IN==PLL_HSE_BY_2
    SET_BIT(MRCC->CR,HSEON);
    SET_BIT(MRCC->CR,PLLON);
    SET_BIT(MRCC->CFGR,PLLSRC);//SET BIT BY 1 TO SELECT HSE
    SET_BIT(MRCC->CFGR,PLLXTPRE);//SET BIT BY 1 TO SELECT HSE DIVIDED BY 2
    //MULTIPLY HSE BY 2 ....BY FACTOR 2
    CLR_BIT(MRCC->CFGR,PLLMUL_18);
    CLR_BIT(MRCC->CFGR,PLLMUL_19);
    CLR_BIT(MRCC->CFGR,PLLMUL_20);
    CLR_BIT(MRCC->CFGR,PLLMUL_21);
    //SELECT PLL AS SOURCES
    CLR_BIT(MRCC->CFGR,SW_0);
    SET_BIT(MRCC->CFGR,SW_1);
    #elif PLL_IN==PLL_HSI_BY_2
    SET_BIT(MRCC->CR,HSION);// ENABLE HSI
    // HSI CALIBRATION
    CLR_BIT(MRCC->CR,HSITRIM_3);
    CLR_BIT(MRCC->CR,HSITRIM_4);
    CLR_BIT(MRCC->CR,HSITRIM_5);
    CLR_BIT(MRCC->CR,HSITRIM_6);
    SET_BIT(MRCC->CR,HSITRIM_7);
    SET_BIT(MRCC->CR,PLLON);//ENABLE PLL
    CLR_BIT(MRCC->CFGR,PLLSRC);//CLR BIT BY 0 TO SELECT HSI BY 2
    //MULTIPLY HSI BY 2 ....BY FACTOR 2
    CLR_BIT(MRCC->CFGR,PLLMUL_18);
    CLR_BIT(MRCC->CFGR,PLLMUL_19);
    CLR_BIT(MRCC->CFGR,PLLMUL_20);
    CLR_BIT(MRCC->CFGR,PLLMUL_21);
    //SELECT PLL AS SOURCES
    CLR_BIT(MRCC->CFGR,SW_0);
    SET_BIT(MRCC->CFGR,SW_1);
    #endif

  #else
      #error ("you chosed wrong clock type")

  #endif
}

void MRCC_voidEnableAHBClk (MRCC_AHBENR_BITS  PeriphID)
{
  SET_BIT(MRCC->AHBENR,PeriphID);
}
void MRCC_voidEnableAPB2Clk(MRCC_APB2ENR_BITS PeriphID)
{
  SET_BIT(MRCC->APB2ENR,PeriphID);
}
void MRCC_voidEnableAPB1Clk(MRCC_APB1ENR_BITS PeriphID)
{
  SET_BIT(MRCC->APB1ENR,PeriphID);
}




void MRCC_voidDisableAHBClk (MRCC_AHBENR_BITS  PeriphID)
{
  CLR_BIT(MRCC->AHBENR,PeriphID);
}
void MRCC_voidDisableAPB2Clk(MRCC_APB2ENR_BITS PeriphID)
{
  CLR_BIT(MRCC->APB2ENR,PeriphID);
}
void MRCC_voidDisableAPB1Clk(MRCC_APB1ENR_BITS PeriphID)
{
  CLR_BIT(MRCC->APB1ENR,PeriphID);
}
