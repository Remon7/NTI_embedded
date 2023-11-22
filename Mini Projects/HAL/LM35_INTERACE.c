/******************************************************************************
 *
 * Module: LM35
 *
 * File Name: LM35_INTERFACE.c
 *
 * Description: Source file for the LM35 driver
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/


#include "LM35_INTERFACE.h"




/*********************************************************
 *                   Function Definitions               *
 ********************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint16 LM35_read_temperature() {


	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_getDigitalValueSynchNonBlocking(ADC0);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;

}
