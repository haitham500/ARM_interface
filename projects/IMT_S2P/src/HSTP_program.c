/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 13 July 2022                                          */
/* Version     : V01                                                  */
/**********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MSTK_interface.h"

#include "HSTP_interface.h"
#include "HSTP_private.h"
#include "HSTP_config.h"

// https://arduino.stackexchange.com/questions/79799/problem-connecting-2-74hc595-8-bit-shift-registers-in-cascading-connection
// this link to connect 2 IC shift register 74HC595 in cascading mode


void HSTP_VoidSendSynchronus ( u8 HSTP_u8DataToSend )
{
  s8 Local_s8counter;
  u8 Local_u8Bit;

  for (Local_s8counter = 7; Local_s8counter >= 0; Local_s8counter--)
  {
    // send data bit by bit in starting from MSB (Most Signifacnt Bit )
    Local_u8Bit = GET_BIT(HSTP_u8DataToSend,Local_s8counter);
    MGPIO_voidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);

    // send pulse to shift clock with width more than 100 nsec
    MGPIO_voidSetPinValue(HSTP_SHIFT_CLK,MGPIO_HIGH);
    MSTK_voidDelay(1);

    MGPIO_voidSetPinValue(HSTP_SHIFT_CLK,MGPIO_LOW);
    MSTK_voidDelay(1);

  }

  // send pulse to store clock with width more than 100 nsec
  MGPIO_voidSetPinValue(HSTP_STORE_CLK,MGPIO_HIGH);
  MSTK_voidDelay(1);

  MGPIO_voidSetPinValue(HSTP_STORE_CLK,MGPIO_LOW);
  MSTK_voidDelay(1);



}
