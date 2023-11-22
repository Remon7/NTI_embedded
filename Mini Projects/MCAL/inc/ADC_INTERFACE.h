/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_INTERFACE.h
 *
 * Description: Header file for the AVR ADC_INTERFACE driver ATMEGA32
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

#ifndef INC_ADC_INTERFACE_H_
#define INC_ADC_INTERFACE_H_


#include "MCU_HW.h"

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56



/*
 * REFS1:0: Reference Selection Bits
These bits select the voltage reference for the ADC, as shown in Table 83. If these bits
are changed during a conversion, the change will not go in effect until this conversion is
complete (ADIF in ADCSRA is set). The internal voltage reference options may not be
used if an external reference voltage is being applied to the AREF pin
* 0 0 AREF, Internal Vref turned off
* 0 1 AVCC with external capacitor at AREF pin
* 1 0 Reserved
* 1 1 Internal 2.56V Voltage Reference with external capacitor at AREF pin
 */



typedef enum{
	AREF,AVCC,Res,Internal
}ADC_ReferenceVolatge;

typedef enum{
	NO_prescaler,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef enum{
	ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7
}ANALOG_CHANNEL;

typedef enum
{
	Right_adjust,
	Left_adjust

}ADC_LEFT_ADJUST_t;

typedef enum
{
	Enable_AutoTrigger,
	Disable_AutoTrigger
}AutoTrigger_t;


typedef enum
{
	Free_Running,
	Analog_Comparator,
	EXTI_REQ_0,
	TIMER_COUNTER0_COMPARE_MATCH,
	TIMER_COUNTER0_OVERFLOW,
	TIMER_COUNTER_COMPARE_matchB,
	TIMER_COUNTER1_OVERFLOW,
	TIMER_COUNTER1_CAPTURE_EVENT

}AutoTriggerSource_t;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
	ANALOG_CHANNEL ADC_Channel;
	ADC_LEFT_ADJUST_t adjust;
	AutoTrigger_t AutoTrigger;
	AutoTriggerSource_t AutoTrigger_Source;

}ADC_Config_t;




/* Function ProtoType */
void ADC_init( const ADC_Config_t * Config_Ptr);
void ADC_getDigitalValueAsynchCallBack( ANALOG_CHANNEL channel,void(*fnptr)(void));
unsigned short ADC_getDigitalValueSynchNonBlocking(ANALOG_CHANNEL channel);

#endif /* INC_ADC_INTERFACE_H_ */
