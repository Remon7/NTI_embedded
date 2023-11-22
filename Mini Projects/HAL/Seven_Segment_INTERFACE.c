/******************************************************************************
 *
 * Module: Seven Segment
 *
 * File Name: 7_seg.c
 *
 * Description: Source file for the AVR Seven Segment driver ATMEGA32
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

#include <Seven_Segment_INTERFACE.h>
#include "util/delay.h"



/*
 * The Channel Numbers refers to how many segment do you want to enable
 *
 * you can choose it from  @ref Seven_Segment Number
 */
void Segment_init(channel_numbers ch_num)
{
	DIO_voidSetPinDirection(GPIOB_BASE,PIN0_ID,Pin_OUTPUT);
	DIO_voidSetPinDirection(GPIOB_BASE,PIN1_ID,Pin_OUTPUT);
	DIO_voidSetPinDirection(GPIOB_BASE,PIN2_ID,Pin_OUTPUT);
	DIO_voidSetPinDirection(GPIOB_BASE,PIN4_ID,Pin_OUTPUT);


	DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,LOW);
	DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
	DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
	DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);

	DIO_voidSetPinDirection(GPIOA_BASE,PIN3_ID,Pin_OUTPUT);
	DIO_voidSetPinDirection(GPIOA_BASE,PIN2_ID,Pin_OUTPUT);
	DIO_voidSetPinDirection(GPIOB_BASE,PIN5_ID,Pin_OUTPUT);
	DIO_voidSetPinDirection(GPIOB_BASE,PIN6_ID,Pin_OUTPUT);
	switch(ch_num)
	{
	case FIRST_SEG:
		DIO_voidSetPinValue(GPIOA_BASE,PIN3_ID,LOW);
		_delay_ms(2);
		DIO_voidSetPinValue(GPIOA_BASE,PIN2_ID,HIGH);
		_delay_ms(2);
		DIO_voidSetPinValue(GPIOB_BASE,PIN5_ID,HIGH);
		_delay_ms(2);
		DIO_voidSetPinValue(GPIOB_BASE,PIN6_ID,HIGH);
		break;
	case TWO_SEGs:
			DIO_voidSetPinValue(GPIOA_BASE,PIN3_ID,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(GPIOA_BASE,PIN2_ID,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(GPIOB_BASE,PIN5_ID,HIGH);
			_delay_ms(2);
			DIO_voidSetPinValue(GPIOB_BASE,PIN6_ID,HIGH);
			break;
	case THREE_SEGs:
			DIO_voidSetPinValue(GPIOA_BASE,PIN3_ID,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(GPIOA_BASE,PIN2_ID,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(GPIOB_BASE,PIN5_ID,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(GPIOB_BASE,PIN6_ID,HIGH);
			break;
	case FOUR_SEGs:
			DIO_voidSetPinValue(GPIOA_BASE,PIN3_ID,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(GPIOA_BASE,PIN2_ID,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(GPIOB_BASE,PIN5_ID,LOW);
			_delay_ms(2);
			DIO_voidSetPinValue(GPIOB_BASE,PIN6_ID,LOW);
			break;
	case SECOND:
				DIO_voidSetPinValue(GPIOA_BASE,PIN3_ID,HIGH);
				_delay_ms(2);
				DIO_voidSetPinValue(GPIOA_BASE,PIN2_ID,LOW);
				_delay_ms(2);
				DIO_voidSetPinValue(GPIOB_BASE,PIN5_ID,HIGH);
				_delay_ms(2);
				DIO_voidSetPinValue(GPIOB_BASE,PIN6_ID,HIGH);
				break;
	case THIRD:
				DIO_voidSetPinValue(GPIOA_BASE,PIN3_ID,HIGH);
				_delay_ms(2);
				DIO_voidSetPinValue(GPIOA_BASE,PIN2_ID,HIGH);
				_delay_ms(2);
				DIO_voidSetPinValue(GPIOB_BASE,PIN5_ID,LOW);
				_delay_ms(2);
				DIO_voidSetPinValue(GPIOB_BASE,PIN6_ID,HIGH);
				break;
	case FOURTH:
				DIO_voidSetPinValue(GPIOA_BASE,PIN3_ID,HIGH);
				_delay_ms(2);
				DIO_voidSetPinValue(GPIOA_BASE,PIN2_ID,HIGH);
				_delay_ms(2);
				DIO_voidSetPinValue(GPIOB_BASE,PIN5_ID,HIGH);
				_delay_ms(2);
				DIO_voidSetPinValue(GPIOB_BASE,PIN6_ID,LOW);
				break;

	}

}





/**================================================================
 * @Fn					-SevenSeg_Num
 * @brief 				-Gives it number from 0 >>> 9 and it displays it
 * @param [in] 			-uint8 num: unsigned number from 0 >>> 9
 * @retval 			-none
 * Note				-none
 * =================================================================*/
void SevenSeg_Num(uint8 num)

{
	switch(num)
	{
	case 0:
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 1 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 2 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 3 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 4 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 5 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 6 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 7 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,LOW);
		break;
	case 8 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,HIGH);
		break;
	case 9 :
		DIO_voidSetPinValue(GPIOB_BASE,PIN0_ID,HIGH);
		DIO_voidSetPinValue(GPIOB_BASE,PIN1_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN2_ID,LOW);
		DIO_voidSetPinValue(GPIOB_BASE,PIN4_ID,HIGH);
		break;
	}

}
