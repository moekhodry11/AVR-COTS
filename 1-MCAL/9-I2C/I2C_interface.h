/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/10/2023      **********************/
/***************  SWC    : I2C             **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_


typedef enum
{
	I2C_Ok,
	I2C_SC_Error,
	I2C_RSC_Error,
	I2C_MT_SLA_W_Error,
	I2C_MR_SLA_R_Error,
	I2C_MT_Data_Error,
	I2C_MR_Data_Error
}I2C_Error_State;


void I2C_voidMasterInit(void);

void I2C_voidSlaveInit(u8 Copy_u8Address);

I2C_Error_State I2C_enuSendStartCondition(void);

I2C_Error_State I2C_enuSendRepeatedStartCondition(void);

I2C_Error_State I2C_enuSendSlaveAddWithWrite(u8 Copy_u8SlaveAdd);

I2C_Error_State I2C_enuSendSlaveAddWithRead(u8 Copy_u8SlaveAdd);

I2C_Error_State I2C_enuMasterSendDataByte(u8 Copy_u8Data);

I2C_Error_State I2C_enuMasterReadDataByte(u8 * Copy_pu8ReturnData);

void I2C_voidSendStopCondition(void);


#endif /* I2C_INTERFACE_H_ */
