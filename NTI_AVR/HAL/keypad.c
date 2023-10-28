/*
 * keypad.c
 *
 *  Created on: Oct 21, 2023
 *      Author: remon
 */

#include "inc/keypad.h"

uint8 Keypad_adjustKeyNum(uint8 buttonNum)
{
	uint8 button=0;
	switch(buttonNum)
	{
	case 1:
		button=7;
		break;
	case 2:
		button=8;
		break;
	case 3:
		button=9;
		break;
	case 4:
		button='%';
		break;
	case 5:
		button=4;
		break;
	case 6:
		button=5;
		break;
	case 7:
		button=6;
		break;
	case 8:
		button='*';
		break;
	case 9:
		button=1;
		break;
	case 10:
		button=2;
		break;
	case 11:
		button=3;
		break;
	case 12:
		button='-';
		break;
	case 13:
		button=13;
		break;
	case 14:
		button=0;
		break;
	case 15:
		button='=';
		break;
	case 16:
		button='+';
		break;
	default :
		button=buttonNum;
		break;
	}
	return button;
}

uint8 Keypad_getPressedKey(void)
{
	uint8 row,col;
	uint8 key=0;
	uint8 keypad_port_value=0;

	while(1)
	{
		for(col=0;col<4;col++)
		{
			DIO_voidSetPortDirection(PORTD_BASE,INPUT);
			switch(col)
			{
			case 0:
				DIO_voidSetPinDirection(PORTD_BASE,PIN7,OUTPUT);
				keypad_port_value = ~(1<<PIN7);
				break;
			case 1:
				DIO_voidSetPinDirection(PORTD_BASE,PIN6,OUTPUT);
				keypad_port_value = ~(1<<PIN6);
				break;
			case 2:
				DIO_voidSetPinDirection(PORTD_BASE,PIN5,OUTPUT);
				keypad_port_value = ~(1<<PIN5);
				break;
			case 3:
				DIO_voidSetPinDirection(PORTD_BASE,PIN3,OUTPUT);
				keypad_port_value = ~(1<<PIN3);
				break;
			}
			DIO_voidSetPortValue(PORTD_BASE,keypad_port_value);

			for(row=0;row<4;row++)
			{
				if(DIO_voidGetPinValue(PORTC_BASE,PIN5-row)==LOGIC_LOW)
				{
					key=Keypad_adjustKeyNum((row*4)+col+1);
					return key;
				}
			}
		}

	}
}
