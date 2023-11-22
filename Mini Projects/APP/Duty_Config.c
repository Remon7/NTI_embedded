/*
 * Duty_Config.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Remon Gerges
 */

#if 0



#include "Keypad.h"

#include "string.h"
#include "Lcd.h"
#include "Dc_motor.h"


int main(void)
{
	H_LCD_void_IniT();
	KEYPAD_INIT();
	DcMotor_Init();

	uint8 key = 0;
	uint8 duty_cycle = 0;
	uint8 flag = 0;

	while(1)
	{
		while(flag == 0)
		{
			H_LCD_void_sendString("Enter Duty Cycle:");
			flag = 1;
			duty_cycle = 0;
		}

		while(duty_cycle <= 100)
		{
			key = KEYPAD_Get_Pressed_Key();
			if(key == '=')
			{
				break;
			}
			else if(key != 0)
			{
				H_LCD_void_sendData(key);
				duty_cycle = duty_cycle*10 + (key - '0');
			}
		}

		if(duty_cycle > 100)
		{
			H_Lcd_Void_Clear();
			H_LCD_void_sendString("Invalid Duty Cycle");
			_delay_ms(2000);
			H_Lcd_Void_Clear();
			flag = 0;
		}

		else
		{
			DcMotor_Rotate(CW, duty_cycle);
			H_Lcd_Void_Clear();

			H_LCD_void_sendString("Duty Cycle:");
			H_LCD_int_to_string(duty_cycle);

			_delay_ms(2000);
			H_Lcd_Void_Clear();
			flag = 0;
		}
	}
}



#endif
