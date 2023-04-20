/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 05/02/2023      **********************/
/***************  SWC    : KPD             **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL
#include <util/delay.h>

/* MCAL */
#include "DIO_interface.h"
/* HAL */
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

const u8 KPD_Au8Keys[4][4]= KPD_KEYS;

const u8 KPD_Au8RowsPins[4]={KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};
const u8 KPD_Au8ColsPins[4]={KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};


u8 KPD_u8GetKeyState(u8 * Copy_pu8ReturnedKey)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8RowsCounter,Local_u8ColsCounter,Local_u8PinValue,Local_u8Flag = 0;
	if(Copy_pu8ReturnedKey != NULL)
	{
		*Copy_pu8ReturnedKey = KPD_u8_KEY_NOT_PRESSED;
		/* Activate Each Row => For loop on the pins of the rows */
		for(Local_u8RowsCounter = 0; Local_u8RowsCounter <= 3 ; Local_u8RowsCounter++)
		{
			DIO_u8SetPinValue(KPD_u8_PORT,KPD_Au8RowsPins[Local_u8RowsCounter],DIO_u8_LOW);
			/* Check Which Input Pin Has Zero */
			for(Local_u8ColsCounter = 0; Local_u8ColsCounter <= 3 ; Local_u8ColsCounter++)
			{
				DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColsPins[Local_u8ColsCounter],&Local_u8PinValue);
				if(Local_u8PinValue == DIO_u8_LOW)/* Switch is Pressed */
				{
					/* Debouncing */
					_delay_ms(20);
					DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColsPins[Local_u8ColsCounter],&Local_u8PinValue);
					/* Check if the Pin is still equal LOW */
					while(Local_u8PinValue == DIO_u8_LOW)
					{
						DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColsPins[Local_u8ColsCounter],&Local_u8PinValue);
					}
					*Copy_pu8ReturnedKey = KPD_Au8Keys[Local_u8RowsCounter][Local_u8ColsCounter];
					Local_u8Flag = 1;
					break;						
				}
			}
			/* Deactivate Row */
			DIO_u8SetPinValue(KPD_u8_PORT,KPD_Au8RowsPins[Local_u8RowsCounter],DIO_u8_HIGH);
			if(Local_u8Flag == 1)
			{	
				break;	
			}
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
