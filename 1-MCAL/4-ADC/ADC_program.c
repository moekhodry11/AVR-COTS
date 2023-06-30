/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 27/06/2023      **********************/
/***************  SWC    : ADC             **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

static void(*ADC_pfNotification)(u16) = NULL;
/* ADC busy flag */
static u8 ADC_u8BusyFlag = 0;

void ADC_voidInit(void)
{
	/*	1- Select Vref = AVCC
		2- Right Adjust
		3- Disable AutoTrigger
		4- Select CLK/64
		5- Enable ADC
	 */
	CLR_BIT(ADC_u8_ADMUX_REG,7);
	SET_BIT(ADC_u8_ADMUX_REG,6);

	CLR_BIT(ADC_u8_ADMUX_REG,5);

	CLR_BIT(ADC_u8_ADCSRA_REG,5);

	SET_BIT(ADC_u8_ADCSRA_REG,2);
	SET_BIT(ADC_u8_ADCSRA_REG,1);
	CLR_BIT(ADC_u8_ADCSRA_REG,0);

	SET_BIT(ADC_u8_ADCSRA_REG,7);
}

u8   ADC_u8GetDigitalValueSynchNonBlocking(u8 Copy_u8ChannelNb, u16 * Copy_pu16DigitalValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32TimeOutCounter = 0;
	if((Copy_u8ChannelNb < 32) && (Copy_pu16DigitalValue != NULL))
	{
		/* Clear MUX4..0 */
		ADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel */
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNb;
		/* Start Conversion */
		SET_BIT(ADC_u8_ADCSRA_REG,6);
		/* Wait flag = 1 */
		while((GET_BIT(ADC_u8_ADCSRA_REG,4)== 0) && (Local_u32TimeOutCounter < ADC_u32_TIME_OUT_MAX_VALUE))
		{
			Local_u32TimeOutCounter++;
		}
		//while(!GET_BIT(ADC_u8_ADCSRA_REG,4));
		if(GET_BIT(ADC_u8_ADCSRA_REG,4)!= 0)//(Local_u32TimeOutCounter<ADC_u32_TIME_OUT_MAX_VALUE)
		{
			/* Clear flag */
			SET_BIT(ADC_u8_ADCSRA_REG,4);
			/* Read the Digital Value */
			*Copy_pu16DigitalValue = ADC_u16_ADC_REG;
		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
u8   ADC_u8GetDigitalValueAsynch          (u8 Copy_u8ChannelNb,void(*Copy_pfNotification)(u16))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8ChannelNb < 32) && (Copy_pfNotification != NULL) && (ADC_u8BusyFlag == 0))
	{
		/* Set Flag to make ADC is Busy */
		ADC_u8BusyFlag = 1;
		/* update Global Pointer to a function */
		ADC_pfNotification = Copy_pfNotification;
		/* Enable ADC Interrupt */
		SET_BIT(ADC_u8_ADCSRA_REG,3);
		/* Clear MUX4..0 */
		ADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel */
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNb;
		/* Start Conversion */
		SET_BIT(ADC_u8_ADCSRA_REG,6);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
u8   ADC_u8GetADCRegValue                 (u16 * Copy_pu16ADCValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pu16ADCValue != NULL)
	{
		/* Read ADC Register */
		*Copy_pu16ADCValue = ADC_u16_ADC_REG;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState ;
}

/* Prototype for ADC ISR */
void __vector_16(void)     __attribute__((signal));
void __vector_16(void)
{
	if(ADC_pfNotification != NULL)
	{
		/* Clear Flag */
		ADC_u8BusyFlag = 0;
		/* Clear PIE of ADC */
		CLR_BIT(ADC_u8_ADCSRA_REG,3);
		/* Calling Notification function */
		ADC_pfNotification(ADC_u16_ADC_REG);
	}
}
