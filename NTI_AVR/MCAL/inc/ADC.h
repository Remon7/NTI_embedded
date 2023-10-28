/*
 * ADC.h
 *
 *  Created on: Oct 24, 2023
 *      Author: remon
 */

#ifndef ADC_H_
#define ADC_H_

#include "../../inc/std_types.h"
#include "MC_HW.h"
#include "../../inc/BIT_MATH.h"


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

typedef enum
{
	ADC_CHANNEL0,ADC_CHANNEL1,ADC_CHANNEL2,ADC_CHANNEL3,ADC_CHANNEL4,ADC_CHANNEL5,ADC_CHANNEL6,ADC_CHANNEL7
}Channel_Num;

typedef enum
{
	AREF_OFF,AVCC,AREF_256=4
}Ref_Vol;

typedef enum
{
	RightAdj,LeftAdj
}Adjust;

typedef enum
{
	ADC_PRESCALAR_2=1,ADC_PRESCALAR_4,ADC_PRESCALAR_8,ADC_PRESCALAR_16,ADC_PRESCALAR_32,ADC_PRESCALAR_64,ADC_PRESCALAR_128
}Div_Fct;

typedef enum
{
	Trig_Disable,Trig_Enable
}Trig_En;

typedef enum
{
	FreeRunning,AnalogCmp,EXT0,TIMER0_CPM,TIMER0_OVF,TIMER1_CPM,TIMER1_OVF,TIMER1_CAP
}Auto_Trig;

typedef struct
{
	Channel_Num Channel;
	Ref_Vol V_ref;
	Adjust Adj;
	Div_Fct Prescalar;
	Trig_En trig_switch;
	Auto_Trig Trigger;
}ADC_ConfigType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void ADC_Init(ADC_ConfigType *ADC_config);
uint16 ADC_getDigitalValueSynchNonBlocking(ADC_ConfigType *ADC_config);


#endif /* ADC_H_ */
