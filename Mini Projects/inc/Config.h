/******************************************************************************
 *
 * Module: Application
 *
 * File Name: Config.h
 *
 * Description: Header file For all Configuration Parameters
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/


#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

/*******************************************************************************
 *                      Types Declaration                                    *
 *******************************************************************************/

typedef enum{

E_OK,E_NOK
}ErrorState_t;


///////////////////////////////////////////////////////////////////////
///////////////////////// Pins Configuration ////////////////////////////////
//////////////////////////////////////////////////////////////////////
//@ref GPIO_PINS_define
typedef enum
{
	PIN0_ID,
	PIN1_ID,
	PIN2_ID,
	PIN3_ID,
	PIN4_ID,
	PIN5_ID,
	PIN6_ID,
	PIN7_ID,
}Pin_ID_t;





/*******************************************************************************
 *                      Configuration                                   *
 *******************************************************************************/





//////////////////////////////////////////////////////////////////////
///////////////////////// DEFINING LCD PINS////////////////////////////////
//////////////////////////////////////////////////////////////////////
#define		LCD_RS_PIN				PIN4_ID
#define		LCD_EN_PIN				PIN2_ID
#define		LCD_D4_PIN				PIN0_ID
#define		LCD_D5_PIN				PIN1_ID
#define		LCD_D6_PIN				PIN2_ID
#define		LCD_D7_PIN				PIN4_ID
//////////////////////////////////////////////////////////////////////
///////////////////////// DEFINING LCD Port////////////////////////////////
//////////////////////////////////////////////////////////////////////
#define		LCD_CONTROL_PORT		GPIOA_BASE
#define		LCD_DATA_PORT			GPIOB_BASE




///////////////////////////////////////////////////////////////////////
///////////////////////// KeyPad Configuration ////////////////////////////////
//////////////////////////////////////////////////////////////////////
/*Keypad Row Pins and Ports configuration*/
#define ROW_PORT				GPIOC_BASE
#define R1_PIN					PIN5_ID
#define R2_PIN					PIN4_ID
#define R3_PIN					PIN3_ID
#define R4_PIN					PIN2_ID

/*Keypad COL Pins and Ports configuration*/
#define COL_PORT				GPIOD_BASE
#define C1_PIN					PIN7_ID
#define C2_PIN					PIN6_ID
#define C3_PIN					PIN5_ID
#define C4_PIN					PIN3_ID


/* Keypad Types*/
#define KEYPAD_ARR1				{{1,2,3,'A'},{4,5,6,'B'},{7,8,9,'C'},{'*',0,'#','D'}}
#define KEYPAD_ARR3				{{1,2,3,'A'},{4,5,6,'B'},{7,8,9,'C'},{'*',0,'#','D'}}

#define KEYPAD_CALC        {{'7','8','9','/'},\
					   	   {'4','5','6','*'},\
						   {'1','2','3','-'},\
						   {'A','0','=','+'}}
/* Keypad Type Configuration */
#define KEYPAD					KEYPAD_CALC



//////////////////////////////////////////////////////////////////////
///////////////////////// DEFINING SPI PINS////////////////////////////////
//////////////////////////////////////////////////////////////////////
#define Slave_Select_Port			GPIOB_BASE
#define Slave_Select_Pin			PIN4_ID


#define MOSI_Port					GPIOB_BASE
#define MOSI_Pin					PIN5_ID

#define MISO_Port					GPIOB_BASE
#define MISO_Pin					PIN6_ID

#define SCK_Port					GPIOB_BASE
#define SCK_Pin						PIN7_ID





//////////////////////////////////////////////////////////////////////
///////////////////////// DEFINING LCD MODE////////////////////////////////
//////////////////////////////////////////////////////////////////////
#define _8_BIT_MODE                   8
#define _4_BIT_MODE                   4

//////////////////////////////////////////////////////////////////////
///////////////////////// Configure Mode DEFINING LCD MODE////////////////////////////////
//////////////////////////////////////////////////////////////////////

#define MODE 						_4_BIT_MODE



//////////////////////////////////////////////////////////////////////
///////////////////////// BaudRate Configuration////////////////////////////////
//////////////////////////////////////////////////////////////////////

#define BAUD_RATE_NUMBER				9600
#define BAUD_RATE						BAUD_RATE_NUMBER



#endif /* INC_CONFIG_H_ */
