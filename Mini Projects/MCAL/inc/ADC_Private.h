/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_Private.h
 *
 * Description: Header file for the AVR ADC_Private driver ATMEGA32
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

#ifndef INC_ADC_PRIVATE_H_
#define INC_ADC_PRIVATE_H_

void __vector_16 (void) __attribute__ ((signal));


///////////////////////////////////////////////////////////////////////////////
///////////////// Masking Macros for each register//////////////////////
///////////////////////////////////////////////////////////////////////////////
#define VOLTAGE_SELECTION_MASK						0x3F
#define ADC_Prescaler_Select_Bits_Mask				0xF8
#define Analog_Channel_Mask							0xE0
///////////////////////////////////////////////////////////////////////////////
///////////////// DEFINING ADCSRA CONTROL AND STATUS REG Bits//////////////////////
///////////////////////////////////////////////////////////////////////////////
#define				ADSC				6		// ADC START CONVERSION
#define				ADEN				7		// ADC ENABLE
#define				ADATE				5		// ADC AUTO TRIGGER ENABLE
#define				ADPS0				0		// channel selection
#define				ADPS1				1		// CLOCK PRESCALLER CHOOSE
#define				ADPS2				2
#define				ADIE				3		// ADC INTERRUPT ENABLE
#define				ADIF				4		// ADC INTERRUPT FLAG

///////////////////////////////////////////////////////////////////////////////
///////////////////////////// DEFINING ADMUX Bits//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define				REFS0				6		// 00 --> AREF, Internal Vref turned off , 01 --> AVCC with external capacitor at AREF pin
#define				REFS1				7		// 11 --> Internal 2.56V Voltage Reference with external capacitor at AREF pin
#define				ADLAR				5		// ADC Left Adjust Result 0 --> right , 1 --> left
#define				MUX0				0		// channel selection
#define				MUX1				1
#define				MUX2				2
#define				MUX3				3
#define				MUX4				4
#endif /* INC_ADC_PRIVATE_H_ */
