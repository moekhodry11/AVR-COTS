/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 27/06/2023      **********************/
/***************  SWC    : ADC             **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/ 
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ADC_u8_CHANNEL_0                  0
#define ADC_u8_CHANNEL_1                  1
#define ADC_u8_CHANNEL_2                  2
#define ADC_u8_CHANNEL_3                  3
#define ADC_u8_CHANNEL_4                  4
#define ADC_u8_CHANNEL_5                  5
#define ADC_u8_CHANNEL_6                  6
#define ADC_u8_CHANNEL_7                  7

void ADC_voidInit(void);

u8   ADC_u8GetDigitalValueSynchNonBlocking(u8 Copy_u8ChannelNb, u16 * Copy_pu16DigitalValue);

u8   ADC_u8GetDigitalValueAsynch          (u8 Copy_u8ChannelNb,void(*Copy_pfNotification)(u16));

u8   ADC_u8GetADCRegValue                 (u16 * Copy_pu16ADCValue);

#endif
