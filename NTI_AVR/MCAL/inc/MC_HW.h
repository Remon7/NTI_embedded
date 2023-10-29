/*
 * MC_HW.h
 *
 *  Created on: Oct 26, 2023
 *      Author: remon
 */

#ifndef MC_HW_H_
#define MC_HW_H_

#include "..\..\inc\std_types.h"


//***********************************************************************************************
//********************************DEFINING  GICR REG FOR INT0,INT1,INT2 PREPHERAL ENABLE ******************************************
//***********************************************************************************************
#define		SREG					(*((volatile uint8 * ) (0x5F)))
#define		 I						7		// I BIT IN SREG FOR GENERAL INTERRUPT ENABLE


#define		SFIOR					(*((volatile uint8 * ) (0x50)))


#define		TIFR					(*((volatile uint8 * ) (0x58)))


#define		TIMSK					(*((volatile uint8 * ) (0x59)))


typedef union
{
	uint8 Reg;
	struct
	{
		uint8 B0:1;
		uint8 B1:1;
		uint8 B2:1;
		uint8 B3:1;
		uint8 B4:1;
		uint8 B5:1;
		uint8 B6:1;
		uint8 B7:1;
	}Bitfield;
}Reg_Def;

typedef struct
{
	Reg_Def Pin;
	Reg_Def DDR;
	Reg_Def PORT;
}Port_Def;


/*******************************************************************************
 *                      EXT INT datatypes                                           *
 *******************************************************************************/
typedef struct
{
	Reg_Def MCUCSR;
	Reg_Def MCUCR;
	Reg_Def RESERVED_Reg[5];
	Reg_Def GICR;
}EXTI_REG_t;



/*******************************************************************************
 *                      ADC datatypes                                           *
 *******************************************************************************/
typedef struct
{
	Reg_Def ADCL;
	Reg_Def ADCH;
	Reg_Def ADCSRA;
	Reg_Def ADMUX;
}ADC_REG_t;


/*******************************************************************************
 *                      Timer0 datatypes                                           *
 *******************************************************************************/
typedef struct
{
	Reg_Def TCNT0_t;
	Reg_Def TCCR0_t;
	Reg_Def RESERVED_Reg[8];
	Reg_Def OCR0_t;

}TIM0_REG_t;


/*******************************************************************************
 *                      Timer1 datatypes                                           *
 *******************************************************************************/
typedef struct
{
	uint16	ICR1_t;
	uint16	OCR1B_t;
	uint16	OCR1A_t;
	uint16	TCNT1_t;
	Reg_Def TCCR1B_t;
	Reg_Def TCCR1A_t;
}TIM1_REG_t;


/*******************************************************************************
 *                      GPIO defines                                           *
 *******************************************************************************/

#define PORTA_BASE  ((Port_Def*)0x39)
#define PORTB_BASE  ((Port_Def*)0x36)
#define PORTC_BASE  ((Port_Def*)0x33)
#define PORTD_BASE  ((Port_Def*)0x30)


/*******************************************************************************
 *                      EXTI defines                                           *
 *******************************************************************************/
#define EXTI_BASE 			(( EXTI_REG_t*) 0x54)


/*******************************************************************************
 *                      ADC defines                                           *
 *******************************************************************************/
#define ADC_BASE 			(( ADC_REG_t*) 0x24)


/*******************************************************************************
 *                      TIM0 defines                                           *
 *******************************************************************************/
#define TIM0_BASE 			(( TIM0_REG_t*) 0x52)


/*******************************************************************************
 *                      TIM1 defines                                           *
 *******************************************************************************/
#define TIM1_BASE 			(( TIM1_REG_t*) 0x46)



#endif /* MC_HW_H_ */
