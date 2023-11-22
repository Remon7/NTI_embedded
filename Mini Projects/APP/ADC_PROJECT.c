
#if 0

#include "ADC_INTERFACE.h"
#include "Lcd.h"
#include "Dc_motor.h"
#include "LM35_INTERFACE.h"

//Cooling System Project

typedef enum
{
	OFF,ON
}FanState;


void Init_Drivers(void)
{
	/* Create configuration structure for ADC driver */
		ADC_Config_t ADC_Config = {Internal,F_CPU_8,ADC0};

		H_LCD_void_IniT(); /* initialize LCD driver */
		ADC_init(&ADC_Config); /* initialize ADC driver */

		DcMotor_Init(); /* initialize DC Motor driver */

}



void Main_Screen(void)
{

	LCD_displayStringRowColumn(0, 4,"Motor is ");

	LCD_displayStringRowColumn(1,4,"Temp =     C ");

	LCD_displayStringRowColumn(2,4,"Duty =     % ");

}
int main(void)
{
	Init_Drivers();
	uint8 temp = 0;
	FanState State;

	Main_Screen();
	while (1)
	{
		if ( State == ON)
		{
			LCD_displayStringRowColumn(0, 13, "ON");
		}
		else if ( State == OFF)
		{
			LCD_displayStringRowColumn(0, 13, "OFF");
		}

		temp = LM35_read_temperature();

		if(temp <= 25)
		{
			State = OFF;

			DcMotor_Rotate(Stop, 0);
			LCD_displayStringRowColumn(2, 11, "0");
		}
		else if (temp > 25)
		{
			State = ON;

			H_LCD_void_sendData(' ');  /* To prevent error like "ONF" to be written */

			if(temp > 25 && temp < 35)
			{
				DcMotor_Rotate(CW,50);
				LCD_displayStringRowColumn(2, 11, "50");

			}
			else if(temp >= 35 )
			{
				DcMotor_Rotate(CW,255);
				LCD_displayStringRowColumn(2, 11, "80");

			}

		}

		H_LCD_void_gotoXY(1,11);

		if(temp >= 100)
		{
			H_LCD_int_to_string(temp);
		}
		else
		{
			H_LCD_int_to_string(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			H_LCD_void_sendData(' ');


		}
	}
}
#endif
