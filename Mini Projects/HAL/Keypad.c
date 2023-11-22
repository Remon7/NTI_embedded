/******************************************************************************
 *
 * Module: Keypad
 *
 * File Name: Kepad.c
 *
 * Description: Source file for Keypad
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

#include "Keypad.h"



/**================================================================
 * @Fn					-KEYPAD_INIT
 * @brief 				-Intialize the pins for Keypad
 * @param [in] 			-none
 * @retval 				-ERROR_STATUS if the Intilization is Successed or not (E_OK, E_NOK)
 * Note					-none
 */
ErrorState_t KEYPAD_INIT()
{

	DIO_voidSetPinDirection(COL_PORT, C1_PIN, PIN_INPUT);
	DIO_voidSetPinDirection(COL_PORT, C2_PIN, PIN_INPUT);
	DIO_voidSetPinDirection(COL_PORT, C3_PIN, PIN_INPUT);

	DIO_voidSetPinDirection(COL_PORT, C4_PIN, PIN_INPUT);

	DIO_voidSetPinDirection(ROW_PORT, R4_PIN, Pin_OUTPUT);
	DIO_voidSetPinDirection(ROW_PORT, R3_PIN, Pin_OUTPUT);
	DIO_voidSetPinDirection(ROW_PORT, R2_PIN, Pin_OUTPUT);

	DIO_voidSetPinDirection(ROW_PORT, R1_PIN, Pin_OUTPUT);



	return E_OK;
}

/**================================================================
 * @Fn					-KEYPAD_INIT
 * @brief 				-Intialize the pins for Keypad
 * @param [in] 			-none
 * @retval 				-The Key Pressed (uint8_t)
 * Note					-This Function Use the Single press api to avoid debouncing also make sure
 * 						 that the press is a single press
 */
uint8_t KEYPAD_Get_Pressed_Key(void)
{
	uint8_t  i,j;
	uint8_t rows[]={R4_PIN,R3_PIN,R2_PIN,R1_PIN};
	uint8_t cols[]={C1_PIN,C2_PIN,C3_PIN,C4_PIN};

	uint8_t KEYPAD_ARR[4][4] = KEYPAD;
	uint8_t key = 0;

	uint8_t flag;
	while(1)
	{
		for(i = 0; i <=4; i++)
		{
			DIO_voidSetPinValue(ROW_PORT, rows[i], LOW);

			for(j = 0; j <=4; j++)
			{
				flag = Single_press(COL_PORT, cols[j]);
				if(flag == pressed)
				{
					key = KEYPAD_ARR[i][j];
					return key;

				}

			}
			DIO_voidSetPinValue(ROW_PORT, rows[i], HIGH);
			_delay_ms(10);


		}
		//return key;
	}
}
//enum KeypadState {
//    IDLE,
//    WAIT_FOR_PRESS,
//    WAIT_FOR_RELEASE
//};
//
//uint8_t KEYPAD_Get_Pressed_Key(void)
//{
//    uint8_t i, j;
//    uint8_t rows[] = {R1_PIN, R2_PIN, R3_PIN, R4_PIN};
//    uint8_t cols[] = {C1_PIN, C2_PIN, C3_PIN, C4_PIN};
//    uint8_t KEYPAD_ARR[4][4] = KEYPAD;
//    uint8_t key = '\0';
//
//    static enum KeypadState state = IDLE;
//    static uint8_t currentKey;
//
//    for (i = 0; i < 4; i++)
//    {
//        DIO_voidSetPinValue(ROW_PORT, rows[i], LOW);
//
//        for (j = 0; j < 4; j++)
//        {
//            switch (state)
//            {
//            case IDLE:
//                if (Single_press(COL_PORT, cols[j]) == pressed)
//                {
//                    currentKey = KEYPAD_ARR[i][j];
//                    state = WAIT_FOR_RELEASE;
//                }
//                break;
//
//            case WAIT_FOR_RELEASE:
//                if (Single_press(COL_PORT, cols[j]) == released)
//                {
//                    key = currentKey;
//                    state = IDLE;
//                    return key;
//                }
//                break;
//
//            default:
//                // Handle other states if needed
//                break;
//            }
//        }
//
//        DIO_voidSetPinValue(ROW_PORT, rows[i], HIGH);
//        _delay_ms(15);
//    }
//
//    return key; // Return key even if no key is pressed
//}
