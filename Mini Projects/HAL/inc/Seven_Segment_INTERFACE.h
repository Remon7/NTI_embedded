
/******************************************************************************
 *
 * Module: Seven Segment
 *
 * File Name: 7_seg.h
 *
 * Description: Header file for the AVR Seven Segment driver ATMEGA32
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

#ifndef SEV_SEG_H_
#define SEV_SEG_H_


#include "Dio_INTERFACE.h"


//@ref Seven_Segment Number
typedef enum
{
	FIRST_SEG,TWO_SEGs,THREE_SEGs,FOUR_SEGs,SECOND,THIRD,FOURTH
}channel_numbers;

/* Function ProtoTypes */
void Segment_init(channel_numbers ch_num);
void SevenSeg_Num(uint8 num);

#endif /* SEV_SEG_H_ */
