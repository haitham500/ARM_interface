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


///////// PORTA PIN direction //////////////////
void MGPIO_voidSetPAMode_CRL(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,MGPIOX_CRL_BITS MGPIO_ModeBit0,MGPIOX_CRL_BITS MGPIO_ModeBit1,MGPIOX_CRL_BITS MGPIO_ConfigBit0,MGPIOX_CRL_BITS MGPIO_ConfigBit1)
{
  switch (MGPIO_modeMODEID)
   {
    case INPUT_MODE  :
    	if(MGPIO_stateSTATE== Analog_INPUT)
    	{
    		 CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    		 CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
             CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    	     CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);
    	}
    	else if (MGPIO_stateSTATE== Floating_INPUT)
    	{
    		 CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    	     CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    		 SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    		 CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);
    	}
    	else if (MGPIO_stateSTATE==PU_PD_INPUT)
		{
    		CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    	    CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    	    CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    	    SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);
		}

     break;
    case OUTPUT_MAX_10_MHZ:
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	{
    		 SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    		 CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    		 CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    		 CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	{
    		SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    		CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    		SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    		CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	{

    	      SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    	      CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    	      CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    	      SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	{
    		  SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    		  CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    		  SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    		  SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);


    	}

    break;
    case OUTPUT_MAX_2_MHZ :
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	    	{

    	            CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    	            SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    	            CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    	            CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	    	{

    	    	      CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    	    	      SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    	    	      SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    	    	      CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	    	{

    	    	      CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    	    	      SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    	    	      CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    	    	      SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    	    	    SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    	    	    SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    	    	    SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);
    	    	}


     break;
    case OUTPUT_MAX_50_MHZ:
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	    	{
    		      SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    		      SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    		      CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    		      CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		   SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    	    		   SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    	    		   SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    	    		   CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	    	{
    	    		 SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    	    		 SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    	    		 CLR_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    	    		 SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);
    	    	}
    	    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit0);
    	    	    SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ModeBit1);
    	    	    SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit0);
    	    	    SET_BIT(MGPIOA->MGPIOA_CRL,MGPIO_ConfigBit1);
    	    	}

     break;
  }

}


void MGPIO_voidSetPAMode_CRH(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,MGPIOX_CRH_BITS MGPIO_ModeBit0,MGPIOX_CRH_BITS MGPIO_ModeBit1,MGPIOX_CRH_BITS MGPIO_ConfigBit0,MGPIOX_CRH_BITS MGPIO_ConfigBit1)
{
  switch (MGPIO_modeMODEID)
   {
    case INPUT_MODE  :
    	if(MGPIO_stateSTATE== Analog_INPUT)
    	{
    		 CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    		 CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
             CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    	     CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);
    	}
    	else if (MGPIO_stateSTATE== Floating_INPUT)
    	{
    		 CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    	     CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    		 SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    		 CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);
    	}
    	else if (MGPIO_stateSTATE==PU_PD_INPUT)
		{
    		CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    	    CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    	    CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    	    SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);
		}

     break;
    case OUTPUT_MAX_10_MHZ:
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	{
    		 SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    		 CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    		 CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    		 CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	{
    		SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    		CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    		SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    		CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	{

    	      SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    	      CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    	      CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    	      SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	{
    		  SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    		  CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    		  SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    		  SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);


    	}

    break;
    case OUTPUT_MAX_2_MHZ :
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	    	{

    	            CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    	            SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    	            CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    	            CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	    	{

    	    	      CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    	    	      SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    	    	      SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    	    	      CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	    	{

    	    	      CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    	    	      SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    	    	      CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    	    	      SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    	    	    SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    	    	    SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    	    	    SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);
    	    	}


     break;
    case OUTPUT_MAX_50_MHZ:
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	    	{
    		      SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    		      SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    		      CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    		      CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		   SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    	    		   SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    	    		   SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    	    		   CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	    	{
    	    		 SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    	    		 SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    	    		 CLR_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    	    		 SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);
    	    	}
    	    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit0);
    	    	    SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ModeBit1);
    	    	    SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit0);
    	    	    SET_BIT(MGPIOA->MGPIOA_CRH,MGPIO_ConfigBit1);
    	    	}

     break;
  }

}

void MGPIO_voidSetPApinDirection(PIN_T MGPIO_pinPINID,MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE)
{
  switch (MGPIO_pinPINID)
  {
    case PIN0 :
    MGPIO_voidSetPAMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE0_0_CRL,MODE0_1_CRL,CNF0_0_CRL,CNF0_1_CRL);
          break;
    case PIN1 :
    MGPIO_voidSetPAMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE1_0_CRL,MODE1_1_CRL,CNF1_0_CRL,CNF1_1_CRL);
            break;
    case PIN2 :
    MGPIO_voidSetPAMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE2_0_CRL,MODE2_1_CRL,CNF2_0_CRL,CNF2_1_CRL);
            break;
    case PIN3 :
    MGPIO_voidSetPAMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE3_0_CRL,MODE3_1_CRL,CNF3_0_CRL,CNF3_1_CRL);
            break;
    case PIN4 :
    MGPIO_voidSetPAMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE4_0_CRL,MODE4_1_CRL,CNF4_0_CRL,CNF4_1_CRL);
          break;
    case PIN5 :
    MGPIO_voidSetPAMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE5_0_CRL,MODE5_1_CRL,CNF5_0_CRL,CNF5_1_CRL);
          break;
    case PIN6 :
    MGPIO_voidSetPAMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE6_0_CRL,MODE6_1_CRL,CNF6_0_CRL,CNF6_1_CRL);
          break;
    case PIN7 :
    MGPIO_voidSetPAMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE7_0_CRL,MODE7_1_CRL,CNF7_0_CRL,CNF7_1_CRL);
          break;
    case PIN8 :
    MGPIO_voidSetPAMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE8_0_CRH,MODE8_1_CRH,CNF8_0_CRH,CNF8_1_CRH);
          break;
    case PIN9 :
    MGPIO_voidSetPAMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE9_0_CRH,MODE9_1_CRH,CNF9_0_CRH,CNF9_1_CRH);
          break;
    case PIN10:
    MGPIO_voidSetPAMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE10_0_CRH,MODE10_1_CRH,CNF10_0_CRH,CNF10_1_CRH);
            break;
    case PIN11:
    MGPIO_voidSetPAMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE11_0_CRH,MODE11_1_CRH,CNF11_0_CRH,CNF11_1_CRH);
          break;
    case PIN12:
    MGPIO_voidSetPAMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE12_0_CRH,MODE12_1_CRH,CNF12_0_CRH,CNF12_1_CRH);
          break;
    case PIN13:
    MGPIO_voidSetPAMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE13_0_CRH,MODE13_1_CRH,CNF13_0_CRH,CNF13_1_CRH);
          break;
    case PIN14:
    MGPIO_voidSetPAMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE14_0_CRH,MODE14_1_CRH,CNF14_0_CRH,CNF14_1_CRH);
          break;
    case PIN15:
    MGPIO_voidSetPAMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE15_0_CRH,MODE15_1_CRH,CNF15_0_CRH,CNF15_1_CRH);
          break;

  }

}

//////////////////PORTB PIN direction////////////////////

void MGPIO_voidSetPBMode_CRL(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,MGPIOX_CRL_BITS MGPIO_ModeBit0,MGPIOX_CRL_BITS MGPIO_ModeBit1,MGPIOX_CRL_BITS MGPIO_ConfigBit0,MGPIOX_CRL_BITS MGPIO_ConfigBit1)
{
  switch (MGPIO_modeMODEID)
   {
    case INPUT_MODE  :
    	if(MGPIO_stateSTATE== Analog_INPUT)
    	{
    		 CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    		 CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
             CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    	     CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);
    	}
    	else if (MGPIO_stateSTATE== Floating_INPUT)
    	{
    		 CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    	     CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    		 SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    		 CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);
    	}
    	else if (MGPIO_stateSTATE==PU_PD_INPUT)
		{
    		CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    	    CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    	    CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    	    SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);
		}

     break;
    case OUTPUT_MAX_10_MHZ:
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	{
    		 SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    		 CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    		 CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    		 CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	{
    		SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    		CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    		SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    		CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	{

    	      SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    	      CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    	      CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    	      SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	{
    		  SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    		  CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    		  SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    		  SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);


    	}

    break;
    case OUTPUT_MAX_2_MHZ :
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	    	{

    	            CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    	            SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    	            CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    	            CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	    	{

    	    	      CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    	    	      SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    	    	      SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    	    	      CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	    	{

    	    	      CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    	    	      SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    	    	      CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    	    	      SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    	    	    SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    	    	    SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    	    	    SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);
    	    	}


     break;
    case OUTPUT_MAX_50_MHZ:
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	    	{
    		      SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    		      SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    		      CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    		      CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		   SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    	    		   SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    	    		   SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    	    		   CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	    	{
    	    		 SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    	    		 SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    	    		 CLR_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    	    		 SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);
    	    	}
    	    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit0);
    	    	    SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ModeBit1);
    	    	    SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit0);
    	    	    SET_BIT(MGPIOB->MGPIOB_CRL,MGPIO_ConfigBit1);
    	    	}

     break;
  }

}


void MGPIO_voidSetPBMode_CRH(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,MGPIOX_CRH_BITS MGPIO_ModeBit0,MGPIOX_CRH_BITS MGPIO_ModeBit1,MGPIOX_CRH_BITS MGPIO_ConfigBit0,MGPIOX_CRH_BITS MGPIO_ConfigBit1)
{
  switch (MGPIO_modeMODEID)
   {
    case INPUT_MODE  :
    	if(MGPIO_stateSTATE== Analog_INPUT)
    	{
    		 CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    		 CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
             CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    	     CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);
    	}
    	else if (MGPIO_stateSTATE== Floating_INPUT)
    	{
    		 CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    	     CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    		 SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    		 CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);
    	}
    	else if (MGPIO_stateSTATE==PU_PD_INPUT)
		{
    		CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    	    CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    	    CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    	    SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);
		}

     break;
    case OUTPUT_MAX_10_MHZ:
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	{
    		 SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    		 CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    		 CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    		 CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	{
    		SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    		CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    		SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    		CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	{

    	      SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    	      CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    	      CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    	      SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	{
    		  SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    		  CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    		  SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    		  SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);


    	}

    break;
    case OUTPUT_MAX_2_MHZ :
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	    	{

    	            CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    	            SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    	            CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    	            CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	    	{

    	    	      CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    	    	      SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    	    	      SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    	    	      CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	    	{

    	    	      CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    	    	      SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    	    	      CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    	    	      SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    	    	    SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    	    	    SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    	    	    SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);
    	    	}


     break;
    case OUTPUT_MAX_50_MHZ:
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	    	{
    		      SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    		      SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    		      CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    		      CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		   SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    	    		   SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    	    		   SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    	    		   CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	    	{
    	    		 SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    	    		 SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    	    		 CLR_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    	    		 SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);
    	    	}
    	    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit0);
    	    	    SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ModeBit1);
    	    	    SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit0);
    	    	    SET_BIT(MGPIOB->MGPIOB_CRH,MGPIO_ConfigBit1);
    	    	}

     break;
  }

}

void MGPIO_voidSetPBpinDirection(PIN_T MGPIO_pinPINID,MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE)
{
  switch (MGPIO_pinPINID)
  {
    case PIN0 :
    MGPIO_voidSetPBMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE0_0_CRL,MODE0_1_CRL,CNF0_0_CRL,CNF0_1_CRL);
          break;
    case PIN1 :
    MGPIO_voidSetPBMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE1_0_CRL,MODE1_1_CRL,CNF1_0_CRL,CNF1_1_CRL);
            break;
    case PIN2 :
    MGPIO_voidSetPBMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE2_0_CRL,MODE2_1_CRL,CNF2_0_CRL,CNF2_1_CRL);
            break;
    case PIN3 :
    MGPIO_voidSetPBMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE3_0_CRL,MODE3_1_CRL,CNF3_0_CRL,CNF3_1_CRL);
            break;
    case PIN4 :
    MGPIO_voidSetPBMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE4_0_CRL,MODE4_1_CRL,CNF4_0_CRL,CNF4_1_CRL);
          break;
    case PIN5 :
    MGPIO_voidSetPBMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE5_0_CRL,MODE5_1_CRL,CNF5_0_CRL,CNF5_1_CRL);
          break;
    case PIN6 :
    MGPIO_voidSetPBMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE6_0_CRL,MODE6_1_CRL,CNF6_0_CRL,CNF6_1_CRL);
          break;
    case PIN7 :
    MGPIO_voidSetPBMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE7_0_CRL,MODE7_1_CRL,CNF7_0_CRL,CNF7_1_CRL);
          break;
    case PIN8 :
    MGPIO_voidSetPBMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE8_0_CRH,MODE8_1_CRH,CNF8_0_CRH,CNF8_1_CRH);
          break;
    case PIN9 :
    MGPIO_voidSetPBMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE9_0_CRH,MODE9_1_CRH,CNF9_0_CRH,CNF9_1_CRH);
          break;
    case PIN10:
    MGPIO_voidSetPBMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE10_0_CRH,MODE10_1_CRH,CNF10_0_CRH,CNF10_1_CRH);
            break;
    case PIN11:
    MGPIO_voidSetPBMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE11_0_CRH,MODE11_1_CRH,CNF11_0_CRH,CNF11_1_CRH);
          break;
    case PIN12:
    MGPIO_voidSetPBMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE12_0_CRH,MODE12_1_CRH,CNF12_0_CRH,CNF12_1_CRH);
          break;
    case PIN13:
    MGPIO_voidSetPBMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE13_0_CRH,MODE13_1_CRH,CNF13_0_CRH,CNF13_1_CRH);
          break;
    case PIN14:
    MGPIO_voidSetPBMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE14_0_CRH,MODE14_1_CRH,CNF14_0_CRH,CNF14_1_CRH);
          break;
    case PIN15:
    MGPIO_voidSetPBMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE15_0_CRH,MODE15_1_CRH,CNF15_0_CRH,CNF15_1_CRH);
          break;

  }

}



////////////////PORTC PIN direction////////////////////


void MGPIO_voidSetPCMode_CRL(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,MGPIOX_CRL_BITS MGPIO_ModeBit0,MGPIOX_CRL_BITS MGPIO_ModeBit1,MGPIOX_CRL_BITS MGPIO_ConfigBit0,MGPIOX_CRL_BITS MGPIO_ConfigBit1)
{
  switch (MGPIO_modeMODEID)
   {
    case INPUT_MODE  :
    	if(MGPIO_stateSTATE== Analog_INPUT)
    	{
    		 CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    		 CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
             CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    	     CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);
    	}
    	else if (MGPIO_stateSTATE== Floating_INPUT)
    	{
    		 CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    	     CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    		 SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    		 CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);
    	}
    	else if (MGPIO_stateSTATE==PU_PD_INPUT)
		{
    		CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    	    CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    	    CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    	    SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);
		}

     break;
    case OUTPUT_MAX_10_MHZ:
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	{
    		 SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    		 CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    		 CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    		 CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	{
    		SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    		CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    		SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    		CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	{

    	      SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    	      CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    	      CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    	      SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	{
    		  SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    		  CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    		  SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    		  SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);


    	}

    break;
    case OUTPUT_MAX_2_MHZ :
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	    	{

    	            CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    	            SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    	            CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    	            CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	    	{

    	    	      CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    	    	      SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    	    	      SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    	    	      CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	    	{

    	    	      CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    	    	      SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    	    	      CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    	    	      SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    	    	    SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    	    	    SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    	    	    SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);
    	    	}


     break;
    case OUTPUT_MAX_50_MHZ:
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	    	{
    		      SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    		      SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    		      CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    		      CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		   SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    	    		   SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    	    		   SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    	    		   CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	    	{
    	    		 SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    	    		 SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    	    		 CLR_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    	    		 SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);
    	    	}
    	    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit0);
    	    	    SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ModeBit1);
    	    	    SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit0);
    	    	    SET_BIT(MGPIOC->MGPIOC_CRL,MGPIO_ConfigBit1);
    	    	}

     break;
  }

}


void MGPIO_voidSetPCMode_CRH(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,MGPIOX_CRH_BITS MGPIO_ModeBit0,MGPIOX_CRH_BITS MGPIO_ModeBit1,MGPIOX_CRH_BITS MGPIO_ConfigBit0,MGPIOX_CRH_BITS MGPIO_ConfigBit1)
{
  switch (MGPIO_modeMODEID)
   {
    case INPUT_MODE  :
    	if(MGPIO_stateSTATE== Analog_INPUT)
    	{
    		 CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    		 CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
             CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    	     CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);
    	}
    	else if (MGPIO_stateSTATE== Floating_INPUT)
    	{
    		 CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    	     CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    		 SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    		 CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);
    	}
    	else if (MGPIO_stateSTATE==PU_PD_INPUT)
		{
    		CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    	    CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    	    CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    	    SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);
		}

     break;
    case OUTPUT_MAX_10_MHZ:
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	{
    		 SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    		 CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    		 CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    		 CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	{
    		SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    		CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    		SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    		CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	{

    	      SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    	      CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    	      CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    	      SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);

    	}
    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	{
    		  SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    		  CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    		  SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    		  SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);


    	}

    break;
    case OUTPUT_MAX_2_MHZ :
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	    	{

    	            CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    	            SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    	            CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    	            CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	    	{

    	    	      CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    	    	      SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    	    	      SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    	    	      CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	    	{

    	    	      CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    	    	      SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    	    	      CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    	    	      SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    	    	    SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    	    	    SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    	    	    SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);
    	    	}


     break;
    case OUTPUT_MAX_50_MHZ:
    	if(MGPIO_stateSTATE==GP_PUSH_PULL_OUTPUT)
    	    	{
    		      SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    		      SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    		      CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    		      CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==GP_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		   SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    	    		   SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    	    		   SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    	    		   CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);

    	    	}
    	    	else if(MGPIO_stateSTATE==AF_PUSH_PULL_OUTPUT)
    	    	{
    	    		 SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    	    		 SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    	    		 CLR_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    	    		 SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);
    	    	}
    	    	else if(MGPIO_stateSTATE==AF_OPEN_DRAIN_OUTPUT)
    	    	{
    	    		SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit0);
    	    	    SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ModeBit1);
    	    	    SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit0);
    	    	    SET_BIT(MGPIOC->MGPIOC_CRH,MGPIO_ConfigBit1);
    	    	}

     break;
  }

}

 void MGPIO_voidSetPCpinDirection(PIN_T MGPIO_pinPINID,MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE)
{
  switch (MGPIO_pinPINID)
  {
    case PIN0 :
    MGPIO_voidSetPCMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE0_0_CRL,MODE0_1_CRL,CNF0_0_CRL,CNF0_1_CRL);
          break;
    case PIN1 :
    MGPIO_voidSetPCMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE1_0_CRL,MODE1_1_CRL,CNF1_0_CRL,CNF1_1_CRL);
            break;
    case PIN2 :
    MGPIO_voidSetPCMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE2_0_CRL,MODE2_1_CRL,CNF2_0_CRL,CNF2_1_CRL);
            break;
    case PIN3 :
    MGPIO_voidSetPCMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE3_0_CRL,MODE3_1_CRL,CNF3_0_CRL,CNF3_1_CRL);
            break;
    case PIN4 :
    MGPIO_voidSetPCMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE4_0_CRL,MODE4_1_CRL,CNF4_0_CRL,CNF4_1_CRL);
          break;
    case PIN5 :
    MGPIO_voidSetPCMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE5_0_CRL,MODE5_1_CRL,CNF5_0_CRL,CNF5_1_CRL);
          break;
    case PIN6 :
    MGPIO_voidSetPCMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE6_0_CRL,MODE6_1_CRL,CNF6_0_CRL,CNF6_1_CRL);
          break;
    case PIN7 :
    MGPIO_voidSetPCMode_CRL(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE7_0_CRL,MODE7_1_CRL,CNF7_0_CRL,CNF7_1_CRL);
          break;
    case PIN8 :
    MGPIO_voidSetPCMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE8_0_CRH,MODE8_1_CRH,CNF8_0_CRH,CNF8_1_CRH);
          break;
    case PIN9 :
    MGPIO_voidSetPCMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE9_0_CRH,MODE9_1_CRH,CNF9_0_CRH,CNF9_1_CRH);
          break;
    case PIN10:
    MGPIO_voidSetPCMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE10_0_CRH,MODE10_1_CRH,CNF10_0_CRH,CNF10_1_CRH);
            break;
    case PIN11:
    MGPIO_voidSetPCMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE11_0_CRH,MODE11_1_CRH,CNF11_0_CRH,CNF11_1_CRH);
          break;
    case PIN12:
    MGPIO_voidSetPCMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE12_0_CRH,MODE12_1_CRH,CNF12_0_CRH,CNF12_1_CRH);
          break;
    case PIN13:
    MGPIO_voidSetPCMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE13_0_CRH,MODE13_1_CRH,CNF13_0_CRH,CNF13_1_CRH);
          break;
    case PIN14:
    MGPIO_voidSetPCMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE14_0_CRH,MODE14_1_CRH,CNF14_0_CRH,CNF14_1_CRH);
          break;
    case PIN15:
    MGPIO_voidSetPCMode_CRH(MGPIO_modeMODEID,MGPIO_stateSTATE,MODE15_0_CRH,MODE15_1_CRH,CNF15_0_CRH,CNF15_1_CRH);
          break;

  }

}





///////////Port pin direction///////////////////////
void MGPIO_voidSetPinDirection(PORT_T MGPIO_portPORTID,PIN_T MGPIO_pinPINID,MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE)
{
  switch (MGPIO_portPORTID)
  {
    case PORTA:
    MGPIO_voidSetPApinDirection(MGPIO_pinPINID,MGPIO_modeMODEID,MGPIO_stateSTATE);
     break;

    case PORTB:
    MGPIO_voidSetPBpinDirection(MGPIO_pinPINID,MGPIO_modeMODEID,MGPIO_stateSTATE);
     break;

    case PORTC:
    MGPIO_voidSetPCpinDirection(MGPIO_pinPINID,MGPIO_modeMODEID,MGPIO_stateSTATE);
     break;

  }

}





///////////////
u8 MGPIO_u8GetPinValue(PORT_T MGPIO_portPORTID, PIN_T MGPIO_pinPINID)
{
  u8 LocaLresult=0;
  switch (MGPIO_portPORTID)
  {
    case PORTA:
    LocaLresult=GET_BIT(MGPIOA->MGPIOA_IDR,MGPIO_pinPINID);
     break;
    case PORTB:
    LocaLresult=GET_BIT(MGPIOB->MGPIOB_IDR,MGPIO_pinPINID);
     break;
    case PORTC:
    LocaLresult=GET_BIT(MGPIOC->MGPIOC_IDR,MGPIO_pinPINID);
     break;

  }

  return LocaLresult;
}

////////////
void  MGPIO_voidSetPinValue(PORT_T MGPIO_portPORTID, PIN_T MGPIO_pinPINID,BIT_VALUE MGPIO_BitValue)
{
  switch (MGPIO_portPORTID)
  {
    case PORTA :
    if (MGPIO_BitValue==MGPIO_HIGH)
    {
     SET_BIT(MGPIOA->MGPIOA_ODR,MGPIO_pinPINID);
    }
    else if (MGPIO_BitValue==MGPIO_LOW)
    {
      CLR_BIT(MGPIOA->MGPIOA_ODR,MGPIO_pinPINID);
    }
      break;
    case PORTB :
    if (MGPIO_BitValue==MGPIO_HIGH)
    {
     SET_BIT(MGPIOB->MGPIOB_ODR,MGPIO_pinPINID);
    }
    else if (MGPIO_BitValue==MGPIO_LOW)
    {
      CLR_BIT(MGPIOB->MGPIOB_ODR,MGPIO_pinPINID);
    }

    break;
    case PORTC :
    if (MGPIO_BitValue==MGPIO_HIGH)
    {
     SET_BIT(MGPIOC->MGPIOC_ODR,MGPIO_pinPINID);
    }
    else if (MGPIO_BitValue==MGPIO_LOW)
    {
      CLR_BIT(MGPIOC->MGPIOC_ODR,MGPIO_pinPINID);
    }


    break;
  }


}
