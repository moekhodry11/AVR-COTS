/*****************************************************************************/
/***************  Name   : Mohamed Khodary 				**********************/
/***************  Date   : 3/08/2023      				**********************/
/***************  SWC    : Multiplexed 4 Digits 7-Seg   **********************/
/*************** Version : 1.0         				    **********************/
/*****************************************************************************/
#ifndef FourDigits7Seg_CONFIG_H
#define FourDigits7Seg_CONFIG_H

/* Control pins for which digit i will use */
#define FourDigits7Seg_u8_Control1_PIN           DIO_u8_PIN6
#define FourDigits7Seg_u8_Control2_PIN           DIO_u8_PIN5
#define FourDigits7Seg_u8_Control3_PIN           DIO_u8_PIN2
#define FourDigits7Seg_u8_Control4_PIN           DIO_u8_PIN3

/* Data pins (BCD) */
#define FourDigits7Seg_u8_DisplayA_PIN           DIO_u8_PIN0
#define FourDigits7Seg_u8_DisplayB_PIN           DIO_u8_PIN1
#define FourDigits7Seg_u8_DisplayC_PIN           DIO_u8_PIN2
#define FourDigits7Seg_u8_DisplayD_PIN           DIO_u8_PIN4

#endif
