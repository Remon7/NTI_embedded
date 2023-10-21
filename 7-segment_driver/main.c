/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: remon
 */

#include "segment7_driver.h"
#include "util/delay.h"


void main()
{

	SevenSeg_Init();

	while(1)
	{
		for(int i=0;i<10;i++)
		{
			SevenSeg_Num(i);
			_delay_ms(1000);
		}

	}
}
