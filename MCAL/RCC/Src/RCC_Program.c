/*
 ******************************************************************************
 * @file           : RCC_Program.c
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : Main program body
 * @Date           : May 4, 2023
 * @Target         : STM32F446xx
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 *
 ******************************************************************************
 */


/*==============================================================================================================================================
 * INCLUDES SECTION START
 *==============================================================================================================================================*/
#include <stdint.h>

#include "../../../LIB/STM32F446xx.h"
#include "../../../LIB/ErrType.h"

#include "../Inc/RCC_Interface.h"
#include "../Inc/RCC_Private.h"

/*==============================================================================================================================================
 * INCLUDES SECTION END
 *==============================================================================================================================================*/



/*==============================================================================================================================================
 * MODULES IMPLEMENTATION
 *==============================================================================================================================================*/

/**
 * @fn	  : RCC_SetCLKStatus
 * @brief : Select a Certain Clock and Enable it or Disable it
 * @param : CLK_Type_t -> Clock Type From Enum ( @CLK_Type_t ) => HSI ,	PLLSAI , PLLI2S , MainPLL , HSE
 * @param : CLK_State_t -> State of Clock ON or OFF From Enum( @CLK_State_t ) => ON , OFF
 * @retval: Error Status  that Return Errors Dependening on Type of Error
 *                 -> OK , TIME_OUT_ERROR , CLK_STATE_ERROR , CLK_TYPE_ERROR
 * @note	  : IF you are using PLL or HSE Clock you must Set the Configuration of the Clock First Before Enabling it ( Using this Function )
 **/

ERRORS_t RCC_SetCLKStatus( CLK_Type_t Copy_eClockType , CLK_State_t Copy_eClockState )
{
	/* Enum Type Variable to Carry Error Status */
	ERRORS_t ErrorStatus = OK ;

	/* uint16_t Variable to Implement Timeout Methodology */
	uint16_t TIME_OUT_VALUE = 0 ;

	switch( Copy_eClockType )
	{
	case HSI :
		if( Copy_eClockState == ON )
		{
			/* Enable HSI */
			(RCC -> CR) |= ( 1 << CR_HSION ) ;

			/* Wait Until Clock is Ready */
			while( ( ( ( ( RCC -> CR ) >> CR_HSIRDY )&0x1 ) == 0 ) && ( TIME_OUT_VALUE < TIMOUT_MAX ) )
			{
				/* Increment Timeout Value  */
				TIME_OUT_VALUE ++ ;
			}

			/* Check if Loop is Broken Because Timeout Max Value is Reached OR
			 * Ready Flag is Set */
			if( TIME_OUT_VALUE == TIMOUT_MAX )
			{
				/* Loop is Broken Because Timout Max Value is Reached */
				ErrorStatus = TIME_OUT_ERROR ;
			}
		}
		else if( Copy_eClockState == OFF )
		{
			/* Disable HSI */
			(RCC -> CR) &= ( ~ ( 1 << CR_HSION ) ) ;
		}
		else
		{
			/* Clock State Wrong Configuration */
			ErrorStatus = CLK_STATE_ERROR ;
		}
		break;

	case PLLSAI :
		if( Copy_eClockState == ON )
		{
			/* Enable PLLSAI */
			(RCC -> CR) |= ( 1 << CR_PLLSAION ) ;

			/* Wait Until Clock is Ready */
			while( ( ( ( ( RCC -> CR ) >> CR_PLLSAIRDY )&0x1 ) == 0 ) && ( TIME_OUT_VALUE < TIMOUT_MAX ) )
			{
				/* Increment Timeout Value  */
				TIME_OUT_VALUE ++ ;
			}

			/* Check if Loop is Broken Because Timeout Max Value is Reached OR
			 * Ready Flag is Set */
			if( TIME_OUT_VALUE == TIMOUT_MAX )
			{
				/* Loop is Broken Because Timout Max Value is Reached */
				ErrorStatus = TIME_OUT_ERROR ;
			}
		}
		else if( Copy_eClockState == OFF )
		{
			/* Disable PLLSAI */
			(RCC -> CR) &= ( ~ ( 1 << CR_PLLSAION ) ) ;
		}
		else
		{
			/* Clock State Wrong Configuration */
			ErrorStatus = CLK_STATE_ERROR ;
		}
		break;

	case PLLI2S :
		if( Copy_eClockState == ON )
		{
			/* Enable PLLI2S */
			(RCC -> CR) |= ( 1 << CR_PLLI2SON ) ;

			/* Wait Until Clock is Ready */
			while( ( ( ( ( RCC -> CR ) >> CR_PLLI2SRDY )&0x1 ) == 0 ) && ( TIME_OUT_VALUE < TIMOUT_MAX ) )
			{
				/* Increment Timeout Value  */
				TIME_OUT_VALUE ++ ;
			}
			/* Check if Loop is Broken Because Timeout Max Value is Reached OR
						 * Ready Flag is Set */
			if( TIME_OUT_VALUE == TIMOUT_MAX )
			{
				/* Loop is Broken Because Timout Max Value is Reached */
				ErrorStatus = TIME_OUT_ERROR ;
			}
		}
		else if( Copy_eClockState == OFF )
		{
			/* Disable PLLI2S */
			(RCC -> CR) &= ( ~ ( 1 << CR_PLLI2SON ) ) ;
		}
		else
		{
			/* Clock State Wrong Configuration */
			ErrorStatus = CLK_STATE_ERROR ;
		}
		break;

	case MainPLL :
		if( Copy_eClockState == ON )
		{
			/* Enable Main PLL */
			(RCC -> CR) |= ( 1 << CR_PLLON ) ;

			/* Wait Until Clock is Ready */
			while( ( ( ( ( RCC -> CR ) >> CR_PLLRDY )&0x1 ) == 0 ) && ( TIME_OUT_VALUE < TIMOUT_MAX ) )
			{
				/* Increment Timeout Value  */
				TIME_OUT_VALUE ++ ;
			}
			/* Check if Loop is Broken Because Timeout Max Value is Reached OR
						 * Ready Flag is Set */
			if( TIME_OUT_VALUE == TIMOUT_MAX )
			{
				/* Loop is Broken Because Timout Max Value is Reached */
				ErrorStatus = TIME_OUT_ERROR ;
			}
		}
		else if( Copy_eClockState == OFF )
		{
			/* Disable Main PLL */
			(RCC -> CR) &= ( ~ ( 1 << CR_PLLON ) ) ;
		}
		else
		{
			/* Clock State Wrong Configuration */
			ErrorStatus = CLK_STATE_ERROR ;
		}
		break;

	case HSE :
		if( Copy_eClockState == ON )
		{
			/* Enable HSE */
			(RCC -> CR) |= ( 1 << CR_HSEON ) ;

			/* Wait Until Clock is Ready */
			while( ( ( ( ( RCC -> CR ) >> CR_HSERDY )&0x1 ) == 0 ) && ( TIME_OUT_VALUE < TIMOUT_MAX ) )
			{
				/* Increment Timeout Value  */
				TIME_OUT_VALUE ++ ;
			}
			/* Check if Loop is Broken Because Timeout Max Value is Reached OR
						 * Ready Flag is Set */
			if( TIME_OUT_VALUE == TIMOUT_MAX )
			{
				/* Loop is Broken Because Timout Max Value is Reached */
				ErrorStatus = TIME_OUT_ERROR ;
			}
		}
		else if( Copy_eClockState == OFF )
		{
			/* Disable HSE */
			(RCC -> CR) &= ( ~ ( 1 << CR_HSEON ) ) ;
		}
		else
		{
			/* Clock State Wrong Configuration */
			ErrorStatus = CLK_STATE_ERROR ;
		}
		break;

		/* Clock Type Wrong Confuguration */
	default : ErrorStatus = CLK_TYPE_ERROR ;
	}

	return ErrorStatus ;
}


/**
 * @fn		: RCC_SetPLLConfig
 * @brief   : Set All PLL Configurations
 * @param   : RCC_PLL_CONGIG_t * -> Pointer to Struct Contatins Enum Elements Having All PLL Configuration
 *                   1- PLLR_FACTOR => PLLR Value From PLLR_BY2 -> PLLR_BY7 ( @PLLR_t )
 *                   2- PLLQ_FACTOR => PLLQ Value From PLLQ_BY2 -> PLLQ_BY15 ( @PLLQ_t )
 *	                 3- PLL_SRC     => PLL SRC Between HSI & HSE( @PLL_SRC_t )
 *	                 4- PLLP_FACTOR => PLLP Value From PLLP_BY2 -> PLLP_BY8 ( @PLLP_t )
 *	                 5- PLLN_FACTOR => PLLN Value From PLLN_X50 -> PLLN_X432 ( @PLLN_t )
 *	                 6- PLLM_FACTOR => PLLM Value From PLLM_BY2 -> PLLM_BY63 ( @PLLM_t )
 * @retval  : Error Status  that Return Errors Dependening on Type of Error
 *                 -> PLL_SRC_ERROR , NULL_POINTER
 * @note		: Must Be Called When ALL PLLs are Disabled ( PLLSIA , PLLI2S , PLL )
 **/

ERRORS_t RCC_SetPLLConfig(const RCC_PLL_CONFIG_t * Copy_psPLLConfig )
{
	/* Enum Type Variable to Carry Error Status */
	ERRORS_t ErrorStatus = OK ;

	if( Copy_psPLLConfig != NULL )
	{
		/* Set PLLR Division Factor */
		(RCC -> PLLCFGR) &= ( PLLR_MASK ) ;
		(RCC -> PLLCFGR) |= ( ( Copy_psPLLConfig -> PLLR_FACTOR ) << PLLCFGR_PLLR ) ;

		/* Set PLLQ Division Factor */
		(RCC -> PLLCFGR) &= ( PLLQ_MASK ) ;
		(RCC -> PLLCFGR) |= ( ( Copy_psPLLConfig -> PLLQ_FACTOR ) << PLLCFGR_PLLQ ) ;

		/* Set PLLP Division Factor */
		(RCC -> PLLCFGR) &= ( PLLP_MASK ) ;
		(RCC -> PLLCFGR) |= ( ( Copy_psPLLConfig -> PLLP_FACTOR ) << PLLCFGR_PLLP ) ;

		/* Set PLLN Multiplication Factor */
		(RCC -> PLLCFGR) &= ( PLLN_MASK ) ;
		(RCC -> PLLCFGR) |= ( ( Copy_psPLLConfig -> PLLN_FACTOR ) << PLLCFGR_PLLN ) ;

		/* Set PLLM Division Factor */
		(RCC -> PLLCFGR) &= ( PLLM_MASK ) ;
		(RCC -> PLLCFGR) |= ( ( Copy_psPLLConfig -> PLLM_FACTOR ) << PLLCFGR_PLLM ) ;


		/* Set PLL Source */
		if( ( Copy_psPLLConfig -> PLL_SRC ) == HSE_SRC )
		{
			/* For HSE PLL_SRC Bit = 1 */
			(RCC -> PLLCFGR) |= ( 1 << PLLCFGR_PLLSRC ) ;
		}
		else if( Copy_psPLLConfig -> PLL_SRC == HSI_SRC )
		{
			/* For HSI PLL_SRC Bit = 0 */
			(RCC -> PLLCFGR) &= ( ~ ( 1 << PLLCFGR_PLLSRC ) ) ;
		}
		else
		{
			/* Wrong PLL_SRC Configuration */
			ErrorStatus = PLL_SRC_ERROR ;
		}
	}
	else
	{
		/* Pointer that Don't Pointer To Allocated Data */
		ErrorStatus = NULL_POINTER ;
	}
	return ErrorStatus ;
}


/**
 * @fn		: RCC_SetSysCLK
 * @brief   : Select a Certain Clock as a System Clock
 * @param   : SYS_CLK_t -> Clock Type  From enum ( @SYS_CLK_t ) => HSI_SYS_CLK , HSE_SYS_CLK , PLL_P , PLL_R
 * @retval	: Error Status that Return Errors Dependening on Type of Error
 *                 -> SYS_CLK_ERROR
 * @note	: Clock should be Ready Before Switching to it , if not Switch will not be done untill clock is ready
 **/

ERRORS_t RCC_SetSysCLK( SYS_CLK_t Copy_eCLKType )
{
	/* Enum Type Variable to Carry Error Status */
	ERRORS_t ErrorStatus = OK ;

	/* Variable To Hold Register Value */
	uint32_t CFGR_REG_VALUE = ( RCC->CFGR ) ;

	/* Check if Passed SYS_CLK is Right OR NOT */
    if( ( Copy_eCLKType >= HSI_SYS_CLK ) && ( Copy_eCLKType <= PLL_R ) )
    {
		/* Clear SW BITS & Set New SYS_CLK */
		CFGR_REG_VALUE &= ( SW_MASK ) ;
		CFGR_REG_VALUE |= ( Copy_eCLKType << CFGR_SW ) ;

		/* Write Back Variable to the Register */
	 	 ( RCC->CFGR ) = CFGR_REG_VALUE ;

    }
	return ErrorStatus ;
}


/**
 * @fn		: RCC_GetSysCLK
 * @brief	: Return Whick Clock is the SYSCLK
 * @retval	: Returns Value From Enum ( @SYS_CLK_t ) => Indicate Which Clock Source is Used as System Clock
 *                 1- HSI_SYS_CLK = 0
 *	               2- HSE_SYS_CLK = 1
 *				   3- PLL_P = 2
 *				   4- PLL_R = 3
 **/

SYS_CLK_t RCC_GetSysCLK( void )
{
	/* Variable Type Enum To Store Status of System Clock */
	SYS_CLK_t CLK_Status =  ( ( (RCC->CFGR)&SWS_MASK ) >> CFGR_SWS ) ;

	return CLK_Status ;
}


/**
 * @fn		: RCC_SetAHBPRE
 * @brief	: Set AHB Prescaler
 * @param   : Prescaler of AHB Bus From Enum ( @AHB_PRE_t )
 * @retval	: Error Status that Return Errors Dependening on Type of Error
 *                 -> AHB_PRE_ERROR
 **/

ERRORS_t RCC_SetAHBPRE( AHB_PRE_t Copy_eAHBPrescaler )
{
	/* Enum Type Variable to Carry Error Status */
	ERRORS_t ErrorStatus = OK ;

	/* Check if AHB Prescaler is Between the Right Range */
	if( ( Copy_eAHBPrescaler >= SYS_CLK_BY1 ) && ( Copy_eAHBPrescaler <= SYS_CLK_BY512 ) )
	{
		/* Clear AHB_PRE Bits & Set New AHB Prescaler  */
		(RCC -> CFGR) &= ( AHB_PRE_MASK ) ;
		(RCC -> CFGR) |= ( Copy_eAHBPrescaler << CFGR_HPRE ) ;
	}
	else
	{
		/* WRONG AHB Prescaler Configuration Option */
		ErrorStatus = AHB_PRE_ERROR ;
	}
	return ErrorStatus ;
}


/**
 * @fn		: RCC_SetAPB1PRE
 * @brief	: Set APB1 Prescaler
 * @param   : Prescaler of APB1 Bus From Enum ( @APB_PRE_t )
 * @retval	: Error Status that Return Errors Dependening on Type of Error
 *                 -> APB1_PRE_ERROR
 **/

ERRORS_t RCC_SetAPB1PRE( APB_PRE_t Copy_eAPB1Prescaler )
{
	/* Enum Type Variable to Carry Error Status */
	ERRORS_t ErrorStatus = OK ;

	/* Check if APB1 Prescaler is Between the Right Range */
	if( ( Copy_eAPB1Prescaler >= AHB_CLK_BY1 ) && ( Copy_eAPB1Prescaler <= AHB_CLK_BY16 ) )
	{
		/* Clear APB1_PRE Bits & Set New APB1 Prescaler  */
		(RCC -> CFGR) &= ( APB1_PRE_MASK ) ;
		(RCC -> CFGR) |= ( Copy_eAPB1Prescaler << CFGR_PPRE1 ) ;
	}
	else
	{
		/* WRONG APB1 Prescaler Configuration Option */
		ErrorStatus = APB1_PRE_ERROR ;
	}
	return ErrorStatus ;
}



/**
 * @fn		: RCC_SetAPB2PRE
 * @brief	: Set APB2 Prescaler Bus
 * @param   : Prescaler of APB2 Bus From Enum ( @APB_PRE_t )
 * @retval	: Error Status that Return Errors Dependening on Type of Error
 *                 -> APB2_PRE_ERROR
 **/

ERRORS_t RCC_SetAPB2PRE( APB_PRE_t Copy_eAPB2Prescaler )
{
	/* Enum Type Variable to Carry Error Status */
	ERRORS_t ErrorStatus = OK ;

	/* Check if AHB Prescaler is Between the Right Range */
	if( ( Copy_eAPB2Prescaler >= AHB_CLK_BY1 ) && ( Copy_eAPB2Prescaler <= AHB_CLK_BY16 ) )
	{
		/* Clear APB2_PRE Bits & Set New APB2 Prescaler  */
		(RCC -> CFGR) &= ( APB2_PRE_MASK ) ;
		(RCC -> CFGR) |= ( Copy_eAPB2Prescaler << CFGR_PPRE2 ) ;
	}
	else
	{
		/* WRONG APB2 Prescaler Configuration Option */
		ErrorStatus = APB2_PRE_ERROR ;
	}
	return ErrorStatus ;
}




/**
 * @fn		: RCC_HSEByPass
 * @brief	: This Function Allow you to Select if HSE is Bypassed or Not
 * @param   : Copy_eHSEConfig From Enum ( @HSE_CONFIG_t )
 *                    -> HSE_NOT_BYPASSED , HSE_BYPASSED
 * @retval	: Error Status that Return Errors Dependening on Type of Error
 *                 -> HSE_CONFIG_ERROR
 **/

ERRORS_t RCC_HSEBypass( HSE_CONFIG_t Copy_eHSEConfig )
{
	/* Enum Type Variable to Carry Error Status */
	ERRORS_t ErrorStatus = OK ;

	/* Check on HSE Config Option IF Bypassed OR NOT */
	if( Copy_eHSEConfig == HSE_NOT_BYPASSED )
	{
		/* For HSE NOT_BYPASSED -> Bit = 0 */
		(RCC -> CR) &= ( ~ ( 1 << CR_HSEBYP ) ) ;
	}
	else if( Copy_eHSEConfig == HSE_BYPASSED )
	{
		/* For HSE BYPASSED -> Bit = 1 */
		(RCC -> CR) |= ( 1 << CR_HSEBYP ) ;
	}
	else
	{
		/* Wrong HSE BYPASS Config */
		ErrorStatus = HSE_CONFIG_ERROR ;
	}
	return ErrorStatus ;
}




/**
 * @fn		: RCC_EnablePeripheral
 * @brief	: Select A Bus Interface and a Peripheral to Enable It's Clock
 * @param   : Copy_eBus From Enum ( @Peripheral_BUS_t ) => 	AHB1 ,	AHB2 ,	AHB3 ,	APB1 ,	APB2
 *
 *            Copy_ePeripheral => A Peripheral to Enable It's Peripheral Clock ( Choose Depending on the Bus you Configured First )
 *                                    From ( @AHB1_Peripheral_t , @AHB2_Peripheral_t , @AHB3_Peripheral_t , @APB1_Peripheral_t , @APB2_Peripheral_t )
 *
 *                => AHB1 Peripherals : AHB1_GPIOA , AHB1_GPIOB , AHB1_GPIOC , AHB1_GPIOD , AHB1_GPIOE , AHB1_GPIOF , AHB1_GPIOG , AHB1_GPIOH ,
 *										AHB1_CRC , AHB1_BKPSRAM , AHB1_DMA1 , AHB1_DMA2 , AHB1_OTGHS , AHB1_OTGHSULPI
 *
 *				  => AHB2 Peripherals : AHB2_DCMI , AHB2_OTGFS
 *
 *				  => AHB3 Peripherals : AHB3_FMCEN , AHB3_QSPI
 *
 *				  => APB1 Peripherals : APB1_TIM2 , APB1_TIM3 , APB1_TIM4 , APB1_TIM5 , APB1_TIM6 , APB1_TIM7 , APB1_TIM12 , APB1_TIM13 ,
 *				                        APB1_TIM14 , APB1_WWDG , APB1_SPI2 , APB1_SPI3 , APB1_SPDIFRX , APB1_USART2 , APB1_USART3 ,APB1_UART4 ,
 *				                        APB1_UART5 , APB1_I2C1 , APB1_I2C2 , APB1_I2C3 , APB1_FMPI2C1 ,	 APB1_CAN1 , APB1_CAN2 , APB1_CEC ,
 *				                        APB1_PWR , APB1_DAC
 *
 *				  => APB2 Peripherals : APB2_TIM1 ,	APB2_TIM8 ,	APB2_USART1 , APB2_USART6 ,	APB2_ADC1 ,	APB2_ADC2 ,	APB2_ADC3 ,	APB2_SDIO ,
 *				                        APB2_SPI1 ,	APB2_SPI4 ,	APB2_SYSCFG , APB2_TIM9 , APB2_TIM10 ,APB2_TIM11 , APB2_SAI1 , APB2_SAI2
 * @retval	: Error Status that Return Errors Dependening on Type of Error
 *                 -> PERIPHERAL_ENABLE_ERROR , BUS_ERROR
 * @note    : Make Sure to Choose A Peripheral From the Bus you Choose in Copy_eBus , Every Peripheral have suffix of the Bus on it , Make Sure to Read Documentation Carefully
 **/

ERRORS_t RCC_EnablePeripheral( Peripheral_BUS_t Copy_eBus , uint8_t Copy_ePeripheral  )
{
	/* Enum Type Variable to Carry Error Status */
	uint8_t ErrorStatus = OK ;

	/* Switch on Peripheral Bus : AHB1 , AHB2 , AHB3 , APB1 , APB2 */
	switch( Copy_eBus )
	{
	case AHB1 :
		/* Check if Peripheral is Between the Right Range */
		if( ( Copy_ePeripheral >= AHB1_GPIOA ) && ( Copy_ePeripheral <=AHB1_OTGHSULPI  ) )
		{
			/* Enable Required Peripheral Clock */
			(RCC -> AHB1ENR) |= ( 1 << Copy_ePeripheral ) ;
		}
		else
		{
			/* Wrong Peripheral is Passed */
			ErrorStatus = PERIPHERAL_ENABLE_ERROR ;
		}
		break ;

	case AHB2 :
		/* Check if Peripheral is One of The Two Values : AHB2_DCMI , AHB2_OTGFS */
		if( ( Copy_ePeripheral == AHB2_DCMI ) || ( Copy_ePeripheral == AHB2_OTGFS ) )
		{
			/* Enable Required Peripheral Clock */
			( RCC -> AHB2ENR ) |= ( 1 << Copy_ePeripheral ) ;
		}
		else
		{
			/* Wrong Peripheral is Passed */
			ErrorStatus = PERIPHERAL_ENABLE_ERROR ;
		}
		break ;

	case AHB3 :
		/* Check if Peripheral is One of The Two Values : AHB3_FMCEN , AHB3_QSPI */
		if( ( Copy_ePeripheral == AHB3_FMCEN ) || ( Copy_ePeripheral == AHB3_QSPI ) )
		{
			/* Enable Required Peripheral Clock */
			( RCC -> AHB3ENR ) |= ( 1 << Copy_ePeripheral ) ;
		}
		else
		{
			/* Wrong Peripheral is Passed */
			ErrorStatus = PERIPHERAL_ENABLE_ERROR ;
		}
		break ;

	case APB1 :
		/* Check if Peripheral is Between the Right Range */
		if( ( Copy_ePeripheral >= APB1_TIM2 ) && ( Copy_ePeripheral <= APB1_DAC ) )
		{
			/* Enable Required Peripheral Clock */
			(RCC -> APB1ENR) |= ( 1 << Copy_ePeripheral ) ;
		}
		else
		{
			/* Wrong Peripheral is Passed */
			ErrorStatus = PERIPHERAL_ENABLE_ERROR ;
		}
		break ;

	case APB2 :
		/* Check if Peripheral is Between the Right Range */
		if( ( Copy_ePeripheral >= APB2_TIM1 ) && ( Copy_ePeripheral <= APB2_SAI2 ) )
		{
			/* Enable Required Peripheral Clock */
			(RCC -> APB2ENR) |= ( 1 << Copy_ePeripheral ) ;
		}
		else
		{
			/* Wrong Peripheral is Passed */
			ErrorStatus = PERIPHERAL_ENABLE_ERROR ;
		}
		break ;

		/* Wrong Bus Option is Passed  */
	default : ErrorStatus = BUS_ERROR ; break ;

	}
	return ErrorStatus ;
}




/**
 * @fn		: RCC_DisablePeripheral
 * @brief	: Select A Bus Interface and a Peripheral to Disable It's Clock
 * @param   : Copy_eBus From Enum ( @Peripheral_BUS_t ) => 	AHB1 ,	AHB2 ,	AHB3 ,	APB1 ,	APB2
 *
 *            Copy_ePeripheral => A Peripheral to Disable It's Peripheral Clock ( Choose Depending on the Bus you Configured First )
 *                                    From ( @AHB1_Peripheral_t OR @AHB2_Peripheral_t OR @AHB3_Peripheral_t OR @APB1_Peripheral_t OR @APB2_Peripheral_t )
 *
 *                => AHB1 Peripherals : AHB1_GPIOA , AHB1_GPIOB , AHB1_GPIOC , AHB1_GPIOD , AHB1_GPIOE , AHB1_GPIOF , AHB1_GPIOG , AHB1_GPIOH ,
 *										AHB1_CRC , AHB1_BKPSRAM , AHB1_DMA1 , AHB1_DMA2 , AHB1_OTGHS , AHB1_OTGHSULPI
 *
 *				  => AHB2 Peripherals : AHB2_DCMI , AHB2_OTGFS
 *
 *				  => AHB3 Peripherals : AHB3_FMCEN , AHB3_QSPI
 *
 *				  => APB1 Peripherals : APB1_TIM2 , APB1_TIM3 , APB1_TIM4 , APB1_TIM5 , APB1_TIM6 , APB1_TIM7 , APB1_TIM12 , APB1_TIM13 ,
 *				                        APB1_TIM14 , APB1_WWDG , APB1_SPI2 , APB1_SPI3 , APB1_SPDIFRX , APB1_USART2 , APB1_USART3 ,APB1_UART4 ,
 *				                        APB1_UART5 , APB1_I2C1 , APB1_I2C2 , APB1_I2C3 , APB1_FMPI2C1 ,	 APB1_CAN1 , APB1_CAN2 , APB1_CEC ,
 *				                        APB1_PWR , APB1_DAC
 *
 *				  => APB2 Peripherals : APB2_TIM1 ,	APB2_TIM8 ,	APB2_USART1 , APB2_USART6 ,	APB2_ADC1 ,	APB2_ADC2 ,	APB2_ADC3 ,	APB2_SDIO ,
 *				                        APB2_SPI1 ,	APB2_SPI4 ,	APB2_SYSCFG , APB2_TIM9 , APB2_TIM10 ,APB2_TIM11 , APB2_SAI1 , APB2_SAI2
 * @retval	: Error Status that Return Errors Dependening on Type of Error
 *                 -> PERIPHERAL_DISABLE_ERROR , BUS_ERROR
 * @note    : Make Sure to Choose A Peripheral From the Bus you Choose in Copy_eBus , Every Peripheral have suffix of the Bus on it , Make Sure to Read Documentation Carefully
 **/

ERRORS_t RCC_DisablePeripheral( Peripheral_BUS_t Copy_eBus , uint8_t Copy_ePeripheral  )
{
	/* Enum Type Variable to Carry Error Status */
	ERRORS_t ErrorStatus = OK ;

	/* Switch on Peripheral Bus : AHB1 , AHB2 , AHB3 , APB1 , APB2 */
	switch( Copy_eBus )
		{
		case AHB1 :
			/* Check if Peripheral is Between the Right Range */
			if( ( Copy_ePeripheral >= AHB1_GPIOA ) && ( Copy_ePeripheral <=AHB1_OTGHSULPI  ) )
			{
				/* Disable Required Peripheral Clock */
				(RCC -> AHB1ENR) &= ( ~ ( 1 << Copy_ePeripheral ) ) ;
			}
			else
			{
				/* Wrong Peripheral is Passed */
				ErrorStatus = PERIPHERAL_DISABLE_ERROR ;
			}
			break ;

		case AHB2 :
			/* Check if Peripheral is One of The Two Values : AHB2_DCMI , AHB2_OTGFS */
			if( ( Copy_ePeripheral == AHB2_DCMI ) || ( Copy_ePeripheral == AHB2_OTGFS ) )
			{
				/* Disable Required Peripheral Clock */
				(RCC -> AHB2ENR) &= ( ~ ( 1 << Copy_ePeripheral ) ) ;
			}
			else
			{
				/* Wrong Peripheral is Passed */
				ErrorStatus = PERIPHERAL_DISABLE_ERROR ;
			}
			break ;

		case AHB3 :
			/* Check if Peripheral is One of The Two Values : AHB3_FMCEN , AHB3_QSPI */
			if( ( Copy_ePeripheral == AHB3_FMCEN ) || ( Copy_ePeripheral == AHB3_QSPI ) )
			{
				/* Disable Required Peripheral Clock */
				(RCC -> AHB3ENR) &= ( ~ ( 1 << Copy_ePeripheral ) ) ;
			}
			else
			{
				/* Wrong Peripheral is Passed */
				ErrorStatus = PERIPHERAL_DISABLE_ERROR ;
			}
			break ;

		case APB1 :
			/* Check if Peripheral is Between the Right Range */
			if( ( Copy_ePeripheral >= APB1_TIM2 ) && ( Copy_ePeripheral <= APB1_DAC ) )
			{
				/* Disable Required Peripheral Clock */
				(RCC -> APB1ENR) &= ( ~ ( 1 << Copy_ePeripheral ) ) ;
			}
			else
			{
				/* Wrong Peripheral is Passed */
				ErrorStatus = PERIPHERAL_DISABLE_ERROR ;
			}
			break ;

		case APB2 :
			/* Check if Peripheral is Between the Right Range */
			if( ( Copy_ePeripheral >= APB2_TIM1 ) && ( Copy_ePeripheral <= APB2_SAI2 ) )
			{
				/* Disable Required Peripheral Clock */
				(RCC -> APB2ENR) &= ( ~ ( 1 << Copy_ePeripheral ) ) ;
			}
			else
			{
				/* Wrong Peripheral is Passed */
				ErrorStatus = PERIPHERAL_DISABLE_ERROR ;
			}
			break ;

			/* Wrong Bus is Passed */
		default : ErrorStatus = BUS_ERROR ; break ;

		}
		return ErrorStatus ;
}
