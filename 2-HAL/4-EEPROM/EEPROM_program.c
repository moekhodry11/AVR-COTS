/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/10/2023      **********************/
/***************  SWC    : EEPROM          **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"


/*0b01010A2A1A0*/

u8 EEPROM_u8WriteDataByte(u16 Copy_u16ByteAddress, u8 Copy_u8Data)
{
	u8 Local_u8ReturnState = 1;
	/* Start Condition */
	I2C_enuSendStartCondition();

	/* Slave Add With Write Operation */
	I2C_enuSendSlaveAddWithWrite( ((EEPROM_FIXED_ADDRESS) |(EEPROM_A2_VALUE<<2) |((Copy_u16ByteAddress >> 8) & 3)) );

	/* Send The Rest of the Byte Address */
	I2C_enuMasterSendDataByte((u8)Copy_u16ByteAddress);

	/* Send The Data Byte */
	I2C_enuMasterSendDataByte(Copy_u8Data);

	/* Stop Condition */
	I2C_voidSendStopCondition();

	return Local_u8ReturnState;
}

u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAddress, u8 * Copy_pu8ReturnData)
{
	u8 Local_u8ReturnState = 1;

	/* Start Condition */
	I2C_enuSendStartCondition();
	/* Slave Add With Write Operation */
	I2C_enuSendSlaveAddWithWrite( ((EEPROM_FIXED_ADDRESS) |(EEPROM_A2_VALUE<<2) |((Copy_u16ByteAddress >> 8) & 3)) );
	/* Send The Rest of the Byte Address */
	I2C_enuMasterSendDataByte((u8)Copy_u16ByteAddress);

	/* Repeated Start Condition */
	I2C_enuSendRepeatedStartCondition();
	/* Slave Add With Read Operation */
	I2C_enuSendSlaveAddWithRead( ((EEPROM_FIXED_ADDRESS) |(EEPROM_A2_VALUE<<2) |((Copy_u16ByteAddress >> 8) & 3)) );

	/* Read Data */
	I2C_enuMasterReadDataByte(Copy_pu8ReturnData);

	/* Stop Condition */
	I2C_voidSendStopCondition();

	return Local_u8ReturnState;
}
