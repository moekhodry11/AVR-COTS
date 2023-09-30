/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/10/2023      **********************/
/***************  SWC    : I2C             **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_reg.h"
void I2C_voidMasterInit(void)
{
	//Set Prescalar Value 0
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);
	//CLK 400kHZ
	TWBR = 32;

	//Enable Ack
	SET_BIT(TWCR,TWCR_TWEA);
	//Enable I2C Peripheral
	SET_BIT(TWCR,TWCR_TWEN);
}

void I2C_voidSlaveInit(u8 Copy_u8Address)
{
	TWAR = Copy_u8Address<<1;

	//Enable Ack
	SET_BIT(TWCR,TWCR_TWEA);
	//Enable I2C Peripheral
	SET_BIT(TWCR,TWCR_TWEN);

}

I2C_Error_State I2C_enuSendStartCondition(void)
{
	I2C_Error_State Local_enuReturnState = I2C_Ok;

	/* Send Start Condition */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Polling on The Flag */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/* Check on ACK */
	if((TWSR & 0xF8) != I2C_SC_ACK)
	{
		Local_enuReturnState = I2C_SC_Error;
	}

	return Local_enuReturnState;
}

I2C_Error_State I2C_enuSendRepeatedStartCondition(void)
{
	I2C_Error_State Local_enuReturnState = I2C_Ok;

	/* Send Start Condition */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Polling on The Flag */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/* Check on ACK */
	if((TWSR & 0xF8) != I2C_RSC_ACK)
	{
		Local_enuReturnState = I2C_RSC_Error;
	}

	return Local_enuReturnState;
}

I2C_Error_State I2C_enuSendSlaveAddWithWrite(u8 Copy_u8SlaveAdd)     /*0b01011000*/
{
	I2C_Error_State Local_enuReturnState = I2C_Ok;

	TWDR = Copy_u8SlaveAdd<<1;

	/* Write operation */
	CLR_BIT(TWDR,0);

	/* Clear Start Condition Bit */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Polling on The Flag */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/* Check on ACK */
	if((TWSR & 0xF8) != I2C_MT_SLA_W_ACK)
	{
		Local_enuReturnState = I2C_MT_SLA_W_Error;
	}

	return Local_enuReturnState;
}

I2C_Error_State I2C_enuSendSlaveAddWithRead(u8 Copy_u8SlaveAdd)
{
	I2C_Error_State Local_enuReturnState = I2C_Ok;

	TWDR = Copy_u8SlaveAdd<<1;

	/* Write operation */
	SET_BIT(TWDR,0);

	/* Clear Start Condition Bit */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Polling on The Flag */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/* Check on ACK */
	if((TWSR & 0xF8) != I2C_MR_SLA_R_ACK)
	{
		Local_enuReturnState = I2C_MR_SLA_R_Error;
	}

	return Local_enuReturnState;

}

I2C_Error_State I2C_enuMasterSendDataByte(u8 Copy_u8Data)
{
	I2C_Error_State Local_enuReturnState = I2C_Ok;
	TWDR = Copy_u8Data;

	/* Clear Flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Polling on The Flag */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/* Check on ACK */
	if((TWSR & 0xF8) != I2C_MT_DATA_ACK)
	{
		Local_enuReturnState = I2C_MT_Data_Error;
	}


	return Local_enuReturnState;
}

I2C_Error_State I2C_enuMasterReadDataByte(u8 * Copy_pu8ReturnData)
{
	I2C_Error_State Local_enuReturnState = I2C_Ok;

	/* Clear Flag To start The Operation */

	SET_BIT(TWCR,TWCR_TWINT);

	/* Polling on The Flag */
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/* Check on ACK */
	if((TWSR & 0xF8) != I2C_MR_DATA_ACK)
	{
		Local_enuReturnState = I2C_MR_Data_Error;
	}
	else
	{
		*Copy_pu8ReturnData = TWDR;
	}


	return Local_enuReturnState;
}

void I2C_voidSendStopCondition(void)
{
	/* Stop Condition */
	SET_BIT(TWCR,TWCR_TWSTO);

	/* Clear Flag */
	SET_BIT(TWCR,TWCR_TWINT);
}


