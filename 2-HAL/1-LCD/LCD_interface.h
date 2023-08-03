/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 05/02/2023      **********************/
/***************  SWC    : LCD      	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LCD_CLEAR         	    0x01          /* replace all characters with ASCII 'space'                       */
#define LCD_HOME            	0x02          /* return cursor to first position on first line                   */
#define LCD_ENTRYMODE       	0x06          // shift cursor from left to right on read/write
#define LCD_DISPLAYOFF      	0x08          // turn display off
#define LCD_DISPLAYON       	0x0C          // display on, cursor off, don't blink character
#define LCD_FUNCTIONRESET   	0x30          // reset the LCD
#define LCD_FUNCTIONSET8BIT 	0x38          // 8-bit data, 2-line display, 5 x 7 font
#define LCD_U8SETCURSOR     	0x80          // set cursor position
#define LCD_SHIFTDISPLAYLEFT	0x18		  //Moving the entire display from left to right
#define LCD_SHIFTDISPLAYRIGHT	0x1C		  //Moving the entire display from right to right
#define LCD_SHIFTCURSORRIGHT	0X14		  //Moving cursor to right
#define LCD_SHIFTCURSORLEFT		0x10		  //Moving cursor to left
/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidInit(void);

/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidSendCmnd(u16 Copy_u8Cmnd);

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidSendChar(u8 Copy_u8Data);

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_voidSendString (u8* Copy_pu8String);

void LCD_voidSendIntger(s32 Copy_s32Data);
void LCD_voidSendFloat(f64 Copy_f32Data);

void LCD_voidGotoxy (u8 Copy_u8Y,u8 Copy_u8X);
void LCD_voidSendExtraChar (u8 Copy_u8Y,u8 Copy_u8X);

/* New */
void LCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);
#endif /* LCD_H_ */
