/******************************************************************************
 *
 * Module: General Interrupt Controller
 *
 * File Name: GIC.h
 *
 * Description: Header file for the AVR General Interrupt Controller driver ATMEGA32
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/
#ifndef INC_GIC_H_
#define INC_GIC_H_



#include "MCU_HW.h"



// Function Prototypes
void ENABLE_GIE();
void DISABLE_GIE();

#endif /* INC_GIC_H_ */
