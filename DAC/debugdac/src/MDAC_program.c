/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 12 Jun. 2021                                          */
/* Version     : V01                                                  */
/**********************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MGPIO_interface.h"
#include "SYSTICK_INTERFACE.h"

#include "song.h"

#include "MDAC_INTERFACE.h"
#include "MDAC_config.h"
#include "MDAC_PRIVATE.h"

volatile u32 sample_counter=0;


static void MDAC_voidCALLBACK(void)
{
    MGPIO_voidSetPinValue(MDAC_PortBit0,MDAC_PinBit0,GET_BIT((u8)song_raw[sample_counter],0));
    MGPIO_voidSetPinValue(MDAC_PortBit1,MDAC_PinBit1,GET_BIT((u8)song_raw[sample_counter],1));
    MGPIO_voidSetPinValue(MDAC_PortBit2,MDAC_PinBit2,GET_BIT((u8)song_raw[sample_counter],2));
    MGPIO_voidSetPinValue(MDAC_PortBit3,MDAC_PinBit3,GET_BIT((u8)song_raw[sample_counter],3));
    MGPIO_voidSetPinValue(MDAC_PortBit4,MDAC_PinBit4,GET_BIT((u8)song_raw[sample_counter],4));
    MGPIO_voidSetPinValue(MDAC_PortBit5,MDAC_PinBit5,GET_BIT((u8)song_raw[sample_counter],5));
    MGPIO_voidSetPinValue(MDAC_PortBit6,MDAC_PinBit6,GET_BIT((u8)song_raw[sample_counter],6));
    MGPIO_voidSetPinValue(MDAC_PortBit7,MDAC_PinBit7,GET_BIT((u8)song_raw[sample_counter],7));
    sample_counter++;

    if(sample_counter==song_length)
    {
      sample_counter=0;
    }
    


}

void MDAC_voidInit(void)
{
  MGPIO_voidSetPinDirection(MDAC_PortBit0,MDAC_PinBit0,OUTPUT_MAX_10_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(MDAC_PortBit1,MDAC_PinBit1,OUTPUT_MAX_10_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(MDAC_PortBit2,MDAC_PinBit2,OUTPUT_MAX_10_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(MDAC_PortBit3,MDAC_PinBit3,OUTPUT_MAX_10_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(MDAC_PortBit4,MDAC_PinBit4,OUTPUT_MAX_10_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(MDAC_PortBit5,MDAC_PinBit5,OUTPUT_MAX_10_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(MDAC_PortBit6,MDAC_PinBit6,OUTPUT_MAX_10_MHZ,GP_PUSH_PULL_OUTPUT);
  MGPIO_voidSetPinDirection(MDAC_PortBit7,MDAC_PinBit7,OUTPUT_MAX_10_MHZ,GP_PUSH_PULL_OUTPUT);

  MSTK_VidInit();



}

void MDAC_voidPlay(void)
{
  MSTK_VidSetCallBack(MDAC_voidCALLBACK);
  MSTK_VidStart(125);

}
