/*
 * SPI_priv.h
 *
 *  Created on: Oct 30, 2023
 *      Author: remon
 */

#ifndef MCAL_INC_SPI_PRIV_H_
#define MCAL_INC_SPI_PRIV_H_


/*******************************************************************************
 *                  DEFINING SPCR Bits                                        *
 *******************************************************************************/
#define					SPR0				(0u)
#define					SPR1				(1u)
#define					CPHA				(2u)
#define					CPOL				(3u)
#define					MSTR				(4u)
#define					DORD				(5u)
#define					SPE					(6u)
#define					SPIE				(7u)


/*******************************************************************************
 *                  DEFINING SPSR Bits                                        *
 *******************************************************************************/
#define					SPI2X				(0u)
#define					WCOL				(6u)
#define					SPIF				(7u)


#endif /* MCAL_INC_SPI_PRIV_H_ */
