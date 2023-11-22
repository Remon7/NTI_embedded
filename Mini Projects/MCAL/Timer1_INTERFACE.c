/*
 * Timer1_INTERFACE.c
 *
 *
 *      Author: Remon Gerges
 */
#include "Timer1_INTERFACE.h"

#include "Timer1_Private.h"
#include "LED_INTERFACING.h"
#include "avr/interrupt.h"
#include "util/delay.h"
/* Global variables to hold the address of the call back function in the application */
static  void (*g_Timer1CallBackPtr)(void) = NULL_PTR;

static  void (*g_callBackPtr)(void) = NULL_PTR;

static  void (*g_ICUcallBackPtr)(void) = NULL_PTR;



/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
//ISR(TIMER1_OVF_vect)
//{
//	if(g_Timer1CallBackPtr != NULL_PTR)
//	{
//		(g_ICUcallBackPtr)();
//	}
//
//}


//ISR(TIMER1_COMPA_vect)
//{
//	if(g_Timer1CallBackPtr != NULL_PTR)
//	{
//		SET_BIT(Timer0_BASE->TIMSK_Reg.Reg,TOIE1);
//		(*g_ICUcallBackPtr)();
//	}
//
//}


ISR(TIMER1_CAPT_vect)
{


	if(g_ICUcallBackPtr != NULL_PTR)
	{
		SET_BIT(Timer0_BASE->TIMSK_Reg.Reg,TICIE1);
		(*g_ICUcallBackPtr)();
	}
}



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void MCAL_Timer1_Init(Timer1_Config *Config_ptr)
{

	Timer1_BASE->TCCR1A_t.Reg = 0;

	switch (Config_ptr->mode)
	{

	case TIMER1_NORMAL:
		Timer1_BASE->TCCR1A_t.Reg = (1<<FOC1A) | (1<<FOC1B);
		Timer1_BASE->TCNT1_t = Config_ptr->reload_value;
		Timer1_BASE->TCCR1B_t.Reg |= (Config_ptr->prescalar) ;
		break;

	case TIMER1_PWM_PHASE_CORRECT_8BIT:
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
		CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
		CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
		CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
		break;

	case TIMER1_PWM_PHASE_CORRECT_9BIT:
		CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
		CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
		CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
		break;

	case TIMER1_PWM_PHASE_CORRECT_10BIT:
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
		CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
		CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
		break;

	case TIMER1_CTC_OCR:

		Timer1_BASE->OCR1A_t = Config_ptr->compare_value;
		Timer1_BASE->TCCR1A_t.Reg |= (1<<FOC1A) | (1<<FOC1B);
		Timer1_BASE->TCCR1B_t.Reg |= (Config_ptr->prescalar) | (1<<WGM12);
		break;

	case TIMER1_FAST_PWM_8BIT:
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
		CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
		SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
		CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
		break;

	case TIMER1_FAST_PWM_9BIT:
		CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
		SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
		CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
		break;

	case TIMER1_FAST_PWM_10BIT:
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
		SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
		CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
		break;

	case TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR:
		CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
		CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
		CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
		SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
		break;

	case TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR:
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
		CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
		CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
		SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
		break;

	case TIMER1_PWM_PHASE_CORRECT_ICR:
		CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
		CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
		SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
		break;

	case TIMER1_PWM_PHASE_CORRECT_OCR:
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
		CLR_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
		SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
		break;

	case TIMER1_CTC_ICR:
		CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
		CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
		SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
		SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
		break;

	case TIMER1_FAST_PWM_ICR:
		CLR_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
		SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
		SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
		break;

	case TIMER1_FAST_PWM_OCR:
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM10);
		SET_BIT(Timer1_BASE->TCCR1A_t.Reg,WGM11);
		SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM12);
		SET_BIT(Timer1_BASE->TCCR1B_t.Reg,WGM13);
		break;

	default:
		break;
	}
	if(Config_ptr->Channels == ChannelB)
	{
		Timer1_BASE->TCCR1B_t.Reg = ((Timer1_BASE->TCCR1B_t.Reg & 0x3F) | (Config_ptr->signal_output) << COM1A0);
	}
	else
	{
		Timer1_BASE->TCCR1A_t.Reg = ((Timer1_BASE->TCCR1A_t.Reg & 0xCF) | (Config_ptr->signal_output) << COM1B0);
	}

}




void MCAL_Timer1_EnableInt(Timer1_Config *Config_ptr,void(*Ptr2Func)(void))
{

	switch(Config_ptr->mode)
	{
	case TIMER1_NORMAL:
		Timer0_BASE->TIMSK_Reg.Reg |= (1<<TOIE1);
		MCAL_Timer1_setCallBack(Ptr2Func);

		break;
	case TIMER1_CTC_ICR:
		if(Config_ptr->Channels == ChannelA)
		{

			SET_BIT(Timer0_BASE->TIMSK_Reg.Reg,OCIE1A);
			MCAL_Timer1_setCallBack(*Ptr2Func);

		}
		else
		{
			SET_BIT(Timer0_BASE->TIMSK_Reg.Reg,OCIE1B);
			MCAL_Timer1_setCallBack(*Ptr2Func);

		}
		break;
	case TIMER1_CTC_OCR:
		if(Config_ptr->Channels == ChannelA)
		{
			Timer0_BASE->TIMSK_Reg.Reg |= (1<<OCIE1A);
			MCAL_Timer1_setCallBack(*Ptr2Func);

		}
		else
		{
			SET_BIT(Timer0_BASE->TIMSK_Reg.Reg,OCIE1B);
			MCAL_Timer1_setCallBack(*Ptr2Func);

		}
		break;
	}
}



void MCAL_Timer1_setCallBack(void(*a_ptr)(void))
{
	g_Timer1CallBackPtr = a_ptr;
}



void MCAL_Timer1_ICU_Init(Icu_ConfigType* Config_ptr)
{

	DIO_voidSetPinDirection(GPIOD_BASE, PIN6_ID, PIN_INPUT);



	TCCR1A = (1<<FOC1A) | (1<<FOC1B);

	TCCR1B = (TCCR1A & 0xF8) | (Config_ptr->prescalar) ;


	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B = (TCCR1B & 0xBF)|((Config_ptr->edge)<<ICES1);


	/* Initial Value for the input capture register */

	TCNT1 = 0;
	ICR1 = 0;
	/* Enable the Input Capture interrupt to generate an interrupt when edge is detected on ICP1/PD6 pin */
	TIMSK |= (1<<TICIE1);
}


void MCAL_Timer1_ICU_setCallBack(void(*a_ptr)(void))
{
	g_ICUcallBackPtr = a_ptr;
}


/*
 * Description: Function to set the required edge detection.
 */
void MCAL_Timer1_ICU_setEdgeDetectionType(const Icu_EdgeType a_edgeType)
{
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B |= ((TCCR1B & 0xBF)| (a_edgeType)<<ICES1);

}




/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 MCAL_Timer1_ICU_getInputCaptureValue(void)
{
	return ICR1;
}

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void MCAL_Timer1_ICU_clearTimerValue(void)
{
	//Timer1_BASE->TCNT1_t = 0;

	TCNT1 = 0;
}



/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void MCAL_Timer1_ICU_DeInit(void)
{
	/* Clear All Timer1 Registers */
	Timer1_BASE->TCCR1A_t.Reg = 0;
	Timer1_BASE->TCCR1B_t.Reg = 0;
	Timer1_BASE->TCNT1_t = 0;
	Timer1_BASE->ICR1_t = 0;

	/* Disable the Input Capture interrupt */
	Timer0_BASE->TIMSK_Reg.Reg &= ~(1<<TICIE1);
}
