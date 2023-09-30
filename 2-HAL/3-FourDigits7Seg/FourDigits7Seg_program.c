/*****************************************************************************/
/***************  Name   : Mohamed Khodary 				**********************/
/***************  Date   : 3/08/2023      				**********************/
/***************  SWC    : Multiplexed 4 Digits 7-Seg   **********************/
/*************** Version : 1.0         				    **********************/
/*****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL
#include <util/delay.h>

/* MCAL */
#include "DIO_interface.h"
/* HAL */
#include "FourDigits7Seg_interface.h"
#include "FourDigits7Seg_private.h"
#include "FourDigits7Seg_config.h"

u8 FourDigits7Seg_u8SendNumber(u16 Copy_Number) {
	u8 Local_u8ErrorState = STD_TYPES_OK, Local_u8Delay = 5;
	u8 Local_u8Temp;
	if (Copy_Number <= 9999) {

		/* First Digit */
		Local_u8Temp = Copy_Number % 10;
		DIO_u8SetPinValue(DIO_u8_PORTA, FourDigits7Seg_u8_Control4_PIN,
		DIO_u8_LOW); // Active LOW
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayA_PIN,
				GET_BIT(Local_u8Temp, 0));
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayB_PIN,
				GET_BIT(Local_u8Temp, 1));
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayC_PIN,
				GET_BIT(Local_u8Temp, 2));
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayD_PIN,
				GET_BIT(Local_u8Temp, 3));
		_delay_ms(Local_u8Delay);
		DIO_u8SetPinValue(DIO_u8_PORTA, FourDigits7Seg_u8_Control4_PIN,
		DIO_u8_HIGH);
		Copy_Number /= 10;

		/* Second Digit */
		Local_u8Temp = Copy_Number % 10;
		DIO_u8SetPinValue(DIO_u8_PORTA, FourDigits7Seg_u8_Control3_PIN,
		DIO_u8_LOW); // Active LOW
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayA_PIN,
				GET_BIT(Local_u8Temp, 0));
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayB_PIN,
				GET_BIT(Local_u8Temp, 1));
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayC_PIN,
				GET_BIT(Local_u8Temp, 2));
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayD_PIN,
				GET_BIT(Local_u8Temp, 3));
		_delay_ms(Local_u8Delay);
		DIO_u8SetPinValue(DIO_u8_PORTA, FourDigits7Seg_u8_Control3_PIN,
		DIO_u8_HIGH);
		Copy_Number /= 10;

		/* 3rd Digit */
		Local_u8Temp = Copy_Number % 10;
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_Control2_PIN,
		DIO_u8_LOW); // Active LOW
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayA_PIN,
				GET_BIT(Local_u8Temp, 0));
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayB_PIN,
				GET_BIT(Local_u8Temp, 1));
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayC_PIN,
				GET_BIT(Local_u8Temp, 2));
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayD_PIN,
				GET_BIT(Local_u8Temp, 3));
		_delay_ms(Local_u8Delay);
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_Control2_PIN,
		DIO_u8_HIGH);
		Copy_Number /= 10;

		/* 4th Digit */
		Local_u8Temp = Copy_Number % 10;
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_Control1_PIN,
		DIO_u8_LOW); // Active LOW
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayA_PIN,
				GET_BIT(Local_u8Temp, 0));
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayB_PIN,
				GET_BIT(Local_u8Temp, 1));
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayC_PIN,
				GET_BIT(Local_u8Temp, 2));
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_DisplayD_PIN,
				GET_BIT(Local_u8Temp, 3));
		_delay_ms(Local_u8Delay);
		DIO_u8SetPinValue(DIO_u8_PORTB, FourDigits7Seg_u8_Control1_PIN,
		DIO_u8_HIGH);
		Copy_Number /= 10;

	} else {
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
