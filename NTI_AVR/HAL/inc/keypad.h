/*
 * keypad.h
 *
 *  Created on: Oct 21, 2023
 *      Author: remon
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "..\..\MCAL\inc\Dio.h"
#include "../../inc/config.h"



uint8 Keypad_adjustKeyNum(uint8 buttonNum);

uint8 Keypad_getPressedKey(void);





#endif /* KEYPAD_H_ */
