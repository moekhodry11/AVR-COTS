/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 09/02/2023      **********************/
/***************  SWC    : EXTI            **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/ 
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_u8_INT0						0
#define EXTI_u8_INT1						1
#define EXTI_u8_INT2						2

/* Micros For Edge Source */
#define  EXTI_u8_RAISING_EDGE 				0
#define  EXTI_u8_FALLING_EDGE 				1
#define  EXTI_u8_ANY_LOGICAL_CHANGE 		2
#define  EXTI_u8_LOW_LEVEL				    3

u8 EXTI_u8EXTIEnable(u8 Copy_u8EXTIIndix,u8 Copy_u8EdgeIndix);

u8 EXTI_u8EXTIDisable(u8 Copy_u8EXTIIndix);

u8 EXTI_u8EXTISetCallBack(u8 Copy_u8EXTIIndix, void(*Copy_pf)(void));

#endif