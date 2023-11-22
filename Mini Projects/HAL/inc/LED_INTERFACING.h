/*
 * LED_INTERFACING.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Remon Gerges
 */

#ifndef INC_LED_INTERFACING_H_
#define INC_LED_INTERFACING_H_


#include <Dio_INTERFACE.h>





typedef enum
{
	ACTIVE_LOW,
	ACTIVE_HIGH
}LED_Status_t;




void TURN_ON_OFF_LED(Port_Def* GPIOx ,LED_Status_t state,Pin_ID_t pin );

#endif /* INC_LED_INTERFACING_H_ */
