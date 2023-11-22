/******************************************************************************
 *
 * Module: Keypad
 *
 * File Name: Kepad.h
 *
 * Description: Header file for Keypad
 *
 * Author: Ahmed Yasser
 *
 *******************************************************************************/

/*******************************************************************************
 *                      File Guarding                                   *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_



/*******************************************************************************
 *                  	    INCLUDES                                  *
 *******************************************************************************/

#include <Dio_INTERFACE.h>
#include "Config.h"
#include "stdint.h"
#include "util/delay.h"
#include "Button.h"



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

ErrorState_t KEYPAD_INIT();

uint8_t KEYPAD_Get_Pressed_Key(void);



#endif /* KEYPAD_H_ */