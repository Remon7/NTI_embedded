/******************************************************************************
 *
 * Module: DIO
 *
 * File Name: Dio.h
 *
 * Description: Header file for the AVR GPIO driver ATMEGA32
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/


/*******************************************************************************
 *                             FILE GURADING	                              *
 *******************************************************************************/
#ifndef DIO_H_
#define DIO_H_



/*******************************************************************************
 *                             INCLUDES			                             *
 *******************************************************************************/
#include "MCU_HW.h"
#include "std_types.h"
#include "Config.h"


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/


typedef enum
{
	PORT_INPUT = 0x00,
	PORT_OUTPUT = 0xFF,
}Port_Direction_t;


typedef enum
{
	PIN_INPUT,
	Pin_OUTPUT
}Pin_Direction_t;


//@ref GPIO_PIN_state
typedef enum
{
	LOW,
	HIGH
}PIN_VALUE_t;



//@ref GPIO_PORT_Value
typedef enum
{
	PORT_LOW=0x00,
	PORT_HIGH=0xFF
}PORT_VALUE_t;



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void DIO_voidSetPinDirection(Port_Def* ptr,Pin_ID_t Copy_u8PinId,Pin_Direction_t Copy_u8Direction);

void DIO_voidSetPinValue(Port_Def* ptr,Pin_ID_t Copy_u8PinId,PIN_VALUE_t Copy_u8Value);

uint8 DIO_voidGetPinValue(Port_Def* ptr,Pin_ID_t Copy_u8PinId);

void DIO_voidSetPortDirection(Port_Def* ptr,Port_Direction_t Copy_u8Direction);

void DIO_voidSetPortValue(Port_Def* ptr,PORT_VALUE_t Copy_u8Value);

uint8 DIO_voidGetPortValue(Port_Def* ptr);


#endif /* DIO_H_ */
