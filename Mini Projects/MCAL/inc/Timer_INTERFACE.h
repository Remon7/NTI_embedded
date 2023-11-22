/*
 * Timer_INTERFACE.h
 *
 *
 *      Author: Remon Gerges
 */

#ifndef INC_TIMER_INTERFACE_H_
#define INC_TIMER_INTERFACE_H_


#include "MCU_HW.h"

typedef enum{
    TIMER0_NORMAL = 0,
    TIMER0_PWM_PHASE_CORRECT = 1,
    TIMER0_CTC = 2,
    TIMER0_FAST_PWM = 3,
}Timer_ModeType;







typedef enum
{
    NO_CLK_, F_CPU_1_, F_CPU_8_, F_CPU_64_, F_CPU_256_, F_CPU_1024_
}TIMER_CLK_SELECT;







typedef enum
{
	Normal_OC_Disconnected,
	Toggle_OCx,
	Clear_OCx,
	Non_inverting=2,
	Set_OCx,
	Inverting=3,

}Compare_Output_Mode_t;

typedef struct
{
	Timer_ModeType mode;
	TIMER_CLK_SELECT prescalar;
	Compare_Output_Mode_t signal_output;
	uint16 reload_value;
	uint16 compare_value;

}Timer_Config;






/* Function ProtoType */
void Timer_Init(Timer_Config *Config_ptr);
void Timer_start(Timer_Config *Config_ptr);
void Timer_stop();
void EnableInt(	Timer_Config *Config_ptr,void(*fnptr)(void));
void setFastPWM(uint8 duty,Compare_Output_Mode_t SignalOutput);
void DisableInt();

void setphaseCorrectPWM(uint8 duty);
void Timer0_setCallBack(void(*a_ptr)(void));

void Timer_setDelayTimeMilliSec(uint16 milliseconds,Timer_Config *Config_ptr);



#endif /* INC_TIMER_INTERFACE_H_ */
