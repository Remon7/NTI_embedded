/*
 * timer0_priv.h
 *
 *  Created on: Oct 27, 2023
 *      Author: remon
 */

#ifndef MCAL_INC_TIMER0_PRIV_H_
#define MCAL_INC_TIMER0_PRIV_H_

/*******************************************************************************
 *                  DEFINING TCCR0 Bits                                        *
 *******************************************************************************/
#define					FOC0				(7u)
#define					WGM00				(6u)
#define					COM01				(5u)
#define					COM00				(4u)
#define					WGM01				(3u)
#define					CS02				(2u)
#define					CS01				(1u)
#define					CS00				(0u)


/*******************************************************************************
 *                  DEFINING TIMSK Bits                                        *
 *******************************************************************************/

#define					OCIE0				(1u)
#define					TOIE0				(0u)

#endif /* MCAL_INC_TIMER0_PRIV_H_ */
