/*
 * timer0_PBcfg.c
 *
 *  Created on: Oct 27, 2023
 *      Author: remon
 */


#include "inc/timer0.h"

const TIM0_ConfigType TIM0_config = {
		NORMAL,
		DISCONNECTED,
		RELOAD_VALUE,
		PRESCALAR_1024,
};
