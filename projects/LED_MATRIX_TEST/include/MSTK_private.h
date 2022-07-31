/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 04 Dec. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  MSTK_PRIVATE_H
#define  MSTK_PRIVATE_H

#define MSTK_BASE_ADDRESS   0xE000E010

typedef struct
{
  volatile u32 MSTK_CTRL;
  volatile u32 MSTK_LOAD;
  volatile u32 MSTK_VAL;
  volatile u32 MSTK_CALIB;
}MSTK_T;


#define MSTK  ((volatile MSTK_T*)MSTK_BASE_ADDRESS)


#endif
