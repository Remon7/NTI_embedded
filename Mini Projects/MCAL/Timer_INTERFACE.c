/*
 * Timer_INTERFACE.c
 *
 *
 *      Author: Remon Gerges
 */

#include "Timer_INTERFACE.h"
#include "Timer_Private.h"
#include <avr/interrupt.h>
#include "stdlib.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
static  void (* gTimer0_Call_BackPOINTER) (void) = NULL_PTR;




/* Timer0 overflow*/
ISR(TIMER0_OVF_vect)
{
	CLR_BIT(SREG,I);
	SET_BIT(Timer0_BASE->TIFR_Reg.Reg,TOV0); /* Clear Flag W1C*/

	if (gTimer0_Call_BackPOINTER != NULL_PTR)
	{
		(*gTimer0_Call_BackPOINTER)();
	}
}

/* Timer0 Compare*/
ISR(TIMER0_COMP_vect)
{
	CLR_BIT(SREG,I);
	SET_BIT(Timer0_BASE->TIFR_Reg.Reg,OCF0); /* Clear Flag W1C*/
	if (gTimer0_Call_BackPOINTER != NULL_PTR)
	{
		(*gTimer0_Call_BackPOINTER)();
	}
}





void Timer_Init(Timer_Config *Config_ptr)
{


	/* Inserting Clock Sourc */
	Timer0_BASE->TCCR0_Reg.Reg |= Config_ptr->prescalar;

	switch(Config_ptr->mode)
	{
	case TIMER0_NORMAL:

		SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,FOC0);
		//Timer0_BASE->TCCR0_Reg.Reg = 0;

		/* Inserting Clock Sourc */

		Timer0_BASE->TCNT0_Reg.Reg = Config_ptr -> reload_value;

		break;

	case TIMER0_CTC:
		SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,FOC0);

		SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM01);


		Timer0_BASE->TCCR0_Reg.Reg |= ((Config_ptr->signal_output) )<< COM00;
		Timer0_BASE->OCR0_Reg.Reg = Config_ptr->compare_value;
		break;

	case TIMER0_PWM_PHASE_CORRECT:
		SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM00);
		CLR_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM01);
		/* Inserting Clock Sourc */
		Timer0_BASE->TCCR0_Reg.Reg |= ((Config_ptr->signal_output) )<< COM00;

		if(Config_ptr->signal_output == Clear_OCx)
		{
			Timer0_BASE->TCCR0_Reg.Reg |= (1 << COM01);
		}
		else if(Config_ptr->signal_output == Set_OCx)
		{
			Timer0_BASE->TCCR0_Reg.Reg |= (1 << COM01) | (1<<COM00);

		}
		break;




	case TIMER0_FAST_PWM:

		SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM01);
		SET_BIT(Timer0_BASE->TCCR0_Reg.Reg,WGM00);


		Timer0_BASE->TCCR0_Reg.Reg |= ((Config_ptr->signal_output) )<< COM00;
		if(Config_ptr->signal_output == Non_inverting)
		{
			Timer0_BASE->TCCR0_Reg.Reg |= (1 << COM01);

		}
		else if(Config_ptr->signal_output == Inverting)
		{
			Timer0_BASE->TCCR0_Reg.Reg |= (1 << COM01) | (1<<COM00);

		}

		break;

	}




}


void Timer_start(Timer_Config *Config_ptr)
{
	Timer0_BASE->TCCR0_Reg.Reg |= Config_ptr->prescalar;

}


void Timer_stop()
{
	Timer0_BASE->TCCR0_Reg.Reg &= 0xF8;

}





void EnableInt(	Timer_Config *Config_ptr,void(*fnptr)(void))
{
	switch(Config_ptr->mode)
	{
	case TIMER0_NORMAL:

		SET_BIT(Timer0_BASE->TIMSK_Reg.Reg,TOIE0); /* enable interrupts for overflow mode */
		SET_BIT(Timer0_BASE->TIFR_Reg.Reg,TOV0); /* enable overflow flag */
		Timer0_setCallBack(fnptr);
		break;

	case TIMER0_CTC:

		SET_BIT(Timer0_BASE->TIMSK_Reg.Reg,OCIE0); /* enable interrupts for overflow mode */
		SET_BIT(Timer0_BASE->TIFR_Reg.Reg,OCF0); /* enable overflow flag */
		Timer0_setCallBack(fnptr);
		break;
	}
}

void DisableInt()
{

	SET_BIT(Timer0_BASE->TIFR_Reg.Reg,OCF0); /* W1C clear flag*/
	SET_BIT(Timer0_BASE->TIFR_Reg.Reg,TOV0); /* W1C clear flag */

}




void setFastPWM(uint8 duty,Compare_Output_Mode_t SignalOutput)
{


	if(SignalOutput == Non_inverting)
	{
		Timer0_BASE->OCR0_Reg.Reg  = abs (((duty*255)/100)-1);
	}
	else if(SignalOutput== Inverting)
	{
		Timer0_BASE->OCR0_Reg.Reg  = abs(255-((duty*256)/100));

	}


}


void setphaseCorrectPWM(uint8 duty)
{


	Timer0_BASE->OCR0_Reg.Reg  = (duty*255)/100;

}


void Timer_setDelayTimeMilliSec(uint16 milliseconds,Timer_Config *Config_ptr)
{
	// Calculate the number of timer counts required for the delay
	uint16 counts = (uint16)((milliseconds * 1000) / Config_ptr->prescalar);

	// Set the compare value
	Timer0_BASE->OCR0_Reg.Reg = counts - 1;

	// Clear the timer counter
	Timer0_BASE->TCNT0_Reg.Reg  = 0;

	// Wait until the compare match flag is set
	while (!(Timer0_BASE->TIFR_Reg.Reg & (1 << OCF0)));

	// Clear the compare match flag by writing a 1 to it
	Timer0_BASE->TIFR_Reg.Reg |= (1 << OCF0);
}





void Timer0_setCallBack(void(*a_ptr)(void))
{
	gTimer0_Call_BackPOINTER = a_ptr;
}


