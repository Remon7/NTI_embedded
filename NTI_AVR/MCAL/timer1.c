/*
 * timer1.c
 *
 *  Created on: Oct 28, 2023
 *      Author: remon
 */



#include "inc/timer1.h"
#include "inc/timer1_priv.h"
#include "avr/interrupt.h"

static void (*P_TIM1_CallBack)(void) = NULL_PTR;


void TIM1_SetCallBack(void(*Ptr2Func)(void))
{
	P_TIM1_CallBack = Ptr2Func;
}

ISR(TIMER1_OVF_vect)
{
	if(P_TIM1_CallBack != NULL_PTR)
	{
		SREG &= ~(1<<7);
		P_TIM1_CallBack();
	}

}


Error_Status Timer1_Init(TIM1_ConfigType *TIM1_config)
{

	switch(TIM1_config->mode)
	{
	case TIM1_NORMAL:
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		TIM1_BASE->TCNT1_t = TIM1_config->reload;
		break;
	case TIM1_PWM_PC8:
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		break;
	case TIM1_PWM_PC9:
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		break;
	case TIM1_PWM_PC10:
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		break;
	case TIM1_CTC_OCR:
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		TIM1_BASE->TCNT1_t = TIM1_config->compare;
		break;
	case TIM1_FAST_PWM_8:
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		break;
	case TIM1_FAST_PWM_9:
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		break;
	case TIM1_PWM_PFC_ICR:
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		break;
	case TIM1_PWM_PFC_OCR:
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		break;
	case TIM1_PWM_PC_ICR:
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		break;
	case TIM1_PWM_PC_OCR:
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		break;
	case TIM1_CTC_ICR:
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		TIM1_BASE->TCNT1_t = TIM1_config->compare;
		break;
	case TIM1_FAST_PWM_ICR:
		CLEAR_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		break;
	case TIM1_FAST_PWM_OCR:
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM11);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM12);
		SET_BIT(TIM1_BASE->TCCR1A_t.Reg,WGM13);
		break;
	}

	if(TIM1_config->channel == Channel_A)
	{
		TIM1_BASE->TCCR1A_t.Reg = ((TIM1_BASE->TCCR1A_t.Reg & 0x3F) | TIM1_config->COM << COM1A0);
	}
	else
	{
		TIM1_BASE->TCCR1A_t.Reg = ((TIM1_BASE->TCCR1A_t.Reg & 0xCF) | TIM1_config->COM << COM1B0);
	}
	TIM1_BASE->TCCR1B_t.Reg = ((TIM1_BASE->TCCR1B_t.Reg & 0xF8) | TIM1_config->prescalar);

	return NO_ERROR;
}


void Timer1_EnableInt(TIM1_ConfigType *TIM1_config,void(*Ptr2Func)(void))
{
	SREG &=  ~(1<<7);
	switch(TIM1_config->mode)
	{
	case TIM1_NORMAL:
		SET_BIT(TIMSK,TOIE1);
		break;
	case TIM1_CTC_ICR:
		if(TIM1_config->channel == Channel_A)
		{
			SET_BIT(TIMSK,OCIE1A);
		}
		else
		{
			SET_BIT(TIMSK,OCIE1B);
		}
		break;
	case TIM1_CTC_OCR:
		if(TIM1_config->channel == Channel_A)
		{
			SET_BIT(TIMSK,OCIE1A);
		}
		else
		{
			SET_BIT(TIMSK,OCIE1B);
		}
		break;
	}
	TIM1_SetCallBack(*Ptr2Func);
	SREG |= (1<<7);
}

