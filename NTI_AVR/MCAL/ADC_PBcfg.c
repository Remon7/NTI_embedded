/*
 * ADC_PBcfg.c
 *
 *  Created on: Oct 24, 2023
 *      Author: remon
 */


#include "inc/ADC.h"

const ADC_ConfigType ADC_config = {
		ADC_CHANNEL0,
		AVCC,
		LeftAdj,
		ADC_PRESCALAR_128,
		Trig_Disable,
		FreeRunning
};
