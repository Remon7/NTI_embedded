/*
 * LCD.c
 *
 *  Created on: Oct 23, 2023
 *      Author: remon
 */
#include "INC/LCD.h"
#include "util/delay.h"


void H_LCD_void_Init(void)
{
	DIO_voidSetPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH);
	DIO_voidSetPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH);

	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,PIN0,OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,PIN1,OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,PIN2,OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,PIN4,OUTPUT);
#if(LCD_DATA_BIT_MODE == 8)
	DIO_voidSetPortDirection(LCD_DATA_PORT_ID,LOGIC_HIGH);
#endif

	_delay_ms(30);

	/********************* function set command ***********************/

#if(LCD_DATA_BIT_MODE == 4)
	DIO_voidSetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW);
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,PIN0,LOGIC_LOW);
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,PIN1,LOGIC_HIGH);
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,PIN2,LOGIC_LOW);
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,PIN4,LOGIC_LOW);
	_delay_ms(1);
	H_LCD_void_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);
	_delay_ms(1);
	H_LCD_void_sendCommand(LCD_CURSOR_OFF);
	_delay_ms(1);
	H_LCD_void_sendCommand(LCD_CLEAR_COMMAND);
	_delay_ms(1);
	H_LCD_void_sendCommand(LCD_GO_TO_HOME);
	_delay_ms(1);

#else if(LCD_DATA_BIT_MODE == 8)
	DIO_voidSetPortDirection(LCD_DATA_PORT_ID,LOGIC_HIGH);
#endif

}

static void H_LCD_void_latchByte(uint8 copy_u8Byte)
{
	DIO_voidSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID,LOGIC_LOW);

	_delay_ms(1);
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, PIN0, GET_BIT(copy_u8Byte,4));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, PIN1, GET_BIT(copy_u8Byte,5));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, PIN2, GET_BIT(copy_u8Byte,6));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, PIN4, GET_BIT(copy_u8Byte,7));

	DIO_voidSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID,LOGIC_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, PIN0, GET_BIT(copy_u8Byte,0));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, PIN1, GET_BIT(copy_u8Byte,1));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, PIN2, GET_BIT(copy_u8Byte,2));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, PIN4, GET_BIT(copy_u8Byte,3));

	DIO_voidSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID,LOGIC_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(5);
}

void H_LCD_void_sendCommand(uint8 copy_u8command)
{
	DIO_voidSetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW);
	H_LCD_void_latchByte(copy_u8command);
}

void H_LCD_void_sendData(uint8 copy_u8data )
{
	DIO_voidSetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH);
	H_LCD_void_latchByte(copy_u8data);
}

void H_LCD_void_sendString(const sint8 * pstr)
{
	uint8 i=0;
	for(;pstr[i]!='\0';i++)
	{
		H_LCD_void_sendData(pstr[i]);
	}
}


char buff[16]; /* String to hold the ascii result */

void H_LCD_void_sendIntNum(sint32 copy_s32Num)
{
	sint8 buff[16];
	itoa(copy_s32Num,buff,10);
	H_LCD_void_sendString(buff);
}

void H_LCD_void_Clear()
{
	H_LCD_void_sendCommand(LCD_CLEAR_COMMAND);
}


void H_LCD_CreateCustomChar(const uint8 *ArrPattern, uint8 charCode) {
	uint8 i;
	charCode &= 0x07;  // Make sure the charCode is in the range 0-7
	H_LCD_void_sendCommand(0x40 + (charCode * 8));  // Set CGRAM address for the custom character

	for (i = 0; i < 8; i++) {
		H_LCD_void_sendCommand(ArrPattern[i]);  // Send the custom character pattern to CGRAM
	}
}

void H_LCD_DisplayCustomChar(uint8 charCode) {
	charCode &= 0x07;  // Make sure the charCode is in the range 0-7
	H_LCD_void_sendData(charCode);  // Display the custom character on the LCD
}

void H_LCD_void_gotoXY(uint8 copy_u8Row, uint8 copy_u8Col)
{
	uint8_t Local_U8_Arr [4] = {LCD_R0_COMMAND , LCD_R1_COMMAND , LCD_R2_COMMAND , LCD_R3_COMMAND};
	H_LCD_void_sendCommand(Local_U8_Arr[copy_u8Row] + copy_u8Col);
}
