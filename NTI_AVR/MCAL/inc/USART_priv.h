/*
 * USART_priv.h
 *
 *  Created on: Oct 29, 2023
 *      Author: remon
 */

#ifndef MCAL_INC_USART_PRIV_H_
#define MCAL_INC_USART_PRIV_H_

#define F_CPU_t								8000000
#define BUAD_RATE							9600
#define USART_MODE_SELECT					0		// 0 for asynchronous and 1 for synchronous
#define USART_PARITY_SELECT					0		// 0 for disabled / 1 is reserved / 2 even parity / 3 odd parity
#define USART_STOP_BIT_SELECT				0		// 0 for 1-bit stop / 1 for 2-bit stop
#define USART_CHAR_SIZE						3		// 0 for 5-bit / 1 for 6-bit / 2 for 7-bit / 3 for 8-bit  /  7 for 9-bit
#define USART_CLK_POLARITY_SELECT			0		// 0 to send with rising and receive with falling edges / 1 to send with falling and receive with rising edges

/*******************************************************************************
 *                  DEFINING UCSRA Bits                                        *
 *******************************************************************************/
#define					MPCM				(0u)
#define					U2X					(1u)
#define					PE					(2u)
#define					DOR					(3u)
#define					FE					(4u)
#define					UDRE				(5u)
#define					TXC					(6u)
#define					RXC					(7u)


/*******************************************************************************
 *                  DEFINING UCSRB Bits                                        *
 *******************************************************************************/
#define					TXB8				(0u)
#define					RXB8				(1u)
#define					UCSZ2				(2u)
#define					TXEN				(3u)
#define					RXEN				(4u)
#define					UDRIE				(5u)
#define					TXCIE				(6u)
#define					RXCIE				(7u)


/*******************************************************************************
 *                  DEFINING UCSRC Bits                                        *
 *******************************************************************************/
#define					UCPOL				(0u)
#define					UCSZ0				(1u)
#define					UCSZ1				(2u)
#define					USBS				(3u)
#define					UPM0				(4u)
#define					UPM1				(5u)
#define					UMSEL				(6u)
#define					URSEL				(7u)


#endif /* MCAL_INC_USART_PRIV_H_ */
