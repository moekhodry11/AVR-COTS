/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/10/2023      **********************/
/***************  SWC    : I2C             **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/* TWCR PINS */
#define TWCR_TWINT             7
#define TWCR_TWEA              6
#define TWCR_TWSTA             5
#define TWCR_TWSTO             4
#define TWCR_TWWC              3
#define TWCR_TWEN              2
#define TWCR_TWIE              0

/* TWSR PINS */
#define TWSR_TWPS1             1
#define TWSR_TWPS0             0

/* TWAR PINS */
#define TWAR_TWGCE             0

/* Macros For Ack in Master Transmitter Mode */
#define I2C_SC_ACK             0x08
#define I2C_RSC_ACK            0x10
#define I2C_MT_SLA_W_ACK       0x18
#define I2C_MT_DATA_ACK        0x28

/* Macros For Ack in Master Reciever Mode */
#define I2C_MR_SLA_R_ACK       0x40
#define I2C_MR_DATA_ACK        0x50


#endif /* I2C_PRIVATE_H_ */
