/*
 * keypad.h
 *
 *  Created on: Oct 21, 2023
 *      Author: remon
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Dio.h"



uint8 Keypad_adjustKeyNum(uint8 buttonNum);

uint8 Keypad_getPressedKey(void);



/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

extern  Port_Def* PORTA;
extern	Port_Def* PORTB;
extern	Port_Def* PORTC;
extern	Port_Def* PORTD;


#endif /* KEYPAD_H_ */
