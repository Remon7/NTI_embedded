/******************************************************************************
 *
 * Module: LM35
 *
 * File Name: LM35_INTERFACE.h
 *
 * Description: Header file for the LM35 driver
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

#ifndef INC_LM35_INTERFACE_H_
#define INC_LM35_INTERFACE_H_

#include "Dio_INTERFACE.h"
#include "Config.h"
#include "ADC_INTERFACE.h"
#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define LM35_PORT			GPIOA_BASE
#define LM35_PIN			PIN7_ID



#define SENSOR_CHANNEL_ID         ADC0
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint16 LM35_read_temperature();

#endif /* INC_LM35_INTERFACE_H_ */
