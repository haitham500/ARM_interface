/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 09 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  MAFIO_PRIVATE_H
#define  MAFIO_PRIVATE_H

#define MAFIO_BASE_ADDRESS   0x40010000

typedef struct
{
  volatile u32 MAFIO_EVCR ;
  volatile u32 MAFIO_MAPR ;
  volatile u32 MAFIO_EXTICR1 ;
  volatile u32 MAFIO_EXTICR2 ;
  volatile u32 MAFIO_EXTICR3 ;
  volatile u32 MAFIO_EXTICR4 ;
  volatile u32 MAFIO_MAPR2 ;

}MAFIO_T;

#define MAFIO  ((volatile MAFIO_T *) MAFIO_BASE_ADDRESS)


#endif
