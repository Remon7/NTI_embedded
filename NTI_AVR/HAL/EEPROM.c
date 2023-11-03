/*
 * EEPROM.c
 *
 *  Created on: Oct 31, 2023
 *      Author: remon
 */

#include "inc/EEPROM.h"

extern	TWI_ConfigType TWI_config;
uint8 *data =0;

void EEPROM_Init()
{
	TWI_Init(&TWI_config);
}

uint8 EEPROM_WriteByte(uint16 copy_u16Address,uint8 copy_u8Data)
{
	TWI_sendStart();

	if(TWI_getStatus() != TWI_START)
	{
		return ERROR;
	}

	TWI_sendByte((uint8)(0xA0 | (copy_u16Address & 0x0700 >> 7)));

	if(TWI_getStatus() != TWI_MT_SLA_W_ACK)
	{
		return ERROR;
	}

	TWI_sendByte((uint8)(copy_u16Address));

	if(TWI_getStatus() != TWI_MT_DATA_ACK)
	{
		return ERROR;
	}

	TWI_sendByte(copy_u8Data);

	if(TWI_getStatus() != TWI_MT_DATA_ACK)
	{
		return ERROR;
	}

	TWI_sendStop();

	return SUCCESS;
}


uint8 EEPROM_ReadByte(uint16 copy_u16Address,uint8 *copy_u8Data)
{
	TWI_sendStart();

	if(TWI_getStatus() != TWI_START)
	{
		return ERROR;
	}

	TWI_sendByte((uint8)(0xA0 | (copy_u16Address & 0x0700 >> 7)));

	if(TWI_getStatus() != TWI_MT_SLA_W_ACK)
	{
		return ERROR;
	}

	TWI_sendByte((uint8)(copy_u16Address));

	if(TWI_getStatus() != TWI_MT_DATA_ACK)
	{
		return ERROR;
	}

	TWI_sendByte(copy_u8Data);

	if(TWI_getStatus() != TWI_MT_DATA_ACK)
	{
		return ERROR;
	}

	TWI_sendStart();

	if(TWI_getStatus() != TWI_REP_START)
	{
		return ERROR;
	}

	TWI_sendByte((uint8)(0xA0 | (copy_u16Address & 0x0700 >> 7) | 1));

	if(TWI_getStatus() != TWI_MR_SLA_R_ACK)
	{
		return ERROR;
	}

	TWI_recieveByteWithACK(data);

	if(TWI_getStatus() != TWI_MR_DATA_ACK)
	{
		return ERROR;
	}

	TWI_sendStop();

	return SUCCESS;
}
