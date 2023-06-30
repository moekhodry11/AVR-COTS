/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 09/02/2023      **********************/
/***************  SWC    : EXTI            **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/ 
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Define for EXTI Refisters */
#define EXTI_u8_MCUCR		*((volatile u8 *)0x55)
#define EXTI_u8_MCUCSR		*((volatile u8 *)0x54)
#define EXTI_u8_GICR		*((volatile u8 *)0x5B)
#define EXTI_u8_GIFR		*((volatile u8 *)0x5A)

#endif