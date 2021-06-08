/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 22 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  MEXTI_INTERFACE_H
#define  MEXTI_INTERFACE_H


#define MEXTI_LINE_0     0
#define MEXTI_LINE_1     1
#define MEXTI_LINE_2     2
#define MEXTI_LINE_3     3
#define MEXTI_LINE_4     4
#define MEXTI_LINE_5     5
#define MEXTI_LINE_6     6
#define MEXTI_LINE_7     7
#define MEXTI_LINE_8     8
#define MEXTI_LINE_9     9
#define MEXTI_LINE_10    10
#define MEXTI_LINE_11    11
#define MEXTI_LINE_12    12
#define MEXTI_LINE_13    13
#define MEXTI_LINE_14    14
#define MEXTI_LINE_15    15
#define MEXTI_LINE_17    16
#define MEXTI_LINE_18    18
#define MEXTI_LINE_19    19


#define MEXTI_FALLING_EDGE   0
#define MEXTI_RISING_EDGE    1
#define MEXTI_ON_CHANGE      3


void MEXTI_voidEnableEXTILine(u8 MEXTI_LINE,u8 MEXTI_SENSE_MOOD);
void MEXTI_voidDisableEXTILine(u8 MEXTI_LINE);
void MEXTI_voidSoftWareTriggerEXTI(u8 MEXTI_LINE);
void MEXTI_voidSetCallBack(void (*ptr)(void),u8 MEXTI_LINE);

#endif
