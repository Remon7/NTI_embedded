/*
 * Dio.h
 *
 *  Created on: Oct 20, 2023
 *      Author: remon
 */

#ifndef DIO_H_
#define DIO_H_

#include "MC_HW.h"

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void DIO_voidSetPinDirection(Port_Def* ptr,uint8 Copy_u8PinId,uint8 Copy_u8Direction);

void DIO_voidSetPinValue(Port_Def* ptr,uint8 Copy_u8PinId,uint8 Copy_u8Value);

uint8 DIO_voidGetPinValue(Port_Def* ptr,uint8 Copy_u8PinId);

void DIO_voidSetPortDirection(Port_Def* ptr,uint8 Copy_u8Direction);

void DIO_voidSetPortValue(Port_Def* ptr,uint8 Copy_u8Value);

uint8 DIO_voidGetPortValue(Port_Def* ptr);



#endif /* DIO_H_ */
