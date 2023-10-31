/*
 * TWI_priv.h
 *
 *  Created on: Oct 30, 2023
 *      Author: remon
 */

#ifndef MCAL_INC_TWI_PRIV_H_
#define MCAL_INC_TWI_PRIV_H_


#define TWI_STATUS_MASK				0xF8

/*******************************************************************************
 *                  DEFINING TWCR Bits                                        *
 *******************************************************************************/
#define					TWIE				(0u)
#define					TWEN				(2u)
#define					TWWC				(3u)
#define					TWSTO				(4u)
#define					TWSTA				(5u)
#define					TWEA				(6u)
#define					TWINT				(7u)



/*******************************************************************************
 *                  DEFINING TWSR Bits                                        *
 *******************************************************************************/
#define					TWPS0				(0u)
#define					TWPS1				(1u)
#define					TWS3				(3u)
#define					TWS4				(4u)
#define					TWS5				(5u)
#define					TWS6				(6u)
#define					TWS7				(7u)



/*******************************************************************************
 *                  DEFINING TWAR Bits                                        *
 *******************************************************************************/
#define					TWGCE				(0u)
#define					TWA0				(1u)
#define					TWA1				(2u)
#define					TWA2				(3u)
#define					TWA3				(4u)
#define					TWA4				(5u)
#define					TWA5				(6u)
#define					TWA6				(7u)

#endif /* MCAL_INC_TWI_PRIV_H_ */
