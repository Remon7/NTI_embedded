/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_INTERFACE.c
 *
 * Description: Source file for the AVR ADC_INTERFACE driver ATMEGA32
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/


#include "ADC_INTERFACE.h"
#include "ADC_Private.h"

/*
 * Call Back pointer
 */

void (*adc_ptr) (void) ;





void __vector_16 ()
{

	CLR_BIT (SREG_t ,I) ;
	adc_ptr ();
	ADC_BASE->ADCSRA_Reg.Bitfield.B4 = 1;
}


/*
 * this function should select ( Vref , Right or Left adjust
, prescaler , autotrigger or Not , and ADC enable).
 */
void ADC_init( const ADC_Config_t * Config_Ptr)
{


	/*Inserting the ref Volatage*/
	ADC_BASE->ADMUX_Reg.Reg = (ADC_BASE->ADMUX_Reg.Reg & VOLTAGE_SELECTION_MASK) | ((Config_Ptr->ref_volt) << REFS0);

	/*Inserting the Prescalar*/
	ADC_BASE->ADCSRA_Reg.Reg = (ADC_BASE->ADCSRA_Reg.Reg & ADC_Prescaler_Select_Bits_Mask) | (Config_Ptr->prescaler);

	SET_BIT(ADC_BASE->ADCSRA_Reg.Reg,ADEN);



	if(Config_Ptr->adjust == Left_adjust)
		ADC_BASE->ADMUX_Reg.Bitfield.B5 = Config_Ptr->adjust;
	else if(Config_Ptr->adjust == Right_adjust)
		ADC_BASE->ADMUX_Reg.Bitfield.B5 = Config_Ptr->adjust;


	if(Config_Ptr->AutoTrigger == Enable_AutoTrigger)
	{
		ADC_BASE->ADCSRA_Reg.Bitfield.B5 = 0;

		ADC_BASE->ADCSRA_Reg.Bitfield.B5 = 1;
		SFIOR_t |= (Config_Ptr->AutoTrigger_Source) << 5;
	}



}







unsigned short ADC_getDigitalValueSynchNonBlocking(ANALOG_CHANNEL channel)
{
	/* Inserting Channel */
	ADC_BASE->ADMUX_Reg.Reg = (ADC_BASE->ADMUX_Reg.Reg & Analog_Channel_Mask) | channel;

	/*Start Conversion */
	SET_BIT(ADC_BASE->ADCSRA_Reg.Reg , ADSC);



	while(BIT_IS_CLEAR(ADC_BASE->ADCSRA_Reg.Reg,ADIF));
	SET_BIT(ADC_BASE->ADCSRA_Reg.Reg,ADIF);
	return 	 ADC_BASE->ADCL_Reg;

}




/*
 *
 * needs to know channel and the call back pointer ,
 *	this fn enables Interrupt and selects the channel and
 *	starts conversion.
 */
void ADC_getDigitalValueAsynchCallBack( ANALOG_CHANNEL channel,void(*fnptr)(void))
{	/* Inserting Channel */
	ADC_BASE->ADMUX_Reg.Reg = (ADC_BASE->ADMUX_Reg.Reg & Analog_Channel_Mask) | channel;

	SET_BIT (SREG_t , I) ;
	SET_BIT(ADC_BASE->ADCSRA_Reg.Reg,ADIE);

	/*Start Conversion */
	SET_BIT(ADC_BASE->ADCSRA_Reg.Reg , ADSC);
	adc_ptr = fnptr;


}

