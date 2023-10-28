/*
 * interrupt.h
 *
 *  Created on: Oct 22, 2023
 *      Author: remon
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "avr/interrupt.h"
#include "std_types.h"


typedef enum
{
	EXTI_INT0_ID,EXTI_INT1_ID,EXTI_INT2_ID
}EXTI_ID;


typedef enum
{
	LOW_LEVEL_INT,ANY_CHANGE_INT,FALLING_EDGE_INT,RISING_EDGE_INT,
	FALLING_EDGE_INT2=0,RISING_EDGE_INT2
}EXTI_TRIG;


void M_EXTI_voidEnable(uint8 Copy_u8PIntId,uint8 Copy_u8Trig);
void M_EXTI_voidDisable(uint8 Copy_u8PIntId);
void EXT_INT1_SetCallBack(void(*Ptr2Func)(void));



#endif /* INTERRUPT_H_ */
