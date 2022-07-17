/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 04 Jul 2022                                          */
/* Version     : V01                                                  */
/**********************************************************************/

#ifndef MDMA_PRIVATE_H
#define MDMA_PRIVATE_H

#define MDMA_BASE_ADD  0x40020000

typedef struct
{
  volatile u32 MDMA_ISR;
  volatile u32 MDMA_IFCR;
  // CHANNEL 01
  volatile u32 MDMA_CCR1;
  volatile u32 MDMA_CNDTR1;
  volatile u32 MDMA_CPAR1;
  volatile u32 MDMA_CMAR1;
  volatile u32 MDMA_RESERVED1;
  // CHANNEL 02
  volatile u32 MDMA_CCR2;
  volatile u32 MDMA_CNDTR2;
  volatile u32 MDMA_CPAR2;
  volatile u32 MDMA_CMAR2;
  volatile u32 MDMA_RESERVED2;
  // CHANNEL 03
  volatile u32 MDMA_CCR3;
  volatile u32 MDMA_CNDTR3;
  volatile u32 MDMA_CPAR3;
  volatile u32 MDMA_CMAR3;
  volatile u32 MDMA_RESERVED3;
  // CHANNEL 04
  volatile u32 MDMA_CCR4;
  volatile u32 MDMA_CNDTR4;
  volatile u32 MDMA_CPAR4;
  volatile u32 MDMA_CMAR4;
  volatile u32 MDMA_RESERVED4;
  // CHANNEL 05
  volatile u32 MDMA_CCR5;
  volatile u32 MDMA_CNDTR5;
  volatile u32 MDMA_CPAR5;
  volatile u32 MDMA_CMAR5;
  volatile u32 MDMA_RESERVED5;
  // CHANNEL 06
  volatile u32 MDMA_CCR6;
  volatile u32 MDMA_CNDTR6;
  volatile u32 MDMA_CPAR6;
  volatile u32 MDMA_CMAR6;
  volatile u32 MDMA_RESERVED6;
  // CHANNEL 07
  volatile u32 MDMA_CCR7;
  volatile u32 MDMA_CNDTR7;
  volatile u32 MDMA_CPAR7;
  volatile u32 MDMA_CMAR7;
  volatile u32 MDMA_RESERVED7;

} MDMA_R;

/*
// another way to define register in short context

#typedef struct
{
volatile u32 MDMA_CCR;
volatile u32 MDMA_CNDTR;
volatile u32 MDMA_CPAR;
volatile u32 MDMA_CMAR;
volatile u32 MDMA_RESERVED;

}MDMA_CH ;

#typedef struct
{
volatile u32 MDMA_ISR;
volatile u32 MDMA_IFCR;
MDMA_CH CHANNEL[7]
}MDMA_R;

*/



#define MDMA  ((volatile MDMA_R*) MDMA_BASE_ADD)


#endif
