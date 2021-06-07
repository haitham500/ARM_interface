/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 26 Sep 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/


//registers and addresses

#ifndef MRCC_PRIVATE_H
#define MRCC_PRIVATE_H

#define MRCC_BASE_ADD   0x40021000

typedef struct  {

volatile u32 CR;
volatile u32 CFGR;
volatile u32 CIR;
volatile u32 APB2RSTR;
volatile u32 APB1RSTR;
volatile u32 AHBENR;
volatile u32 APB2ENR;
volatile u32 APB1ENR;
volatile u32 BDCR;
volatile u32 CSR;

}MRCC_R;

#define MRCC  ((volatile MRCC_R *) MRCC_BASE_ADD)

#endif
