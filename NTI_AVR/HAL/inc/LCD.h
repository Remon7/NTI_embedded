/*
 * LCD.h
 *
 *  Created on: Oct 23, 2023
 *      Author: remon
 */

#ifndef LCD_H_
#define LCD_H_

#include "..\..\MCAL\inc\Dio.h"
#include "../../inc/config.h"
#include "LCD_config.h"
#include <stdlib.h>

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void H_LCD_void_Init(void);

static void H_LCD_void_latchByte(uint8 copy_u8Byte);

void H_LCD_void_sendCommand(uint8 copy_u8command);

void H_LCD_void_sendData(uint8 copy_u8data );

void H_LCD_void_sendString(const sint8 * pstr);

void H_LCD_void_sendIntNum(sint32 copy_s32Num);

void H_LCD_void_Clear();

void H_LCD_CreateCustomChar(const uint8 *ArrPattern, uint8 charCode);

void H_LCD_DisplayCustomChar(uint8 charCode);

void H_LCD_void_gotoXY(uint8 copy_u8Row, uint8 copy_u8Col);


#endif /* LCD_H_ */
