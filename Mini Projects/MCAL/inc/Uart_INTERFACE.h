/*
 * Uart_INTERFACE.h
 *
 *
 *      Author: Remon Gerges
 */

#ifndef INC_UART_INTERFACE_H_
#define INC_UART_INTERFACE_H_

#include "MCU_HW.h"


typedef enum
{
	one_bit, two_bit
}Stop_bit_select;

typedef enum
{
	five_bit, six_bit, seven_bit, eight_bit, nine_bit=7
}character_size;

typedef enum
{
	Disabled,Reserved,Even_Parity,Odd_Parity
}Parity_mode;


typedef enum
{
	Asynchronous, Synchronous
}Mode_select;

typedef enum
{
	Disable__, Enable__
}Double_Speed;




typedef struct{
Stop_bit_select  stop_bit;
character_size	 size;
Parity_mode	     parity_mode;
Mode_select  	Mode;
Double_Speed   Double_Speed;
}UART_Config;

void MCAL_UART_init(uint32 baud_rate, const UART_Config *config_ptr);

void MCAL_UART_sendByte_Blocking(const uint8 data);

void MCAL_UART_sendString_Blocking(const char *str);

void MCAL_UART_receiveString_Non_Block(uint8 *str);

uint8 MCAL_UART_recieveByte_Non_Blocking(void);

uint8 MCAL_UART_recieveByte_Blocking(void);

void MCAL_UART_receiveString_Polling(uint8 *str);

void MCAL_UART_receiveByteAsynchCallBack(void(*fnptr)(uint8 data));


#endif /* INC_UART_INTERFACE_H_ */
