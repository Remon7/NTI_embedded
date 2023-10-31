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
	TWI_BASE->TWBR_t.Reg = 0x02;

	//setting the prescalar bits

	TWI_BASE->TWSR_t.Reg = TWI_config->prescale<<TWPS0;

	TWI_BASE->TWAR_t.Reg = 0b00000010; // my address = 0x01

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

	// wait foe the TWINT flag to know that stop bit is sent successfully
	while(BIT_IS_CLEAR(TWI_BASE->TWCR_t.Reg,TWINT));
}


uint8 TWI_recieveByteWithACK()
{


	/* clear the TWINT flag by setting the bit before sending the data
	 * enable the TWI module by setting TWEN
	 */
	TWI_BASE->TWCR_t.Reg = (1 << TWINT) | (1<<TWEA) | (1 << TWEN);

	// wait foe the TWINT flag to know that data is sent successfully
	while(BIT_IS_CLEAR(TWI_BASE->TWCR_t.Reg,TWINT));

	/* Read Data */
	return TWI_BASE->TWDR_t.Reg;
}


uint8 TWI_recieveByteWithNACK()
{


	/* clear the TWINT flag by setting the bit before sending the data
	 * enable the TWI module by setting TWEN
	 */
	TWI_BASE->TWCR_t.Reg = (1 << TWINT) | (1 << TWEN);

	// wait foe the TWINT flag to know that data is sent successfully
	while(BIT_IS_CLEAR(TWI_BASE->TWCR_t.Reg,TWINT));

	/* Read Data */
	return TWI_BASE->TWDR_t.Reg;
}


uint8 TWI_getStatus(void)
{
	uint8 status;
	/* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
	status = TWI_BASE->TWSR_t.Reg & TWI_STATUS_MASK;
	return status;
}



static void (*P_TWI_CallBack)(void) = NULL_PTR;


uint8 TWI_receiveByteAsynchCallBack()
{
	TWI_BASE->TWCR_t.Reg = (1 << TWINT) | (1 << TWEN);
	return TWI_BASE->TWDR_t.Reg;
}


void TWI_SetCallBack(void(*TWI_receiveByteAsynchCallBack)(void))
{

	P_TWI_CallBack = TWI_receiveByteAsynchCallBack;
	SREG |= (1<<7);
}

ISR(TWI_vect)
{
	if(P_TWI_CallBack != NULL_PTR)
	{
		SREG &= ~(1<<7);
		P_TWI_CallBack();
	}

}

