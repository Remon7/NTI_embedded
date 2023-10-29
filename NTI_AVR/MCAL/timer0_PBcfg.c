/*
 * timer0_PBcfg.c
 *
 *  Created on: Oct 27, 2023
 *      Author: remon
 */


#include "inc/timer0.h"
#include "inc/timer1.h"

const TIM0_ConfigType TIM0_config = {
		FAST_PWM,
		CLEAR_COM,
		255,
		0,
		PRESCALAR_1024,
};


const TIM1_ConfigType TIM1_config = {
		TIM1_NORMAL,
		TIM1_DISCONNECTED,
		255,
		0,
		TIM1_PRESCALAR_1024,
		Channel_A,
};
