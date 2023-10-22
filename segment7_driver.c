/*
 * segment7_driver.c
 *
 *  Created on: Oct 21, 2023
 *      Author: remon
 */

#include "segment7_driver.h"

void SevenSeg_Init()
{
	DIO_voidSetPinDirection(PORTB,PIN0,1);
	DIO_voidSetPinDirection(PORTB,PIN1,1);
	DIO_voidSetPinDirection(PORTB,PIN2,1);
	DIO_voidSetPinDirection(PORTB,PIN4,1);


	DIO_voidSetPinValue(PORTB,PIN0,0);
	DIO_voidSetPinValue(PORTB,PIN1,0);
	DIO_voidSetPinValue(PORTB,PIN2,0);
	DIO_voidSetPinValue(PORTB,PIN4,0);

	DIO_voidSetPinDirection(PORTA,PIN3,1);
	DIO_voidSetPinValue(PORTA,PIN3,0);
	DIO_voidSetPinDirection(PORTA,PIN2,1);
	DIO_voidSetPinValue(PORTA,PIN2,0);
	DIO_voidSetPinDirection(PORTB,PIN5,1);
	DIO_voidSetPinValue(PORTB,PIN5,0);
	DIO_voidSetPinDirection(PORTB,PIN6,1);
	DIO_voidSetPinValue(PORTB,PIN6,0);
}


void SevenSeg_Num(uint8 num)
{
	switch(num)
	{
	case 0 :
		DIO_voidSetPinValue(PORTB,PIN0,0);
		DIO_voidSetPinValue(PORTB,PIN1,0);
		DIO_voidSetPinValue(PORTB,PIN2,0);
		DIO_voidSetPinValue(PORTB,PIN4,0);
		break;
	case 1 :
		DIO_voidSetPinValue(PORTB,PIN0,1);
		DIO_voidSetPinValue(PORTB,PIN1,0);
		DIO_voidSetPinValue(PORTB,PIN2,0);
		DIO_voidSetPinValue(PORTB,PIN4,0);
		break;
	case 2 :
		DIO_voidSetPinValue(PORTB,PIN0,0);
		DIO_voidSetPinValue(PORTB,PIN1,1);
		DIO_voidSetPinValue(PORTB,PIN2,0);
		DIO_voidSetPinValue(PORTB,PIN4,0);
		break;
	case 3 :
		DIO_voidSetPinValue(PORTB,PIN0,1);
		DIO_voidSetPinValue(PORTB,PIN1,1);
		DIO_voidSetPinValue(PORTB,PIN2,0);
		DIO_voidSetPinValue(PORTB,PIN4,0);
		break;
	case 4 :
		DIO_voidSetPinValue(PORTB,PIN0,0);
		DIO_voidSetPinValue(PORTB,PIN1,0);
		DIO_voidSetPinValue(PORTB,PIN2,1);
		DIO_voidSetPinValue(PORTB,PIN4,0);
		break;
	case 5 :
		DIO_voidSetPinValue(PORTB,PIN0,1);
		DIO_voidSetPinValue(PORTB,PIN1,0);
		DIO_voidSetPinValue(PORTB,PIN2,1);
		DIO_voidSetPinValue(PORTB,PIN4,0);
		break;
	case 6 :
		DIO_voidSetPinValue(PORTB,PIN0,0);
		DIO_voidSetPinValue(PORTB,PIN1,1);
		DIO_voidSetPinValue(PORTB,PIN2,1);
		DIO_voidSetPinValue(PORTB,PIN4,0);
		break;
	case 7 :
		DIO_voidSetPinValue(PORTB,PIN0,1);
		DIO_voidSetPinValue(PORTB,PIN1,1);
		DIO_voidSetPinValue(PORTB,PIN2,1);
		DIO_voidSetPinValue(PORTB,PIN4,0);
		break;
	case 8 :
		DIO_voidSetPinValue(PORTB,PIN0,0);
		DIO_voidSetPinValue(PORTB,PIN1,0);
		DIO_voidSetPinValue(PORTB,PIN2,0);
		DIO_voidSetPinValue(PORTB,PIN4,1);
		break;
	case 9 :
		DIO_voidSetPinValue(PORTB,PIN0,1);
		DIO_voidSetPinValue(PORTB,PIN1,0);
		DIO_voidSetPinValue(PORTB,PIN2,0);
		DIO_voidSetPinValue(PORTB,PIN4,1);
		break;
	}

}

