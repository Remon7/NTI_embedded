/*
 * SPI_PBcfg.c
 *
 *  Created on: Oct 30, 2023
 *      Author: remon
 */


#include "inc/SPI.h"

const SPI_ConfigType SPI_config = {
		SPI_INT_DISABLE,
		SPI_DATA_MSB,
		SPI_MASTER,
		SCK_HIGH,
		SAMPLE_FIRST,
		SPI_PRESCALAR_4,
		SPI_DS_ENABLE
};
