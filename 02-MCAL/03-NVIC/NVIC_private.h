/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 24 Aug 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/




#ifndef  NVIC_PRIVATE_H
#define  NVIC_PRIVATE_H

/* 0xE000E100-0xE000E4EF NVIC base address*/

#define NVIC_ISER0       *((u32*)0xE000E100) /* Enable External Interrupts from 0 to 31       */
#define NVIC_ISER1       *((u32*)0xE000E104) /* Enable External Interrupts from 32 to 63      */

#define NVIC_ICER0       *((u32*)0xE000E180) /* Disable External Interrupts from 0 to 31      */
#define NVIC_ICER1       *((u32*)0xE000E184) /* Disable External Interrupts from 32 to 63     */

#define NVIC_ISPR0       *((u32*)0xE000E200) /* Enable Pending Flag Interrupts from 0 to 31   */
#define NVIC_ISPR1       *((u32*)0xE000E204) /* Enable Pending Flag Interrupts from 32 to 63  */

#define NVIC_ICPR0       *((u32*)0xE000E280) /* Disable Pending Flag Interrupts from 0 to 31  */
#define NVIC_ICPR1       *((u32*)0xE000E284) /* Disable Pending Flag Interrupts from 32 to 63 */

#define NVIC_IABR0       *((volatile u32*)0xE000E300) /* Read Only Active Flag Interrupts from 0 to 31  */
#define NVIC_IABR1       *((volatile u32*)0xE000E304) /* Read Only Active Flag Interrupts from 32 to 63  */

#define NVIC_IPR           ((volatile u8*)(0xE000E100+0x300)) /* set S.W priority */
#define SCB_AIRCR         *((volatile u32*)(0xE000ED00+0x0C)) /* specify groups and subgroups in NVIC_IPR  */

#endif
