/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 14/04/2023      **********************/
/***************  SWC    : LCD      	   **********************/
/*************** Version : 1.1             **********************/
/****************************************************************/

/********************************** Header Files INCLUSIONS ****************************/
/* Lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include "util/delay.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_Extra.h"
#include "LCD_private.h"
/***************************************************************************************/

/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PA2|---------------->|E         |
 |        PA1|---------------->|RW        |
 |        PA0|---------------->|RS        |
 -----------                   ----------
 */

/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/********************************** Macros *********************************************/
/***************************************************************************************/

#define lcd_Clear           		 0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home           			 0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       	     0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff     			 0x08          // turn display off
#define lcd_DisplayOn      			 0x0F          // display on, cursor off, don't blink character
#define lcd_FunctionReset   		 0x30          // reset the LCD
#define lcd_FunctionSet8bit 		 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_FunctionSet4bit 		 0x2F          // 4-bit data, 2-line display, 5 x 7 font
#define lcd_u8SetCursor     		 0x80          // set cursor position

/***************************************************************************************/
/********************************** Constant Variables *********************************/
/***************************************************************************************/

/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidInit(void) {

#if LCD_u8_MODE == LCD_u8_MODE_8_BIT
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(35);

	/* Return Home  */
	LCD_voidSendCmnd(lcd_Home);
	_delay_ms(1);

	/* Function Set  */
	LCD_voidSendCmnd(lcd_FunctionSet8bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_voidSendCmnd(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_voidSendCmnd(lcd_Clear);
	_delay_ms(1);

	/* Entry Mode Set  */
	LCD_voidSendCmnd(lcd_EntryMode);
	_delay_ms(2);

#elif LCD_u8_MODE == LCD_u8_MODE_4_BIT
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(35);

	/* Return Home  */
	LCD_voidSendCmnd(lcd_Home);
	_delay_ms(1);

	/* Function Set  */
	LCD_voidSendCmnd(lcd_FunctionSet4bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_voidSendCmnd(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_voidSendCmnd(lcd_Clear);
	_delay_ms(1);

	/* Entry Mode Set  */
	LCD_voidSendCmnd(lcd_EntryMode);
	_delay_ms(2);
#endif
}

/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidSendCmnd(u16 Copy_u8Cmnd) {

#if LCD_u8_MODE == LCD_u8_MODE_8_BIT

	/* Set RS to DIO_u8_LOW */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RS_PIN, DIO_u8_LOW);

	/* Set R/W to DIO_u8_LOW */
	//DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

	/* Load Command on Data bus */
	//DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Cmnd);
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D7_PIN, GET_BIT(Copy_u8Cmnd, 7));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D6_PIN, GET_BIT(Copy_u8Cmnd, 6));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D5_PIN, GET_BIT(Copy_u8Cmnd, 5));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D4_PIN, GET_BIT(Copy_u8Cmnd, 4));

	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D3_PIN, GET_BIT(Copy_u8Cmnd, 3));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D2_PIN, GET_BIT(Copy_u8Cmnd, 2));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D1_PIN, GET_BIT(Copy_u8Cmnd, 1));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D0_PIN, GET_BIT(Copy_u8Cmnd, 0));

	/* Set E to DIO_u8_HIGH  */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

	/* Wait for E to settle */
	_delay_ms(2);

	/* Set E to DIO_u8_LOW */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_LOW);

#elif LCD_u8_MODE == LCD_u8_MODE_4_BIT

	/* Set RS to DIO_u8_LOW */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RS_PIN, DIO_u8_LOW);

	/* Set R/W to DIO_u8_LOW */
	//DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);
	/* Load Command on Data bus */
	//DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Cmnd);
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D7_PIN, GET_BIT(Copy_u8Cmnd, 7));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D6_PIN, GET_BIT(Copy_u8Cmnd, 6));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D5_PIN, GET_BIT(Copy_u8Cmnd, 5));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D4_PIN, GET_BIT(Copy_u8Cmnd, 4));

	/* Set E to DIO_u8_HIGH  */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

	/* Wait for E to settle */
	_delay_ms(2);

	/* Set E to DIO_u8_LOW */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_LOW);

	/*write the rest of the command */
	//DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Cmnd << 4);
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D7_PIN, GET_BIT(Copy_u8Cmnd, 3));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D6_PIN, GET_BIT(Copy_u8Cmnd, 2));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D5_PIN, GET_BIT(Copy_u8Cmnd, 1));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D4_PIN, GET_BIT(Copy_u8Cmnd, 0));

	/* Set E to DIO_u8_HIGH  */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

	/* Wait for E to settle */
	_delay_ms(2);

	/* Set E to DIO_u8_LOW */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_LOW);
#endif

}

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidSendChar(u8 Copy_u8Data) {

#if LCD_u8_MODE == LCD_u8_MODE_8_BIT
	/* Set RS to HIG */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RS_PIN, DIO_u8_HIGH);

	/* Set R/W to DIO_u8_LOW */
	//DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

	/* Set E to DIO_u8_HIGH */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

	/* Load Command on Data bus */
	//DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Data);

	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D7_PIN, GET_BIT(Copy_u8Data, 7));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D6_PIN, GET_BIT(Copy_u8Data, 6));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D5_PIN, GET_BIT(Copy_u8Data, 5));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D4_PIN, GET_BIT(Copy_u8Data, 4));

	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D3_PIN, GET_BIT(Copy_u8Data, 3));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D2_PIN, GET_BIT(Copy_u8Data, 2));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D1_PIN, GET_BIT(Copy_u8Data, 1));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D0_PIN, GET_BIT(Copy_u8Data, 0));

	/* Set E to DIO_u8_LOW */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_LOW);

	/* Wait for E to settle */
	_delay_ms(2);

	/* Set E to DIO_u8_HIGH */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

	/* Delay to let the LCD Display the character */
	_delay_ms(2);

#elif LCD_u8_MODE == LCD_u8_MODE_4_BIT
	/* Set RS to HIG */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RS_PIN, DIO_u8_HIGH);

	/* Set R/W to DIO_u8_LOW */
	//DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);
	/* Set E to DIO_u8_HIGH */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

	/* Load Command on Data bus */
	//DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Data);
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D7_PIN, GET_BIT(Copy_u8Data, 7));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D6_PIN, GET_BIT(Copy_u8Data, 6));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D5_PIN, GET_BIT(Copy_u8Data, 5));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D4_PIN, GET_BIT(Copy_u8Data, 4));

	/* Set E to DIO_u8_LOW */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_LOW);

	/* Wait for E to settle */
	_delay_ms(2);

	/* Set E to DIO_u8_HIGH */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

	/*Load the rest of the command on Data bus */
	//DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Data << 4);
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D7_PIN, GET_BIT(Copy_u8Data, 3));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D6_PIN, GET_BIT(Copy_u8Data, 2));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D5_PIN, GET_BIT(Copy_u8Data, 1));
	DIO_u8SetPinValue(LCD_u8_DATA_PORT, LCD_u8_D4_PIN, GET_BIT(Copy_u8Data, 0));

	/* Set E to DIO_u8_LOW */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_LOW);

	/* Wait for E to settle */
	_delay_ms(2);

	/* Set E to DIO_u8_HIGH */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

	/* Delay to let the LCD Display the character */
	_delay_ms(2);

#endif

}

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidSendString(u8 *Copy_pu8String) {

	//	/* Local loop index */
	//	u8 u8Index = 0;
	u8 iteration = 0;
	//	while (pu8StringCpy[u8Index] != '\0')
	for (iteration = 0; Copy_pu8String[iteration] != '\0'; iteration++) {
		/* Write Character on LCD */
		LCD_voidSendChar(Copy_pu8String[iteration]);

		//		/* Increment local loop index */
		//		u8Index++;
	}
}

void LCD_voidSendIntger(s32 Copy_s32Data) {
	u32 str[10];
	// Converts Int to String
	sprintf(str, "%ld", Copy_s32Data);
	LCD_voidSendString(str);
}

void LCD_voidSendFloat(f64 Copy_f32Data) {
	s32 int_part;
	f32 frac_part;
	// separate integer and fractional parts
	int_part = (s32) Copy_f32Data;
	frac_part = Copy_f32Data - int_part;
	frac_part = (s32) (frac_part * 1000);
	LCD_voidSendIntger(int_part);
	LCD_voidSendChar('.');
	LCD_voidSendIntger(frac_part);
}

/***************************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD     */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidGotoxy(u8 Copy_u8Y, u8 Copy_u8X) {
	u8 line;

		switch (Copy_u8Y) {
		case 0:
			line = 0x00;

			break;
		case 1:
			line = 0x40;
			break;
		case 2:
			line = 0x14;
			break;
		case 3:
			line = 0x54;
			break;
		default:
			break;
		}
		u8 ddram_address = line + Copy_u8X;
		LCD_voidSendCmnd(0x80 | ddram_address);
	}

/***************************************************************************************/
/* Description! Interface to write extra characters saved in the CGRAM                 */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidSendExtraChar(u8 Copy_u8Y, u8 Copy_u8X) {
	u8 iteration1, iteration2;

	/*DDRAM-->CGRAM*/
	LCD_voidSendCmnd(64);
	for (iteration1 = 0; iteration1 < 64; iteration1++) {
		LCD_voidSendChar(ExtraChar[iteration1]);
	}
	/*CGRAM-->DDRAM*/
	LCD_voidSendCmnd(128);
	LCD_voidGotoxy(Copy_u8Y, Copy_u8X);
	/*First eight character which saved at CGRAM*/
	for (iteration2 = 0; iteration2 <= 7; iteration2++) {
		/* Write bytes of DDRAM */
		LCD_voidSendChar(iteration2);

		_delay_ms(5);
	}
}

/*  New */
void LCD_voidWriteSpecialCharacter(u8 *Copy_pu8Pattern, u8 Copy_u8PatternNumber,
		u8 Copy_u8XPos, u8 Copy_u8YPos) {
	u8 Local_u8Address, Local_u8PatternCounter;

	/*1- Calculate the required address of CGRAM*/
	Local_u8Address = Copy_u8PatternNumber * 8;

	/*2- Set CGRAM Address with bit 6 equal to 1 and bit 7 equal to 0*/
	LCD_voidSendCmnd(Local_u8Address + 64);

	/*3- write the required pattern inside the CGRAM*/
	for (Local_u8PatternCounter = 0; Local_u8PatternCounter < 8;
			Local_u8PatternCounter++) {
		LCD_voidSendChar(Copy_pu8Pattern[Local_u8PatternCounter]);
	}

	/*4- shift the address counter to the DDRAM*/
	LCD_voidGotoxy(Copy_u8XPos, Copy_u8YPos);

	/*5- Display the CGRAM pattern on the LCD*/
	LCD_voidSendChar(Copy_u8PatternNumber);

}

