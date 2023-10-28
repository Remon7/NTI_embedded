/*
 * interrupt.c
 *
 *  Created on: Oct 22, 2023
 *      Author: remon
 */

#include "interrupt.h"

static void (*P_IRQ_CallBack)(void) = NULL_PTR;


void EXT_INT1_SetCallBack(void(*Ptr2Func)(void))
{
	P_IRQ_CallBack = Ptr2Func;
}

ISR(EXT1_vect)
{
    /* Check if the Timer0_setCallBack is already called */
    if(P_IRQ_CallBack != NULL_PTR)
    {
        P_IRQ_CallBack(); /* call the function in the scheduler using call-back concept */
    }
    /* No need to clear the trigger flag (COUNT) bit ... it cleared automatically by the HW */
}


void M_EXTI_voidEnable(uint8 Copy_u8PIntId,uint8 Copy_u8Trig)
{
	SREG &= ~(1<<7);
	switch(Copy_u8PIntId)
	{
	case EXTI_INT0_ID:
		GICR |= (1<<INT0);
		MCUCR &= (0xFC);
		MCUCR |= Copy_u8Trig;
		break;
	case EXTI_INT1_ID:
		GICR |= (1<<INT1);
		MCUCR &= (0xF3);
		MCUCR |= (Copy_u8Trig<<2);
		break;
	case EXTI_INT2_ID:
		GICR |= (1<<INT2);
		MCUCSR &= 0xBF;
		MCUCSR |=(Copy_u8Trig<<6);
		break;
	}
	SREG |= (1<<7);
}


void M_EXTI_voidDisable(uint8 Copy_u8PIntId)
{
	SREG  &= ~(1<<7);
	switch(Copy_u8PIntId)
	{
	case EXTI_INT0_ID:
		GICR &= (~(1<<INT0));
		break;
	case EXTI_INT1_ID:
		GICR |= (~(1<<INT1));
		break;
	case EXTI_INT2_ID:
		GICR |= (~(1<<INT2));
		break;
	}
	SREG |= (1<<7);
}
