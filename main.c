/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: remon
 */


#include "keypad.h"
#include "segment7_driver.h"
#include "util/delay.h"


void main()
{
	SevenSeg_Init();
	uint8 key=0;
	while(1)
	{
		key= Keypad_getPressedKey();
		if((key >= 0) && (key <= 9))
		{
			SevenSeg_Num(key);
		}

	}
}
