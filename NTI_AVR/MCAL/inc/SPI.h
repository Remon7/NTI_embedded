/*
 * SPI.h
 *
 *  Created on: Oct 30, 2023
 *      Author: remon
 */

#ifndef MCAL_INC_SPI_H_
#define MCAL_INC_SPI_H_


#include "../../inc/std_types.h"
#include "../../inc/config.h"
#include "MC_HW.h"
#include "../../inc/BIT_MATH.h"

#define SPI_DEFAULT_DATA_VALUE 0xFF

typedef enum
{
	SPI_INT_ENABLE,SPI_INT_DISABLE
}SPI_Interrupt;

typedef enum
{
	SPI_DATA_MSB,SPI_DATA_LSB
}SPI_DATA_ORDER;

typedef enum
{
	SPI_SLAVE,SPI_MASTER
}SPI_MASTER_SLAVE;

typedef enum
{
	SCK_LOW,SCK_HIGH
}SPI_CLK_POLARITY;

typedef enum
{
	SAMPLE_FIRST,SETUP_FIRST
}SPI_CLK_PHASE;

typedef enum
{
	SPI_PRESCALAR_4,SPI_PRESCALAR_16,SPI_PRESCALAR_64,SPI_PRESCALAR_128
}SPI_Prescal;

typedef enum
{
	SPI_DS_ENABLE,SPI_DS_DISABLE
}SPI_DOUBLE_SPEED;

typedef struct
{
	SPI_Interrupt interrupt;
	SPI_DATA_ORDER data_order;
	SPI_MASTER_SLAVE MS_select;
	SPI_CLK_POLARITY polarity;
	SPI_CLK_PHASE phase;
	SPI_Prescal prescalar;
	SPI_DOUBLE_SPEED ds;
}SPI_ConfigType;




void SPI_Init(SPI_ConfigType *SPI_config);

uint8 SPI_sendReceiveByte(uint8 copyu8data);

void SPI_sendString(const uint8 *str);

void SPI_receiveString(uint8 *str);

#endif /* MCAL_INC_SPI_H_ */
