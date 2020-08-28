/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 19 Aug 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MGPIO_private.h"
#include "MGPIO_config.h"


void MGPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN,u8 Copy_u8Mode)
{
  switch (Copy_u8PORT) {
    case GPIOA:
               if (Copy_u8PIN<=7)
                {
                 GPIOA_CRL &= ~((0b1111)<<(Copy_u8PIN * 4)); /* CLEAR */
                 GPIOA_CRL |= (Copy_u8Mode)<<(Copy_u8PIN * 4); /*PUT VALUE*/
                }
                else if (Copy_u8PIN<=15)
                {
                  Copy_u8PIN = Copy_u8PIN - 8;
                  GPIOA_CRH &= ~((0b1111)<<(Copy_u8PIN * 4)); /* CLEAR */
                  GPIOA_CRH |= (Copy_u8Mode)<<(Copy_u8PIN * 4); /*PUT VALUE*/
                }
                break;
    case GPIOB:
               if (Copy_u8PIN<=7)
               {
                 GPIOB_CRL &= ~((0b1111)<<(Copy_u8PIN * 4)); /* CLEAR */
                 GPIOB_CRL |= (Copy_u8Mode)<<(Copy_u8PIN * 4); /*PUT VALUE*/
               }
               else if (Copy_u8PIN<=15)
               {
                 Copy_u8PIN = Copy_u8PIN - 8;
                 GPIOB_CRH &= ~((0b1111)<<(Copy_u8PIN * 4)); /* CLEAR */
                 GPIOB_CRH |= (Copy_u8Mode)<<(Copy_u8PIN * 4); /*PUT VALUE*/
               }
               break;
    case GPIOC:
                if (Copy_u8PIN<=7)
                {
                  GPIOC_CRL &= ~((0b1111)<<(Copy_u8PIN * 4)); /* CLEAR */
                  GPIOC_CRL |= (Copy_u8Mode)<<(Copy_u8PIN * 4); /*PUT VALUE*/
                }
                else if (Copy_u8PIN<=15)
                {
                  Copy_u8PIN = Copy_u8PIN - 8;
                  GPIOC_CRH &= ~((0b1111)<<(Copy_u8PIN * 4)); /* CLEAR */
                  GPIOC_CRH |= (Copy_u8Mode)<<(Copy_u8PIN * 4); /*PUT VALUE*/
                }
                break;
    default:    break;
  }

}
void MGPIO_voidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN,u8 Copy_u8Value)
{
  switch (Copy_u8PORT)
  {
    case GPIOA:
               if (Copy_u8Value==GPIO_HIGH)
                {
                 SET_BIT(GPIOA_ODR,Copy_u8PIN);
                }
                else if (Copy_u8Value==GPIO_LOW)
                {
                  CLR_BIT(GPIOA_ODR,Copy_u8PIN);

                }
                break;
    case GPIOB:
               if (Copy_u8Value==GPIO_HIGH)
                {
                 SET_BIT(GPIOB_ODR,Copy_u8PIN);
                }
               else if (Copy_u8Value==GPIO_LOW)
                {
                 CLR_BIT(GPIOA_ODR,Copy_u8PIN);
                }
                break;
    case GPIOC:
               if (Copy_u8Value==GPIO_HIGH)
                {
                 SET_BIT(GPIOC_ODR,Copy_u8PIN);
                }
               else if (Copy_u8Value==GPIO_LOW)
                {
                 CLR_BIT(GPIOC_ODR,Copy_u8PIN);
                }
                break;
    default:    break;
  }

}
u8 MGPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
  u8 LOCAL_u8Result = 0;
  switch (Copy_u8PORT)
  {
    case GPIOA: LOCAL_u8Result=GET_BIT(GPIOA_IDR,Copy_u8PIN); break;
    case GPIOB: LOCAL_u8Result=GET_BIT(GPIOB_IDR,Copy_u8PIN); break;
    case GPIOC: LOCAL_u8Result=GET_BIT(GPIOC_IDR,Copy_u8PIN); break;
    default   : break;
  }
  return LOCAL_u8Result;

}
