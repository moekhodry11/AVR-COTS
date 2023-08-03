/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 05/02/2023      **********************/
/***************  SWC    : LCD      	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/** OPTIONS: 1- DIO_u8_PORTA
			 2- DIO_u8_PORTB
			 3- DIO_u8_PORTC
			 4- DIO_u8_PORTD */

#define LCD_u8_CONTROL_PORT	DIO_u8_PORTA
#define LCD_u8_RS_PIN		DIO_u8_PIN3
//#define LCD_u8_RW_PIN		DIO_u8_PIN1
#define LCD_u8_E_PIN		DIO_u8_PIN2

#define LCD_u8_DATA_PORT	DIO_u8_PORTB
#define		LCD_u8_D0_PIN		DIO_u8_PIN5
#define		LCD_u8_D1_PIN		DIO_u8_PIN6
#define		LCD_u8_D2_PIN		DIO_u8_PIN7
#define		LCD_u8_D3_PIN		DIO_u8_PIN3

#define		LCD_u8_D4_PIN		DIO_u8_PIN0
#define		LCD_u8_D5_PIN		DIO_u8_PIN1
#define		LCD_u8_D6_PIN		DIO_u8_PIN2
#define		LCD_u8_D7_PIN		DIO_u8_PIN4

/** OPTIONS: 1- LCD_u8_MODE_8_BIT
 * 			 2- LCD_u8_MODE_4_BIT
 */

#define LCD_u8_MODE		LCD_u8_MODE_4_BIT

#endif
