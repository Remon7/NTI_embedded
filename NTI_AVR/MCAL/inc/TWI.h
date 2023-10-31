/*
 * TWI.h
 *
 *  Created on: Oct 30, 2023
 *      Author: remon
 */

#ifndef MCAL_INC_TWI_H_
#define MCAL_INC_TWI_H_


#include "../../inc/std_types.h"
#include "../../inc/config.h"
#include "MC_HW.h"
#include "../../inc/BIT_MATH.h"

/*******************************************************************************
 *                     STATUS CODES DEFINETIONS                                *
 *******************************************************************************/

#define TWI_START									0x08		// A START condition has been transmitted
#define TWI_REP_START								0x10		// A repeated START condition has been transmitted
#define TWI_MT_SLA_W_ACK							0x18		// SLA+W has been transmitted; ACK has been received
#define TWI_MT_SLA_W_NACK							0x20		//SLA+W has been transmitted; NOT ACK has been received
#define TWI_MT_DATA_ACK								0x28		// Data byte has been transmitted; ACK has been received
#define TWI_MT_DATA_NACK							0x30		// Data byte has been transmitted; NACK has been received
#define TWI_ARP_LOST_NACK							0x38		//Arbitration lost in SLA+R or NOT ACK bit
#define TWI_MR_SLA_R_ACK							0x40		//SLA+R has been transmitted; ACK has been received
#define TWI_MR_SLA_R_NACK							0x48		//SLA+R has been transmitted; NOT ACK has been received
#define TWI_MR_DATA_ACK								0x50		// Data byte has been received; ACK has been received
#define TWI_MR_DATA_NACK							0x58		// Data byte has been received; NOT ACK has been received


/*******************************************************************************
 *                     MODULE DATATYPES                                        *
 *******************************************************************************/



typedef enum
{
	TWI_PRESCALAR_1,TWI_PRESCALAR_4,TWI_PRESCALAR_16,TWI_PRESCALAR_64
}TWI_Prescal;



typedef struct
{
	TWI_Prescal prescale;

}TWI_ConfigType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

Error_Status TWI_Init(TWI_ConfigType *TWI_config);

void TWI_sendByte(uint8 copy_u8data);

void TWI_sendStart(void);

void TWI_sendStop(void);

uint8 TWI_recieveByteWithACK();

uint8 TWI_recieveByteWithNACK();

uint8 TWI_getStatus(void);

uint8 TWI_receiveByteAsynchCallBack();

void TWI_SetCallBack(void(*TWI_receiveByteAsynchCallBack)(void));
#endif /* MCAL_INC_TWI_H_ */
