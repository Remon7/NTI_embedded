/*
 * Dio.c
 *
 *  Created on: Oct 20, 2023
 *      Author: remon
 */
#include "Dio.h"




void DIO_voidSetPinDirection(Port_Def* ptr,uint8 Copy_u8PinId,uint8 Copy_u8Direction)
{

	switch (Copy_u8PinId)
	{
	case 0:
		ptr->DDR.Bitfield.B0=Copy_u8Direction;
		break;
	case 1:
		ptr->DDR.Bitfield.B1=Copy_u8Direction;
		break;
	case 2:
		ptr->DDR.Bitfield.B2=Copy_u8Direction;
		break;
	case 3:
		ptr->DDR.Bitfield.B3=Copy_u8Direction;
		break;
	case 4:
		ptr->DDR.Bitfield.B4=Copy_u8Direction;
		break;
	case 5:
		ptr->DDR.Bitfield.B5=Copy_u8Direction;
		break;
	case 6:
		ptr->DDR.Bitfield.B6=Copy_u8Direction;
		break;
	case 7:
		ptr->DDR.Bitfield.B7=Copy_u8Direction;
		break;

	}
}



void DIO_voidSetPinValue(Port_Def* ptr,uint8 Copy_u8PinId,uint8 Copy_u8Value)
{

	switch (Copy_u8PinId)
	{
	case 0:
		ptr->PORT.Bitfield.B0=Copy_u8Value;
		break;
	case 1:
		ptr->PORT.Bitfield.B1=Copy_u8Value;
		break;
	case 2:
		ptr->PORT.Bitfield.B2=Copy_u8Value;
		break;
	case 3:
		ptr->PORT.Bitfield.B3=Copy_u8Value;
		break;
	case 4:
		ptr->PORT.Bitfield.B4=Copy_u8Value;
		break;
	case 5:
		ptr->PORT.Bitfield.B5=Copy_u8Value;
		break;
	case 6:
		ptr->PORT.Bitfield.B6=Copy_u8Value;
		break;
	case 7:
		ptr->PORT.Bitfield.B7=Copy_u8Value;
		break;

	}
}

uint8 DIO_voidGetPinValue(Port_Def* ptr,uint8 Copy_u8PinId)
{
	uint8 value=0;

	switch (Copy_u8PinId)
	{
	case 0:
		value=ptr->Pin.Bitfield.B0;
		break;
	case 1:
		value=ptr->Pin.Bitfield.B1;
		break;
	case 2:
		value=ptr->Pin.Bitfield.B2;
		break;
	case 3:
		value=ptr->Pin.Bitfield.B3;
		break;
	case 4:
		value=ptr->Pin.Bitfield.B4;
		break;
	case 5:
		value=ptr->Pin.Bitfield.B5;
		break;
	case 6:
		value=ptr->Pin.Bitfield.B6;
		break;
	case 7:
		value=ptr->Pin.Bitfield.B7;
		break;
	}

	return value;
}


void DIO_voidSetPortDirection(Port_Def* ptr,uint8 Copy_u8Direction)
{
	ptr->DDR.Reg=Copy_u8Direction;
}


void DIO_voidSetPortValue(Port_Def* ptr,uint8 Copy_u8Value)
{
	ptr->PORT.Reg=Copy_u8Value;
}

uint8 DIO_voidGetPortValue(Port_Def* ptr)
{
	return ptr->Pin.Reg;
}



