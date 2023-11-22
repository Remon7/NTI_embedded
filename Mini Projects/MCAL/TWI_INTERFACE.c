/*
 * TWI_INTERFACE.c
 *
 *
 *      Author: Remon Gerges
 */
#include "TWI_INTERFACE.h"
#include "TWI_Private.h"


void TWI_init(TWIconfig * TWIconfig)
{

	TWI_BASE->TWBR_t.Reg = TWIconfig->freq;

	TWCR_t = (1<<TWINT) | (1<<TWEN);    /*Clear the interrupt flag & enable the TWI module*/
	TWI_BASE->TWSR_t.Reg = (TWSR & Pre_Mask) | (TWIconfig -> preScaler); /*Set the prescaler */
}

void TWI_start(void)
{
	/*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR_t = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	/* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
	while(BIT_IS_CLEAR(TWCR_t,TWINT));
}

void TWI_stop(void)
{
	/*
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR_t = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void TWI_writeByte(uint8 data)
{
	/* Put data On TWI data Register */
	TWI_BASE->TWDR_t.Reg = data;
	/*
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR_t = (1 << TWINT) | (1 << TWEN);
	/* Wait for TWINT flag set in TWCR Register(data is send successfully) */
	while(BIT_IS_CLEAR(TWCR_t,TWINT));

}

void TWI_readByteWithACK(uint8* ptr)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR_t = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	/* Wait for TWINT flag set in TWCR Register (data received successfully) */
	while(BIT_IS_CLEAR(TWCR_t,TWINT));
	/* Read Data */
	*ptr =  TWI_BASE->TWDR_t.Reg;
}


void TWI_readByteWithNACK(uint8* ptr)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR_t = (1 << TWINT) | (1 << TWEN);
	/* Wait for TWINT flag set in TWCR Register (data received successfully) */
	while(BIT_IS_CLEAR(TWCR_t,TWINT));
	/* Read Data */
	*ptr =  TWI_BASE->TWDR_t.Reg;
}

uint8 TWI_getStatus(void)
{
	uint8 status;
	/* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
	status = TWI_BASE->TWSR_t.Reg & Masking_To_Eliminate_First_3bits;
	return  status;
}
