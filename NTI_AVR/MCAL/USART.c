/*
 * USART.c
 *
 *  Created on: Oct 29, 2023
 *      Author: remon
 */

#include "inc/USART.h"
#include "inc/USART_priv.h"
#include "avr/interrupt.h"


void UART_init()
{
	uint16 ubrr_value = 0;
	/* U2X = 1 for double transmission speed */
	USART_BASE->UCSRA_t.Reg = (1<<U2X);

	/************************** UCSRB Description **************************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN  = 1 Receiver Enable
	 * RXEN  = 1 Transmitter Enable
	 * UCSZ2 = 0 For 8-bit data mode
	 * RXB8 & TXB8 not used for 8-bit data mode
	 ***********************************************************************/
	USART_BASE->UCSRB_t.Reg = (1<<RXEN) | (1<<TXEN);

	/************************** UCSRC Description **************************
	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
	 * UMSEL   = usart mode selection
	 * UPM1:0  = parity mode
	 * USBS    = stop bit select
	 * UCSZ2:0 = data size select
	 * UCPOL   = 0 Used with the Synchronous operation only
	 ***********************************************************************/
	USART_BASE->UCSRC_t.Reg = (1<<URSEL) |(USART_MODE_SELECT<<UMSEL) | (USART_PARITY_SELECT<<UPM0) | (USART_STOP_BIT_SELECT<<USBS) | (USART_CHAR_SIZE<<UCSZ0);

#if (USART_MODE_SELECT == 1) // this bit is used in synchronous mode only
	USART_BASE->UCSRC_t.Reg |= (USART_CLK_POLARITY_SELECT<<UCPOL);
#endif


	ubrr_value = (uint16)(((F_CPU_t / (BUAD_RATE * 8UL))) - 1);

	USART_BASE->UBRRH_t.Reg = ubrr_value>>8;
	USART_BASE->UBRRL_t.Reg = ubrr_value;

}


void UART_sendByte(const uint8 Copy_u8Data)
{
	while(BIT_IS_CLEAR(USART_BASE->UCSRA_t.Reg,UDRE)){}

	USART_BASE->UDR_t.Reg = Copy_u8Data;
}


void UART_sendString(const uint8 *Str)
{
	uint8 i = 0;

	/* Send the whole string */
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}

}

uint8 UART_receiveByteSynchNonBlocking()
{
	while(BIT_IS_CLEAR(USART_BASE->UCSRA_t.Reg,RXC)){}

	return USART_BASE->UDR_t.Reg;
}

uint8 UART_receiveByteAsynchCallBack()
{

	return USART_BASE->UDR_t.Reg;
}


static void (*P_UART_CallBack)(void) = NULL_PTR;


void UART_SetCallBack(void(*UART_receiveByteAsynchCallBack)(void))
{
	P_UART_CallBack = UART_receiveByteAsynchCallBack;
}

ISR(USART_RXC_vect)
{
	if(P_UART_CallBack != NULL_PTR)
	{
		SREG &= ~(1<<7);
		P_UART_CallBack();
	}

}
