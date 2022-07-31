/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 22 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  MEXTI_PRIVATE_H
#define  MEXTI_PRIVATE_H

#define  MEXTI_BASE_ADDRESS   0x40010400

typedef struct
{
  volatile u32 MEXTI_IMR;
  volatile u32 MEXTI_EMR;
  volatile u32 MEXTI_RTSR;
  volatile u32 MEXTI_FTSR;
  volatile u32 MEXTI_SWIER;
  volatile u32 MEXTI_PR;

}MEXTI_T;

#define  MEXTI    ((volatile MEXTI_T*)MEXTI_BASE_ADDRESS)


#endif
