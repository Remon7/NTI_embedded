/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: Dc_motor.c
 *
 * Description: Source file for the Dc Motor Driver
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

#include "Dc_motor.h"
#include "Timer_INTERFACE.h"


/*******************************************************************************
 *                         Function Definitions                                *
 *******************************************************************************/

void DcMotor_Init(void)
{

	DIO_voidSetPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_PIN_IN1, Pin_OUTPUT);

	DIO_voidSetPinDirection(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN_IN2 ,Pin_OUTPUT);
	DIO_voidSetPinValue(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN_IN1,LOGIC_LOW);
	DIO_voidSetPinValue(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN_IN2 ,LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 DUTY)
{
	Timer_Config timer = {TIMER0_FAST_PWM,F_CPU_1024_,Inverting};
	Timer_Init(&timer);

	DIO_voidSetPinDirection(GPIOB_BASE,PIN3_ID,Pin_OUTPUT);

	setFastPWM(DUTY,Inverting);
//	setphaseCorrectPWM(DUTY);

	switch(state)
	{
	case Stop:
		// Stop the motor
		DIO_voidSetPinValue(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_LOW);
		DIO_voidSetPinValue(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_LOW);
		break;
	case CW:
		// Rotate the motor --> clock wise
		DIO_voidSetPinValue(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_HIGH);
		DIO_voidSetPinValue(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_LOW);
		break;
	case CCW:
		// Rotate the motor --> anti-clock wise
		DIO_voidSetPinValue(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_LOW);
		DIO_voidSetPinValue(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_HIGH);
		break;
	}
}
