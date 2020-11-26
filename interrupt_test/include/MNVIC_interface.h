/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 14 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  MNVIC_INTERFACE_H
#define  MNVIC_INTERFACE_H


typedef enum MNVIC_ISER_BITS
{
  SETENA_0_ISER,
  SETENA_1_ISER,
  SETENA_2_ISER,
  SETENA_3_ISER,
  SETENA_4_ISER,
  SETENA_5_ISER,
  SETENA_6_ISER,
  SETENA_7_ISER,
  SETENA_8_ISER,
  SETENA_9_ISER,
  SETENA_10_ISER,
  SETENA_11_ISER,
  SETENA_12_ISER,
  SETENA_13_ISER,
  SETENA_14_ISER,
  SETENA_15_ISER,
  SETENA_16_ISER,
  SETENA_17_ISER,
  SETENA_18_ISER,
  SETENA_19_ISER,
  SETENA_20_ISER,
  SETENA_21_ISER,
  SETENA_22_ISER,
  SETENA_23_ISER,
  SETENA_24_ISER,
  SETENA_25_ISER,
  SETENA_26_ISER,
  SETENA_27_ISER,
  SETENA_28_ISER,
  SETENA_29_ISER,
  SETENA_30_ISER,
  SETENA_31_ISER
  /*
  Bits 31:0 SETENA[31:0]: Interrupt set-enable bits.
Write:
0: No effect
1: Enable interrupt
Read:
0: Interrupt disabled
1: Interrupt enabled.
See Table 41: Mapping of interrupts to the interrupt variables on page 119 for the
correspondence of interrupts to each register bit.
If a pending interrupt is enabled, the NVIC activates the interrupt based on its priority. If an
interrupt is not enabled, asserting its interrupt signal changes the interrupt state to pending,
but the NVIC never activates the interrupt, regardless of its priority.
*/
}MNVIC_ISER_BITS_T;


typedef enum MNVIC_ICER_BITS
{
  CLRENA_0_ICER,
  CLRENA_1_ICER,
  CLRENA_2_ICER,
  CLRENA_3_ICER,
  CLRENA_4_ICER,
  CLRENA_5_ICER,
  CLRENA_6_ICER,
  CLRENA_7_ICER,
  CLRENA_8_ICER,
  CLRENA_9_ICER,
  CLRENA_10_ICER,
  CLRENA_11_ICER,
  CLRENA_12_ICER,
  CLRENA_13_ICER,
  CLRENA_14_ICER,
  CLRENA_15_ICER,
  CLRENA_16_ICER,
  CLRENA_17_ICER,
  CLRENA_18_ICER,
  CLRENA_19_ICER,
  CLRENA_20_ICER,
  CLRENA_21_ICER,
  CLRENA_22_ICER,
  CLRENA_23_ICER,
  CLRENA_24_ICER,
  CLRENA_25_ICER,
  CLRENA_26_ICER,
  CLRENA_27_ICER,
  CLRENA_28_ICER,
  CLRENA_29_ICER,
  CLRENA_30_ICER,
  CLRENA_31_ICER
  /*
  Bits 31:0 CLRENA[31:0]: Interrupt clear-enable bits.
Write:
0: No effect
1: Disable interrupt
Read:
0: Interrupt disabled
1: Interrupt enabled.
See Table 41: Mapping of interrupts to the interrupt variables on page 119 for the
correspondence of interrupts to each register bit.
*/
}MNVIC_ICER_BITS_T;


typedef enum MNVIC_ISPR_BITS
{
  SETPEND_0_ISPR,
  SETPEND_1_ISPR,
  SETPEND_2_ISPR,
  SETPEND_3_ISPR,
  SETPEND_4_ISPR,
  SETPEND_5_ISPR,
  SETPEND_6_ISPR,
  SETPEND_7_ISPR,
  SETPEND_8_ISPR,
  SETPEND_9_ISPR,
  SETPEND_10_ISPR,
  SETPEND_11_ISPR,
  SETPEND_12_ISPR,
  SETPEND_13_ISPR,
  SETPEND_14_ISPR,
  SETPEND_15_ISPR,
  SETPEND_16_ISPR,
  SETPEND_17_ISPR,
  SETPEND_18_ISPR,
  SETPEND_19_ISPR,
  SETPEND_20_ISPR,
  SETPEND_21_ISPR,
  SETPEND_22_ISPR,
  SETPEND_23_ISPR,
  SETPEND_24_ISPR,
  SETPEND_25_ISPR,
  SETPEND_26_ISPR,
  SETPEND_27_ISPR,
  SETPEND_28_ISPR,
  SETPEND_29_ISPR,
  SETPEND_30_ISPR,
  SETPEND_31_ISPR
  /*
  Bits 31:0 SETPEND[31:0]: Interrupt set-pending bits
Write:
0: No effect
1: Changes interrupt state to pending
Read:
0: Interrupt is not pending
1: Interrupt is pending
See Table 41: Mapping of interrupts to the interrupt variables on page 119 for the
correspondence of interrupts to each register bit.
Writing 1 to the ISPR bit corresponding to an interrupt that is pending:
– has no effect.
Writing 1 to the ISPR bit corresponding to a disabled interrupt:
– sets the state of that interrupt to pending.
*/
}MNVIC_ISPR_BITS_T;


typedef enum MNVIC_ICPR_BITS
{
  CLRPEND_0_ICPR,
  CLRPEND_1_ICPR,
  CLRPEND_2_ICPR,
  CLRPEND_3_ICPR,
  CLRPEND_4_ICPR,
  CLRPEND_5_ICPR,
  CLRPEND_6_ICPR,
  CLRPEND_7_ICPR,
  CLRPEND_8_ICPR,
  CLRPEND_9_ICPR,
  CLRPEND_10_ICPR,
  CLRPEND_11_ICPR,
  CLRPEND_12_ICPR,
  CLRPEND_13_ICPR,
  CLRPEND_14_ICPR,
  CLRPEND_15_ICPR,
  CLRPEND_16_ICPR,
  CLRPEND_17_ICPR,
  CLRPEND_18_ICPR,
  CLRPEND_19_ICPR,
  CLRPEND_20_ICPR,
  CLRPEND_21_ICPR,
  CLRPEND_22_ICPR,
  CLRPEND_23_ICPR,
  CLRPEND_24_ICPR,
  CLRPEND_25_ICPR,
  CLRPEND_26_ICPR,
  CLRPEND_27_ICPR,
  CLRPEND_28_ICPR,
  CLRPEND_29_ICPR,
  CLRPEND_30_ICPR,
  CLRPEND_31_ICPR
  /*
  Bits 31:0 CLRPEND[31:0]: Interrupt clear-pending bits
  Write:
  0: No effect
  1: Removes the pending state of an interrupt
  Read:
  0: Interrupt is not pending
  1: Interrupt is pending
  See Table 41: Mapping of interrupts to the interrupt variables on page 119 for the
  correspondence of interrupts to each register bit.
  Writing 1 to an ICPR bit does not affect the active state of the corresponding interrupt.
*/
}MNVIC_ICPR_BITS_T;


typedef enum MNVIC_IABR_BITS
{
  ACTIVE_0_IABR,
  ACTIVE_1_IABR,
  ACTIVE_2_IABR,
  ACTIVE_3_IABR,
  ACTIVE_4_IABR,
  ACTIVE_5_IABR,
  ACTIVE_6_IABR,
  ACTIVE_7_IABR,
  ACTIVE_8_IABR,
  ACTIVE_9_IABR,
  ACTIVE_10_IABR,
  ACTIVE_11_IABR,
  ACTIVE_12_IABR,
  ACTIVE_13_IABR,
  ACTIVE_14_IABR,
  ACTIVE_15_IABR,
  ACTIVE_16_IABR,
  ACTIVE_17_IABR,
  ACTIVE_18_IABR,
  ACTIVE_19_IABR,
  ACTIVE_20_IABR,
  ACTIVE_21_IABR,
  ACTIVE_22_IABR,
  ACTIVE_23_IABR,
  ACTIVE_24_IABR,
  ACTIVE_25_IABR,
  ACTIVE_26_IABR,
  ACTIVE_27_IABR,
  ACTIVE_28_IABR,
  ACTIVE_29_IABR,
  ACTIVE_30_IABR,
  ACTIVE_31_IABR
  /*
  Bits 31:0 ACTIVE[31:0]: Interrupt active flags
0: Interrupt not active
1: Interrupt active
See Table 41: Mapping of interrupts to the interrupt variables on page 119 for the
correspondence of interrupts to each register bit.
A bit reads as 1 if the status of the corresponding interrupt is active or active and pending.
*/
}MNVIC_IABR_BITS_T;


typedef enum MNVIC_IPR_BITS
{
  IP0_0_IPR,
  IP0_1_IPR,
  IP0_2_IPR,
  IP0_3_IPR,
  IP0_4_IPR,
  IP0_5_IPR,
  IP0_6_IPR,
  IP0_7_IPR,
  IP1_8_IPR,
  IP1_9_IPR,
  IP1_10_IPR,
  IP1_11_IPR,
  IP1_12_IPR,
  IP1_13_IPR,
  IP1_14_IPR,
  IP1_15_IPR,
  IP2_16_IPR,
  IP2_17_IPR,
  IP2_18_IPR,
  IP2_19_IPR,
  IP2_20_IPR,
  IP2_21_IPR,
  IP2_22_IPR,
  IP2_23_IPR,
  IP3_24_IPR,
  IP3_25_IPR,
  IP3_26_IPR,
  IP3_27_IPR,
  IP3_28_IPR,
  IP3_29_IPR,
  IP3_30_IPR,
  IP3_31_IPR
  /*
The IPR0-IPR16 registers provide a 4-bit priority field for each interrupt. These registers are byte-accessible. Each register holds four priority fields, that map to four elements in the CMSIS interrupt priority array IP[0] to IP[67], as shown in Figure 19.
Each priority field holds a priority value, 0-255. The lower the value,
the greater the priority of the corresponding interrupt. The processor
implements only bits[7:4] of each field, bits[3:0] read as zero and
ignore writes.
See The CMSIS mapping of the Cortex®-M3 NVIC registers on page 119 for more information about the IP[0] to IP[67] interrupt priority array, that provides the software view of the interrupt priorities.
*/
}MNVIC_IPR_BITS_T;

typedef enum MNVIC_STIR_BITS
{
  INTID_0_STIR,
  INTID_1_STIR,
  INTID_2_STIR,
  INTID_3_STIR,
  INTID_4_STIR,
  INTID_5_STIR,
  INTID_6_STIR,
  INTID_7_STIR,
  INTID_8_STIR,
  /*
  Bits 8:0
NTID[8:0] Software generated interrupt ID
Write to the STIR to generate a Software Generated Interrupt (SGI). The value to be written is
the Interrupt ID of the required SGI, in the range 0-239. For example, a value of 0b000000011
specifies interrupt IRQ3.
  */
  RESERVED_BIT_9_STIR,
  RESERVED_BIT_10_STIR,
  RESERVED_BIT_11_STIR,
  RESERVED_BIT_12_STIR,
  RESERVED_BIT_13_STIR,
  RESERVED_BIT_14_STIR,
  RESERVED_BIT_15_STIR,
  RESERVED_BIT_16_STIR,
  RESERVED_BIT_17_STIR,
  RESERVED_BIT_18_STIR,
  RESERVED_BIT_19_STIR,
  RESERVED_BIT_20_STIR,
  RESERVED_BIT_21_STIR,
  RESERVED_BIT_22_STIR,
  RESERVED_BIT_23_STIR,
  RESERVED_BIT_24_STIR,
  RESERVED_BIT_25_STIR,
  RESERVED_BIT_26_STIR,
  RESERVED_BIT_27_STIR,
  RESERVED_BIT_28_STIR,
  RESERVED_BIT_29_STIR,
  RESERVED_BIT_30_STIR,
  RESERVED_BIT_31_STIR
  /*
Bits 31:9 Reserved, must be kept cleared.
*/
}MNVIC_STIR_BITS_T;

///////set enable of interrupt function////////
void MNVIC_voidSetEnableINT(u8 MNVIC_InterruptID);
void MNVIC_voidClearEnableINT(u8 MNVIC_InterruptID);
void MNVIC_voidSetPendingFlagINT(u8 MNVIC_InterruptID);
void MNVIC_voidClearPendingFlagINT(u8 MNVIC_InterruptID);
u8 MNVIC_u8GetActiveBitFlagINT(u8 MNVIC_InterruptID);
void MNVIC_voidSetPriorityINT(u8 MNVIC_InterruptID,u8 MNVIC_Group,u8 MNVIC_SUBPriority);


#endif
