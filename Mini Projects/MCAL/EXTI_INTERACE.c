/******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: EXTI_INTERFACE.c
 *
 * Description: Source file for EXTI
 *
 * Author: Remon Gerges
 *
 *******************************************************************************/

#include "EXTI_Private.h"

#include "EXTI_INTERACE.h"


/*******************************************************************************
 *                      		Global Variables                                   *
 *******************************************************************************/

void (* g_EXT_INT_POINTERS [3]) (void) ;

/**================================================================
 * @Fn				-MCAL_EXTI_INIT
 * @brief 			-this is used to inialize EXTI and specify the Mask/Trigger Condition and IRQ CallBack
 * @param [in]   	-EXTI_Config set by @ref EXTI_define, EXTI_Trigger_define
 * @retval 			-ErrorSate if (E_OK or E_NOK if the CONFIG PTR is NULL
 * Note				-We use ENABLE_GIC() to Enable the SREG REGISTERS
 */
ErrorState_t MCAL_EXTI_INIT(EXTI_CONFIG_t* EXTI_Config)
{
	if (EXTI_Config == NULL_PTR)
	{
		return E_NOK;
	}
	else
	{
		// Enable Global Interrupt
		ENABLE_GIE();

		//Enable Interrupt For the Choosen INTx
		SET_BIT(EXTI_BASE->GICR_Reg.Reg, EXTI_Config->external_number);

		/*
		 * Switch on the nmber of the intterrput to writing on the related reg and
		 * Puts the call back function in the related index
		 */
		switch (EXTI_Config->external_number)
		{
		case EXTI_NUM_0:
			EXTI_BASE->MCUCR_Reg.Reg &= ~(INT0_MASK);
			EXTI_BASE->MCUCR_Reg.Reg |= EXTI_Config->trigger_edge;
			g_EXT_INT_POINTERS[0]  = EXTI_Config->P_IRQ_CallBack;
			break;
		case EXTI_NUM_1:
			EXTI_BASE->MCUCR_Reg.Reg &= (INT1_MASK);
			EXTI_BASE->MCUCR_Reg.Reg |= (EXTI_Config->trigger_edge)<<2 ;
			g_EXT_INT_POINTERS[1]  = EXTI_Config->P_IRQ_CallBack;

			break;
		case EXTI_NUM_2:
			EXTI_BASE->MCUCSR_Reg.Reg &= (INT2_MASK);
			EXTI_BASE->MCUCSR_Reg.Reg |= (EXTI_Config->trigger_edge - 2)<<6;
			g_EXT_INT_POINTERS[2]  = EXTI_Config->P_IRQ_CallBack;
			break;

		}
	}
	return E_OK;
}



/**================================================================
 * @Fn					-MCAL_EXTI_DeInit
 * @brief 				-reset  EXTI Registers
 * param [in]			- Number of the External interrupt
 * @retval 				-ErrorState_t
 * Note					-none
 */
ErrorState_t MCAL_EXTI_DeInit (EXTI_CONFIG_t* EXTI_Config)
{
	if (EXTI_Config == NULL_PTR)
	{
		return E_NOK;
	}
	else
	{
		switch(EXTI_Config->external_number)
		{
		case EXTI_NUM_0:

			CLR_BIT(EXTI_BASE->GICR_Reg.Reg,EXTI_Config->external_number);
			break;
		case EXTI_NUM_1:

			CLR_BIT(EXTI_BASE->GICR_Reg.Reg,EXTI_Config->external_number);
			break;

		case EXTI_NUM_2:

			CLR_BIT(EXTI_BASE->GICR_Reg.Reg,EXTI_Config->external_number);
			break;


		}
	}
	return E_OK;
}


/*******************************************************************************
 *                      		ISR Functions                                   *
 *******************************************************************************/

void __vector_1 (void)
{
	//CLEAR THE FLAG
	CLR_BIT(EXTI_BASE->GICR_Reg.Reg,EXTI_NUM_0);

	//CALL IRQ_CALL
	g_EXT_INT_POINTERS[0]();
}

void __vector_2 (void)
{
	//CLEAR THE FLAG
	CLR_BIT(EXTI_BASE->GICR_Reg.Reg,EXTI_NUM_1);

	//CALL IRQ_CALL
	g_EXT_INT_POINTERS[1]();
}


void __vector_3 (void)
{
	//CLEAR THE FLAG
	CLR_BIT(EXTI_BASE->GICR_Reg.Reg,EXTI_NUM_2);

	//CALL IRQ_CALL
	g_EXT_INT_POINTERS[2]();
}

