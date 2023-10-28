/*
 * segment7_driver.c
 *
 *  Created on: Oct 21, 2023
 *      Author: remon
 */

#include "inc\segment7_driver.h"

void SevenSeg_Init()
{
	DIO_voidSetPinDirection(PORTB_BASE,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTB_BASE,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTB_BASE,PIN2,OUTPUT);
	DIO_voidSetPinDirection(PORTB_BASE,PIN4,OUTPUT);


	DIO_voidSetPinValue(PORTB_BASE,PIN0,INPUT);
	DIO_voidSetPinValue(PORTB_BASE,PIN1,INPUT);
	DIO_voidSetPinValue(PORTB_BASE,PIN2,INPUT);
	DIO_voidSetPinValue(PORTB_BASE,PIN4,INPUT);

	DIO_voidSetPinDirection(PORTA_BASE,PIN3,OUTPUT);
	DIO_voidSetPinValue(PORTA_BASE,PIN3,LOGIC_LOW);
	DIO_voidSetPinDirection(PORTA_BASE,PIN2,OUTPUT);
	DIO_voidSetPinValue(PORTA_BASE,PIN2,LOGIC_LOW);
	DIO_voidSetPinDirection(PORTB_BASE,PIN5,OUTPUT);
	DIO_voidSetPinValue(PORTB_BASE,PIN5,LOGIC_LOW);
	DIO_voidSetPinDirection(PORTB_BASE,PIN6,OUTPUT);
	DIO_voidSetPinValue(PORTB_BASE,PIN6,LOGIC_LOW);
}


void SevenSeg_Num(uint8 num)
{
	switch(num)
	{
	case 0 :
		DIO_voidSetPinValue(PORTB_BASE,PIN0,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN1,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN2,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN4,LOGIC_LOW);
		break;
	case 1 :
		DIO_voidSetPinValue(PORTB_BASE,PIN0,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB_BASE,PIN1,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN2,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN4,LOGIC_LOW);
		break;
	case 2 :
		DIO_voidSetPinValue(PORTB_BASE,PIN0,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN1,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB_BASE,PIN2,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN4,LOGIC_LOW);
		break;
	case 3 :
		DIO_voidSetPinValue(PORTB_BASE,PIN0,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB_BASE,PIN1,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB_BASE,PIN2,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN4,LOGIC_LOW);
		break;
	case 4 :
		DIO_voidSetPinValue(PORTB_BASE,PIN0,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN1,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN2,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB_BASE,PIN4,LOGIC_LOW);
		break;
	case 5 :
		DIO_voidSetPinValue(PORTB_BASE,PIN0,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB_BASE,PIN1,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN2,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB_BASE,PIN4,LOGIC_LOW);
		break;
	case 6 :
		DIO_voidSetPinValue(PORTB_BASE,PIN0,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN1,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB_BASE,PIN2,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB_BASE,PIN4,LOGIC_LOW);
		break;
	case 7 :
		DIO_voidSetPinValue(PORTB_BASE,PIN0,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB_BASE,PIN1,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB_BASE,PIN2,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB_BASE,PIN4,LOGIC_LOW);
		break;
	case 8 :
		DIO_voidSetPinValue(PORTB_BASE,PIN0,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN1,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN2,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN4,LOGIC_HIGH);
		break;
	case 9 :
		DIO_voidSetPinValue(PORTB_BASE,PIN0,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB_BASE,PIN1,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN2,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB_BASE,PIN4,LOGIC_HIGH);
		break;
	}

}

