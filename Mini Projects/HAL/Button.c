/******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button.c
 *
 * Description: Source file for the Button Driver
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/


/*******************************************************************************
 *                              INCLUDES		                              *
 *******************************************************************************/
#include "Button.h"





void Button_Init(Port_Def* GPIOx,Pin_ID_t pin)
{
	DIO_voidSetPinDirection(GPIOx, pin, PIN_INPUT);
}



Key_status Single_press(Port_Def* GPIOx, Pin_ID_t pin)
{
	DIO_voidSetPinDirection(GPIOx, pin, PIN_INPUT);
	static uint8 flag ;
	if(!DIO_voidGetPinValue(GPIOx, pin))
	{

		_delay_ms(50);
		if(!DIO_voidGetPinValue(GPIOx, pin))
		{
			if(flag == 0)
			{
				flag = 1;
				return pressed;
			}

		}

	}
	else
	{
		flag = 0;
	}

	return released;
}
