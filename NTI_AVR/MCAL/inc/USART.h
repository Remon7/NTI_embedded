/*
 * USART.h
 *
 *  Created on: Oct 29, 2023
 *      Author: remon
 */

#ifndef MCAL_INC_USART_H_
#define MCAL_INC_USART_H_

#include "../../inc/std_types.h"
#include "../../inc/config.h"
#include "MC_HW.h"
#include "../../inc/BIT_MATH.h"


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void UART_init();

void UART_sendByte(const uint8 Copy_u8Data);

void UART_sendString(const uint8 *Str);

uint8 UART_receiveByteSynchNonBlocking();

uint8 UART_receiveByteAsynchCallBack();

void UART_SetCallBack();
#endif /* MCAL_INC_USART_H_ */
