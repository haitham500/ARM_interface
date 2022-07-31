/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 26 Sep 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  BIT_MATH_H
#define  BIT_MATH_H

#define  SET_BIT(VAR,BIT)              VAR |=  (1 << (BIT))
#define  CLR_BIT(VAR,BIT)              VAR &= ~(1 << (BIT))
#define  GET_BIT(VAR,BIT)              ((VAR >> BIT)& 1)
#define  TOG_BIT(VAR,BIT)              VAR ^=  (1 << (BIT))


#define SET_HIGHER_NIBBLE(REG) (REG|=0X0F)
#define SET_LOWER_NIBBLE(REG) (REG|=0XF0)
#define CLR_HIGHER_NIBBLE(REG) (REG&=0X0F)
#define CLR_LOWER_NIBBLE(REG) (REG&=0XF0)
#define GET_HIGHER_NIBBLE(REG) (REG>>4)
#define GET_LOWER_NIBBLE(REG) (REG&=0X0F)
#define PUT_VAL_HIGHER_NIBBLE(REG,VAL) (REG=((REG&0X0F)|(VAL<<4)))
#define PUT_VAL_LOWER_NIBBLE(REG,VAL) (REG=((REG&0XF0)|(VAL&0X0F)))
#define SET_REGISTER_NIBBLE(REG) (REG=0XFF)

#endif
