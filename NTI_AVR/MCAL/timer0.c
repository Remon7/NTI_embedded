/*
 * timer0.c
 *
 *  Created on: Oct 27, 2023
 *      Author: remon
 */


#include "inc/timer0.h"
#include "inc/timer0_priv.h"
#include "avr/interrupt.h"

static void (*P_TIM0_CallBack)(void) = NULL_PTR;


void TIM0_SetCallBack(void(*Ptr2Func)(void))
{
	P_TIM0_CallBack = Ptr2Func;
}

ISR(TIMER0_OVF_vect)
{
	if(P_TIM0_CallBack != NULL_PTR)
	{
		SREG &= ~(1<<7);
		P_TIM0_CallBack();
	}

}


Error_Status Timer0_Init(TIM0_ConfigType *TIM0_config)
{

	switch(TIM0_config->mode)
	{
	case NORMAL:
		SET_BIT(TIM0_BASE->TCCR0_t.Reg,FOC0);
		CLEAR_BIT(TIM0_BASE->TCCR0_t.Reg,WGM01);
		CLEAR_BIT(TIM0_BASE->TCCR0_t.Reg,WGM00);
		TIM0_BASE->TCNT0_t.Reg = TIM0_config->reload;
		break;
	case PHASE_CORRECT_PWM:
		CLEAR_BIT(TIM0_BASE->TCCR0_t.Reg,FOC0);
		CLEAR_BIT(TIM0_BASE->TCCR0_t.Reg,WGM01);
		SET_BIT(TIM0_BASE->TCCR0_t.Reg,WGM00);
		break;
	case CTC:
		SET_BIT(TIM0_BASE->TCCR0_t.Reg,FOC0);
		SET_BIT(TIM0_BASE->TCCR0_t.Reg,WGM01);
		CLEAR_BIT(TIM0_BASE->TCCR0_t.Reg,WGM00);
		TIM0_BASE->OCR0_t.Reg = TIM0_config->compare;
		break;
	case FAST_PWM:
		CLEAR_BIT(TIM0_BASE->TCCR0_t.Reg,FOC0);
		SET_BIT(TIM0_BASE->TCCR0_t.Reg,WGM01);
		SET_BIT(TIM0_BASE->TCCR0_t.Reg,WGM00);
		break;
	}
	if(((TIM0_config->mode == PHASE_CORRECT_PWM) || (TIM0_config->mode == FAST_PWM)) && (TIM0_config->COM == NON_PWM_TOGGLE))
	{
		return OUT_OF_RANGE;
	}
	else
	{
		TIM0_BASE->TCCR0_t.Reg = ((TIM0_BASE->TCCR0_t.Reg & 0xCF) | TIM0_config->COM << COM00);
	}
	TIM0_BASE->TCCR0_t.Reg = ((TIM0_BASE->TCCR0_t.Reg & 0xF8) | TIM0_config->prescalar);

	return NO_ERROR;
}


void Timer0_start(TIM0_ConfigType *TIM0_config)
{
	TIM0_BASE->TCCR0_t.Reg = ((TIM0_BASE->TCCR0_t.Reg & 0xF8) | TIM0_config->prescalar);
}

void Timer0_stop()
{
	TIM0_BASE->TCCR0_t.Reg &= 0xF8;
}

void Timer0_GetCounts()
{
}

void Timer0_SetDelayTimeMilliSecond()
{
}

void Timer0_EnableInt(TIM0_ConfigType *TIM0_config,void(*Ptr2Func)(void))
{
	SREG &=  ~(1<<7);
	switch(TIM0_config->mode)
	{
	case NORMAL:
		SET_BIT(TIMSK,TOIE0);
		break;
	case CTC:
		SET_BIT(TIMSK,OCIE0);
		break;
	}
	TIM0_SetCallBack(*Ptr2Func);
	SREG |= (1<<7);
}

void Timer0_DisableInt()
{
	CLEAR_BIT(TIMSK,TOIE0);
	CLEAR_BIT(TIMSK,OCIE0);
}

Error_Status Timer0_setFastPWM(uint8 duty,TIM0_ConfigType *TIM0_config)
{
	if(duty>=0 || duty<=100)
	{
		TIM0_BASE->OCR0_t.Reg  = abs (((duty*256)/100)-1);

		if(TIM0_config->COM == CLEAR_COM)
		{
			TIM0_BASE->OCR0_t.Reg  = abs (((duty*255)/100)-1);
		}
		else if(TIM0_config->COM == SET_COM)
		{
			TIM0_BASE->OCR0_t.Reg  = abs(255-((duty*256)/100));

		}
	}
	else
	{
		return OUT_OF_RANGE;
	}

	return NO_ERROR;
}


void setphaseCorrectPWM(uint8 duty)
{


	TIM0_BASE->OCR0_t.Reg  = (duty*255)/100;

}

