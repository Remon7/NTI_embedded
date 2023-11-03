/*
 * TWI.c
 *
 *  Created on: Oct 30, 2023
 *      Author: remon
 */

#include "inc/TWI.h"
#include "inc/TWI_priv.h"
#include "avr/interrupt.h"


void TWI_Init(TWI_ConfigType *TWI_config)
{
	// frequency = cpu_clk / (16 + 2*(TWBR)*(2^TWSR))

	switch (TWI_config->freq)
	{
	case TWI_100KHZ_FREQ:
		TWI_BASE->TWBR_t.Reg = TWI_100KHZ_TWBR_VALUE;
		break;
	case TWI_400KHZ_FREQ:
		TWI_BASE->TWBR_t.Reg = TWI_400KHZ_TWBR_VALUE;
		break;
	}

	//setting the prescalar bits

	TWI_BASE->TWSR_t.Reg = TWI_config->prescale<<TWPS0;

	TWI_BASE->TWAR_t.Reg = TWI_MY_ADDRESS_VALUE; // my address = 0x01

	//TWEN to enable the TWI
	TWI_BASE->TWCR_t.Reg = (1<<TWEN);

}



void TWI_sendByte(uint8 copy_u8Byte)
{
	//put the data in the TWDR data register
	TWI_BASE->TWDR_t.Reg = copy_u8Byte;


	/* clear the TWINT flag by setting the bit before sending the data
	 * enable the TWI module by setting TWEN
	 */
	TWI_BASE->TWCR_t.Reg = (1 << TWINT) | (1 << TWEN);

	// wait foe the TWINT flag to know that data is sent successfully
	while(BIT_IS_CLEAR(TWI_BASE->TWCR_t.Reg,TWINT));

}


void TWI_sendStart(void)
{
	/* clear the TWINT flag by setting the bit before sending the data
	 * send the start bit by setting TWSTA bit
	 * enable the TWI module by setting TWEN
	 */
	TWI_BASE->TWCR_t.Reg = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	// wait foe the TWINT flag to know that start bit is sent successfully
	while(BIT_IS_CLEAR(TWI_BASE->TWCR_t.Reg,TWINT));
}


void TWI_sendStop(void)
{
	/* clear the TWINT flag by setting the bit before sending the data
	 * send the stop bit by setting TWSTO bit
	 * enable the TWI module by setting TWEN
	 */
	TWI_BASE->TWCR_t.Reg = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

}


void TWI_recieveByteWithACK(uint8 *ptr)
{


	/* clear the TWINT flag by setting the bit before sending the data
	 * enable the TWI module by setting TWEN
	 */
	TWI_BASE->TWCR_t.Reg = (1 << TWINT) | (1<<TWEA) | (1 << TWEN);

	// wait foe the TWINT flag to know that data is sent successfully
	while(BIT_IS_CLEAR(TWI_BASE->TWCR_t.Reg,TWINT));

	/* Read Data */
	*ptr = TWI_BASE->TWDR_t.Reg;
}


void TWI_recieveByteWithNACK(uint8 *ptr)
{


	/* clear the TWINT flag by setting the bit before sending the data
	 * enable the TWI module by setting TWEN
	 */
	TWI_BASE->TWCR_t.Reg = (1 << TWINT) | (1 << TWEN);

	// wait foe the TWINT flag to know that data is sent successfully
	while(BIT_IS_CLEAR(TWI_BASE->TWCR_t.Reg,TWINT));

	/* Read Data */
	*ptr = TWI_BASE->TWDR_t.Reg;
}


uint8 TWI_getStatus(void)
{
	uint8 status;
	/* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
	status = TWI_BASE->TWSR_t.Reg & TWI_STATUS_MASK;
	return status;
}


