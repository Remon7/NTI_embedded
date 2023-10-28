/*
 * ADC_priv.h
 *
 *  Created on: Oct 24, 2023
 *      Author: remon
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

void __vector_16 (void) __attribute__ ((signal)) ;


/*******************************************************************************
 *                  DEFINING ADCSRA CONTROL AND STATUS REG Bits                 *
 *******************************************************************************/
#define				ADSC				6		// ADC START CONVERSION
#define				ADEN				7		// ADC ENABLE
#define				ADATE				5		// ADC AUTO TRIGGER ENABLE
#define				ADPS0				0		// channel selection
#define				ADPS1				1		// CLOCK PRESCALLER CHOOSE
#define				ADPS2				2
#define				ADIE				3		// ADC INTERRUPT ENABLE
#define				ADIF				4		// ADC INTERRUPT FLAG
#define				ADTS0				5


/*******************************************************************************
 *                  DEFINING ADMUX Bits                                        *
 *******************************************************************************/
#define				REFS0				6		// 00 --> AREF, Internal Vref turned off , 01 --> AVCC with external capacitor at AREF pin
#define				REFS1				7		// 11 --> Internal 2.56V Voltage Reference with external capacitor at AREF pin
#define				ADLAR				5		// ADC Left Adjust Result 0 --> right , 1 --> left
#define				MUX0				0		// channel selection
#define				MUX1				1
#define				MUX2				2
#define				MUX3				3
#define				MUX4				4


#endif /* ADC_PRIV_H_ */
