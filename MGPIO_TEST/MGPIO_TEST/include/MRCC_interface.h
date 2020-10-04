
/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 26 Sep 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/

//PROTTYPE OF FUNCTIONS AND VARIABLES

#ifndef MRCC_INTERFACE_H
#define MRCC_INTERFACE_H


typedef enum
 {
// HIGH SPEED CLOCK SOURCES
HSE, //
HSE_BYP,
HSI,
PLL,
PLL_BY_2,
PLL_HSE_BY_2,
PLL_HSI_BY_2,
SYSCLK,
// LOW SPEED CLOCK SOURCES
LSE,
LSE_BYP,
LSI,
HSE_BY_128
  }CLOCK_SOURCE;

typedef  enum
   { HSION,
     /*
     Bit 0 HSION: Internal high-speed clock enable
     high-speed clock enable
Set and cleared by software.
Set by hardware to force the internal 8 MHz RC oscillator ON when leaving Stop or Standby
mode or in case of failure of the external 4-16 MHz oscillator used directly or indirectly as
system clock. This bit cannot be reset if the internal 8 MHz RC is used directly or indirectly
as system clock or is selected to become the system clock.
0: internal 8 MHz RC oscillator OFF
1: internal 8 MHz RC oscillator ON
     */
     HSIRDY,
     /*
     Bit 1 HSIRDY: Internal high-speed clock ready flag
Set by hardware to indicate that internal 8 MHz RC oscillator is stable. After the HSION bit is
cleared, HSIRDY goes low after 6 internal 8 MHz RC oscillator clock cycles.
0: internal 8 MHz RC oscillator not ready
1: internal 8 MHz RC oscillator ready
     */
     RESERVED_BIT_2_CR,
     /*
      Bit 2 Reserved, must be kept at reset value.
     */
     HSITRIM_3,
     HSITRIM_4,
     HSITRIM_5,
     HSITRIM_6,
     HSITRIM_7,
     /*
     Bits 7:3 HSITRIM[4:0]: Internal high-speed clock trimming
These bits provide an additional user-programmable trimming value that is added to the
HSICAL[7:0] bits. It can be programmed to adjust to variations in voltage and temperature
that influence the frequency of the internal HSI RC.
The default value is 16, which, when added to the HSICAL value, should trim the HSI to 8
MHz ± 1%. The trimming step (Fhsitrim) is around 40 kHz between two consecutive HSICAL
steps.


     */
     HSICAL,
     /*
     Bits 15:8 HSICAL[7:0]: Internal high-speed clock calibration
These bits are initialized automatically at startup.

     */
     HSEON,
     /*
     Bit 16 HSEON: HSE clock enable
Set and cleared by software.
Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode. This
bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock.
0: HSE oscillator OFF
1: HSE oscillator ON
     */
     HSERDY,
     /*
     Bit 17 HSERDY: External high-speed clock ready flag
Set by hardware to indicate that the HSE oscillator is stable. This bit needs 6 cycles of the
HSE oscillator clock to fall down after HSEON reset.
0: HSE oscillator not ready
1: HSE oscillator ready
     */
     HSEBYP,
     /*
     Bit 18 HSEBYP: External high-speed clock bypass
Set and cleared by software to bypass the oscillator with an external clock. The external
clock must be enabled with the HSEON bit set, to be used by the device. The HSEBYP bit
can be written only if the HSE oscillator is disabled.
0: external 4-16 MHz oscillator not bypassed
1: external 4-16 MHz oscillator bypassed with external clock
     */
     CSSON,
     /*
     Bit 19 CSSON: Clock security system enable
Set and cleared by software to enable the clock security system. When CSSON is set, the
clock detector is enabled by hardware when the HSE oscillator is ready, and disabled by
hardware if a HSE clock failure is detected.
0: Clock detector OFF
1: Clock detector ON (Clock detector ON if the HSE oscillator is ready , OFF if not).
     */
     RESERVED_BIT_20_CR,
     RESERVED_BIT_21_CR,
     RESERVED_BIT_22_CR,
     RESERVED_BIT_23_CR,
     /*
      Bits 23:20 Reserved, must be kept at reset value.
     */
     PLLON,
     /*
     Bit 24 PLLON: PLL enable
Set and cleared by software to enable PLL.
Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
PLL clock is used as system clock or is selected to become the system clock.
0: PLL OFF
1: PLL ON
     */
     PLLRDY,
     /*
     Bit 25 PLLRDY: PLL clock ready flag
Set by hardware to indicate that the PLL is locked.
0: PLL unlocked
1: PLL locked
     */
     RESERVED_BIT_26_CR,
     RESERVED_BIT_27_CR,
     RESERVED_BIT_28_CR,
     RESERVED_BIT_29_CR,
     RESERVED_BIT_30_CR,
     RESERVED_BIT_31_CR
     /*
      Bits 31:26 Reserved, must be kept at reset value.
     */
    }MRCC_CR_BITS;

typedef enum
{
  SW_0,
  SW_1,
  /*
  Bits 1:0 SW: System clock switch
Set and cleared by software to select SYSCLK source.
Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
System is enabled).
00: HSI selected as system clock
01: HSE selected as system clock
10: PLL selected as system clock
11: not allowed
  */
  SWS_2,
  SWS_3,
  /*
  Bits 3:2 SWS: System clock switch status
Set and cleared by hardware to indicate which clock source is used as system clock.
00: HSI oscillator used as system clock
01: HSE oscillator used as system clock
10: PLL used as system clock
11: not applicable
  */
  HPRE_4,
  HPRE_5,
  HPRE_6,
  HPRE_7,
  /*
  Bits 7:4 HPRE: AHB prescaler
Set and cleared by software to control the division factor of the AHB clock.
0xxx: SYSCLK not divided
1000: SYSCLK divided by 2
1001: SYSCLK divided by 4
1010: SYSCLK divided by 8
1011: SYSCLK divided by 16
1100: SYSCLK divided by 64
1101: SYSCLK divided by 128
1110: SYSCLK divided by 256
1111: SYSCLK divided by 512
Note: The prefetch buffer must be kept on when using a prescaler different from 1 on the
AHB clock. Refer to Reading the Flash memory section for more details.
  */
  PPRE1_8,
  PPRE1_9,
  PPRE1_10,
  /*
  Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
Set and cleared by software to control the division factor of the APB low-speed clock
(PCLK1).
Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16
  */
  PPRE2_11,
  PPRE2_12,
  PPRE2_13,
  /*
  Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
Set and cleared by software to control the division factor of the APB high-speed clock
(PCLK2).
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16
  */
  ADCPRE_14,
  ADCPRE_15,
  /*
  Bits 15:14 ADCPRE: ADC prescaler
Set and cleared by software to select the frequency of the clock to the ADCs.
00: PCLK2 divided by 2
01: PCLK2 divided by 4
10: PCLK2 divided by 6
11: PCLK2 divided by 8
  */
  PLLSRC,
  /*
  Bit 16 PLLSRC: PLL entry clock source
Set and cleared by software to select PLL clock source. This bit can be written only when
PLL is disabled.
0: HSI oscillator clock / 2 selected as PLL input clock
1: HSE oscillator clock selected as PLL input clock
  */
  PLLXTPRE,
  /*
  Bit 17 PLLXTPRE: HSE divider for PLL entry
Set and cleared by software to divide HSE before PLL entry. This bit can be written only
when PLL is disabled.
0: HSE clock not divided
1: HSE clock divided by 2
  */
  PLLMUL_18,
  PLLMUL_19,
  PLLMUL_20,
  PLLMUL_21,
  /*
  Bits 21:18 PLLMUL: PLL multiplication factor
These bits are written by software to define the PLL multiplication factor. These bits can be
written only when PLL is disabled.
Caution: The PLL output frequency must not exceed 72 MHz.
0000: PLL input clock x 2
0001: PLL input clock x 3
0010: PLL input clock x 4
0011: PLL input clock x 5
0100: PLL input clock x 6
0101: PLL input clock x 7
0110: PLL input clock x 8
0111: PLL input clock x 9
1000: PLL input clock x 10
1001: PLL input clock x 11
1010: PLL input clock x 12
1011: PLL input clock x 13
1100: PLL input clock x 14
1101: PLL input clock x 15
1110: PLL input clock x 16
1111: PLL input clock x 16
  */
  USBPRE,
  /*
  Bit 22 USBPRE: USB prescaler
Set and cleared by software to generate 48 MHz USB clock. This bit must be valid before
enabling the USB clock in the RCC_APB1ENR register. This bit can’t be reset if the USB
clock is enabled.
0: PLL clock is divided by 1.5
1: PLL clock is not divided
  */
  RESERVED_BIT_23_CFGR,
  /*
   Bit 23 Reserved, must be kept at reset value.
  */
  MCO_24,
  MCO_25,
  MCO_26,
  /*
  Bits 26:24 MCO: Microcontroller clock output
Set and cleared by software.
0xx: No clock
100: System clock (SYSCLK) selected
101: HSI clock selected
110: HSE clock selected
111: PLL clock divided by 2 selected
Note: This clock output may have some truncated cycles at startup or during MCO clock
source switching.
When the System Clock is selected to output to the MCO pin, make sure that this clock
does not exceed 50 MHz (the maximum IO speed).
  */
  RESERVED_BIT_27_CFGR,
  RESERVED_BIT_28_CFGR,
  RESERVED_BIT_29_CFGR,
  RESERVED_BIT_30_CFGR,
  RESERVED_BIT_31_CFGR
  /*
   Bits 31:27 Reserved, must be kept at reset value.
  */
  }MRCC_CFGR_BITS;

typedef enum
{
  LSIRDYF,
  /*
  Bit 0 LSIRDYF: LSI ready interrupt flag
Set by hardware when the internal low speed clock becomes stable and LSIRDYDIE is set.
Cleared by software setting the LSIRDYC bit.
0: No clock ready interrupt caused by the internal RC 40 kHz oscillator
1: Clock ready interrupt caused by the internal RC 40 kHz oscillator
  */
  LSERDYF,
  /*
  Bit 1 LSERDYF: LSE ready interrupt flag
Set by hardware when the External Low Speed clock becomes stable and LSERDYDIE is
set.
Cleared by software setting the LSERDYC bit.
0: No clock ready interrupt caused by the external 32 kHz oscillator
1: Clock ready interrupt caused by the external 32 kHz oscillator
  */
  HSIRDYF,
  /*
  Bit 2 HSIRDYF: HSI ready interrupt flag
Set by hardware when the Internal High Speed clock becomes stable and HSIRDYDIE is
set.
Cleared by software setting the HSIRDYC bit.
0: No clock ready interrupt caused by the internal 8 MHz RC oscillator
1: Clock ready interrupt caused by the internal 8 MHz RC oscillator
  */
  HSERDYF,
  /*
  Bit3 HSERDYF: HSE ready interrupt flag
Set by hardware when External High Speed clock becomes stable and HSERDYDIE is set.
Cleared by software setting the HSERDYC bit.
0: No clock ready interrupt caused by the external 4-16 MHz oscillator
1: Clock ready interrupt caused by the external 4-16 MHz oscillator
  */
  PLLRDYF,
  /*
  Bit 4 PLLRDYF: PLL ready interrupt flag
  Set by hardware when the PLL locks and PLLRDYDIE is set.
  Cleared by software setting the PLLRDYC bit.
  0: No clock ready interrupt caused by PLL lock
  1: Clock ready interrupt caused by PLL lock

  */
  RESERVED_BIT_5_CIR,
  RESERVED_BIT_6_CIR,
  /*
Bits 6:5 Reserved, must be kept at reset value.
  */
  CSSF,
  /*
  Bit 7 CSSF: Clock security system interrupt flag
Set by hardware when a failure is detected in the external 4-16 MHz oscillator.
Cleared by software setting the CSSC bit.
0: No clock security interrupt caused by HSE clock failure
1: Clock security interrupt caused by HSE clock failure
  */
  LSIRDYIE,
  /*
  Bit 8 LSIRDYIE: LSI ready interrupt enable
  Set and cleared by software to enable/disable interrupt caused by internal RC 40 kHz
  oscillator stabilization.
  0: LSI ready interrupt disabled
  1: LSI ready interrupt enabled
  */
  LSERDYIE,
  /*
  Bit 9 LSERDYIE: LSE ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by the external 32 kHz
oscillator stabilization.
0: LSE ready interrupt disabled
1: LSE ready interrupt enabled
*/
  HSIRDYIE,
  /*
  Bit 10 HSIRDYIE: HSI ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by the internal 8 MHz RC
oscillator stabilization.
0: HSI ready interrupt disabled
1: HSI ready interrupt enabled
  */
  HSERDYIE,
  /*
  Bit 11 HSERDYIE: HSE ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by the external 4-16 MHz
oscillator stabilization.
0: HSE ready interrupt disabled
1: HSE ready interrupt enabled
  */
  PLLRDYIE,
  /*
  Bit 12 PLLRDYIE: PLL ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by PLL lock.
0: PLL lock interrupt disabled
1: PLL lock interrupt enabled
  */
  RESERVED_BIT_13_CIR,
  RESERVED_BIT_14_CIR,
  RESERVED_BIT_15_CIR,
  /*
  Bits 15:13 Reserved, must be kept at reset value.
  */
  LSIRDYC,
  /*
  Bit 16 LSIRDYC: LSI ready interrupt clear
This bit is set by software to clear the LSIRDYF flag.
0: No effect
1: LSIRDYF cleared
*/
  LSERDYC,
  /*
  Bit 17 LSERDYC: LSE ready interrupt clear
This bit is set by software to clear the LSERDYF flag.
0: No effect
1: LSERDYF cleared
  */
  HSIRDYC,
  /*
  Bit 18 HSIRDYC: HSI ready interrupt clear
This bit is set software to clear the HSIRDYF flag.
0: No effect
1: HSIRDYF cleared
  */
  HSERDYC,
  /*
  Bit 19 HSERDYC: HSE ready interrupt clear
This bit is set by software to clear the HSERDYF flag.
0: No effect
1: HSERDYF cleared
  */
  PLLRDYC,
  /*
  Bit 20 PLLRDYC: PLL ready interrupt clear
This bit is set by software to clear the PLLRDYF flag.
0: No effect
1: PLLRDYF cleared
  */
  RESERVED_BIT_21_CIR,
  RESERVED_BIT_22_CIR,
  /*
  Bits 22:21 Reserved, must be kept at reset value
  */
  CSSC,
  /*
  Bit 23 CSSC: Clock security system interrupt clear
This bit is set by software to clear the CSSF flag.
0: No effect
1: Clear CSSF flag
  */
  RESERVED_BIT_24_CIR,
  RESERVED_BIT_25_CIR,
  RESERVED_BIT_26_CIR,
  RESERVED_BIT_27_CIR,
  RESERVED_BIT_28_CIR,
  RESERVED_BIT_29_CIR,
  RESERVED_BIT_30_CIR,
  RESERVED_BIT_31_CIR
  /*
  Bits 31:24 Reserved, must be kept at reset value.
  */

}MRCC_CIR_BITS;

typedef enum
{
  AFIORST,
  /*
  Bit 0 AFIORST: Alternate function IO reset
  Set and cleared by software.
  0: No effect
  1: Reset Alternate Function
  */
  RESERVED_BIT_1_APB2RSTR,
  /*
  Bit 1 Reserved, must be kept at reset value.
  */
  IOPARST,
  /*
  Bit 2 IOPARST: IO port A reset
Set and cleared by software.
0: No effect
1: Reset IO port A
  */
  IOPBRST,
  /*
  Bit 3 IOPBRST: IO port B reset
Set and cleared by software.
0: No effect
1: Reset IO port B
  */
  IOPCRST,
  /*
  Bit 4 IOPCRST: IO port C reset
Set and cleared by software.
0: No effect
1: Reset IO port C
  */
  IOPDRST,
  /*
  Bit 5 IOPDRST: IO port D reset
Set and cleared by software.
0: No effect
1: Reset IO port D
  */
  IOPERST,
  /*
  Bit 6 IOPERST: IO port E reset
Set and cleared by software.
0: No effect
1: Reset IO port E
  */
  IOPFRST,
  /*
  Bit 7 IOPFRST: IO port F reset
Set and cleared by software.
0: No effect
1: Reset IO port F
  */
  IOPGRST,
  /*
  Bit 8 IOPGRST: IO port G reset
Set and cleared by software.
0: No effect
1: Reset IO port G
  */
  ADC1RST,
  /*
  Bit 9 ADC1RST: ADC 1 interface reset
Set and cleared by software.
0: No effect
1: Reset ADC 1 interface
  */
  ADC2RST,
  /*
  Bit 10 ADC2RST: ADC 2 interface reset
Set and cleared by software.
0: No effect
1: Reset ADC 2 interface
  */
  TIM1RST,
  /*
  Bit 11 TIM1RST: TIM1 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM1 timer
  */
  SPI1RST,
  /*
  Bit 12 SPI1RST: SPI1 reset
Set and cleared by software.
0: No effect
1: Reset SPI1
  */
  TIM8RST,
  /*
  Bit 13 TIM8RST: TIM8 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM8 timer
  */
  USART1RST,
  /*
  Bit 14 USART1RST: USART1 reset
Set and cleared by software.
0: No effect
1: Reset USART1
  */
  ADC3RST,
  /*
  Bit 15 ADC3RST: ADC3 interface reset
Set and cleared by software.
0: No effect
1: Reset ADC3 interface
  */
  RESERVED_BIT_16_APB2RSTR,
  RESERVED_BIT_17_APB2RSTR,
  RESERVED_BIT_18_APB2RSTR,
  /*
  Bits 18:16 Reserved, always read as 0.
  */
  TIM9RST,
  /*
  Bit 19 TIM9RST: TIM9 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM9 timer
  */
  TIM10RST,
  /*
  Bit 20 TIM10RST: TIM10 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM10 timer
*/
  TIM11RST,
  /*
  Bit 21 TIM11RST: TIM11 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM11 timer
*/
  RESERVED_BIT_22_APB2RSTR,
  RESERVED_BIT_23_APB2RSTR,
  RESERVED_BIT_24_APB2RSTR,
  RESERVED_BIT_25_APB2RSTR,
  RESERVED_BIT_26_APB2RSTR,
  RESERVED_BIT_27_APB2RSTR,
  RESERVED_BIT_28_APB2RSTR,
  RESERVED_BIT_29_APB2RSTR,
  RESERVED_BIT_30_APB2RSTR,
  RESERVED_BIT_31_APB2RSTR
  /*
  Bits 31:22 Reserved, must be kept at reset value.
  */

}MRCC_APB2RSTR_BITS;

typedef enum
{
  TIM2RST,
  /*
  Bit 0 TIM2RST: TIM2 timer reset
  Set and cleared by software.
  0: No effect
  1: Reset TIM2
  */
  TIM3RST,
  /*
  Bit 1 TIM3RST: TIM3 timer reset
  Set and cleared by software.
  0: No effect
  1: Reset TIM3
  */
  TIM4RST,
  /*
  Bit 2 TIM4RST: TIM4 timer reset
  Set and cleared by software.
  0: No effect
  1: Reset TIM4
  */
  TIM5RST,
  /*
  Bit 3 TIM5RST: TIM5 timer reset
  Set and cleared by software.
  0: No effect
  1: Reset TIM5
  */
  TIM6RST,
  /*
  Bit 4 TIM6RST: TIM6 timer reset
  Set and cleared by software.
  0: No effect
  1: Reset TIM6
  */
  TIM7RST,
  /*
  Bit 5 TIM7RST: TIM7 timer reset
  Set and cleared by software.
  0: No effect
  1: Reset TIM7
  */
  TIM12RST,
  /*
  Bit 6 TIM12RST: TIM12 timer reset
  Set and cleared by software.
  0: No effect
  1: Reset TIM12
  */
  TIM13RST,
  /*
  Bit 7 TIM13RST: TIM13 timer reset
  Set and cleared by software.
  0: No effect
  1: Reset TIM13
  */
  TIM14RST,
  /*
  Bit 8 TIM14RST: TIM14 timer reset
  Set and cleared by software.
  0: No effect
  1: Reset TIM14
  */
  RESERVED_BIT_9_APB1RST,
  RESERVED_BIT_10_APB1RST,
  /*
Bits 10:9 Reserved, must be kept at reset value.
  */
  WWDGRST,
  /*
  Bit 11 WWDGRST: Window watchdog reset
  Set and cleared by software.
  0: No effect
  1: Reset window watchdog
  */
  RESERVED_BIT_12_APB1RST,
  RESERVED_BIT_13_APB1RST,
  /*
Bits 13:12 Reserved, must be kept at reset value.
  */
  SPI2RST,
  /*
  Bit 14 SPI2RST: SPI2 reset
  Set and cleared by software.
  0: No effect
  1: Reset SPI2
  */
  SPI3RST,
  /*
  Bit 15 SPI3RST: SPI3 reset
  Set and cleared by software.
  0: No effect
  1: Reset SPI3
  */
  RESERVED_BIT_16_APB1RST,
  /*
Bit 16 Reserved, must be kept at reset value.
  */
  USART2RST,
  /*
  Bit 17 USART2RST: USART2 reset
  Set and cleared by software.
  0: No effect
  1: Reset USART2
  */
  USART3RST,
  /*
  Bit 18 USART3RST: USART3 reset
  Set and cleared by software.
  0: No effect
  1: Reset USART3
  */
  UART4RST,
  /*
  Bit 19 UART4RST: USART4 reset
  Set and cleared by software.
  0: No effect
  1: Reset USART4
  */
  UART5RST,
  /*
  Bit 20 UART5RST: USART5 reset
  Set and cleared by software.
  0: No effect
  1: Reset USART5
  */
  I2C1RST,
  /*
  Bit 21 I2C1RST: I2C1 reset
  Set and cleared by software.
  0: No effect
  1: Reset I2C1
  */
  I2C2RST,
  /*
  Bit 22 I2C2RST: I2C2 reset
  Set and cleared by software.
  0: No effect
  1: Reset I2C2
  */
  USBRST,
  /*
  Bit 23 USBRST: USB reset
  Set and cleared by software.
  0: No effect
  1: Reset USB
  */
  RESERVED_BIT_24_APB1RST,
  /*
Bit 24 Reserved, always read as 0.
  */
  CANRST,
  /*
  Bit 25 CANRST: CAN reset
  Set and cleared by software.
  0: No effect
  1: Reset CAN
  */
  RESERVED_BIT_26_APB1RST,
  /*
Bit 26 Reserved, must be kept at reset value.
  */
  BKPRST,
  /*
  Bit 27 BKPRST: Backup interface reset
  Set and cleared by software.
  0: No effect
  1: Reset backup interface
  */
  PWRRST,
  /*
  Bit 28 PWRRST: Power interface reset
  Set and cleared by software.
  0: No effect
  1: Reset power interface
  */
  DACRST,
  /*
  Bit 29 DACRST: DAC interface reset
  Set and cleared by software.
  0: No effect
  1: Reset DAC interface
  */
  RESERVED_BIT_30_APB1RST,
  RESERVED_BIT_31_APB1RST
  /*
Bits 31:30 Reserved, must be kept at reset value.
  */

}MRCC_APB1RST_BITS;

typedef enum
{
  DMA1EN,
  /*
  Bit 0 DMA1EN: DMA1 clock enable
  Set and cleared by software.
  0: DMA1 clock disabled
  1: DMA1 clock enabled
  */
  DMA2EN,
  /*
  Bit 1 DMA2EN: DMA2 clock enable
  Set and cleared by software.
  0: DMA2 clock disabled
  1: DMA2 clock enabled
  */
  SRAMEN,
  /*
  Bit 2 SRAMEN: SRAM interface clock enable
  Set and cleared by software to disable/enable SRAM interface clock during Sleep mode.
  0: SRAM interface clock disabled during Sleep mode.
  1: SRAM interface clock enabled during Sleep mode
  */
  RESERVED_BIT_3_AHBENR,
  /*
Bit 3 Reserved, must be kept at reset value.
  */
  FLITFEN,
  /*
  Bit 4 FLITFEN: FLITF clock enable
  Set and cleared by software to disable/enable FLITF clock during Sleep mode.
  0: FLITF clock disabled during Sleep mode
  1: FLITF clock enabled during Sleep mode
  */
  RESERVED_BIT_5_AHBENR,
  /*
Bit 5 Reserved, must be kept at reset value.
  */
  CRCEN,
  /*
  Bit 6 CRCEN: CRC clock enable
  Set and cleared by software.
  0: CRC clock disabled
  1: CRC clock enabled
  */
  RESERVED_BIT_7_AHBENR,
  /*
Bit 7 Reserved, always read as 0.
  */
  FSMCEN,
  /*
  Bit 8 FSMCEN: FSMC clock enable
  Set and cleared by software.
  0: FSMC clock disabled
  1: FSMC clock enabled
  */
  RESERVED_BIT_9_AHBENR,
  /*
Bits 9 Reserved, always read as 0.
  */
  SDIOEN,
  /*
  Bit 10 SDIOEN: SDIO clock enable
  Set and cleared by software.
  0: SDIO clock disabled
  1: SDIO clock enabled
  */
  RESERVED_BIT_11_AHBENR,
  RESERVED_BIT_12_AHBENR,
  RESERVED_BIT_13_AHBENR,
  RESERVED_BIT_14_AHBENR,
  RESERVED_BIT_15_AHBENR,
  RESERVED_BIT_16_AHBENR,
  RESERVED_BIT_17_AHBENR,
  RESERVED_BIT_18_AHBENR,
  RESERVED_BIT_19_AHBENR,
  RESERVED_BIT_20_AHBENR,
  RESERVED_BIT_21_AHBENR,
  RESERVED_BIT_22_AHBENR,
  RESERVED_BIT_23_AHBENR,
  RESERVED_BIT_24_AHBENR,
  RESERVED_BIT_25_AHBENR,
  RESERVED_BIT_26_AHBENR,
  RESERVED_BIT_27_AHBENR,
  RESERVED_BIT_28_AHBENR,
  RESERVED_BIT_29_AHBENR,
  RESERVED_BIT_30_AHBENR,
  RESERVED_BIT_31_AHBENR
  /*
Bits 31:11 Reserved, must be kept at reset value.
  */

}MRCC_AHBENR_BITS;

typedef enum
{
  AFIOEN,
  /*
  Bit 0 AFIOEN: Alternate function IO clock enable
  Set and cleared by software.
  0: Alternate Function IO clock disabled
  1: Alternate Function IO clock enabled
  */
  RESERVED_BIT_2_APB2ENR,
  /*
Bit 1 Reserved, must be kept at reset value.
  */
  IOPAEN,
  /*
  Bit 2 IOPAEN: IO port A clock enable
  Set and cleared by software.
  0: IO port A clock disabled
  1: IO port A clock enabled
  */
  IOPBEN,
  /*
  Bit 3 IOPBEN: IO port B clock enable
  Set and cleared by software.
  0: IO port B clock disabled
  1: IO port B clock enabled
  */
  IOPCEN,
  /*
  Bit 4 IOPCEN: IO port C clock enable
  Set and cleared by software.
  0: IO port C clock disabled
  1: IO port C clock enabled
  */
  IOPDEN,
  /*
  Bit 5 IOPDEN: IO port D clock enable
  Set and cleared by software.
  0: IO port D clock disabled
  1: IO port D clock enabled
  */
  IOPEEN,
  /*
  Bit 6 IOPEEN: IO port E clock enable
  Set and cleared by software.
  0: IO port E clock disabled
  1: IO port E clock enabled
  */
  IOPFEN,
  /*
  Bit 7 IOPFEN: IO port F clock enable
  Set and cleared by software.
  0: IO port F clock disabled
  1: IO port F clock enabled
  */
  IOPGEN,
  /*
  Bit 8 IOPGEN: IO port G clock enable
  Set and cleared by software.
  0: IO port G clock disabled
  1: IO port G clock enabled
  */
  ADC1EN,
  /*
  Bit 9 ADC1EN: ADC 1 interface clock enable
  Set and cleared by software.
  0: ADC 1 interface disabled
  1: ADC 1 interface clock enabled
  */
  ADC2EN,
  /*
  Bit 10 ADC2EN: ADC 2 interface clock enable
  Set and cleared by software.
  0: ADC 2 interface clock disabled
  1: ADC 2 interface clock enabled
  */
  TIM1EN,
  /*
  Bit 11 TIM1EN: TIM1 timer clock enable
  Set and cleared by software.
  0: TIM1 timer clock disabled
  1: TIM1 timer clock enabled
  */
  SPI1EN,
  /*
  Bit 12 SPI1EN: SPI1 clock enable
  Set and cleared by software.
  0: SPI1 clock disabled
  1: SPI1 clock enabled
  */
  TIM8EN,
  /*
  Bit 13 TIM8EN: TIM8 Timer clock enable
  Set and cleared by software.
  0: TIM8 timer clock disabled
  1: TIM8 timer clock enabled
  */
  USART1EN,
  /*
  Bit 14 USART1EN: USART1 clock enable
  Set and cleared by software.
  0: USART1 clock disabled
  1: USART1 clock enabled
  */
  ADC3EN,
  /*
  Bit 15 ADC3EN: ADC3 interface clock enable
  Set and cleared by software.
  0: ADC3 interface clock disabled
  1: ADC3 interface clock enabled
  */
  RESERVED_BIT_16_APB2ENR,
  RESERVED_BIT_17_APB2ENR,
  RESERVED_BIT_18_APB2ENR,
  /*
Bits 18:16 Reserved, always read as 0.
  */
  TIM9EN,
  /*
  Bit 19 TIM9EN: TIM9 timer clock enable
  Set and cleared by software.
  0: TIM9 timer clock disabled
  1: TIM9 timer clock enabled
  */
  TIM10EN,
  /*
  Bit 20 TIM10EN: TIM10 timer clock enable
  Set and cleared by software.
  0: TIM10 timer clock disabled
  1: TIM10 timer clock enabled
  */
  TIM11EN,
  /*
  Bit 21 TIM11EN: TIM11 timer clock enable
  Set and cleared by software.
  0: TIM11 timer clock disabled
  1: TIM11 timer clock enabled
  */
  RESERVED_BIT_22_APB2ENR,
  RESERVED_BIT_23_APB2ENR,
  RESERVED_BIT_24_APB2ENR,
  RESERVED_BIT_25_APB2ENR,
  RESERVED_BIT_26_APB2ENR,
  RESERVED_BIT_27_APB2ENR,
  RESERVED_BIT_28_APB2ENR,
  RESERVED_BIT_29_APB2ENR,
  RESERVED_BIT_30_APB2ENR,
  RESERVED_BIT_31_APB2ENR
  /*
Bits 31:22 Reserved, must be kept at reset value.
  */
}MRCC_APB2ENR_BITS;

typedef enum
{
  TIM2EN,
  /*
  Bit 0 TIM2EN: TIM2 timer clock enable
  Set and cleared by software.
  0: TIM2 clock disabled
  1: TIM2 clock enabled
  */
  TIM3EN,
  /*
  Bit 1 TIM3EN: TIM3 timer clock enable
  Set and cleared by software.
  0: TIM3 clock disabled
  1: TIM3 clock enabled
  */
  TIM4EN,
  /*
  Bit 2 TIM4EN: TIM4 timer clock enable
  Set and cleared by software.
  0: TIM4 clock disabled
  1: TIM4 clock enabled
  */
  TIM5EN,
  /*
  Bit 3 TIM5EN: TIM5 timer clock enable
  Set and cleared by software.
  0: TIM5 clock disabled
  1: TIM5 clock enabled
  */
  TIM6EN,
  /*
  Bit 4 TIM6EN: TIM6 timer clock enable
  Set and cleared by software.
  0: TIM6 clock disabled
  1: TIM6 clock enabled
  */
  TIM7EN,
  /*
  Bit 5 TIM7EN: TIM7 timer clock enable
  Set and cleared by software.
  0: TIM7 clock disabled
  1: TIM7 clock enabled
  */
  TIM12EN,
  /*
  Bit 6 TIM12EN: TIM12 timer clock enable
  Set and cleared by software.
  0: TIM12 clock disabled
  1: TIM12 clock enabled
  */
  TIM13EN,
  /*
  Bit 7 TIM13EN: TIM13 timer clock enable
  Set and cleared by software.
  0: TIM13 clock disabled
  1: TIM13 clock enabled
  */
  TIM14EN,
  /*
  Bit 8 TIM14EN: TIM14 timer clock enable
  Set and cleared by software.
  0: TIM14 clock disabled
  1: TIM14 clock enabled
  */
  RESERVED_BIT_9_APB1ENR,
  RESERVED_BIT_10_APB1ENR,
  /*
Bits 10:9 Reserved, must be kept at reset value.
  */
  WWDGEN,
  /*
  Bit 11 WWDGEN: Window watchdog clock enable
Set and cleared by software.
0: Window watchdog clock disabled
1: Window watchdog clock enabled
  */
  RESERVED_BIT_12_APB1ENR,
  RESERVED_BIT_13_APB1ENR,
  /*
Bits 13:12 Reserved, must be kept at reset value.
  */
  SPI2EN,
  /*
  Bit 14 SPI2EN: SPI2 clock enable
  Set and cleared by software.
  0: SPI2 clock disabled
  1: SPI2 clock enabled
  */
  SPI3EN,
  /*
  Bit 15 SPI3EN: SPI 3 clock enable
  Set and cleared by software.
  0: SPI 3 clock disabled
  1: SPI 3 clock enabled
  */
  RESERVED_BIT_16_APB1ENR,
  /*
Bits 16 Reserved, always read as 0.
  */
  USART2EN,
  /*
  Bit 17 USART2EN: USART2 clock enable
  Set and cleared by software.
  0: USART2 clock disabled
  1: USART2 clock enabled
  */
  USART3EN,
  /*
  Bit 18 USART3EN: USART3 clock enable
  Set and cleared by software.
  0: USART3 clock disabled
  1: USART3 clock enabled
  */
  UART4EN,
  /*
  Bit 19 UART4EN: USART4 clock enable
  Set and cleared by software.
  0: USART4 clock disabled
  1: USART4 clock enabled
  */
  UART5EN,
  /*
  Bit 20 UART5EN: USART5 clock enable
  Set and cleared by software.
  0: USART5 clock disabled
  1: USART5 clock enabled
  */
  I2C1EN,
  /*
  Bit 21 I2C1EN: I2C1 clock enable
  Set and cleared by software.
  0: I2C1 clock disabled
  1: I2C1 clock enabled
  */
  I2C2EN,
  /*
  Bit 22 I2C2EN: I2C2 clock enable
  Set and cleared by software.
  0: I2C2 clock disabled
  1: I2C2 clock enabled
  */
  USBEN,
  /*
  Bit 23 USBEN: USB clock enable
  Set and cleared by software.
  0: USB clock disabled
  1: USB clock enabled
  */
  RESERVED_BIT_24_APB1ENR,
  /*
Bit 24 Reserved, always read as 0.
  */
  CANEN,
  /*
  Bit 25 CANEN: CAN clock enable
  Set and cleared by software.
  0: CAN clock disabled
  1: CAN clock enabled
  */
  RESERVED_BIT_26_APB1ENR,
  /*
Bit 26 Reserved, must be kept at reset value.
  */
  BKPEN,
  /*
  Bit 27 BKPEN: Backup interface clock enable
  Set and cleared by software.
  0: Backup interface clock disabled
  1: Backup interface clock enabled
  */
  PWREN,
  /*
  Bit 28 PWREN: Power interface clock enable
  Set and cleared by software.
  0: Power interface clock disabled
  1: Power interface clock enable
  */
  DACEN,
  /*
  Bit 29 DACEN: DAC interface clock enable
  Set and cleared by software.
  0: DAC interface clock disabled
  1: DAC interface clock enable
  */
  RESERVED_BIT_30_APB1ENR,
  RESERVED_BIT_31_APB1ENR
  /*
Bits 31:30 Reserved, must be kept at reset value.
  */

}MRCC_APB1ENR_BITS;

typedef enum
{
  LSEON,
  /*
  Bit 0 LSEON: External low-speed oscillator enable
  Set and cleared by software.
  0: External 32 kHz oscillator OFF
  1: External 32 kHz oscillator ON
  */
  LSERDY,
  /*
  Bit 1 LSERDY: External low-speed oscillator ready
  Set and cleared by hardware to indicate when the external 32 kHz oscillator is stable. After
  the LSEON bit is cleared, LSERDY goes low after 6 external low-speed oscillator clock
  cycles.
  0: External 32 kHz oscillator not ready
  1: External 32 kHz oscillator ready
  */
  LSEBYP,
  /*
  Bit 2 LSEBYP: External low-speed oscillator bypass
  Set and cleared by software to bypass oscillator in debug mode. This bit can be written only
  when the external 32 kHz oscillator is disabled.
  0: LSE oscillator not bypassed
  1: LSE oscillator bypassed
  */
  RESERVED_BIT_3_BDCR,
  RESERVED_BIT_4_BDCR,
  RESERVED_BIT_5_BDCR,
  RESERVED_BIT_6_BDCR,
  RESERVED_BIT_7_BDCR,
  /*
Bits 7:3 Reserved, must be kept at reset value.
  */
  RTCSEL_8,
  RTCSEL_9,
  /*
  Bits 9:8 RTCSEL[1:0]: RTC clock source selection
  Set by software to select the clock source for the RTC. Once the RTC clock source has been
  selected, it cannot be changed anymore unless the Backup domain is reset. The BDRST bit
  can be used to reset them.
  00: No clock
  01: LSE oscillator clock used as RTC clock
  10: LSI oscillator clock used as RTC clock
  11: HSE oscillator clock divided by 128 used as RTC clock
  */
  RESERVED_BIT_10_BDCR,
  RESERVED_BIT_11_BDCR,
  RESERVED_BIT_12_BDCR,
  RESERVED_BIT_13_BDCR,
  RESERVED_BIT_14_BDCR,
  /*
Bits 14:10 Reserved, must be kept at reset value.
  */
  RTCEN,
  /*
  Bit 15 RTCEN: RTC clock enable
  Set and cleared by software.
  0: RTC clock disabled
  1: RTC clock enabled
  */
  BDRST,
  /*
  Bit 16 BDRST: Backup domain software reset
  Set and cleared by software.
  0: Reset not activated
  1: Resets the entire Backup domain
  */
  RESERVED_BIT_17_BDCR,
  RESERVED_BIT_18_BDCR,
  RESERVED_BIT_19_BDCR,
  RESERVED_BIT_20_BDCR,
  RESERVED_BIT_21_BDCR,
  RESERVED_BIT_22_BDCR,
  RESERVED_BIT_23_BDCR,
  RESERVED_BIT_24_BDCR,
  RESERVED_BIT_25_BDCR,
  RESERVED_BIT_26_BDCR,
  RESERVED_BIT_27_BDCR,
  RESERVED_BIT_28_BDCR,
  RESERVED_BIT_29_BDCR,
  RESERVED_BIT_30_BDCR,
  RESERVED_BIT_31_BDCR
  /*
Bits 31:17 Reserved, must be kept at reset value.
  */
  }MRCC_BDCR_BITS;

typedef enum
{
  LSION,
  /*
  Bit 0 LSION: Internal low-speed oscillator enable
  Set and cleared by software.
  0: Internal RC 40 kHz oscillator OFF
  1: Internal RC 40 kHz oscillator ON
  */
  LSIRDY,
  /*
  Bit 1 LSIRDY: Internal low-speed oscillator ready
  Set and cleared by hardware to indicate when the internal RC 40 kHz oscillator is stable.
  After the LSION bit is cleared, LSIRDY goes low after 3 internal RC 40 kHz oscillator clock
  cycles.
  0: Internal RC 40 kHz oscillator not ready
  1: Internal RC 40 kHz oscillator ready
  */
  RESERVED_BIT_2_CSR,
  RESERVED_BIT_3_CSR,
  RESERVED_BIT_4_CSR,
  RESERVED_BIT_5_CSR,
  RESERVED_BIT_6_CSR,
  RESERVED_BIT_7_CSR,
  RESERVED_BIT_8_CSR,
  RESERVED_BIT_9_CSR,
  RESERVED_BIT_10_CSR,
  RESERVED_BIT_11_CSR,
  RESERVED_BIT_12_CSR,
  RESERVED_BIT_13_CSR,
  RESERVED_BIT_14_CSR,
  RESERVED_BIT_15_CSR,
  RESERVED_BIT_16_CSR,
  RESERVED_BIT_17_CSR,
  RESERVED_BIT_18_CSR,
  RESERVED_BIT_19_CSR,
  RESERVED_BIT_20_CSR,
  RESERVED_BIT_21_CSR,
  RESERVED_BIT_22_CSR,
  RESERVED_BIT_23_CSR,
  /*
Bits 23:2 Reserved, must be kept at reset value.
  */
  RMVF,
  /*
  Bit 24 RMVF: Remove reset flag
  Set by software to clear the reset flags.
  0: No effect
  1: Clear the reset flags
  */
  RESERVED_BIT_25_CSR,
  /*
Bit 25 Reserved, must be kept at reset value
  */
  PINRSTF,
  /*
  Bit 26 PINRSTF: PIN reset flag
  Set by hardware when a reset from the NRST pin occurs.
  Cleared by writing to the RMVF bit.
  0: No reset from NRST pin occurred
  1: Reset from NRST pin occurred
  */
  PORRSTF,
  /*
  Bit 27 PORRSTF: POR/PDR reset flag
  Set by hardware when a POR/PDR reset occurs.
  Cleared by writing to the RMVF bit.
  0: No POR/PDR reset occurred
  1: POR/PDR reset occurred
  */
  SFTRSTF,
  /*
  Bit 28 SFTRSTF: Software reset flag
  Set by hardware when a software reset occurs.
  Cleared by writing to the RMVF bit.
  0: No software reset occurred
  1: Software reset occurred
  */
  IWDGRSTF,
  /*
  Bit 29 IWDGRSTF: Independent watchdog reset flag
  Set by hardware when an independent watchdog reset from VDD domain occurs.
  Cleared by writing to the RMVF bit.
  0: No watchdog reset occurred
  1: Watchdog reset occurred
  */
  WWDGRSTF,
  /*
  Bit 30 WWDGRSTF: Window watchdog reset flag
  Set by hardware when a window watchdog reset occurs.
  Cleared by writing to the RMVF bit.
  0: No window watchdog reset occurred
  1: Window watchdog reset occurred
  */
  LPWRRSTF
  /*
  Bit 31 LPWRRSTF: Low-power reset flag
  Set by hardware when a Low-power management reset occurs.
  Cleared by writing to the RMVF bit.
  0: No Low-power management reset occurred
  1: Low-power management reset occurred
  For further information on Low-power management reset, refer to Low-power management
  reset.
  */
}MRCC_CSR_BITS;


void MRCC_voidInitSysClk(void);
void MRCC_voidEnableAHBClk (MRCC_AHBENR_BITS  PeriphID);
void MRCC_voidEnableAPB2Clk(MRCC_APB2ENR_BITS PeriphID);
void MRCC_voidEnableAPB1Clk(MRCC_APB1ENR_BITS PeriphID);

void MRCC_voidDisableAHBClk (MRCC_AHBENR_BITS  PeriphID);
void MRCC_voidDisableAPB2Clk(MRCC_APB2ENR_BITS PeriphID);
void MRCC_voidDisableAPB1Clk(MRCC_APB1ENR_BITS PeriphID);


#endif
