/*
 * segment7_driver.h
 *
 *  Created on: Oct 21, 2023
 *      Author: remon
 */

#ifndef SEGMENT7_DRIVER_H_
#define SEGMENT7_DRIVER_H_


#include "Dio.h"


void SevenSeg_Init();

void SevenSeg_Num(uint8 num);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

extern  Port_Def* PORTA;
extern	Port_Def* PORTB;
extern	Port_Def* PORTC;
extern	Port_Def* PORTD;

#endif /* SEGMENT7_DRIVER_H_ */
