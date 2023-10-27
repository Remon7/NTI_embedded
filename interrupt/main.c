/*
 * main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: remon
 */

#include "interrupt.h"
#include "Dio.h"

void EXT1_IS(void)
{
	DIO_voidSetPinDirection(PORTA_Base,5,LOGIC_HIGH);
	DIO_voidSetPinValue(PORTA_Base,5,LOGIC_HIGH);
}

void main()
{
	DIO_voidSetPinDirection(PORTC_Base,2,LOGIC_HIGH);
	DIO_voidSetPinValue(PORTC_Base,2,LOGIC_LOW);
	M_EXTI_voidEnable(INT1,ANY_CHANGE_INT);
	EXT_INT1_SetCallBack(EXT1_IS);
	while(1)
	{

	}
}
