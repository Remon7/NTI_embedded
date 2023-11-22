/******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: EXTI_INTERFACE.h
 *
 * Description: Header file for EXTI
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

/*******************************************************************************
 *                      		File Guarding                                   *
 *******************************************************************************/

#ifndef EXTI_INTERACE_H_
#define EXTI_INTERACE_H_


/*******************************************************************************
 *                      			INCLUDES                                   *
 *******************************************************************************/

#include "MCU_HW.h"
#include "Config.h"
#include "GIC.h"

/*******************************************************************************
 *                      	Types Declaration                                    *
 *******************************************************************************/



//@ref EXTI_define
typedef enum
{
	EXTI_NUM_0=6,
	EXTI_NUM_1=7,
	EXTI_NUM_2=5,
}EXTI_t;


//@ref EXTI_Trigger_define
typedef enum
{
	LOW_LEVEL_MODE=0,
	LOGICAL_CHANGE_MODE=1,
	FALLING_EDGE_MODE=2,
	RISING_EDGE_MODE=3
}Trigger_t;


typedef struct
{
	EXTI_t external_number;
	Trigger_t trigger_edge;
	void (* P_IRQ_CallBack)(void);
}EXTI_CONFIG_t;


/*******************************************************************************
 *                      Function ProtoTypes                                    *
 *******************************************************************************/

ErrorState_t MCAL_EXTI_INIT(EXTI_CONFIG_t* EXTI_Config);

ErrorState_t MCAL_EXTI_DeInit (EXTI_CONFIG_t* EXTI_Config);


#endif /* EXTI_INTERACE_H_ */
