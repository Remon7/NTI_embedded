/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: remon
 */

#include "MCAL/inc/Dio.h"
#include "HAL/inc/segment7_driver.h"
#include "HAL/inc/keypad.h"
#include "HAL/inc/LCD.h"
#include "util/delay.h"
#include "MCAL/inc/ADC.h"
#include "MCAL/inc/timer0.h"
#include "MCAL/inc/timer1.h"
#include "MCAL/inc/USART.h"
#include "MCAL/inc/SPI.h"
#include "MCAL/inc/TWI.h"
#include "HAL/inc/EEPROM.h"

extern  ADC_ConfigType ADC_config;
extern	TIM0_ConfigType TIM0_config;
extern	TIM1_ConfigType TIM1_config;
extern	SPI_ConfigType SPI_config;
/*


void DIO_main()
{
	DIO_voidSetPinDirection(PORTA_BASE,6,OUTPUT);

	while(1)
	{
		DIO_voidSetPinValue(PORTA_BASE,6,OUTPUT);
	}
}


void SEG7_main()
{
	SevenSeg_Init();

	while(1)
	{
		for(int i=0;i<10;i++)
		{
			DIO_voidSetPinValue(PORTA_BASE,PIN2,LOGIC_LOW);
			SevenSeg_Num(i);
			for(int j=0;i<10;j++)
			{
				DIO_voidSetPinValue(PORTA_BASE,PIN3,LOGIC_LOW);
				SevenSeg_Num(j);
				_delay_ms(1000);

			}
		}


	}
}


void KEYPAD_main()
{
	SevenSeg_Init();
	uint8 key=0;
	while(1)
	{
		key= Keypad_getPressedKey();
		if((key >= 0) && (key <= 9))
		{
			SevenSeg_Num(key);
		}

	}
}

void LCD_main()
{
	H_LCD_void_Init();
	H_LCD_void_sendString("Remon");
	H_LCD_void_sendIntNum(741);
	while(1)
	{

	}
}


void ADC_main()
{
	uint16 ADC_res;
	H_LCD_void_Init();
	ADC_Init(&ADC_config);
	H_LCD_void_sendString("START ADC");
	_delay_ms(5000);
	H_LCD_void_sendCommand(LCD_CLEAR_COMMAND);
	while(1)
	{
		ADC_res=ADC_getDigitalValueSynchNonBlocking(&ADC_config);
		H_LCD_void_sendIntNum(ADC_res);
		_delay_ms(1000);
		H_LCD_void_sendCommand(LCD_CLEAR_COMMAND);
	}
}
 */

/*static gTick=0;

void Tim0_Task()
{

}
void TIM0_main()
{
	DIO_voidSetPinDirection(PORTB_BASE,3,OUTPUT);
	Timer0_Init(&TIM0_config);
	uint8 key;
	uint8 duty=90;
	Timer0_setFastPWM(duty,&TIM0_config);
	while(1)
	{
		key= Keypad_getPressedKey();
		if(key == '+')
		{
			duty = duty +10;
			Timer0_setFastPWM(duty,&TIM0_config);
			_delay_ms(50);
		}
		if(key == '-')
		{
			duty = duty -10;
			Timer0_setFastPWM(duty,&TIM0_config);
			_delay_ms(50);
		}
	}
}*/

/*
static uint8 gTick=0;

void Tim1_Task()
{
	gTick++;
	if(gTick == 1)
	{
		DIO_voidSetPinValue(PORTA_BASE,5,LOGIC_LOW);
		_delay_ms(5000);
	}
}
void TIM1_main()
{
	Timer1_Init(&TIM1_config);
	Timer1_EnableInt(&TIM1_config,Tim1_Task);
	DIO_voidSetPinDirection(PORTA_BASE,5,OUTPUT);
	while(1)
	{
		DIO_voidSetPinValue(PORTA_BASE,5,LOGIC_HIGH);

	}
}*/

/*
static volatile uint8 counter=0;

static uint8 edge_count = 0;
static uint8 gHigh =0;
static uint8 Total =0;

void ICU_CALLBACK(void)
{
	DIO_voidSetPinDirection(PORTA_BASE, PIN4, OUTPUT);
	DIO_voidSetPinDirection(PORTA_BASE, PIN5, OUTPUT);
	DIO_voidSetPinDirection(PORTA_BASE, PIN6, OUTPUT);


	edge_count++ ;
	if(edge_count == 1)
	{

	}


	else if (edge_count ==2)
	{


	}

	else if (edge_count ==3)
	{


	}
}

void OVF_CALLBACK()
{
	counter ++;
	DIO_voidSetPinDirection(PORTA_BASE, PIN5, OUTPUT);

}


void ICU_main()
{
	DIO_voidSetPinDirection(PORTB_BASE, PIN3, OUTPUT);
	DIO_voidSetPinDirection(PORTD_BASE, PIN6, INPUT);

	Timer1_Init(&TIM1_config);
	Timer1_EnableInt(&TIM1_config,OVF_CALLBACK);

	Timer1_ICU_SetTrig(RISING);
	Timer1_ICU_EnableInt(ICU_CALLBACK);

	Timer0_Init(&TIM0_config);
	uint8 duty=50;
	Timer0_setFastPWM(duty,&TIM0_config);

	H_LCD_void_Init();
	float time=0;
	time = abs(((65535-reading1)*100)/65535 );
	H_LCD_void_sendIntNum(time);

	while(1)
	{


	}
}
 */

/*void UART_main()
{
	UART_init();
	UART_sendString("REMON#");
	while(1)
	{

	}
}*/


/*void SPI_main()
{
	DIO_voidSetPinDirection(PORTB_BASE,PIN4,INPUT);
	DIO_voidSetPinDirection(PORTB_BASE,PIN5,INPUT);
	DIO_voidSetPinDirection(PORTB_BASE,PIN6,OUTPUT);
	DIO_voidSetPinDirection(PORTB_BASE,PIN7,INPUT);
	SevenSeg_Init();


	uint8 data;

	SPI_Init(&SPI_config);

	while(1)
	{
		data = SPI_sendReceiveByte(2);
		SevenSeg_Num(data);
	}
}*/


void main()
{
	uint8 value =0;

	SevenSeg_Init();
	H_LCD_void_Init();

	EEPROM_Init();
	EEPROM_WriteByte(0, 2);
	_delay_ms(10);
	EEPROM_ReadByte(0, &value);
	SevenSeg_Num(value);

	H_LCD_void_sendIntNum(value);
	while(1)
	{
	}
}
