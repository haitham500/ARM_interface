/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 09 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  MAFIO_INTERFACE_H
#define  MAFIO_INTERFACE_H

typedef enum STATE_EVOUT
{
  enable,
  disable
}STATE_EVOUT_T;

typedef enum MAFIO_EVCR_BITS
{
  PIN_0_EVCR,
  PIN_1_EVCR,
  PIN_2_EVCR,
  PIN_3_EVCR,
  /*
  Bits 3:0 PIN[3:0]: Pin selection (x = A .. E)
Set and cleared by software. Select the pin used to output the Cortex® EVENTOUT signal.
0000: Px0 selected
0001: Px1 selected
0010: Px2 selected
0011: Px3 selected
...
1111: Px15 selected
  */
  PORT_0_EVCR,
  PORT_1_EVCR,
  PORT_2_EVCR,
  /*
  Bits 6:4 PORT[2:0]: Port selection
Set and cleared by software. Select the port used to output the Cortex® EVENTOUT signal.
Note: The EVENTOUT signal output capability is not extended to ports PF and PG.
000: PA selected
001: PB selected
010: PC selected
011: PD selected
100: PE selected
  */
  EVOE_EVCR,
  /*
  Bit 7 EVOE: Event output enable
Set and cleared by software. When set the EVENTOUT Cortex® output is connected to the
I/O selected by the PORT[2:0] and PIN[3:0] bits.
  */
  RESERVED_BIT_8_EVCR,
  RESERVED_BIT_9_EVCR,
  RESERVED_BIT_10_EVCR,
  RESERVED_BIT_11_EVCR,
  RESERVED_BIT_12_EVCR,
  RESERVED_BIT_13_EVCR,
  RESERVED_BIT_14_EVCR,
  RESERVED_BIT_15_EVCR,
  RESERVED_BIT_16_EVCR,
  RESERVED_BIT_17_EVCR,
  RESERVED_BIT_18_EVCR,
  RESERVED_BIT_19_EVCR,
  RESERVED_BIT_20_EVCR,
  RESERVED_BIT_21_EVCR,
  RESERVED_BIT_22_EVCR,
  RESERVED_BIT_23_EVCR,
  RESERVED_BIT_24_EVCR,
  RESERVED_BIT_25_EVCR,
  RESERVED_BIT_26_EVCR,
  RESERVED_BIT_27_EVCR,
  RESERVED_BIT_28_EVCR,
  RESERVED_BIT_29_EVCR,
  RESERVED_BIT_30_EVCR,
  RESERVED_BIT_31_EVCR
  /*
    Bits 31:8 Reserved
  */
}MAFIO_EVCR_BITS_T;

typedef enum MAFIO_MAPR_BITS
{
  SPI1_REMAP_MAPR,
  /*
  Bit 0 SPI1_REMAP: SPI1 remapping
This bit is set and cleared by software. It controls the mapping of SPI1 NSS, SCK, MISO,
MOSI alternate functions on the GPIO ports.
0: No remap (NSS/PA4, SCK/PA5, MISO/PA6, MOSI/PA7)
1: Remap (NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5)
  */
  I2C1_REMAP_MAPR,
  /*
  Bit 1 I2C1_REMAP: I2C1 remapping
This bit is set and cleared by software. It controls the mapping of I2C1 SCL and SDA
alternate functions on the GPIO ports.
0: No remap (SCL/PB6, SDA/PB7)
1: Remap (SCL/PB8, SDA/PB9)
  */
  USART1_REMAP_MAPR,
  /*
  Bit 2 USART1_REMAP: USART1 remapping
This bit is set and cleared by software. It controls the mapping of USART1 TX and RX
alternate functions on the GPIO ports.
0: No remap (TX/PA9, RX/PA10)
1: Remap (TX/PB6, RX/PB7)
  */
  USART2_REMAP_MAPR,
  /*
  Bit 3 USART2_REMAP: USART2 remapping
This bit is set and cleared by software. It controls the mapping of USART2 CTS, RTS,CK,TX
and RX alternate functions on the GPIO ports.
0: No remap (CTS/PA0, RTS/PA1, TX/PA2, RX/PA3, CK/PA4)
1: Remap (CTS/PD3, RTS/PD4, TX/PD5, RX/PD6, CK/PD7)
  */
  USART3_REMAP_0_MAPR,
  USART3_REMAP_1_MAPR,
  /*
  Bits 5:4 USART3_REMAP[1:0]: USART3 remapping
These bits are set and cleared by software. They control the mapping of USART3 CTS,
RTS,CK,TX and RX alternate functions on the GPIO ports.
00: No remap (TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14)
01: Partial remap (TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14)
10: not used
11: Full remap (TX/PD8, RX/PD9, CK/PD10, CTS/PD11, RTS/PD12)
  */
  TIM1_REMAP_0_MAPR,
  TIM1_REMAP_1_MAPR,
  /*
  Bits 7:6 TIM1_REMAP[1:0]: TIM1 remapping
These bits are set and cleared by software. They control the mapping of TIM1 channels 1 to
4, 1N to 3N, external trigger (ETR) and Break input (BKIN) on the GPIO ports.
00: No remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12,
CH1N/PB13, CH2N/PB14, CH3N/PB15)
01: Partial remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6,
CH1N/PA7, CH2N/PB0, CH3N/PB1)
10: not used
11: Full remap (ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15,
CH1N/PE8, CH2N/PE10, CH3N/PE12)
  */
  TIM2_REMAP_0_MAPR,
  TIM2_REMAP_1_MAPR,
  /*
  Bits 9:8 TIM2_REMAP[1:0]: TIM2 remapping
These bits are set and cleared by software. They control the mapping of TIM2 channels 1 to
4 and external trigger (ETR) on the GPIO ports.
00: No remap (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3)
01: Partial remap (CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3)
10: Partial remap (CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11)
11: Full remap (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)
  */
  TIM3_REMAP_0_MAPR,
  TIM3_REMAP_1_MAPR,
  /*
  Bits 11:10 TIM3_REMAP[1:0]: TIM3 remapping
These bits are set and cleared by software. They control the mapping of TIM3 channels 1 to
4 on the GPIO ports.
00: No remap (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
01: Not used
10: Partial remap (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)
11: Full remap (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)
Note: TIM3_ETR on PE0 is not re-mapped.
  */
  TIM4_REMAP_MAPR,
  /*
  Bit 12 TIM4_REMAP: TIM4 remapping
This bit is set and cleared by software. It controls the mapping of TIM4 channels 1 to 4 onto
the GPIO ports.
0: No remap (TIM4_CH1/PB6, TIM4_CH2/PB7, TIM4_CH3/PB8, TIM4_CH4/PB9)
1: Full remap (TIM4_CH1/PD12, TIM4_CH2/PD13, TIM4_CH3/PD14, TIM4_CH4/PD15)
Note: TIM4_ETR on PE0 is not re-mapped.
  */
  CAN_REMAP_0_MAPR,
  CAN_REMAP_1_MAPR,
  /*
  Bits 14:13 CAN_REMAP[1:0]: CAN alternate function remapping
  These bits are set and cleared by software. They control the mapping of alternate functions
  CAN_RX and CAN_TX in devices with a single CAN interface.
  00: CAN_RX mapped to PA11, CAN_TX mapped to PA12
  01: Not used
  10: CAN_RX mapped to PB8, CAN_TX mapped to PB9 (not available on 36-pin package)
  11: CAN_RX mapped to PD0, CAN_TX mapped to PD1
  */
  PD01_REMAP_MAPR,
  /*
  Bit 15 PD01_REMAP: Port D0/Port D1 mapping on OSC_IN/OSC_OUT
  This bit is set and cleared by software. It controls the mapping of PD0 and PD1 GPIO
  functionality. When the HSE oscillator is not used (application running on internal 8 MHz RC)
  PD0 and PD1 can be mapped on OSC_IN and OSC_OUT. This is available only on 36-, 48-
  and 64-pin packages (PD0 and PD1 are available on 100-pin and 144-pin packages, no
  need for remapping).
  0: No remapping of PD0 and PD1
  1: PD0 remapped on OSC_IN, PD1 remapped on OSC_OUT,
  */
  TIM5CH4_IREMAP_MAPR,
  /*
  Bits 16 TIM5CH4_IREMAP: TIM5 channel4 internal remap
  Set and cleared by software. This bit controls the TIM5_CH4 internal mapping. When reset
  the timer TIM5_CH4 is connected to PA3. When set the LSI internal clock is connected to
  TIM5_CH4 input for calibration purpose.
  Note: This bit is available only in high density value line devices.
  */
  ADC1_ETRGINJ_REMAP_MAPR,
  /*
  Bits 17 ADC1_ETRGINJ_REMAP: ADC 1 External trigger injected conversion remapping
  Set and cleared by software. This bit controls the trigger input connected to ADC1
  External trigger injected conversion. When reset the ADC1 External trigger injected
  conversion is connected to EXTI15. When set the ADC1 External Event injected conversion
  is connected to TIM8 Channel4.
  */
  ADC1_ETRGREG_REMAP_MAPR,
  /*
  Bits 18 ADC1_ETRGREG_REMAP: ADC 1 external trigger regular conversion remapping
  Set and cleared by software. This bit controls the trigger input connected to ADC1
  External trigger regular conversion. When reset the ADC1 External trigger regular
  conversion is connected to EXTI11. When set the ADC1 External Event regular conversion
  is connected to TIM8 TRGO
  */
  ADC2_ETRGINJ_REMAP_MAPR,
  /*
  Bits 19 ADC2_ETRGINJ_REMAP: ADC 2 external trigger injected conversion remapping
  Set and cleared by software. This bit controls the trigger input connected to ADC2 external
  trigger injected conversion. When this bit is reset, the ADC2 external trigger injected
  conversion is connected to EXTI15. When this bit is set, the ADC2 external event injected
  conversion is connected to TIM8_Channel4.
  */
  ADC2_ETRGREG_REMAP_MAPR,
  /*
  Bits 20 ADC2_ETRGREG_REMAP: ADC 2 external trigger regular conversion remapping
  Set and cleared by software. This bit controls the trigger input connected to ADC2 external
  trigger regular conversion. When this bit is reset, the ADC2 external trigger regular
  conversion is connected to EXTI11. When this bit is set, the ADC2 external event regular
  conversion is connected to TIM8_TRGO.
  */
  RESERVED_BIT_21_MAPR,
  RESERVED_BIT_22_MAPR,
  RESERVED_BIT_23_MAPR,
  /*
  Bits 23:21 Reserved.
  */
  SWJ_CFG_0_MAPR,
  SWJ_CFG_1_MAPR,
  SWJ_CFG_2_MAPR,
  /*
  Bits 26:24 SWJ_CFG[2:0]: Serial wire JTAG configuration
These bits are write-only (when read, the value is undefined). They are used to configure the
SWJ and trace alternate function I/Os. The SWJ (Serial Wire JTAG) supports JTAG or SWD
access to the Cortex® debug port. The default state after reset is SWJ ON without trace.
This allows JTAG or SW mode to be enabled by sending a specific sequence on the JTMS /
JTCK pin.
000: Full SWJ (JTAG-DP + SW-DP): Reset State
001: Full SWJ (JTAG-DP + SW-DP) but without NJTRST
010: JTAG-DP Disabled and SW-DP Enabled
100: JTAG-DP Disabled and SW-DP Disabled
Other combinations: no effect
  */
  RESERVED_BIT_27_MAPR,
  RESERVED_BIT_28_MAPR,
  RESERVED_BIT_29_MAPR,
  RESERVED_BIT_30_MAPR,
  RESERVED_BIT_31_MAPR
/*
Bits 31:27 Reserved
*/

}MAFIO_MAPR_BITS_T;


typedef enum MAFIO_EXTICR1_BITS
{
  EXTI0_0_EXTICR1,
  EXTI0_1_EXTICR1,
  EXTI0_2_EXTICR1,
  EXTI0_3_EXTICR1,

  EXTI1_0_EXTICR1,
  EXTI1_1_EXTICR1,
  EXTI1_2_EXTICR1,
  EXTI1_3_EXTICR1,

  EXTI2_0_EXTICR1,
  EXTI2_1_EXTICR1,
  EXTI2_2_EXTICR1,
  EXTI2_3_EXTICR1,

  EXTI3_0_EXTICR1,
  EXTI3_1_EXTICR1,
  EXTI3_2_EXTICR1,
  EXTI3_3_EXTICR1,
  /*
  Bits 15:0 EXTIx[3:0]: EXTI x configuration (x= 0 to 3)
  These bits are written by software to select the source input for EXTIx external interrupt.
  Refer to Section 10.2.5: External interrupt/event line mapping
  0000: PA[x] pin
  0001: PB[x] pin
  0010: PC[x] pin
  0011: PD[x] pin
  0100: PE[x] pin
  0101: PF[x] pin
  0110: PG[x] pin
  */
  RESERVED_BIT_16_EXTICR1,
  RESERVED_BIT_17_EXTICR1,
  RESERVED_BIT_18_EXTICR1,
  RESERVED_BIT_19_EXTICR1,
  RESERVED_BIT_20_EXTICR1,
  RESERVED_BIT_21_EXTICR1,
  RESERVED_BIT_22_EXTICR1,
  RESERVED_BIT_23_EXTICR1,
  RESERVED_BIT_24_EXTICR1,
  RESERVED_BIT_25_EXTICR1,
  RESERVED_BIT_26_EXTICR1,
  RESERVED_BIT_27_EXTICR1,
  RESERVED_BIT_28_EXTICR1,
  RESERVED_BIT_29_EXTICR1,
  RESERVED_BIT_30_EXTICR1,
  RESERVED_BIT_31_EXTICR1
  /*
Bits 31:16 Reserved
  */

}MAFIO_EXTICR1_BITS_T;

typedef enum MAFIO_EXTICR2_BITS
{
  EXTI4_0_EXTICR2,
  EXTI4_1_EXTICR2,
  EXTI4_2_EXTICR2,
  EXTI4_3_EXTICR2,

  EXTI5_0_EXTICR2,
  EXTI5_1_EXTICR2,
  EXTI5_2_EXTICR2,
  EXTI5_3_EXTICR2,

  EXTI6_0_EXTICR2,
  EXTI6_1_EXTICR2,
  EXTI6_2_EXTICR2,
  EXTI6_3_EXTICR2,

  EXTI7_0_EXTICR2,
  EXTI7_1_EXTICR2,
  EXTI7_2_EXTICR2,
  EXTI7_3_EXTICR2,
  /*
  Bits 15:0 EXTIx[3:0]: EXTI x configuration (x= 0 to 3)
  These bits are written by software to select the source input for EXTIx external interrupt.
  Refer to Section 10.2.5: External interrupt/event line mapping
  0000: PA[x] pin
  0001: PB[x] pin
  0010: PC[x] pin
  0011: PD[x] pin
  0100: PE[x] pin
  0101: PF[x] pin
  0110: PG[x] pin
  */
  RESERVED_BIT_16_EXTICR2,
  RESERVED_BIT_17_EXTICR2,
  RESERVED_BIT_18_EXTICR2,
  RESERVED_BIT_19_EXTICR2,
  RESERVED_BIT_20_EXTICR2,
  RESERVED_BIT_21_EXTICR2,
  RESERVED_BIT_22_EXTICR2,
  RESERVED_BIT_23_EXTICR2,
  RESERVED_BIT_24_EXTICR2,
  RESERVED_BIT_25_EXTICR2,
  RESERVED_BIT_26_EXTICR2,
  RESERVED_BIT_27_EXTICR2,
  RESERVED_BIT_28_EXTICR2,
  RESERVED_BIT_29_EXTICR2,
  RESERVED_BIT_30_EXTICR2,
  RESERVED_BIT_31_EXTICR2
  /*
Bits 31:16 Reserved
  */

}MAFIO_EXTICR2_BITS_T;
typedef enum MAFIO_EXTICR3_BITS
{
  EXTI8_0_EXTICR3,
  EXTI8_1_EXTICR3,
  EXTI8_2_EXTICR3,
  EXTI8_3_EXTICR3,

  EXTI9_0_EXTICR3,
  EXTI9_1_EXTICR3,
  EXTI9_2_EXTICR3,
  EXTI9_3_EXTICR3,

  EXTI10_0_EXTICR3,
  EXTI10_1_EXTICR3,
  EXTI10_2_EXTICR3,
  EXTI10_3_EXTICR3,

  EXTI11_0_EXTICR3,
  EXTI11_1_EXTICR3,
  EXTI11_2_EXTICR3,
  EXTI11_3_EXTICR3,
  /*
  Bits 15:0 EXTIx[3:0]: EXTI x configuration (x= 0 to 3)
  These bits are written by software to select the source input for EXTIx external interrupt.
  Refer to Section 10.2.5: External interrupt/event line mapping
  0000: PA[x] pin
  0001: PB[x] pin
  0010: PC[x] pin
  0011: PD[x] pin
  0100: PE[x] pin
  0101: PF[x] pin
  0110: PG[x] pin
  */
  RESERVED_BIT_16_EXTICR3,
  RESERVED_BIT_17_EXTICR3,
  RESERVED_BIT_18_EXTICR3,
  RESERVED_BIT_19_EXTICR3,
  RESERVED_BIT_20_EXTICR3,
  RESERVED_BIT_21_EXTICR3,
  RESERVED_BIT_22_EXTICR3,
  RESERVED_BIT_23_EXTICR3,
  RESERVED_BIT_24_EXTICR3,
  RESERVED_BIT_25_EXTICR3,
  RESERVED_BIT_26_EXTICR3,
  RESERVED_BIT_27_EXTICR3,
  RESERVED_BIT_28_EXTICR3,
  RESERVED_BIT_29_EXTICR3,
  RESERVED_BIT_30_EXTICR3,
  RESERVED_BIT_31_EXTICR3
  /*
Bits 31:16 Reserved
  */

}MAFIO_EXTICR3_BITS_T;
typedef enum MAFIO_EXTICR4_BITS
{
  EXTI12_0_EXTICR4,
  EXTI12_1_EXTICR4,
  EXTI12_2_EXTICR4,
  EXTI12_3_EXTICR4,

  EXTI13_0_EXTICR4,
  EXTI13_1_EXTICR4,
  EXTI13_2_EXTICR4,
  EXTI13_3_EXTICR4,

  EXTI14_0_EXTICR4,
  EXTI14_1_EXTICR4,
  EXTI14_2_EXTICR4,
  EXTI14_3_EXTICR4,

  EXTI15_0_EXTICR4,
  EXTI15_1_EXTICR4,
  EXTI15_2_EXTICR4,
  EXTI15_3_EXTICR4,
  /*
  Bits 15:0 EXTIx[3:0]: EXTI x configuration (x= 0 to 3)
  These bits are written by software to select the source input for EXTIx external interrupt.
  Refer to Section 10.2.5: External interrupt/event line mapping
  0000: PA[x] pin
  0001: PB[x] pin
  0010: PC[x] pin
  0011: PD[x] pin
  0100: PE[x] pin
  0101: PF[x] pin
  0110: PG[x] pin
  */
  RESERVED_BIT_16_EXTICR4,
  RESERVED_BIT_17_EXTICR4,
  RESERVED_BIT_18_EXTICR4,
  RESERVED_BIT_19_EXTICR4,
  RESERVED_BIT_20_EXTICR4,
  RESERVED_BIT_21_EXTICR4,
  RESERVED_BIT_22_EXTICR4,
  RESERVED_BIT_23_EXTICR4,
  RESERVED_BIT_24_EXTICR4,
  RESERVED_BIT_25_EXTICR4,
  RESERVED_BIT_26_EXTICR4,
  RESERVED_BIT_27_EXTICR4,
  RESERVED_BIT_28_EXTICR4,
  RESERVED_BIT_29_EXTICR4,
  RESERVED_BIT_30_EXTICR4,
  RESERVED_BIT_31_EXTICR4
  /*
Bits 31:16 Reserved
  */

}MAFIO_EXTICR4_BITS_T;
typedef enum MAFIO_MAPR2_BITS
{
  RESERVED_BIT_0_MAPR2,
  RESERVED_BIT_1_MAPR2,
  RESERVED_BIT_2_MAPR2,
  RESERVED_BIT_3_MAPR2,
  RESERVED_BIT_4_MAPR2,
  /*
  Bits 4:0 Reserved.
  */
  TIM9_REMAP,
  /*
  Bit 5 TIM9_REMAP: TIM9 remapping
  This bit is set and cleared by software. It controls the mapping of the TIM9_CH1 and
  TIM9_CH2 alternate functions onto the GPIO ports.
  0: No remap (TIM9_CH1 on PA2 and TIM9_CH2 on PA3)
  1: Remap (TIM9_CH1 on PE5 and TIM9_CH2 on PE6)
  */
  TIM10_REMAP,
  /*
  Bit 6 TIM10_REMAP: TIM10 remapping
  This bit is set and cleared by software. It controls the mapping of the TIM10_CH1 alternate
  function onto the GPIO ports.
  0: No remap (PB8)
  1: Remap (PF6)
  */
  TIM11_REMAP,
  /*
  Bit 7 TIM11_REMAP: TIM11 remapping
  This bit is set and cleared by software. It controls the mapping of the TIM11_CH1 alternate
  function onto the GPIO ports.
  0: No remap (PB9)
  1: Remap (PF7)
  */
  TIM13_REMAP,
  /*
  Bit 8 TIM13_REMAP: TIM13 remapping
  This bit is set and cleared by software. It controls the mapping of the TIM13_CH1 alternate
  function onto the GPIO ports.
  0: No remap (PA6)
  1: Remap (PF8)
  */
  TIM14_REMAP,
  /*
  Bit 9 TIM14_REMAP: TIM14 remapping
  This bit is set and cleared by software. It controls the mapping of the TIM14_CH1 alternate
  function onto the GPIO ports.
  0: No remap (PA7)
  1: Remap (PF9)
  */
  FSMC_NADV,
  /*
  Bit 10 FSMC_NADV: NADV connect/disconnect
  This bit is set and cleared by software. It controls the use of the optional FSMC_NADV
  signal.
  0: The NADV signal is connected to the output (default)
  1: The NADV signal is not connected. The I/O pin can be used by another peripheral.
  */
  RESERVED_BIT_11_MAPR2,
  RESERVED_BIT_12_MAPR2,
  RESERVED_BIT_13_MAPR2,
  RESERVED_BIT_14_MAPR2,
  RESERVED_BIT_15_MAPR2,
  RESERVED_BIT_16_MAPR2,
  RESERVED_BIT_17_MAPR2,
  RESERVED_BIT_18_MAPR2,
  RESERVED_BIT_19_MAPR2,
  RESERVED_BIT_20_MAPR2,
  RESERVED_BIT_21_MAPR2,
  RESERVED_BIT_22_MAPR2,
  RESERVED_BIT_23_MAPR2,
  RESERVED_BIT_24_MAPR2,
  RESERVED_BIT_25_MAPR2,
  RESERVED_BIT_26_MAPR2,
  RESERVED_BIT_27_MAPR2,
  RESERVED_BIT_28_MAPR2,
  RESERVED_BIT_29_MAPR2,
  RESERVED_BIT_30_MAPR2,
  RESERVED_BIT_31_MAPR2
  /*
Bits 31:11 Reserved.
  */
}MAFIO_MAPR2_BITS_T;


//
// ///////////////////
// void MAFIO_voidSelectPortEXTICR1(PORT_T MAFIO_portPORTID,MAFIO_EXTICR1_BITS_T MAFIO_BIT0,MAFIO_EXTICR1_BITS_T MAFIO_BIT1,MAFIO_EXTICR1_BITS_T MAFIO_BIT2,MAFIO_EXTICR1_BITS_T MAFIO_BIT3);
// //////////////////
// void MAFIO_voidSelectPortEXTICR2(PORT_T MAFIO_portPORTID,MAFIO_EXTICR2_BITS_T MAFIO_BIT0,MAFIO_EXTICR2_BITS_T MAFIO_BIT1,MAFIO_EXTICR2_BITS_T MAFIO_BIT2,MAFIO_EXTICR2_BITS_T MAFIO_BIT3);
// //////////////////////
// void MAFIO_voidSelectPortEXTICR3(PORT_T MAFIO_portPORTID,MAFIO_EXTICR3_BITS_T MAFIO_BIT0,MAFIO_EXTICR3_BITS_T MAFIO_BIT1,MAFIO_EXTICR3_BITS_T MAFIO_BIT2,MAFIO_EXTICR3_BITS_T MAFIO_BIT3);
// ////////////////////////
// void MAFIO_voidSelectPortEXTICR4(PORT_T MAFIO_portPORTID,MAFIO_EXTICR4_BITS_T MAFIO_BIT0,MAFIO_EXTICR4_BITS_T MAFIO_BIT1,MAFIO_EXTICR4_BITS_T MAFIO_BIT2,MAFIO_EXTICR4_BITS_T MAFIO_BIT3);

///////////////////////////// main function to select pin which will apply external interrupt as alternative function///
void MAFIO_voidSelectEXTIPin(PORT_T MAFIO_portPORTID, PIN_T MAFIO_pinPINID);
//
// //////////////
// void MAFIO_voidSelectPortEVOUT(PORT_T MAFIO_portPORTID);
// void MAFIO_voidSelectPinEVOUT(PIN_T MAFIO_pinPINID);

//////// main function to select pin as event output////
void MAFIO_voidConfigEventOutput(STATE_EVOUT_T MAFIO_State,PORT_T MAFIO_portPORTID,PIN_T MAFIO_pinPINID) ;

///////remap functions/////////
void MAFIO_voidRemapSPI1(void);


#endif
