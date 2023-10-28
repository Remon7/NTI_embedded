/*
 * config.h
 *
 *  Created on: Oct 26, 2023
 *      Author: remon
 */

#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

#include "std_types.h"

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
}Pin_ID_t;

typedef enum
{
	OUT_OF_RANGE,NULL_POINTER,NO_ERROR,
}Error_Status;


#endif /* INC_CONFIG_H_ */
