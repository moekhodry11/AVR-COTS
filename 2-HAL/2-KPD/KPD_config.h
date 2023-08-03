/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 05/02/2023      **********************/
/***************  SWC    : KPD             **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

/* Rows */ //Set it as Output
#define KPD_ROWS_u8_PORT             DIO_u8_PORTC

#define KPD_u8_R1_PIN           DIO_u8_PIN5
#define KPD_u8_R2_PIN           DIO_u8_PIN4
#define KPD_u8_R3_PIN           DIO_u8_PIN3
#define KPD_u8_R4_PIN           DIO_u8_PIN2

/* Cols */ //Set it as Input
#define KPD_COLS_u8_PORT             DIO_u8_PORTD

#define KPD_u8_C1_PIN           DIO_u8_PIN7
#define KPD_u8_C2_PIN           DIO_u8_PIN6
#define KPD_u8_C3_PIN           DIO_u8_PIN5
#define KPD_u8_C4_PIN           DIO_u8_PIN3

#define KPD_KEYS              {{'7','8','9','/'},   \
				  	           {'4','5','6','*'},   \
				  	           {'1','2','3','-'},   \
				  	           {'C','0','=','+'}}
				              

#endif
