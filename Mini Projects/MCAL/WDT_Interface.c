/******************************************************************************
 *
 * Module: DIO
 *
 * File Name: WDT_Interface.c
 *
 * Description: Source file for the AVR WDT driver ATMEGA32
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/


#include "WDT_Private.h"
#include "WDT_Interface.h"

void WDT_Enable(void)
{
	/* Write logical one to WDTOE and WDE */
	WDTCR_REG = (1<<WDTOE) | (1<<WDE);

}
void WDT_Disable()
{
	/* Write logical one to WDTOE and WDE */
	WDTCR_REG |= (1<<WDTOE) | (1<<WDE);
	/* Turn off WDT */
	WDTCR_REG = 0x00;
}

void WDT_sleep(Time_out sleepTime)
{
	WDTCR_REG |= sleepTime;
}
void WDT_refresh()
{
	asm("WDR");
}
