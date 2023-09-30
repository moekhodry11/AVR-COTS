/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/10/2023      **********************/
/***************  SWC    : I2C             **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef I2C_REG_H_
#define I2C_REG_H_

#define TWBR    *((volatile u8 *)0x20)
#define TWSR    *((volatile u8 *)0x21)
#define TWAR    *((volatile u8 *)0x22)
#define TWDR    *((volatile u8 *)0x23)
#define TWCR    *((volatile u8 *)0x56)

#endif /* I2C_REG_H_ */
