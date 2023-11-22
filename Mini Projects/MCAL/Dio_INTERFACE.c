/******************************************************************************
 *
 * Module: DIO
 *
 * File Name: Dio.c
 *
 * Description: Source file for the AVR GPIO driver ATMEGA32
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

#include <Dio_INTERFACE.h>



/**================================================================
 * @Fn					-DIO_voidSetPinDirection
 * @brief 				-Specifies The direction of the Pin
 * @param [in] 			-Port_Def* ptr: where ptr can be (A..D depending on device used) to select the GPIO peripheral
 *@param [in] 			-Copy_u8PinId:  specifies the port bit to Make direction. Set by @ref GPIO_PINS_define
 *@param [in] 			-Value: Pin Value
 * @retval 			-none
 * Note				-none
 */
void DIO_voidSetPinDirection(Port_Def* ptr,Pin_ID_t Copy_u8PinId,Pin_Direction_t Copy_u8Direction)
{

	switch (Copy_u8PinId)
	{
	case 0:
		ptr->DDR.Bitfield.B0=Copy_u8Direction;
		break;
	case 1:
		ptr->DDR.Bitfield.B1=Copy_u8Direction;
		break;
	case 2:
		ptr->DDR.Bitfield.B2=Copy_u8Direction;
		break;
	case 3:
		ptr->DDR.Bitfield.B3=Copy_u8Direction;
		break;
	case 4:
		ptr->DDR.Bitfield.B4=Copy_u8Direction;
		break;
	case 5:
		ptr->DDR.Bitfield.B5=Copy_u8Direction;
		break;
	case 6:
		ptr->DDR.Bitfield.B6=Copy_u8Direction;
		break;
	case 7:
		ptr->DDR.Bitfield.B7=Copy_u8Direction;
		break;

	}
}


/**================================================================
 * @Fn					-DIO_voidSetPinValue
 * @brief 				-write on specific input pin
 * @param [in] 			-ptr: where ptr can be (A..D depending on device used) to select the GPIO peripheral
 *@param [in] 			-Copy_u8PinId:  specifies the port bit to read. Set by @ref GPIO_PINS_define
 *@param [in] 			-Copy_u8Value: Pin Value
 * @retval 			-none
 * Note				-none
 */
void DIO_voidSetPinValue(Port_Def* ptr,Pin_ID_t Copy_u8PinId, PIN_VALUE_t Copy_u8Value)
{

	switch (Copy_u8PinId)
	{
	case 0:
		ptr->PORT.Bitfield.B0=Copy_u8Value;
		break;
	case 1:
		ptr->PORT.Bitfield.B1=Copy_u8Value;
		break;
	case 2:
		ptr->PORT.Bitfield.B2=Copy_u8Value;
		break;
	case 3:
		ptr->PORT.Bitfield.B3=Copy_u8Value;
		break;
	case 4:
		ptr->PORT.Bitfield.B4=Copy_u8Value;
		break;
	case 5:
		ptr->PORT.Bitfield.B5=Copy_u8Value;
		break;
	case 6:
		ptr->PORT.Bitfield.B6=Copy_u8Value;
		break;
	case 7:
		ptr->PORT.Bitfield.B7=Copy_u8Value;
		break;

	}
}




/**================================================================
 * @Fn				-DIO_voidGetPinValue
 * @brief 			-Read Specific PIN
 * @param [in] 		-ptr: where x can be (A..D depending on device used) to select the GPIO peripheral
 * @param [in] 		-Copy_u8PinId: Set Pin Number according @ref GPIO_PINS_define
 * @retval
 * Note				-none
 */

uint8 DIO_voidGetPinValue(Port_Def* ptr,Pin_ID_t Copy_u8PinId)
{
	uint8 value=0;

	switch (Copy_u8PinId)
	{
	case 0:
		value=ptr->Pin.Bitfield.B0;
		break;
	case 1:
		value=ptr->Pin.Bitfield.B1;
		break;
	case 2:
		value=ptr->Pin.Bitfield.B2;
		break;
	case 3:
		value=ptr->Pin.Bitfield.B3;
		break;
	case 4:
		value=ptr->Pin.Bitfield.B4;
		break;
	case 5:
		value=ptr->Pin.Bitfield.B5;
		break;
	case 6:
		value=ptr->Pin.Bitfield.B6;
		break;
	case 7:
		value=ptr->Pin.Bitfield.B7;
		break;
	}

	return value;
}


/**================================================================
 * @Fn					-DIO_voidSetPortDirection
 * @brief 				-Specifies The direction of the Pin
 * @param [in] 			-Port_Def* ptr: where ptr can be (A..D depending on device used) to select the GPIO peripheral
 *@param [in] 			-Copy_u8Direction:  specifies the port bit to Make direction. Set by @ref GPIO_PORT_Value
 * @retval 			-none
 * Note				-none
 */
void DIO_voidSetPortDirection(Port_Def* ptr,Port_Direction_t Copy_u8Direction)
{
	ptr->DDR.Reg=Copy_u8Direction;
}



/**================================================================
 * @Fn					-DIO_voidSetPortValue
 * @brief 				-write on output port
 * @param [in] 			-ptr: where ptr can be (A..D depending on device used) to select the GPIO peripheral
 *
 * @retval 				-none
 * Note					-none
 */
void DIO_voidSetPortValue(Port_Def* ptr,PORT_VALUE_t Copy_u8Value)
{
	ptr->PORT.Reg=Copy_u8Value;
}



uint8 DIO_voidGetPortValue(Port_Def* ptr)
{
	return ptr->Pin.Reg;
}

