/******************************************************************************
 *
 * Module: SPI
 *
 * File Name: SPI_INTERFACE.h
 *
 * Description: Header file for the AVR SPI Driver ATMEGA32
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

#ifndef INC_SPI_INTERFACE_H_
#define INC_SPI_INTERFACE_H_

#include "MCU_HW.h"
#include "GIC.h"

#include "avr/interrupt.h"





typedef enum
{
	Rising , Falling
}Clock_Polarity;



typedef enum
{
	Sample , Setup
}Clock_phase;



typedef enum
{
	f_4,f_16,f_64,f_128,f_2,f_8,f_32,f_64_
}Spi_clock;

typedef enum
{
	Disable, Enable
}Double_speed;

typedef enum
{
	MSB, LSB
}Data_Order;

typedef enum
{
	Slave, Master
}Master_Or_Slave;


typedef struct
{
	Data_Order 			Order;
	Clock_Polarity 		Polarity;
	Clock_phase 		Phase;
	Double_speed		Speed;
	Spi_clock			Clock;
	Master_Or_Slave		Select;
}Spi_Config;


void MCAL_SPI_Init(Spi_Config* Config_Ptr);


void MCAL_SPI_Transfer(uint8 copy, uint8* pch); //copy is data recived   //


void AsynchSetCallBack( void (*ptr)(uint8 dat));



#endif /* INC_SPI_INTERFACE_H_ */
