/******************************************************************************
 *
 * Module: SPI
 *
 * File Name: SPI_INTERFACE.c
 *
 * Description: Source file for the AVR SPI Driver for ATMEGA32
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/


/*******************************************************************************
 *                      		INCLUDES                                   *
 *******************************************************************************/

#include "Spi_INTERFACE.h"
#include "Spi_Private.h"



/*******************************************************************************
 *                      		Global Variables                                   *
 *******************************************************************************/

static  void (*g_SpiCallBackPtr)(uint8 data) = NULL_PTR;



/*******************************************************************************
 *                      		ISR Function                                   *
 *******************************************************************************/

ISR(SPI_STC_vect)
{
	g_SpiCallBackPtr(SPI_BASE->SPDR_t.Reg);
}






void MCAL_SPI_Init(Spi_Config* Config_Ptr)
{
	//Enable Spi
	SPI_BASE->SPCR_t.Reg = (SPI_BASE->SPCR_t.Reg & ENABLE_MASK) | (1<<SPE);

	//LSB or MSB
	SPI_BASE->SPCR_t.Reg = (SPI_BASE->SPCR_t.Reg & LsbOrMSB_MASK) | ((Config_Ptr->Order)<<DORD);

	//Master or slave
	SPI_BASE->SPCR_t.Reg = (SPI_BASE->SPCR_t.Reg & MASTER_SLAVE_MASK) | ((Config_Ptr->Select)<<MSTR);

	//Clock Polarity
	SPI_BASE->SPCR_t.Reg = (SPI_BASE->SPCR_t.Reg & POLARITY_MASK) | ((Config_Ptr->Polarity)<<CPOL);

	//Clock Phase
	SPI_BASE->SPCR_t.Reg = (SPI_BASE->SPCR_t.Reg & PHASE_MASK) | ((Config_Ptr->Phase)<<CPHA);

	//clock pres
	SPI_BASE->SPCR_t.Reg = (SPI_BASE->SPCR_t.Reg & PRESCALAR_MASk) | ((Config_Ptr->Clock)<<SPR0);




}




void MCAL_SPI_Transfer(uint8 copy, uint8* pch)
{

	SPI_BASE->SPDR_t.Reg = copy;


	while (BIT_IS_CLEAR(SPI_BASE->SPSR_t.Reg,SPIF));

	*pch = SPI_BASE->SPDR_t.Reg;

}



void AsynchSetCallBack( void (*ptr)(uint8 dat))
{
	SPI_BASE->SPCR_t.Reg = (SPI_BASE->SPCR_t.Reg & 0x7F) | (1<<SPIE);
	g_SpiCallBackPtr = ptr;
}
