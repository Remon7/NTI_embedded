/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: Dc_motor.h
 *
 * Description: Header file for the Dc Motor Driver
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/




#ifndef INC_EEPROM_INTERFACE_H_
#define INC_EEPROM_INTERFACE_H_
#include "std_types.h"


typedef enum
{
	ERROR, SUCCESS
}ERROR_STATUS;







void EEPROM_Init(void);


ERROR_STATUS EEPROM_WriteByte (uint16 u16addr, uint8 u8data);


ERROR_STATUS EEPROM_ReadByte(uint16 addr, uint8 *u8data);


#endif /* INC_EEPROM_INTERFACE_H_ */
