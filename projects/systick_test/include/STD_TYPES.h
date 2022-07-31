/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 26 Sep 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/


#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef signed   char                     s8 ;
typedef signed   short int                s16;
typedef signed   long  int                s32;

typedef unsigned char                     u8 ;
typedef unsigned short int                u16;
typedef unsigned long  int                u32;


typedef enum PIN
{
  PIN0,
  PIN1,
  PIN2,
  PIN3,
  PIN4,
  PIN5,
  PIN6,
  PIN7,
  PIN8,
  PIN9,
  PIN10,
  PIN11,
  PIN12,
  PIN13,
  PIN14,
  PIN15
}PIN_T;
typedef enum PORT
{
  PORTA,
  PORTB,
  PORTC,

}PORT_T;

#endif
