/*
 * EEPROM.h
 *
 *  Created on: Oct 31, 2023
 *      Author: remon
 */

#ifndef HAL_INC_EEPROM_H_
#define HAL_INC_EEPROM_H_

#include "..\..\MCAL\inc\TWI.h"
#include "../../inc/config.h"
#include "../../inc/std_types.h"


#define 	ERROR				0
#define		SUCCESS				1



void EEPROM_Init();
uint8 EEPROM_WriteByte(uint16 copy_u16Address,uint8 copy_u8Data);
uint8 EEPROM_ReadByte(uint16 copy_u16Address,uint8 *copy_u8Data);
#endif /* HAL_INC_EEPROM_H_ */
