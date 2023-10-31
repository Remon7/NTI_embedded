/*
 * SPI.c
 *
 *  Created on: Oct 30, 2023
 *      Author: remon
 */

#include "inc/SPI.h"
#include "inc/SPI_priv.h"
#include "avr/interrupt.h"


void SPI_Init(SPI_ConfigType *SPI_config)
{

	/************************** SPCR Description **************************
	 * SPIE     enable or disable interrupt
	 * SPE     = 1 Enable SPI Driver
	 * DORD     transmission data order
	 * MSTR     select master or slave
	 * CPOL     SCK is low or high when idle
	 * CPHA     Sample Data with the raising or falling edge
	 * SPR1:0   Choose SPI clock prescale
	 ***********************************************************************/

	SPI_BASE->SPCR_t.Reg = (SPI_config->interrupt <<SPIE) | (1<<SPE) | (SPI_config->data_order <<DORD) | (SPI_config->data_order <<DORD) | (SPI_config->polarity <<CPOL) | (SPI_config->phase <<CPHA) | (SPI_config->prescalar <<SPR0);

	/* SPI2X bit in SPSR controls double speed so if prescalar is 128 and ds enabled it's 64 */
	SPI_BASE->SPSR_t.Reg = ((SPI_BASE->SPSR_t.Reg & 0xFE) |(SPI_config->ds<<SPI2X));

}

uint8 SPI_sendReceiveByte(uint8 copyu8data)
{
	/* Initiate the communication and send data by SPI */
	SPDR = copyu8data;

	/* Wait until SPI interrupt flag SPIF = 1 (data has been sent/received correctly) */
	while(BIT_IS_CLEAR(SPSR,SPIF)){}

	/*
	 * Note: SPIF flag is cleared by first reading SPSR (with SPIF set) which is done in the previous step.
	 * and then accessing SPDR like the below line.
	 */
	return SPDR;
}

void SPI_sendString(const uint8 *str)
{
	uint8 i = 0;
	uint8 received_data = 0;

	/* Send the whole string */
	while(str[i] != '\0')
	{
		/*
		 * received_data contains the received data from the other device.
		 * It is a dummy data variable as we just need to send the string to other device.
		 */
		received_data = SPI_sendReceiveByte(str[i]);
		i++;
	}
}


void SPI_receiveString(uint8 *str)
{
	uint8 i = 0;

	/* Receive the first byte */
	str[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);

	/* Receive the whole string until the '#' */
	while(str[i] != '#')
	{
		i++;
		str[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	str[i] = '\0';
}

