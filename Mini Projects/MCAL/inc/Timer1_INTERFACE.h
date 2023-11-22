/*
 * Timer1_INTERFACE.h
 *
 *
 *      Author: Remon Gerges
 */

#ifndef INC_TIMER1_INTERFACE_H_
#define INC_TIMER1_INTERFACE_H_
#include "MCU_HW.h"


/*
 * Modes of Timer 1 To be choosen in the configuration Parameter
 */

typedef enum
{
	TIMER1_NORMAL = 0,
	TIMER1_PWM_PHASE_CORRECT_8BIT = 1,
	TIMER1_PWM_PHASE_CORRECT_9BIT = 2,
	TIMER1_PWM_PHASE_CORRECT_10BIT = 3,
	TIMER1_CTC_OCR = 4,
	TIMER1_FAST_PWM_8BIT = 5,
	TIMER1_FAST_PWM_9BIT = 6,
	TIMER1_FAST_PWM_10BIT = 7,
	TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR = 8,
	TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR = 9,
	TIMER1_PWM_PHASE_CORRECT_ICR = 10,
	TIMER1_PWM_PHASE_CORRECT_OCR = 11,
	TIMER1_CTC_ICR = 12,
	TIMER1_FAST_PWM_ICR = 14,
	TIMER1_FAST_PWM_OCR = 15
}Timer1_Modes_t;

/*
 * Choosing The Prescalar for Timer1
 */
typedef enum
{
    NO_CLK__, F_CPU_1__, F_CPU_8__, F_CPU_64__, F_CPU_256__, F_CPU_1024__
}TIMER1_CLK_SELECT;


/*
 * To Choose what type of o/p wave you want to generate on OCx
 */
typedef enum
{
	Timer1_Normal_OC_Disconnected,
	Timer1_Toggle_OCx,
	Timer1_Clear_OCx,
	Timer1_Non_inverting=2,
	Timer1_Set_OCx,
	Timer1_Inverting=3,

}Timer1_Compare_Output_Mode_t;



/*
 * For switching Between Channels in Timer1 Registers
 */
typedef enum
{
	ChannelA,ChannelB
}Timer1_Channel;



typedef enum
{
	FALLING,RISING
}Icu_EdgeType;



typedef struct
{
	Icu_EdgeType edge;
	TIMER1_CLK_SELECT prescalar;
}Icu_ConfigType;


typedef struct
{
	Timer1_Modes_t mode;
	TIMER1_CLK_SELECT prescalar;
	Timer1_Compare_Output_Mode_t signal_output;
	uint16 reload_value;
	uint16 compare_value;
	Timer1_Channel Channels;
}Timer1_Config;


/*
 * Function ProtoTypes
 */
void MCAL_Timer1_Init(Timer1_Config *Config_ptr);
void MCAL_Timer1_EnableInt(Timer1_Config *Config_ptr,void(*Ptr2Func)(void));
void MCAL_Timer1_ICU_Init(Icu_ConfigType* Config_ptr);
void MCAL_Timer1_ICU_setCallBack(void(*a_ptr)(void));
void MCAL_Timer1_setCallBack(void(*a_ptr)(void));
void MCAL_Timer1_ICU_clearTimerValue(void);
uint16 MCAL_Timer1_ICU_getInputCaptureValue(void);
void MCAL_Timer1_ICU_setEdgeDetectionType(const Icu_EdgeType a_edgeType);
void MCAL_Timer1_ICU_DeInit(void);

#endif /* INC_TIMER1_INTERFACE_H_ */
