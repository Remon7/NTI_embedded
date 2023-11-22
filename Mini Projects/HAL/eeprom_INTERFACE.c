/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: Dc_motor.h
 *
 * Description: Header file for the Dc Motor Driver
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/


#include "eeprom_INTERFACE.h"
#include "TWI_INTERFACE.h"


void EEPROM_Init(void)
{
	TWIconfig twi_config = {PRE_4,	FREQ_400};

	TWI_init(&twi_config);
}



ERROR_STATUS EEPROM_WriteByte(uint16 u16addr, uint8 u8data)
{

	/* Send the Start Bit */
	TWI_start();
	if (TWI_getStatus() != MT_MODE_START)
		return ERROR;

	/* Send the device address, we need to get A8 A9 A10 address bits from the
	 * memory location address and R/W=0 (write) */
	TWI_writeByte((uint8)(0xA0 | ((u16addr & 0x0700) >> 7)));
	if (TWI_getStatus() != MT_MODE_SLAVE_WRITE_ACK)
		return ERROR;

	/* Send the required memory location address */
	TWI_writeByte((uint8)(u16addr));
	if (TWI_getStatus() != MR_MODE_DATA_RECEIVED_ACK)
		return ERROR;

	/* write byte to eeprom */
	TWI_writeByte(u8data);
	if (TWI_getStatus() != MR_MODE_DATA_RECEIVED_ACK)
		return ERROR;

	/* Send the Stop Bit */
	TWI_stop();

	return SUCCESS;
}

ERROR_STATUS EEPROM_ReadByte(uint16 addr, uint8 *u8data)
{
	/* Send the Start Bit */
	TWI_start();
	if (TWI_getStatus() != MT_MODE_START)
		return ERROR;

	/* Send the device address, we need to get A8 A9 A10 address bits from the
	 * memory location address and R/W=0 (write) */
	TWI_writeByte((uint8)((0xA0) | ((addr & 0x0700) >> 7)));
	if (TWI_getStatus() != MT_MODE_SLAVE_WRITE_ACK)
		return ERROR;

	/* Send the required memory location address */
	TWI_writeByte((uint8)(addr));
	if (TWI_getStatus() != MT_MODE_DATA_TRANSMITTED_ACK)
		return ERROR;

	/* Send the Repeated Start Bit */
	TWI_start();
	if (TWI_getStatus() != MT_MODE_REP_START)
		return ERROR;

	/* Send the device address, we need to get A8 A9 A10 address bits from the
	 * memory location address and R/W=1 (Read) */
	TWI_writeByte((uint8)((0xA0) | ((addr & 0x0700) >> 7) | 1));
	if (TWI_getStatus() != MR_MODE_SLAVE_READ_ACK)
		return ERROR;

	/* Read Byte from Memory without send ACK */
	 TWI_readByteWithNACK(u8data);

	if (TWI_getStatus() != MR_MODE_SLAVE_READ_NACK)
		return ERROR;

	/* Send the Stop Bit */
	TWI_stop();



	return SUCCESS;
}

