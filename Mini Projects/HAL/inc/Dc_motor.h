/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: Dc_motor.h
 *
 * Description: Header file for the Dc Motor Driver
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

/*******************************************************************************
 *                         File Guarding                                  *
 *******************************************************************************/
#ifndef INC_DC_MOTOR_H_
#define INC_DC_MOTOR_H_



/*******************************************************************************
 *                         INCLUDES                                   *
 *******************************************************************************/
#include "Dio_INTERFACE.h"
#include "MCU_HW.h"
#include "Config.h"





/*******************************************************************************
 *                         Definitions                                         *
 *******************************************************************************/

#define DC_MOTOR_PORT_ID            GPIOA_BASE
#define DC_MOTOR_PIN_IN1            PIN5_ID
#define DC_MOTOR_PIN_IN2            PIN6_ID

#define DC_MOTOR_PORT_ID_EN           GPIOB_BASE

#define DC_MOTOR_PIN_EN1            PIN3_ID



/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum {
	Stop,CW,CCW
}DcMotor_State;


/*******************************************************************************
 *                         Function Prototypes                                 *
 *******************************************************************************/

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 DUTY);

#endif /* INC_DC_MOTOR_H_ */
