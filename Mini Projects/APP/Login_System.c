/******************************************************************************
 *
 * Module: Application
 *
 * File Name: APP.c
 *
 * Description: Source file
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

#include <Dio_INTERFACE.h>
#include "LED_INTERFACING.h"
#include "Button.h"
#include "Timer1_INTERFACE.h"
#include "GIC.h"

#include "Timer_INTERFACE.h"
#include "Lcd.h"

#include "Dc_motor.h"


#include "ADC_INTERFACE.h"


#include "LM35_INTERFACE.h"


#include "util/delay.h"


#include "Ultrasonic.h"





#if 0


uint16 reading = 0;


#define  F_CPU 		16000000UL      					 /* Define a CPU frequency of 8Mhz */
int main (void)
{
	ENABLE_GIE();
	H_LCD_void_IniT();
	Ultrasonic_init();

	LCD_displayStringRowColumn(0, 0,"Distance =    cm");

	///_delay_ms(2000);




	while (1)
	{
		Ultrasonic_Trigger();
		H_LCD_void_gotoXY(0, 11);
		reading = Ultrasonic_readDistance();


		if(reading >= 100)
		{
			H_LCD_int_to_string(reading);
		}
		else
		{
			H_LCD_int_to_string(reading);
			H_LCD_void_sendData(' ');
		}
	}
}
#endif
