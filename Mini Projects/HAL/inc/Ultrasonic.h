/*
 * Ultrasonic.h
 *
 *
 *      Author: Remon Gerges
 */

#ifndef INC_ULTRASONIC_H_
#define INC_ULTRASONIC_H_


#include "std_types.h"
#include <util/delay.h>

/*******************************************************************************************
 * 										Function ProtoTypes							       *
 *******************************************************************************************/


uint16 Ultrasonic_readDistance(void);

void Ultrasonic_init(void);

void Ultrasonic_edgeProcessing(void);

void Ultrasonic_Trigger(void);

#endif /* INC_ULTRASONIC_H_ */
