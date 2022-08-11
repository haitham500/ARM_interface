/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 02 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  MGPIO_INTERFACE_H
#define  MGPIO_INTERFACE_H


typedef enum
{
  MODE0_0_CRL,
  MODE0_1_CRL,
  CNF0_0_CRL,
  CNF0_1_CRL,
  MODE1_0_CRL,
  MODE1_1_CRL,
  CNF1_0_CRL,
  CNF1_1_CRL,
  MODE2_0_CRL,
  MODE2_1_CRL,
  CNF2_0_CRL,
  CNF2_1_CRL,
  MODE3_0_CRL,
  MODE3_1_CRL,
  CNF3_0_CRL,
  CNF3_1_CRL,
  MODE4_0_CRL,
  MODE4_1_CRL,
  CNF4_0_CRL,
  CNF4_1_CRL,
  MODE5_0_CRL,
  MODE5_1_CRL,
  CNF5_0_CRL,
  CNF5_1_CRL,
  MODE6_0_CRL,
  MODE6_1_CRL,
  CNF6_0_CRL,
  CNF6_1_CRL,
  MODE7_0_CRL,
  MODE7_1_CRL,
  CNF7_0_CRL,
  CNF7_1_CRL
  /*
  Bits 31:30, 27:26,
  23:22, 19:18, 15:14,
  11:10, 7:6, 3:2
  CNFy[1:0]: Port x configuration bits (y= 0 .. 7)
  These bits are written by software to configure the corresponding I/O port.
  Refer to Table 20: Port bit configuration table.
  In input mode (MODE[1:0]=00):
  00: Analog mode
  01: Floating input (reset state)
  10: Input with pull-up / pull-down
  11: Reserved
  In output mode (MODE[1:0] > 00):
  00: General purpose output push-pull
  01: General purpose output Open-drain
  10: Alternate function output Push-pull
  11: Alternate function output Open-drain
  Bits 29:28, 25:24,
  21:20, 17:16, 13:12,
  9:8, 5:4, 1:0
  MODEy[1:0]: Port x mode bits (y= 0 .. 7)
  These bits are written by software to configure the corresponding I/O port.
  Refer to Table 20: Port bit configuration table.
  00: Input mode (reset state)
  01: Output mode, max speed 10 MHz.
  10: Output mode, max speed 2 MHz.
  11: Output mode, max speed 50 MHz.
  */

}MGPIOX_CRL_BITS;

typedef enum
{
  MODE8_0_CRH,
  MODE8_1_CRH,
  CNF8_0_CRH,
  CNF8_1_CRH,
  MODE9_0_CRH,
  MODE9_1_CRH,
  CNF9_0_CRH,
  CNF9_1_CRH,
  MODE10_0_CRH,
  MODE10_1_CRH,
  CNF10_0_CRH,
  CNF10_1_CRH,
  MODE11_0_CRH,
  MODE11_1_CRH,
  CNF11_0_CRH,
  CNF11_1_CRH,
  MODE12_0_CRH,
  MODE12_1_CRH,
  CNF12_0_CRH,
  CNF12_1_CRH,
  MODE13_0_CRH,
  MODE13_1_CRH,
  CNF13_0_CRH,
  CNF13_1_CRH,
  MODE14_0_CRH,
  MODE14_1_CRH,
  CNF14_0_CRH,
  CNF14_1_CRH,
  MODE15_0_CRH,
  MODE15_1_CRH,
  CNF15_0_CRH,
  CNF15_1_CRH
  /*
  Bits 31:30, 27:26,
  23:22, 19:18, 15:14,
  11:10, 7:6, 3:2
  CNFy[1:0]: Port x configuration bits (y= 8 .. 15)
  These bits are written by software to configure the corresponding I/O port.
  Refer to Table 20: Port bit configuration table.
  In input mode (MODE[1:0]=00):
  00: Analog mode
  01: Floating input (reset state)
  10: Input with pull-up / pull-down
  11: Reserved
  In output mode (MODE[1:0] > 00):
  00: General purpose output push-pull
  01: General purpose output Open-drain
  10: Alternate function output Push-pull
  11: Alternate function output Open-drain
  Bits 29:28, 25:24,
  21:20, 17:16, 13:12,
  9:8, 5:4, 1:0
  MODEy[1:0]: Port x mode bits (y= 8 .. 15)
  These bits are written by software to configure the corresponding I/O port.
  Refer to Table 20: Port bit configuration table.
  00: Input mode (reset state)
  01: Output mode, max speed 10 MHz.
  10: Output mode, max speed 2 MHz.
  11: Output mode, max speed 50 MHz.
  */

}MGPIOX_CRH_BITS;


typedef enum
{
  IDR0,
  IDR1,
  IDR2,
  IDR3,
  IDR4,
  IDR5,
  IDR6,
  IDR7,
  IDR8,
  IDR9,
  IDR10,
  IDR11,
  IDR12,
  IDR13,
  IDR14,
  IDR15,
  RESERVED_BIT_16_IDR,
  RESERVED_BIT_17_IDR,
  RESERVED_BIT_18_IDR,
  RESERVED_BIT_19_IDR,
  RESERVED_BIT_20_IDR,
  RESERVED_BIT_21_IDR,
  RESERVED_BIT_22_IDR,
  RESERVED_BIT_23_IDR,
  RESERVED_BIT_24_IDR,
  RESERVED_BIT_25_IDR,
  RESERVED_BIT_26_IDR,
  RESERVED_BIT_27_IDR,
  RESERVED_BIT_28_IDR,
  RESERVED_BIT_29_IDR,
  RESERVED_BIT_30_IDR,
  RESERVED_BIT_31_IDR

  /*
  Bits 31:16 Reserved, must be kept at reset value.
Bits 15:0 IDRy: Port input data (y= 0 .. 15)
These bits are read only and can be accessed in Word mode only. They contain the input
value of the corresponding I/O port.
  */

}MGPIOX_IDR_BITS;



typedef enum
{
  ODR0,
  ODR1,
  ODR2,
  ODR3,
  ODR4,
  ODR5,
  ODR6,
  ODR7,
  ODR8,
  ODR9,
  ODR10,
  ODR11,
  ODR12,
  ODR13,
  ODR14,
  ODR15,
  RESERVED_BIT_16_ODR,
  RESERVED_BIT_17_ODR,
  RESERVED_BIT_18_ODR,
  RESERVED_BIT_19_ODR,
  RESERVED_BIT_20_ODR,
  RESERVED_BIT_21_ODR,
  RESERVED_BIT_22_ODR,
  RESERVED_BIT_23_ODR,
  RESERVED_BIT_24_ODR,
  RESERVED_BIT_25_ODR,
  RESERVED_BIT_26_ODR,
  RESERVED_BIT_27_ODR,
  RESERVED_BIT_28_ODR,
  RESERVED_BIT_29_ODR,
  RESERVED_BIT_30_ODR,
  RESERVED_BIT_31_ODR

  /*
  Bits 31:16 Reserved, must be kept at reset value.
Bits 15:0 ODRy: Port output data (y= 0 .. 15)
These bits can be read and written by software and can be accessed in Word mode only.
Note: For atomic bit set/reset, the ODR bits can be individually set and cleared by writing to
the GPIOx_BSRR register (x = A .. G).
  */

}MGPIOX_ODR_BITS;


typedef enum
{
  BS0_BSRR,
  BS1_BSRR,
  BS2_BSRR,
  BS3_BSRR,
  BS4_BSRR,
  BS5_BSRR,
  BS6_BSRR,
  BS7_BSRR,
  BS8_BSRR,
  BS9_BSRR,
  BS10_BSRR,
  BS11_BSRR,
  BS12_BSRR,
  BS13_BSRR,
  BS14_BSRR,
  BS15_BSRR,

  BR0_BSRR,
  BR1_BSRR,
  BR2_BSRR,
  BR3_BSRR,
  BR4_BSRR,
  BR5_BSRR,
  BR6_BSRR,
  BR7_BSRR,
  BR8_BSRR,
  BR9_BSRR,
  BR10_BSRR,
  BR11_BSRR,
  BR12_BSRR,
  BR13_BSRR,
  BR14_BSRR,
  BR15_BSRR

  /*
  Bits 31:16 BRy: Port x Reset bit y (y= 0 .. 15)
These bits are write-only and can be accessed in Word mode only.
0: No action on the corresponding ODRx bit
1: Reset the corresponding ODRx bit
Note: If both BSx and BRx are set, BSx has priority.
Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
These bits are write-only and can be accessed in Word mode only.
0: No action on the corresponding ODRx bit
1: Set the corresponding ODRx bit
  */

}MGPIOX_BSRR_BITS;


typedef enum
{

  BR0,
  BR1,
  BR2,
  BR3,
  BR4,
  BR5,
  BR6,
  BR7,
  BR8,
  BR9,
  BR10,
  BR11,
  BR12,
  BR13,
  BR14,
  BR15,

  RESERVED_BIT_16_BRR,
  RESERVED_BIT_17_BRR,
  RESERVED_BIT_18_BRR,
  RESERVED_BIT_19_BRR,
  RESERVED_BIT_20_BRR,
  RESERVED_BIT_21_BRR,
  RESERVED_BIT_22_BRR,
  RESERVED_BIT_23_BRR,
  RESERVED_BIT_24_BRR,
  RESERVED_BIT_25_BRR,
  RESERVED_BIT_26_BRR,
  RESERVED_BIT_27_BRR,
  RESERVED_BIT_28_BRR,
  RESERVED_BIT_29_BRR,
  RESERVED_BIT_30_BRR,
  RESERVED_BIT_31_BRR

  /*
  Bits 31:16 Reserved
Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
These bits are write-only and can be accessed in Word mode only.
0: No action on the corresponding ODRx bit
1: Reset the corresponding ODRx bit

  */

}MGPIOX_BRR_BITS;


typedef enum
{

  LCK0,
  LCK1,
  LCK2,
  LCK3,
  LCK4,
  LCK5,
  LCK6,
  LCK7,
  LCK8,
  LCK9,
  LCK10,
  LCK11,
  LCK12,
  LCK13,
  LCK14,
  LCK15,
  LCKK,

  RESERVED_BIT_17_LCKR,
  RESERVED_BIT_18_LCKR,
  RESERVED_BIT_19_LCKR,
  RESERVED_BIT_20_LCKR,
  RESERVED_BIT_21_LCKR,
  RESERVED_BIT_22_LCKR,
  RESERVED_BIT_23_LCKR,
  RESERVED_BIT_24_LCKR,
  RESERVED_BIT_25_LCKR,
  RESERVED_BIT_26_LCKR,
  RESERVED_BIT_27_LCKR,
  RESERVED_BIT_28_LCKR,
  RESERVED_BIT_29_LCKR,
  RESERVED_BIT_30_LCKR,
  RESERVED_BIT_31_LCKR

  /*
  This register is used to lock the configuration of the port bits when a correct write sequence
  is applied to bit 16 (LCKK). The value of bits [15:0] is used to lock the configuration of the
  GPIO. During the write sequence, the value of LCKR[15:0] must not change. When the
  LOCK sequence has been applied on a port bit it is no longer possible to modify the value of
  the port bit until the next reset.
  Each lock bit freezes the corresponding 4 bits of the control register (CRL, CRH).
  Address offset: 0x18
  Reset value: 0x0000 0000

  Bits 31:17 Reserved
Bit 16 LCKK[16]: Lock key
This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
0: Port configuration lock key not active
1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
LOCK key writing sequence:
Write 1
Write 0
Write 1
Read 0
Read 1 (this read is optional but confirms that the lock is active)
Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
Any error in the lock sequence will abort the lock.
Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
These bits are read write but can only be written when the LCKK bit is 0.
0: Port configuration not locked
1: Port configuration locked.
  */

}MGPIOX_LCKR_BITS;

typedef enum
{
  MGPIO_LOW,
  MGPIO_HIGH
}BIT_VALUE;

typedef enum
{
  INPUT_MODE,
  OUTPUT_MAX_10_MHZ,
  OUTPUT_MAX_2_MHZ,
  OUTPUT_MAX_50_MHZ

}MODE;

typedef enum
{
  Analog_INPUT,
  Floating_INPUT,
  PU_PD_INPUT,   // PULL_UP OR PULL_DOWN  INPUT MODE state

  GP_PUSH_PULL_OUTPUT,
  GP_OPEN_DRAIN_OUTPUT,
  AF_PUSH_PULL_OUTPUT,
  AF_OPEN_DRAIN_OUTPUT
} STATE ;


///////////Port pin direction main function ///////////////////////
void MGPIO_voidSetPinDirection(PORT_T MGPIO_portPORTID,PIN_T MGPIO_pinPINID,MODE MGPIO_modeMODEID,STATE MGPIO_stateSTATE);

///////////////get value from pin function /////////////////////
u8 MGPIO_u8GetPinValue(PORT_T MGPIO_portPORTID, PIN_T MGPIO_pinPINID);

//////////// set value to pin function /////////////////////////
void  MGPIO_voidSetPinValue(PORT_T MGPIO_portPORTID, PIN_T MGPIO_pindPINID,BIT_VALUE MGPIO_BitValue);



#endif
