/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 21 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  MSCB_PRIVATE_H
#define  MSCB_PRIVATE_H

#define  MSCB_BASE_ADDRESS   0xE000ED00

typedef struct
{
  volatile u32 MSCB_CPUID;
  //contains the processor part number, version, and implementation information.
  volatile u32 MSCB_ICSR;
  //SET AND CLEAR PENDING OF NMI,SYSTICK,PENDSV EXCEPTION AND STATE REGISTER
  volatile u32 MSCB_VTOR;
  // VECTOR TABLE OFFSET
  volatile u32 MSCB_AIRCR;
  //provides priority grouping control for the exception model,SOFTWARE RESET
  volatile u32 MSCB_SCR;
  volatile u32 MSCB_CCR;
  volatile u32 MSCB_SHPR1;
  volatile u32 MSCB_SHPR2;
  volatile u32 MSCB_SHPR3;
  volatile u32 MSCB_SHCRS;
  volatile u32 MSCB_HFSR;
  volatile u32 MSCB_MMAR;
  volatile u32 MSCB_BFAR;

}MSCB_T;

#define  MSCB    ((volatile MSCB_T*)MSCB_BASE_ADDRESS)

#endif
