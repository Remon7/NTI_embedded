/*
 * ADC.c
 *
 *  Created on: Oct 24, 2023
 *      Author: remon
 */


#include "inc/ADC.h"
#include "inc/ADC_priv.h"


void ADC_Init(ADC_ConfigType *ADC_config)
{
	ADC_BASE->ADMUX.Reg =0;
	CLEAR_BIT(ADC_BASE->ADCSRA.Reg,ADIE); /*clear the interrupt enable bit 3 in ADCSRA REG to disable the ADC interrupt*/
	ADC_BASE->ADCSRA.Reg = (ADC_BASE->ADCSRA.Reg & 0xF8) | (ADC_config->Prescalar);
	ADC_BASE->ADMUX.Reg = (ADC_BASE->ADMUX.Reg & 0x3F) | (ADC_config->V_ref<<REFS0);
	ADC_BASE->ADMUX.Reg = (ADC_BASE->ADMUX.Reg & 0xDF) | (ADC_config->Adj<<ADLAR);
	ADC_BASE->ADCSRA.Reg = (ADC_BASE->ADCSRA.Reg & 0xDF) | (ADC_config->trig_switch);
	SET_BIT(ADC_BASE->ADCSRA.Reg,ADEN); /*set the enable bit 7 in ADCSRA REG*/
}

uint16 ADC_getDigitalValueSynchNonBlocking(ADC_ConfigType *ADC_config)
{
	ADC_BASE->ADMUX.Reg = (ADC_BASE->ADMUX.Reg & 0xE0)|(ADC_config->Channel & 0x07);
	SET_BIT(ADC_BASE->ADCSRA.Reg,ADSC);
	while(BIT_IS_CLEAR(ADC_BASE->ADCSRA.Reg,ADIF))
	{

	}
	SET_BIT(ADC_BASE->ADCSRA.Reg,ADIF);
	return ADC_BASE->ADCL.Reg;
}

void ADC_getDigitalValueAsynchCallBack(ADC_ConfigType *ADC_config)
{
	ADC_BASE->ADMUX.Reg = (ADC_BASE->ADMUX.Reg & 0xE0)|(ADC_config->Channel & 0x07);
	SFIOR = (SFIOR & 0x1F) | (ADC_config->Trigger <<ADTS0);
	SET_BIT(ADC_BASE->ADCSRA.Reg,ADIE);
	SET_BIT(ADC_BASE->ADCSRA.Reg,ADIF);
}

