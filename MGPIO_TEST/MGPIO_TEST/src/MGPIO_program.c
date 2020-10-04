/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 02 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MGPIO_INTERFACE.h"
#include "MGPIO_PRIVATE.h"
#include "MGPIO_config.h"


void MGPIO_voidSetMode(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,u32 MGPIO_u32Register,u8 MGPIO_U8ModeBit0,u8 MGPIO_U8ModeBit1,u8 MGPIO_U8ConfigBit0,u8 MGPIO_U8ConfigBit1);


void MGPIO_voidSetPinDirection(PORTID MGPIO_portidPORTID,PINID MGPIO_pinidPINID,MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE)
{
  switch (MGPIO_portidPORTID)
  {
    case PORTA:
    switch (MGPIO_pinidPINID)
    {
      case PIN0 :
      MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRL,MODE0_0_CRL,MODE0_1_CRL,CNF0_0_CRL,CNF0_1_CRL);
            break;
      case PIN1 :
            MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRL,MODE1_0_CRL,MODE1_1_CRL,CNF1_0_CRL,CNF1_1_CRL);
              break;
      case PIN2 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRL,MODE2_0_CRL,MODE2_1_CRL,CNF2_0_CRL,CNF2_1_CRL);
              break;
      case PIN3 :
            MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRL,MODE3_0_CRL,MODE3_1_CRL,CNF3_0_CRL,CNF3_1_CRL);
              break;
      case PIN4 :
            MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRL,MODE4_0_CRL,MODE4_1_CRL,CNF4_0_CRL,CNF4_1_CRL);
            break;
      case PIN5 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRL,MODE5_0_CRL,MODE5_1_CRL,CNF5_0_CRL,CNF5_1_CRL);
            break;
      case PIN6 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRL,MODE6_0_CRL,MODE6_1_CRL,CNF6_0_CRL,CNF6_1_CRL);
            break;
      case PIN7 :
            MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRL,MODE7_0_CRL,MODE7_1_CRL,CNF7_0_CRL,CNF7_1_CRL);
            break;
      case PIN8 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRH,MODE8_0_CRH,MODE8_1_CRH,CNF8_0_CRH,CNF8_1_CRH);
            break;
      case PIN9 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRH,MODE9_0_CRH,MODE9_1_CRH,CNF9_0_CRH,CNF9_1_CRH);
            break;
      case PIN10:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRH,MODE10_0_CRH,MODE10_1_CRH,CNF10_0_CRH,CNF10_1_CRH);
              break;
      case PIN11:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRH,MODE11_0_CRH,MODE11_1_CRH,CNF11_0_CRH,CNF11_1_CRH);
            break;
      case PIN12:
      MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRH,MODE12_0_CRH,MODE12_1_CRH,CNF12_0_CRH,CNF12_1_CRH);
            break;
      case PIN13:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRH,MODE13_0_CRH,MODE13_1_CRH,CNF13_0_CRH,CNF13_1_CRH);
            break;
      case PIN14:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRH,MODE14_0_CRH,MODE14_1_CRH,CNF14_0_CRH,CNF14_1_CRH);
            break;
      case PIN15:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOA->MGPIOA_CRH,MODE15_0_CRH,MODE15_1_CRH,CNF15_0_CRH,CNF15_1_CRH);
            break;

    }

     break;

    case PORTB:
    switch (MGPIO_pinidPINID)
    {
      case PIN0 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRL,MODE0_0_CRL,MODE0_1_CRL,CNF0_0_CRL,CNF0_1_CRL);
            break;
      case PIN1 :
            MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRL,MODE1_0_CRL,MODE1_1_CRL,CNF1_0_CRL,CNF1_1_CRL);
            break;
      case PIN2 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRL,MODE2_0_CRL,MODE2_1_CRL,CNF2_0_CRL,CNF2_1_CRL);
            break;
      case PIN3 :
            MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRL,MODE3_0_CRL,MODE3_1_CRL,CNF3_0_CRL,CNF3_1_CRL);
            break;
      case PIN4 :
            MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRL,MODE4_0_CRL,MODE4_1_CRL,CNF4_0_CRL,CNF4_1_CRL);
            break;
      case PIN5 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRL,MODE5_0_CRL,MODE5_1_CRL,CNF5_0_CRL,CNF5_1_CRL);
            break;
      case PIN6 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRL,MODE6_0_CRL,MODE6_1_CRL,CNF6_0_CRL,CNF6_1_CRL);
            break;
      case PIN7 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRL,MODE7_0_CRL,MODE7_1_CRL,CNF7_0_CRL,CNF7_1_CRL);
            break;
      case PIN8 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRH,MODE8_0_CRH,MODE8_1_CRH,CNF8_0_CRH,CNF8_1_CRH);
              break;
      case PIN9 :
            MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRH,MODE9_0_CRH,MODE9_1_CRH,CNF9_0_CRH,CNF9_1_CRH);
            break;
      case PIN10:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRH,MODE10_0_CRH,MODE10_1_CRH,CNF10_0_CRH,CNF10_1_CRH);
          break;
      case PIN11:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRH,MODE11_0_CRH,MODE11_1_CRH,CNF11_0_CRH,CNF11_1_CRH);
            break;
      case PIN12:
            MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRH,MODE12_0_CRH,MODE12_1_CRH,CNF12_0_CRH,CNF12_1_CRH);
              break;
      case PIN13:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRH,MODE13_0_CRH,MODE13_1_CRH,CNF13_0_CRH,CNF13_1_CRH);
              break;
      case PIN14:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRH,MODE14_0_CRH,MODE14_1_CRH,CNF14_0_CRH,CNF14_1_CRH);
              break;
      case PIN15:
            MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOB->MGPIOB_CRH,MODE15_0_CRH,MODE15_1_CRH,CNF15_0_CRH,CNF15_1_CRH);
              break;

    }

     break;

    case PORTC:
    switch (MGPIO_pinidPINID)
    {
      case PIN0 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRL,MODE0_0_CRL,MODE0_1_CRL,CNF0_0_CRL,CNF0_1_CRL);
            break;
      case PIN1 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRL,MODE1_0_CRL,MODE1_1_CRL,CNF1_0_CRL,CNF1_1_CRL);
              break;
      case PIN2 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRL,MODE2_0_CRL,MODE2_1_CRL,CNF2_0_CRL,CNF2_1_CRL);
            break;
      case PIN3 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRL,MODE3_0_CRL,MODE3_1_CRL,CNF3_0_CRL,CNF3_1_CRL);
            break;
      case PIN4 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRL,MODE4_0_CRL,MODE4_1_CRL,CNF4_0_CRL,CNF4_1_CRL);
            break;
      case PIN5 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRL,MODE5_0_CRL,MODE5_1_CRL,CNF5_0_CRL,CNF5_1_CRL);
            break;
      case PIN6 :
            MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRL,MODE6_0_CRL,MODE6_1_CRL,CNF6_0_CRL,CNF6_1_CRL);
            break;
      case PIN7 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRL,MODE7_0_CRL,MODE7_1_CRL,CNF7_0_CRL,CNF7_1_CRL);
            break;
      case PIN8 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRH,MODE8_0_CRH,MODE8_1_CRH,CNF8_0_CRH,CNF8_1_CRH);
              break;
      case PIN9 :
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRH,MODE9_0_CRH,MODE9_1_CRH,CNF9_0_CRH,CNF9_1_CRH);
            break;
      case PIN10:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRH,MODE10_0_CRH,MODE10_1_CRH,CNF10_0_CRH,CNF10_1_CRH);
            break;
      case PIN11:
            MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRH,MODE11_0_CRH,MODE11_1_CRH,CNF11_0_CRH,CNF11_1_CRH);
            break;
      case PIN12:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRH,MODE12_0_CRH,MODE12_1_CRH,CNF12_0_CRH,CNF12_1_CRH);
            break;
      case PIN13:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRH,MODE13_0_CRH,MODE13_1_CRH,CNF13_0_CRH,CNF13_1_CRH);
            break;
      case PIN14:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRH,MODE14_0_CRH,MODE14_1_CRH,CNF14_0_CRH,CNF14_1_CRH);
          break;
      case PIN15:
          MGPIO_voidSetMode(MGPIO_modeMODEID,MGPIO_stateSTATE,MGPIOC->MGPIOC_CRH,MODE15_0_CRH,MODE15_1_CRH,CNF15_0_CRH,CNF15_1_CRH);
            break;

    }

     break;

  }

}




void MGPIO_voidSetMode(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,u32 MGPIO_u32Register,u8 MGPIO_U8ModeBit0,u8 MGPIO_U8ModeBit1,u8 MGPIO_U8ConfigBit0,u8 MGPIO_U8ConfigBit1)
{
  switch (MGPIO_modeMODEID)
   {
    case INPUT_MODE  :
    switch (MGPIO_stateSTATE)
     {

      case Analog_INPUT:
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);
            break;
      case Floating_INPUT:
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);
          break;

      case PU_PD_INPUT:
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);
             break;


      break;
    }

     break;
    case OUTPUT_MAX_10_MHZ:
    switch (MGPIO_stateSTATE)
    {
      case GP_PUSH_PULL_OUTPUT :
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);

      break;
      case GP_OPEN_DRAIN_OUTPUT:
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);

       break;
      case AF_PUSH_PULL_OUTPUT :
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);

       break;
      case AF_OPEN_DRAIN_OUTPUT:
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);

       break;

    }
    break;
    case OUTPUT_MAX_2_MHZ :
    switch (MGPIO_stateSTATE)
    {
      case GP_PUSH_PULL_OUTPUT :
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);

       break;
      case GP_OPEN_DRAIN_OUTPUT:
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);

       break;
      case AF_PUSH_PULL_OUTPUT :
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);

       break;
      case AF_OPEN_DRAIN_OUTPUT:
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);
       break;

    }

     break;
    case OUTPUT_MAX_50_MHZ:
    switch (MGPIO_stateSTATE)
    {
      case GP_PUSH_PULL_OUTPUT :
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);

       break;
      case GP_OPEN_DRAIN_OUTPUT:
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);

       break;
      case AF_PUSH_PULL_OUTPUT :
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      CLR_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);
       break;
      case AF_OPEN_DRAIN_OUTPUT:
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ModeBit1);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit0);
      SET_BIT(MGPIO_u32Register,MGPIO_U8ConfigBit1);

       break;

    }

     break;
  }

}

///////////////
u8 MGPIO_u8GetPinValue(PORTID MGPIO_portidPORTID, PINID MGPIO_pinidPINID)
{
  u8 LocaLresult=0;
  switch (MGPIO_portidPORTID)
  {
    case PORTA:
    LocaLresult=GET_BIT(MGPIOA->MGPIOA_IDR,MGPIO_pinidPINID);
     break;
    case PORTB:
    LocaLresult=GET_BIT(MGPIOB->MGPIOB_IDR,MGPIO_pinidPINID);
     break;
    case PORTC:
    LocaLresult=GET_BIT(MGPIOC->MGPIOC_IDR,MGPIO_pinidPINID);
     break;

  }

  return LocaLresult;
}

////////////
void  MGPIO_voidSetPinValue(PORTID MGPIO_portidPORTID, PINID MGPIO_pinidPINID,BIT_VALUE MGPIO_BitValue)
{
  switch (MGPIO_portidPORTID)
  {
    case PORTA :
    if (MGPIO_BitValue==MGPIO_HIGH)
    {
     SET_BIT(MGPIOA->MGPIOA_ODR,MGPIO_pinidPINID);
    }
    else if (MGPIO_BitValue==MGPIO_LOW)
    {
      CLR_BIT(MGPIOA->MGPIOA_ODR,MGPIO_pinidPINID);
    }
      break;
    case PORTB :
    if (MGPIO_BitValue==MGPIO_HIGH)
    {
     SET_BIT(MGPIOB->MGPIOB_ODR,MGPIO_pinidPINID);
    }
    else if (MGPIO_BitValue==MGPIO_LOW)
    {
      CLR_BIT(MGPIOB->MGPIOB_ODR,MGPIO_pinidPINID);
    }

    break;
    case PORTC :
    if (MGPIO_BitValue==MGPIO_HIGH)
    {
     SET_BIT(MGPIOC->MGPIOC_ODR,MGPIO_pinidPINID);
    }
    else if (MGPIO_BitValue==MGPIO_LOW)
    {
      CLR_BIT(MGPIOC->MGPIOC_ODR,MGPIO_pinidPINID);
    }


    break;
  }


}
