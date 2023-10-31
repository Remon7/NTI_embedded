/*
 * timer1.h
 *
 *  Created on: Oct 28, 2023
 *      Author: remon
 */

#ifndef MCAL_INC_TIMER1_H_
#define MCAL_INC_TIMER1_H_


#include "../../inc/std_types.h"
#include "../../inc/config.h"
#include "MC_HW.h"
#include "../../inc/BIT_MATH.h"

#define RISING	(1u)
#define FALLING	(0u)

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

typedef enum
{
	TIM1_NORMAL,TIM1_PWM_PC8,TIM1_PWM_PC9,TIM1_PWM_PC10,
	TIM1_CTC_OCR,TIM1_FAST_PWM_8,TIM1_FAST_PWM_9,TIM1_FAST_PWM_10,
	TIM1_PWM_PFC_ICR,TIM1_PWM_PFC_OCR,TIM1_PWM_PC_ICR,TIM1_PWM_PC_OCR,
	TIM1_CTC_ICR,TIM1_FAST_PWM_ICR=14,TIM1_FAST_PWM_OCR
}Timer1_Mode;

typedef enum
{
	TIM1_DISCONNECTED,TIM1_NON_PWM_TOGGLE,TIM1_CLEAR_COM,TIM1_SET_COM
}Timer1_COM;


typedef enum
{
	TIM1_NO_CLOCK,TIM1_PRESCALAR,TIM1_PRESCALAR_8,TIM1_PRESCALAR_64,TIM1_PRESCALAR_256,TIM1_PRESCALAR_1024,TIM1_EXTERNAL_FALLING,TIM1_EXTERNAL_RISING
}Timer1_Prescal;

typedef enum
{
	Channel_A,Channel_B
}Timer1_Channel;

typedef struct
{
	Timer1_Mode mode;
	Timer1_COM COM;
	uint16 compare;
	uint16 reload;
	Timer1_Prescal prescalar;
	Timer1_Channel channel;
}TIM1_ConfigType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

Error_Status Timer1_Init(TIM1_ConfigType *TIM1_config);

void Timer1_start(TIM1_ConfigType *TIM1_config);

void TIM1_SetCallBack(void(*Ptr2Func)(void));

void Timer1_EnableInt(TIM1_ConfigType *TIM1_config,void(*Ptr2Func)(void));

void Timer1_ICU_EnableInt(void(*Ptr2Func)(void));

void Timer1_ICU_DisableInt();

void Timer1_ICU_SetTrig(uint8 Copy_u8Trig);

uint16 Timer1_ICU_takeReading(void);

void Timer1_Icu_clearTimerValue();


#endif /* MCAL_INC_TIMER1_H_ */
