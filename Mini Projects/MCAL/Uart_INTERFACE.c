/*
 * Uart_INTERFACE.c
 *
 *
 *      Author: Remon Gerges
 */


#include "Uart_INTERFACE.h"
#include "Uart_Private.h"

#include "std_types.h"
#include "avr/interrupt.h"
#include "LED_INTERFACING.h"


void (*Uart_CallBack) (uint8 data) = NULL_PTR;



ISR(USART_RXC_vect)
{
	if(Uart_CallBack != NULL_PTR)
	{
		SET_BIT(UART_BASE->UCSRB_t.Reg,RXCIE);
		Uart_CallBack(UART_BASE->UDR_t.Reg);
		UART_BASE->UDR_t.Reg = 0;
	}
}



void MCAL_UART_init(uint32 baud_rate, const UART_Config *config_ptr)
{
	uint16 ubrr_value = 0;
	/*Write this bit one to double the transfer rate for asynchronous communication */
	UART_BASE->UCSRA_t.Reg |= ((config_ptr->Double_Speed)<<U2X);


	//Enable Rx & Tx
	UART_BASE->UCSRB_t.Reg = (1<<RXEN) | (1<<TXEN);


	UCSRC_t = (1<<URSEL);
	UCSRC_t = ( UCSRC_t & Mask_Parity ) | ((config_ptr -> parity_mode ) <<UPM0);
	UCSRC_t = ( UCSRC_t & StopBit_Mask ) | ((config_ptr -> stop_bit ) <<USBS);
	UCSRC_t = ( UCSRC_t & CharacterSize_Mask ) | ((config_ptr -> size ) <<UCSZ0);





	//	/* Calculate the UBRR register value */
	ubrr_value = (uint16)(((8000000 / (baud_rate * 8UL))) - 1);

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH_t = ubrr_value>>8;
	UART_BASE->UBRRL_t.Reg = ubrr_value;


}




/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void MCAL_UART_sendByte_Blocking(const uint8 data)
{
	UART_BASE->UDR_t.Reg = data;

	while(BIT_IS_CLEAR(UART_BASE->UCSRA_t.Reg,TXC)){} // Wait until the transmission is complete TXC = 1
	SET_BIT(UART_BASE->UCSRA_t.Reg,TXC); // Clear the TXC flag
}



/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void MCAL_UART_sendString_Blocking(const char *str)
{
	uint8 i = 0;
	while(str[i] != 0)
	{
		MCAL_UART_sendByte_Blocking(str[i]);
		i++;
	}

}




/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */


uint8 MCAL_UART_recieveByte_Blocking(void)
{
	while(BIT_IS_CLEAR(UART_BASE->UCSRA_t.Reg,RXC)); /* RXC flag is set when the UART receive data so wait until this flag is set to one */
	SET_BIT(UART_BASE->UCSRA_t.Reg,RXC); /* Clear the TXC flag*/
	return  UART_BASE->UDR_t.Reg;   /*Read the received data from the Rx buffer (UDR)*/


}


uint8 MCAL_UART_recieveByte_Non_Blocking(void)
{

	if(BIT_IS_CLEAR(UART_BASE->UCSRA_t.Reg,RXC))
	{
		SET_BIT(UART_BASE->UCSRA_t.Reg,RXC);
		return UART_BASE->UDR_t.Reg;   /*Read the received data from the Rx buffer (UDR)*/

	}
	/*
	 * Return a special value (e.g., 0xFF) to indicate no data available
	 */
	return  0xFF;
}

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void MCAL_UART_receiveString_Non_Block(uint8 *str)
{
	uint8 i = 0;

	/* Receive the first byte */
	str[i] = MCAL_UART_recieveByte_Blocking();

	/* Receive the whole string until the '#' */
	while(str[i] != '#')
	{
		i++;
		str[i] = MCAL_UART_recieveByte_Blocking();
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	str[i] = '\0';

}


void MCAL_UART_receiveString_Polling(uint8 *str)
{
	uint8 i = 0;

	/* Receive the first byte */
	str[i] = MCAL_UART_recieveByte_Blocking();

	/* Receive the whole string until the '#' */
	while(str[i] != '#')
	{
		i++;
		str[i] = MCAL_UART_recieveByte_Blocking();
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	str[i] = '\0';


}




void MCAL_UART_receiveByteAsynchCallBack(void(*fnptr)(uint8 data))
{
	SET_BIT(UART_BASE->UCSRB_t.Reg,RXCIE);
	Uart_CallBack = fnptr;

}



