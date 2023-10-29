/*
 * timer1_priv.h
 *
 *  Created on: Oct 28, 2023
 *      Author: remon
 */

#ifndef MCAL_INC_TIMER1_PRIV_H_
#define MCAL_INC_TIMER1_PRIV_H_


/*******************************************************************************
 *                  DEFINING TCCR1A Bits                                        *
 *******************************************************************************/
#define					FOC1A				(3u)
#define					FOC1B				(2u)
#define					COM1B0				(4u)
#define					COM1B1				(5u)
#define					COM1A0				(6u)
#define					COM1A1				(7u)
#define					WGM10				(0u)
#define					WGM11				(1u)


/*******************************************************************************
 *                  DEFINING TCCR1B Bits                                        *
 *******************************************************************************/
#define					WGM12				(3u)
#define					CS12				(2u)
#define					WGM13				(4u)

#define					ICES1				(6u)
#define					ICNC1				(7u)
#define					CS10				(0u)
#define					CS11				(1u)

/*******************************************************************************
 *                  DEFINING TIMSK Bits                                        *
 *******************************************************************************/

#define					T0IE1				(2u)
#define					OCIE1B				(3u)
#define					OCIE1A				(4u)
#define					TICIE1				(5u)

#endif /* MCAL_INC_TIMER1_PRIV_H_ */
