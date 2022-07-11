/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 04 Jul 2022                                          */
/* Version     : V01                                                  */
/**********************************************************************/

#ifndef MDMA_INTERFACE_H
#define MDMA_INTERFACE_H

void MDMA_voidCHSelect (u8 CHannel_ID);
void MDMA_voidCHannelInit(void);
void MDMA_voidCHannelStart(u32 * MDMA_u32PtrSrcAdd, u32 * MDMA_u32PtrDestAdd ,u16 MDMA_u16BlockLength );
void MDMA_VoidSetCallBackCH1(void (*ptr)(void));
void MDMA_VoidSetCallBackCH2(void (*ptr)(void));
void MDMA_VoidSetCallBackCH3(void (*ptr)(void));
void MDMA_VoidSetCallBackCH4(void (*ptr)(void));
void MDMA_VoidSetCallBackCH5(void (*ptr)(void));
void MDMA_VoidSetCallBackCH6(void (*ptr)(void));
void MDMA_VoidSetCallBackCH7(void (*ptr)(void));




typedef enum MDMA_ISR_BIT
{
  GIF1,
  TCIF1,
  HTIF1,
  TEIF1,

  GIF2,
  TCIF2,
  HTIF2,
  TEIF2,

  GIF3,
  TCIF3,
  HTIF3,
  TEIF3,

  GIF4,
  TCIF4,
  HTIF4,
  TEIF4,

  GIF5,
  TCIF5,
  HTIF5,
  TEIF5,

  GIF6,
  TCIF6,
  HTIF6,
  TEIF6,

  GIF7,
  TCIF7,
  HTIF7,
  TEIF7,

  RESERVED_BIT_28_ISR,
  RESERVED_BIT_29_ISR,
  RESERVED_BIT_30_ISR,
  RESERVED_BIT_31_ISR

}MDMA_ISR_BIT_T;


typedef enum MDMA_IFCR_BIT
{
  CGIF1,
  CTCIF1,
  CHTIF1,
  CTEIF1,

  CGIF2,
  CTCIF2,
  CHTIF2,
  CTEIF2,

  CGIF3,
  CTCIF3,
  CHTIF3,
  CTEIF3,

  CGIF4,
  CTCIF4,
  CHTIF4,
  CTEIF4,

  CGIF5,
  CTCIF5,
  CHTIF5,
  CTEIF5,

  CGIF6,
  CTCIF6,
  CHTIF6,
  CTEIF6,

  CGIF7,
  CTCIF7,
  CHTIF7,
  CTEIF7,

  RESERVED_BIT_28_IFCR,
  RESERVED_BIT_29_IFCR,
  RESERVED_BIT_30_IFCR,
  RESERVED_BIT_31_IFCR

}MDMA_IFCR_BIT_T;

typedef enum MDMA_CCR_BIT
{
  EN,
  TCIE,
  HTIE,
  TEIE,
  DIR,
  CIRC,
  PINC,
  MINC,
  PSIZE_0,
  PSIZE_1,
  MSIZE_0,
  MSIZE_1,
  PL_0,
  PL_1,
  MEM2MEM,
  RESERVED_BIT_15_CCR,
  RESERVED_BIT_16_CCR,
  RESERVED_BIT_17_CCR,
  RESERVED_BIT_18_CCR,
  RESERVED_BIT_19_CCR,
  RESERVED_BIT_20_CCR,
  RESERVED_BIT_21_CCR,
  RESERVED_BIT_22_CCR,
  RESERVED_BIT_23_CCR,
  RESERVED_BIT_24_CCR,
  RESERVED_BIT_25_CCR,
  RESERVED_BIT_26_CCR,
  RESERVED_BIT_27_CCR,
  RESERVED_BIT_28_CCR,
  RESERVED_BIT_29_CCR,
  RESERVED_BIT_30_CCR,
  RESERVED_BIT_31_CCR

}MDMA_CCR_BIT_T;

#endif
