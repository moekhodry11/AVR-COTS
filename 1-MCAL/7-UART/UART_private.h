/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 012/07/2023     **********************/
/***************  SWC    : UART      	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/
#ifndef     UART_private_H 
#define     UART_private_H

#define uart_u8_UDR_REG           *((volatile u8*)0x2c)
#define uart_u8_UCSRA_REG         *((volatile u8*)0x2B)
#define uart_u8_UCSRB_REG         *((volatile u8*)0x2A)
#define uart_u8_UCSRC_REG         *((volatile u8*)0x40)

#define uart_u8_UBRRH_REG         *((volatile u8*)0x40)
#define uart_u8_UBRRL_REG         *((volatile u8*)0x29 ) 
#endif
