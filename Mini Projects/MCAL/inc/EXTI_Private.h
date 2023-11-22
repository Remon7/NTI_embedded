/******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: EXTI_Private.h
 *
 * Description: Header file for External Interrupt Private file
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/*******************************************************************************
 *                     			INCLUDES                                 *
 *******************************************************************************/

#include "stdint.h"
#include "BIT_MATH.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void __vector_1 (void) __attribute__ ((signal)); //INT0
void __vector_2 (void) __attribute__ ((signal)); //INT1

void __vector_3 (void) __attribute__ ((signal)); //IN2

/*******************************************************************************
 *                      			MACROS for MASKING                                *
 *******************************************************************************/

#define INT1_MASK				0x11110011
#define INT0_MASK				0x11111100
#define INT2_MASK				0x10111111
//***********************************************************************************************

#endif /* EXTI_PRIVATE_H_ */
