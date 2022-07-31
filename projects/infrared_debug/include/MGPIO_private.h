/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 02 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  MGPIO_PRIVATE_H
#define  MGPIO_PRIVATE_H

#define MGPIOA_BASE_ADDRESS  0x40010800
#define MGPIOB_BASE_ADDRESS  0x40010C00
#define MGPIOC_BASE_ADDRESS  0x40011000




// GPIOA registers addresses
typedef struct
{
 volatile u32 MGPIOA_CRL;
 volatile u32 MGPIOA_CRH;
 volatile u32 MGPIOA_IDR;
 volatile u32 MGPIOA_ODR;
 volatile u32 MGPIOA_BSRR;
 volatile u32 MGPIOA_BRR;
 volatile u32 MGPIOA_LCKR;

}MGPIOA_RT;

#define MGPIOA  ((volatile MGPIOA_RT*) 0x40010800)


// MGPIOB registers addresses
typedef struct
{
 volatile u32 MGPIOB_CRL;
 volatile u32 MGPIOB_CRH;
 volatile u32 MGPIOB_IDR;
 volatile u32 MGPIOB_ODR;
 volatile u32 MGPIOB_BSRR;
 volatile u32 MGPIOB_BRR;
 volatile u32 MGPIOB_LCKR;

}MGPIOB_RT;

#define MGPIOB  ((volatile MGPIOB_RT*) MGPIOB_BASE_ADDRESS)



// MGPIOC registers addresses
typedef struct 
{
 volatile u32 MGPIOC_CRL;
 volatile u32 MGPIOC_CRH;
 volatile u32 MGPIOC_IDR;
 volatile u32 MGPIOC_ODR;
 volatile u32 MGPIOC_BSRR;
 volatile u32 MGPIOC_BRR;
 volatile u32 MGPIOC_LCKR;

}MGPIOC_RT;

#define MGPIOC  ((volatile MGPIOC_RT*) MGPIOC_BASE_ADDRESS)



///////// PORTA PIN direction  SUBFUNCTION //////////////////
static void MGPIO_voidSetPAMode_CRL(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,MGPIOX_CRL_BITS MGPIO_ModeBit0,MGPIOX_CRL_BITS MGPIO_ModeBit1,MGPIOX_CRL_BITS MGPIO_ConfigBit0,MGPIOX_CRL_BITS MGPIO_ConfigBit1);

static void MGPIO_voidSetPAMode_CRH(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,MGPIOX_CRH_BITS MGPIO_ModeBit0,MGPIOX_CRH_BITS MGPIO_ModeBit1,MGPIOX_CRH_BITS MGPIO_ConfigBit0,MGPIOX_CRH_BITS MGPIO_ConfigBit1);

static void MGPIO_voidSetPApinDirection(PIN_T MGPIO_pinPINID,MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE);

//////////////////PORTB PIN direction subfunction  ////////////////////
static void MGPIO_voidSetPBMode_CRL(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,MGPIOX_CRL_BITS MGPIO_ModeBit0,MGPIOX_CRL_BITS MGPIO_ModeBit1,MGPIOX_CRL_BITS MGPIO_ConfigBit0,MGPIOX_CRL_BITS MGPIO_ConfigBit1);

static void MGPIO_voidSetPBMode_CRH(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,MGPIOX_CRH_BITS MGPIO_ModeBit0,MGPIOX_CRH_BITS MGPIO_ModeBit1,MGPIOX_CRH_BITS MGPIO_ConfigBit0,MGPIOX_CRH_BITS MGPIO_ConfigBit1);

static void MGPIO_voidSetPBpinDirection(PIN_T MGPIO_pinPINID,MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE);
////////////////PORTC PIN direction subfunction ////////////////////
static void MGPIO_voidSetPCMode_CRL(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,MGPIOX_CRL_BITS MGPIO_ModeBit0,MGPIOX_CRL_BITS MGPIO_ModeBit1,MGPIOX_CRL_BITS MGPIO_ConfigBit0,MGPIOX_CRL_BITS MGPIO_ConfigBit1);

static void MGPIO_voidSetPCMode_CRH(MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE,MGPIOX_CRH_BITS MGPIO_ModeBit0,MGPIOX_CRH_BITS MGPIO_ModeBit1,MGPIOX_CRH_BITS MGPIO_ConfigBit0,MGPIOX_CRH_BITS MGPIO_ConfigBit1);

static void MGPIO_voidSetPCpinDirection(PIN_T MGPIO_pinPINID,MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE);



#endif
