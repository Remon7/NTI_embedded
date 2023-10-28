/*
 * timer0.h
 *
 *  Created on: Oct 27, 2023
 *      Author: remon
 */

#ifndef MCAL_INC_TIMER0_H_
#define MCAL_INC_TIMER0_H_


#include "../../inc/std_types.h"
#include "../../inc/config.h"
#include "MC_HW.h"
#include "../../inc/BIT_MATH.h"


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

typedef enum
{
	NORMAL,PHASE_CORRECT_PWM,CTC,FAST_PWM
}Timer0_Mode;

typedef enum
{
	DISCONNECTED,NON_PWM_TOGGLE,CLEAR_COM,SET_COM
}Timer0_COM;

typedef enum
{
	RELOAD_VALUE,CMP_VALUE
}Timer0_Value;

typedef enum
{
	NO_CLOCK,PRESCALAR,PRESCALAR_8,PRESCALAR_64,PRESCALAR_256,PRESCALAR_1024,EXTERNAL_FALLING,EXTERNAL_RISING
}Timer0_Prescal;

typedef struct
{
	Timer0_Mode mode;
	Timer0_COM COM;
	Timer0_Value value;
	Timer0_Prescal prescalar;
}TIM0_ConfigType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

Error_Status Timer0_Init(TIM0_ConfigType *TIM0_config);

void Timer0_start(TIM0_ConfigType *TIM0_config);

void TIM0_SetCallBack(void(*Ptr2Func)(void));

void Timer0_start(TIM0_ConfigType *TIM0_config);

void Timer0_stop();

void Timer0_EnableInt(TIM0_ConfigType *TIM0_config,void(*Ptr2Func)(void));

void Timer0_DisableInt();

void Timer0_GetCounts();

void Timer0_SetDelayTimeMilliSecond();




#endif /* MCAL_INC_TIMER0_H_ */
