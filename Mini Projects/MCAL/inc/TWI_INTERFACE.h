/*
 * TWI_INTERFACE.h
 *
 *
 *      Author: Remon Gerges
 */

#ifndef INC_TWI_INTERFACE_H_
#define INC_TWI_INTERFACE_H_

#include "MCU_HW.h"



/*******************************************************************************
 *                        Status Codes for Master Transmitter Mode
                                   *
 *******************************************************************************/

#define MT_MODE_START									0x08
#define MT_MODE_REP_START								0x10
#define MT_MODE_SLAVE_WRITE_ACK							0x18
#define MT_MODE_SLAVE_WRITE_NACK						0x20
#define MT_MODE_DATA_TRANSMITTED_ACK					0x28
#define MT_MODE_DATA_TRANSMITTED_NACK					0x30
#define MT_MODE_ARIBTRATION_LOST_SLA_W					0x38



/*******************************************************************************
 *                        Status Codes for Master Receiver Mode
                                   *
 *******************************************************************************/

#define MR_MODE_START									0x08
#define MR_MODE_REP_START								0x10
#define MR_MODE_ARIBTRATION_LOST_SLA_R					0x38
#define MR_MODE_SLAVE_READ_ACK							0x40
#define MR_MODE_SLAVE_READ_NACK							0x48
#define MR_MODE_DATA_RECEIVED_ACK						0x50
#define MR_MODE_DATA_RECEIVED_NACK						0x58



/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	PRE_1 , PRE_4 , PRE_16 , PRE_64
}i2cPreScaler;


typedef enum
{
	FREQ_100 = 72,
	FREQ_400 = 12,
}Frequancy;
typedef struct
{
	i2cPreScaler preScaler;
	Frequancy freq;
}TWIconfig;




/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void TWI_init(TWIconfig * TWIconfig);
void TWI_start(void);
void TWI_stop(void);
void TWI_writeByte(uint8 data);
void TWI_readByteWithACK(uint8* ptr);
void TWI_readByteWithNACK(uint8* ptr);
uint8 TWI_getStatus(void);


#endif /* INC_TWI_INTERFACE_H_ */
