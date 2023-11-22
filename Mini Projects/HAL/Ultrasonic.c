/*
 * Ultrasonic.c
 *
 *
 *      Author: Remon Gerges
 */
#include "Dio_INTERFACE.h"
#include "Timer1_INTERFACE.h"
#include "Ultrasonic.h"

#include "LED_INTERFACING.h"

uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;

uint32 distance = 0;





void Ultrasonic_edgeProcessing(void)
{

	g_edgeCount++;
	if(g_edgeCount == 1)
	{

		/* Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		MCAL_Timer1_ICU_clearTimerValue();
		/* Detect falling edge */
		MCAL_Timer1_ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		TOGGLE_BIT(GPIOB_BASE->PORT.Reg,PIN6_ID);


		g_timeHigh =  MCAL_Timer1_ICU_getInputCaptureValue();

		/* Detect rising edge */
		MCAL_Timer1_ICU_setEdgeDetectionType(RISING);
	}
}


void Ultrasonic_init(void)
{
	Icu_ConfigType ICU_CONFIG= {RISING,F_CPU_256__};


	//leD
	DIO_voidSetPinDirection(GPIOB_BASE, PIN6_ID, Pin_OUTPUT);

	MCAL_Timer1_ICU_Init(&ICU_CONFIG);
	MCAL_Timer1_ICU_setCallBack(Ultrasonic_edgeProcessing);

	DIO_voidSetPinDirection(GPIOB_BASE, PIN5_ID, Pin_OUTPUT);
	DIO_voidSetPinValue(GPIOB_BASE, PIN5_ID, LOGIC_LOW);
	Ultrasonic_Trigger();
}

void Ultrasonic_Trigger(void)
{
	DIO_voidSetPinValue(GPIOB_BASE, PIN5_ID, LOGIC_HIGH);
	_delay_us(10);
	DIO_voidSetPinValue(GPIOB_BASE, PIN5_ID, LOGIC_LOW);
}



uint16 Ultrasonic_readDistance(void)
{
	//Ultrasonic_Trigger();

	if(g_edgeCount == 2)
	{

		distance = ((g_timeHigh*5)/294)+((sint32)(distance-57)/73)+1;

		if (distance >= 2 && distance < 60)
		{
			distance = distance + 1;
		}
		else if (distance >= 60 && distance < 133)
		{
			distance = distance + 2;
		}
		else if (distance >= 133 && distance < 207)
		{

			distance = distance + 3;
		}
		else if (distance >= 207 && distance < 280)
		{

			distance = distance + 4;
		}
		else if (distance >= 280 && distance < 353)
		{

			distance = distance + 5;
		}
		else if (distance >= 353 && distance <= 400)
		{

			distance = distance + 6;
		}
		g_edgeCount = 0;
	}

	return distance;
}
