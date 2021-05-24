/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 14 Oct. 2020                                          */
/* Version     : V01                                                  */
/**********************************************************************/



#ifndef  MNVIC_PRIVATE_H
#define  MNVIC_PRIVATE_H

#define  MNVIC_BASE_ADDRESS  0xE000E100

typedef struct
{
  volatile u32 MNVIC_ISER[3];

}MNVIC_ISER_T;

#define MNVIC_ISER_STRUCT  ((volatile MNVIC_ISER_T*) 0xE000E100)


typedef struct
{
  volatile u32 MNVIC_ICER[3];

}MNVIC_ICER_T;

 #define  MNVIC_ICER_STRUCT  ((volatile MNVIC_ICER_T*)0xE000E180)


typedef struct
{
  volatile u32 MNVIC_ISPR[3];

}MNVIC_ISPR_T;

#define MNVIC_ISPR_STRUCT  ((volatile MNVIC_ISPR_T*) 0xE000E200)


typedef struct
{
  volatile u32 MNVIC_ICPR[3];

}MNVIC_ICPR_T;

#define MNVIC_ICPR_STRUCT  ((volatile MNVIC_ICPR_T*) 0xE000E280)


typedef struct
{
  volatile u32 MNVIC_IABR[3];

}MNVIC_IABR_T;

#define MNVIC_IABR_STRUCT  ((volatile MNVIC_IABR_T*) 0xE000E300)



typedef struct
{
  volatile u8 MNVIC_IPR[80];

}MNVIC_IPR_T;

#define MNVIC_IPR_STRUCT  ((volatile MNVIC_IPR_T*) 0xE000E400)


typedef struct
{
  volatile u32 MNVIC_STIR;

}MNVIC_STIR_T;

#define MNVIC_STIR  ((volatile MNVIC_STIR_T*) 0xE000EF00)



#endif
