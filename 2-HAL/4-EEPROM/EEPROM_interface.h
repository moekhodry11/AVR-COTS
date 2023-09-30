/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/10/2023      **********************/
/***************  SWC    : EEPROM          **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


u8 EEPROM_u8WriteDataByte(u16 Copy_u16ByteAddress, u8 Copy_u8Data);

u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAddress, u8 * Copy_pu8ReturnData);


#endif /* EEPROM_INTERFACE_H_ */
