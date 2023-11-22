/*
 * OS.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Remon Gerges
 */


///// SMALL OS

#include "Dio_INTERFACE.h"
#include "Timer_INTERFACE.h"
#include "LED_INTERFACING.h"
#include "Button.h"
#include "GIC.h"



#define RED_LED_PIN   6
#define BLUE_LED_PIN  5
#define GREEN_LED_PIN 4
#define PB1_PIN       3


// Define time intervals for each task in milliseconds
#define Red_INTERVAL 30
#define Green_INTERVAL 91
#define Blue_INTERVAL 5


typedef void (*TaskFunction)();



// Structure to represent a task control block
typedef struct {
	TaskFunction task_ptr; 					//Pointer to the task Function
	uint16_t interval;						//Required Number for OverFlows
	uint16_t ticks;          				// Number for OverFlows
} TaskControlBlock;


// Define task functions
void task1();
void task2();
void task3();


// Initialize task control blocks
TaskControlBlock tasks[] =
{
		{task2, Blue_INTERVAL},    			 //Blue Led Task
		{task1, Red_INTERVAL},				 //Red Led Task
		{task3, Green_INTERVAL}			   		//Green Led Task
};


// Initialize Timer0 With Overflo
Timer_Config timer0 = {TIMER0_NORMAL,F_CPU_1024_,0};


// LED control functions
void initLEDs()
{
	// Configure LED pins as output
	DIO_voidSetPortDirection(GPIOA_BASE, PORT_OUTPUT);
}




// Task functions
void task1()
{
	TOGGLE_BIT(	GPIOA_BASE->PORT.Reg,RED_LED_PIN);
}

void task2() {


	if (Single_press(GPIOD_BASE, PB1_PIN) == pressed)

	{
		TOGGLE_BIT(GPIOA_BASE->PORT.Reg,BLUE_LED_PIN);
	}
}

void task3() {
	TOGGLE_BIT(	GPIOA_BASE->PORT.Reg,GREEN_LED_PIN);
}




uint32_t task1_counter = 0, task2_counter = 0, task3_counter = 0;




void Runnable_Task(void) {
    // Loop through tasks and update based on counter values

    // Task 2 has the highest priority
    task2_counter++;
    if (task2_counter >= Blue_INTERVAL) {
        task2(); // Execute task 2
        task2_counter = 0; // Reset counter
    }

    // Tasks 1 and 3 follow
    for (uint8_t i = 0; i < 3; i++) {
        if (i == 0 && i != 1) {
            task1_counter++;
            if (task1_counter >= Red_INTERVAL) {
                task1(); // Execute task 1
                task1_counter = 0; // Reset counter
            }
        } else if (i == 2 && i != 1) {
            task3_counter++;
            if (task3_counter >= Green_INTERVAL) {
                task3(); // Execute task 3
                task3_counter = 0; // Reset counter
            }
        }
    }
}
void TIMER_INIT()
{
	Timer_Init(&timer0);
	EnableInt(&timer0,Runnable_Task);
}



int main()
{
	ENABLE_GIE();
	H_LCD_void_IniT();
	initLEDs();
	// Initialize the intervals for each task
	tasks[0].interval = Blue_INTERVAL; // Blue interval 30
	tasks[1].interval = Red_INTERVAL; // Red 15 one second
	tasks[2].interval = Green_INTERVAL; // Task 3: GREEN LED every 3 sec


	TIMER_INIT();


	while(1)
	{




	}

}

