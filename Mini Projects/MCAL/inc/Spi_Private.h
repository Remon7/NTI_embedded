/******************************************************************************
 *
 * Module: SPI
 *
 * File Name: SPI_Private.h
 *
 * Description: Header file for the AVR SPI Driver ATMEGA32
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

#ifndef INC_SPI_PRIVATE_H_
#define INC_SPI_PRIVATE_H_



/*******************************************************************************
 *                      		Bits in every register                                  *
 *******************************************************************************/
#define SPIE			7

#define SPE				6
#define DORD			5
#define MSTR			4
#define CPOL			3
#define CPHA			2
#define SPR1			1
#define SPR0			0



#define SPIF			7
#define SPI2X			0




/*******************************************************************************
 *                      		Mask Macros                                  *
 *******************************************************************************/
#define ENABLE_MASK							0xBF
#define LsbOrMSB_MASK						0xDF
#define MASTER_SLAVE_MASK					0xEF
#define POLARITY_MASK						0xFE
#define PHASE_MASK							0xFB
#define PRESCALAR_MASk						0xFC

#endif /* INC_SPI_PRIVATE_H_ */
