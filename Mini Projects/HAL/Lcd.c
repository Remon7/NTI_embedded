/*
 * Lcd.c
 *
 *
 *      Author: Remon Gerges
 */
#include "Lcd.h"
#include "LCD_Private.h"
#include "stdlib.h"


static void latchbyte(uint8_t copy_u8Byte)
{
#if(MODE == _8_BIT_MODE)
	{

		DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, LOW);

		_delay_ms(10);
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D0_PIN, GET_BIT(copy_u8Byte,0));
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D1_PIN, GET_BIT(copy_u8Byte,1));
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D2_PIN, GET_BIT(copy_u8Byte,2));
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D3_PIN, GET_BIT(copy_u8Byte,3));
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(copy_u8Byte,4));
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(copy_u8Byte,5));
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(copy_u8Byte,6));
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(copy_u8Byte,7));
		DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, HIGH);
		DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, LOW);
		_delay_ms(50);

	}
#elif(MODE == _4_BIT_MODE)
	{

		DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, LOW);

		_delay_ms(10);
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(copy_u8Byte,4));
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(copy_u8Byte,5));
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(copy_u8Byte,6));
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(copy_u8Byte,7));
		DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, HIGH);
		_delay_ms(10);
		DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, LOW);
		_delay_ms(10);
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(copy_u8Byte,0));
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(copy_u8Byte,1));
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(copy_u8Byte,2));
		DIO_voidSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(copy_u8Byte,3));
		DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, HIGH);
		_delay_ms(10);
		DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, LOW);
		_delay_ms(50);

	}
#endif
}



/*Initialization of LCD with the required mode and configuration*/
void H_LCD_void_IniT (void)
{
	/*Configure the direction of RS and E pins as o/p pins*/
	_delay_ms(30);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, Pin_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_EN_PIN, Pin_OUTPUT);

	/*LCD power ON delay is always 15 ms*/
	_delay_ms(20);
#if(MODE == _4_BIT_MODE)
	{
		DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_D4_PIN, Pin_OUTPUT);
		DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_D5_PIN, Pin_OUTPUT);
		DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_D6_PIN, Pin_OUTPUT);
		DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_D7_PIN, Pin_OUTPUT);
		/*Send initialization commands for 4 bit mode*/
		H_LCD_void_sendCommand(LCD_MODE_2LINES_4BITS_INIT1);
		H_LCD_void_sendCommand(LCD_MODE_2LINES_4BITS_INIT2);

		/*choose the mode of operation of LCD*/
		H_LCD_void_sendCommand(LCD_MODE_2LINES_4BITS);
	}
#elif (LCD_DATA_BITS_MODE == 8)
	{
		/*Configure the data port as o/p port*/
		GPIO_setupPortDirection(LCD_DATA_BUS_PORT,PORT_OUTPUT);

		/*choose the mode of operation of LCD*/
		H_LCD_void_sendCommand(LCD_MODE_2LINES_8BITS);
	}
#endif

		/*Send initialization display commands*/
	H_LCD_void_sendCommand(LCD_DISPLAY_ON_CURSOR_OFF);
	H_LCD_void_sendCommand(LCD_CLEAR_DISPLAY_SCREEN);
	}




/*Send the required command to the LCD*/
void H_LCD_void_sendCommand (uint8_t copy_u8command)
{
	/*RS = 0 for sending command*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, LOW);
	_delay_ms(1);
	latchbyte(copy_u8command);
}


/*Display the required character on the LCD*/
void H_LCD_void_sendData(uint8_t copy_u8data)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, HIGH);
	latchbyte(copy_u8data);

}

/*Display the required string on the lCD*/
void H_LCD_void_sendString(const uint8_t *pstr)
{
	while (*(pstr)!= NULL)
	{
		H_LCD_void_sendData(*pstr);
		pstr++;
	}
}


void H_LCD_int_to_string(int data)
{
	char buff[16]; /*array to hold the ASCII result of each number*/
		itoa(data,buff,10); /*itoa c function to convert the integer data to corresponding ASCII vale, 10 --> base 10 for decimal*/
		H_LCD_void_sendString(buff);
}

void H_LCD_void_gotoXY(uint8_t copy_u8Row, uint8_t copy_u8Col)
{
	uint8_t Local_U8_Arr [4] = {LCD_R0_COMMAND , LCD_R1_COMMAND , LCD_R2_COMMAND , LCD_R3_COMMAND};
	H_LCD_void_sendCommand(Local_U8_Arr[copy_u8Row] + copy_u8Col);
}


void H_Lcd_Void_Clear()
{
	H_LCD_void_sendCommand(LCD_CLEAR_DISPLAY_SCREEN);
}

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	H_LCD_void_gotoXY(row,col); /* go to to the required LCD position */
	H_LCD_void_sendString(Str); /* display the string */
}
