/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 012/07/2023     **********************/
/***************  SWC    : UART      	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/
#ifndef     UART_interface_H 
#define     UART_interface_H

// the intial the uart to work for boudrate 9800 
void UART_voidinit(void);
// the  funcation to sent dATA 
void UART_void_sent_databyte(u8 data_sent );
//FUNCATION TO RECIVE DATA 
u8 UART_void_resive_databyte(u8 *copy_pu8recive );




#endif
