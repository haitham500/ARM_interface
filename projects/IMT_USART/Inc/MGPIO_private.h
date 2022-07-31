/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 02 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  MGPIO_PRIVATE_H
#define  MGPIO_PRIVATE_H

#define MGPIOA_BASE_ADDRESS  0x40010800
#define MGPIOB_BASE_ADDRESS  0x40010C00
#define MGPIOC_BASE_ADDRESS  0x40011000




// GPIOA registers addresses
typedef struct
{
 volatile u32 MGPIOA_CRL;
 volatile u32 MGPIOA_CRH;
 volatile u32 MGPIOA_IDR;
 volatile u32 MGPIOA_ODR;
 volatile u32 MGPIOA_BSRR;
 volatile u32 MGPIOA_BRR;
 volatile u32 MGPIOA_LCKR;

}MGPIOA_RT;

#define MGPIOA  ((volatile MGPIOA_RT*) 0x40010800)


// MGPIOB registers addresses
typedef struct
{
 volatile u32 MGPIOB_CRL;
 volatile u32 MGPIOB_CRH;
 volatile u32 MGPIOB_IDR;
 volatile u32 MGPIOB_ODR;
 volatile u32 MGPIOB_BSRR;
 volatile u32 MGPIOB_BRR;
 volatile u32 MGPIOB_LCKR;

}MGPIOB_RT;

#define MGPIOB  ((volatile MGPIOB_RT*) MGPIOB_BASE_ADDRESS)



// MGPIOC registers addresses
typedef struct 
{
 volatile u32 MGPIOC_CRL;
 volatile u32 MGPIOC_CRH;
 volatile u32 MGPIOC_IDR;
 volatile u32 MGPIOC_ODR;
 volatile u32 MGPIOC_BSRR;
 volatile u32 MGPIOC_BRR;
 volatile u32 MGPIOC_LCKR;

}MGPIOC_RT;

#define MGPIOC  ((volatile MGPIOC_RT*) MGPIOC_BASE_ADDRESS)



#endif
