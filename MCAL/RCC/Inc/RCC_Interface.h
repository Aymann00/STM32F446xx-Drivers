/*
 ******************************************************************************
 * @file           : RCC_Interface.h
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : Main program body
 * @Date           : May 3, 2023
 * @Target     	   : STM32F446RE
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 *
 ******************************************************************************
 */
#ifndef RCC_RCC_INTERFACE_H_
#define RCC_RCC_INTERFACE_H_


/* -------------------------------------------------------------------------------- */
/* ------------------------------- RCC Option Enums ------------------------------- */
/* -------------------------------------------------------------------------------- */

/**
 * @enum  : @PLLR_t
 * @brief : This Enum Holds All Available Options for PLLR Value
 *
 */
typedef enum
{
	PLLR_BY2=2,PLLR_BY3,PLLR_BY4,PLLR_BY5,PLLR_BY6,PLLR_BY7

}PLLR_t;



/**
 * @enum  : @PLLQ_t
 * @brief : This Enum Holds All Available Options for PLLQ Value
 *
 */
typedef enum
{
	PLLQ_BY2=2 , PLLQ_BY3 ,	PLLQ_BY4 ,	PLLQ_BY5 ,	PLLQ_BY6 ,	PLLQ_BY7 ,	PLLQ_BY8 , PLLQ_BY9 , PLLQ_BY10 , PLLQ_BY11 , PLLQ_BY12 ,
	PLLQ_BY13 ,  PLLQ_BY14 ,PLLQ_BY15
}PLLQ_t;



/**
 * @enum  : @PLL_SRC_t
 * @brief : This Enum Holds All Available Options For PLL Entry Source ( HSI OR HSE )
 *
 */
typedef enum
{
	HSI_SRC , HSE_SRC
}PLL_SRC_t;



/**
 * @enum  : @PLLP_t
 * @brief : This Enum Holds All Available Options for PLLP Value
 *
 */
typedef enum
{
	PLLP_BY2,PLLP_BY4,PLLP_BY6,PLLP_BY8
}PLLP_t;



/**
 * @enum  : @PLLN_t
 * @brief : This Enum Holds All Available Options for PLLN Multiplication Value
 *
 */
typedef enum
{
	PLLN_X50 = 50,PLLN_X51 ,	PLLN_X52 ,	PLLN_X53 ,	PLLN_X54 ,	PLLN_X55 ,	PLLN_X56 ,	PLLN_X57 ,	PLLN_X58 ,	PLLN_X59 ,	PLLN_X60 ,	PLLN_X61 ,	  PLLN_X62 ,	PLLN_X63 ,	PLLN_X64 ,	PLLN_X65 ,	PLLN_X66 ,	PLLN_X67 ,	PLLN_X68 ,	PLLN_X69 ,	PLLN_X70 ,	PLLN_X71 ,
	PLLN_X72 ,	  PLLN_X73 ,	PLLN_X74 ,	PLLN_X75 ,	PLLN_X76 ,	PLLN_X77 ,	PLLN_X78 ,	PLLN_X79 ,	PLLN_X80 ,	PLLN_X81 ,	PLLN_X82 ,  PLLN_X83 ,    PLLN_X84 ,	PLLN_X85 ,  PLLN_X86 ,	PLLN_X87 ,	PLLN_X88 ,	PLLN_X89 ,  PLLN_X90 ,	PLLN_X91 ,	PLLN_X92 ,	PLLN_X93 ,
	PLLN_X94 ,	  PLLN_X95 ,	PLLN_X96 ,	PLLN_X97 ,	PLLN_X98 ,	PLLN_X99 ,	PLLN_X100 ,	PLLN_X101 ,	PLLN_X102 ,	PLLN_X103 ,	PLLN_X104 ,	PLLN_X105 ,	  PLLN_X106 ,	PLLN_X107 ,	PLLN_X108 ,	PLLN_X109 ,	PLLN_X110 ,	PLLN_X111 ,	PLLN_X112 ,	PLLN_X113 ,	PLLN_X114 ,	PLLN_X115 ,
	PLLN_X116 ,	  PLLN_X117 ,	PLLN_X118 ,	PLLN_X119 ,	PLLN_X120 ,	PLLN_X121 ,	PLLN_X122 ,	PLLN_X123 ,	PLLN_X124 ,	PLLN_X125 ,	PLLN_X126 ,	PLLN_X127 ,	  PLLN_X128 ,	PLLN_X129 ,	PLLN_X130 ,	PLLN_X131 ,	PLLN_X132 ,	PLLN_X133 ,	PLLN_X134 ,	PLLN_X135 ,	PLLN_X136 ,	PLLN_X137 ,
	PLLN_X138 ,	  PLLN_X139 ,	PLLN_X140 ,	PLLN_X141 ,	PLLN_X142 ,	PLLN_X143 ,	PLLN_X144 ,	PLLN_X145 ,	PLLN_X146 ,	PLLN_X147 ,	PLLN_X148 ,	PLLN_X149 ,	  PLLN_X150 ,	PLLN_X151 ,	PLLN_X152 ,	PLLN_X153 ,	PLLN_X154 ,	PLLN_X155 ,	PLLN_X156 ,	PLLN_X157 ,	PLLN_X158 ,	PLLN_X159 ,
	PLLN_X160 ,   PLLN_X161 ,   PLLN_X162 , PLLN_X163 , PLLN_X164 , PLLN_X165 , PLLN_X166 ,	PLLN_X167 ,	PLLN_X168 , PLLN_X169 ,	PLLN_X170 ,	PLLN_X171 ,   PLLN_X172 ,	PLLN_X173 ,	PLLN_X174 , PLLN_X175 ,	PLLN_X176 ,	PLLN_X177 ,	PLLN_X178 ,	PLLN_X179 ,	PLLN_X180 ,	PLLN_X181 ,
	PLLN_X182 ,	  PLLN_X183 ,	PLLN_X184 ,	PLLN_X185 ,	PLLN_X186 , PLLN_X187 , PLLN_X188 ,	PLLN_X189 ,	PLLN_X190 ,	PLLN_X191 ,	PLLN_X192 ,	PLLN_X193 ,	  PLLN_X194 ,	PLLN_X195 ,	PLLN_X196 ,	PLLN_X197 ,	PLLN_X198 ,	PLLN_X199 ,	PLLN_X200 ,	PLLN_X201 ,	PLLN_X202 ,	PLLN_X203 ,
	PLLN_X204 ,	  PLLN_X205 ,	PLLN_X206 ,	PLLN_X207 ,	PLLN_X208 ,	PLLN_X209 ,	PLLN_X210 ,	PLLN_X211 ,	PLLN_X212 ,	PLLN_X213 ,	PLLN_X214 ,	PLLN_X215 ,	  PLLN_X216 ,	PLLN_X217 ,	PLLN_X218 ,	PLLN_X219 ,	PLLN_X220 ,	PLLN_X221 ,	PLLN_X222 ,	PLLN_X223 ,	PLLN_X224 ,	PLLN_X225 ,
	PLLN_X226 ,   PLLN_X227 ,   PLLN_X228 ,	PLLN_X229 ,	PLLN_X230 ,	PLLN_X231 ,	PLLN_X232 , PLLN_X233 ,	PLLN_X234 ,	PLLN_X235 ,	PLLN_X236 ,	PLLN_X237 ,	  PLLN_X238 ,	PLLN_X239 ,	PLLN_X240 ,	PLLN_X241 ,	PLLN_X242 ,	PLLN_X243 ,	PLLN_X244 ,	PLLN_X245 ,	PLLN_X246 ,	PLLN_X247 ,
	PLLN_X248 ,	  PLLN_X249 ,	PLLN_X250 ,	PLLN_X251 ,	PLLN_X252 ,	PLLN_X253 ,	PLLN_X254 ,	PLLN_X255 ,	PLLN_X256 ,	PLLN_X257 ,	PLLN_X258 ,	PLLN_X259 ,	  PLLN_X260 ,	PLLN_X261 ,	PLLN_X262 ,	PLLN_X263 ,	PLLN_X264 ,	PLLN_X265 ,	PLLN_X266 ,	PLLN_X267 ,	PLLN_X268 ,	PLLN_X269 ,
	PLLN_X270 ,	  PLLN_X271 ,	PLLN_X272 ,	PLLN_X273 ,	PLLN_X274 ,	PLLN_X275 ,	PLLN_X276 ,	PLLN_X277 ,	PLLN_X278 ,	PLLN_X279 ,	PLLN_X280 ,	PLLN_X281 ,	  PLLN_X282 ,	PLLN_X283 ,	PLLN_X284 ,	PLLN_X285 , PLLN_X286 ,	PLLN_X287 ,	PLLN_X288 ,	PLLN_X289 ,	PLLN_X290 ,	PLLN_X291 ,
	PLLN_X292 ,	  PLLN_X293 ,	PLLN_X294 ,	PLLN_X295 ,	PLLN_X296 ,	PLLN_X297 ,	PLLN_X298 ,	PLLN_X299 ,	PLLN_X300 ,	PLLN_X301 ,	PLLN_X302 ,	PLLN_X303 ,	  PLLN_X304 ,	PLLN_X305 ,	PLLN_X306 ,	PLLN_X307 ,	PLLN_X308 ,	PLLN_X309 ,	PLLN_X310 ,	PLLN_X311 ,	PLLN_X312 ,	PLLN_X313 ,
	PLLN_X314 ,	  PLLN_X315 ,	PLLN_X316 ,	PLLN_X317 ,	PLLN_X318 ,	PLLN_X319 ,	PLLN_X320 ,	PLLN_X321 ,	PLLN_X322 ,	PLLN_X323 ,	PLLN_X324 ,	PLLN_X325 ,	  PLLN_X326 ,	PLLN_X327 ,	PLLN_X328 ,	PLLN_X329 ,	PLLN_X330 ,	PLLN_X331 ,	PLLN_X332 ,	PLLN_X333 ,	PLLN_X334 ,	PLLN_X335 ,
	PLLN_X336 ,	  PLLN_X337 ,	PLLN_X338 ,	PLLN_X339 ,	PLLN_X340 ,	PLLN_X341 ,	PLLN_X342 ,	PLLN_X343 ,	PLLN_X344 ,	PLLN_X345 ,	PLLN_X346 ,	PLLN_X347 ,   PLLN_X348 ,   PLLN_X349 , PLLN_X350 , PLLN_X351 , PLLN_X352 ,	PLLN_X353 ,	PLLN_X354 ,	PLLN_X355 ,	PLLN_X356 ,	PLLN_X357 ,
	PLLN_X358 ,	  PLLN_X359 ,	PLLN_X360 ,	PLLN_X361 ,	PLLN_X362 , PLLN_X363 ,	PLLN_X364 ,	PLLN_X365 ,	PLLN_X366 ,	PLLN_X367 ,	PLLN_X368 ,	PLLN_X369 ,	  PLLN_X370 ,	PLLN_X371 ,	PLLN_X372 ,	PLLN_X373 ,	PLLN_X374 ,	PLLN_X375 ,	PLLN_X376 ,	PLLN_X377 ,	PLLN_X378 ,	PLLN_X379 ,
	PLLN_X380 ,	  PLLN_X381 ,	PLLN_X382 ,	PLLN_X383 ,	PLLN_X384 ,	PLLN_X385 ,	PLLN_X386 ,	PLLN_X387 ,	PLLN_X388 ,	PLLN_X389 ,	PLLN_X390 ,	PLLN_X391 ,	  PLLN_X392 ,	PLLN_X393 ,	PLLN_X394 ,	PLLN_X395 ,	PLLN_X396 ,	PLLN_X397 ,	PLLN_X398 ,	PLLN_X399 ,	PLLN_X400 ,	PLLN_X401 ,
	PLLN_X402 ,	  PLLN_X403 ,	PLLN_X404 ,	PLLN_X405 ,	PLLN_X406 ,	PLLN_X407 ,	PLLN_X408 ,	PLLN_X409 ,	PLLN_X410 ,	PLLN_X411 ,	PLLN_X412 ,	PLLN_X413 ,	  PLLN_X414 ,	PLLN_X415 ,	PLLN_X416 ,	PLLN_X417 ,	PLLN_X418 ,	PLLN_X419 ,	PLLN_X420 ,	PLLN_X421 ,	PLLN_X422 ,	PLLN_X423 ,
	PLLN_X424 ,	  PLLN_X425 ,	PLLN_X426 ,	PLLN_X427 ,	PLLN_X428 ,	PLLN_X429 ,	PLLN_X430 ,	PLLN_X431 ,	PLLN_X432 ,

}PLLN_t;



/**
 * @enum  : @PLLM_t
 * @brief : This Enum Holds All Available Options for PLLM Division Factor
 *
 */
typedef enum  {
    PLLM_BY2 = 2 , PLLM_BY3 ,   PLLM_BY4 ,   PLLM_BY5 ,   PLLM_BY6 ,   PLLM_BY7 ,   PLLM_BY8 ,   PLLM_BY9 ,   PLLM_BY10 , PLLM_BY11 ,
    PLLM_BY12 ,    PLLM_BY13 ,  PLLM_BY14 ,  PLLM_BY15 ,  PLLM_BY16 ,  PLLM_BY17 ,  PLLM_BY18 ,  PLLM_BY19 ,  PLLM_BY20 , PLLM_BY21 ,
	PLLM_BY22 ,    PLLM_BY23 ,  PLLM_BY24 ,  PLLM_BY25 ,  PLLM_BY26 ,  PLLM_BY27 ,  PLLM_BY28 ,  PLLM_BY29 ,  PLLM_BY30 ,
    PLLM_BY31 ,    PLLM_BY32 ,  PLLM_BY33 ,  PLLM_BY34 ,  PLLM_BY35 ,  PLLM_BY36 ,  PLLM_BY37 ,  PLLM_BY38 ,  PLLM_BY39 ,
    PLLM_BY40 ,    PLLM_BY41 ,  PLLM_BY42 ,  PLLM_BY43 ,  PLLM_BY44 ,  PLLM_BY45 ,  PLLM_BY46 ,  PLLM_BY47 ,  PLLM_BY48 ,
    PLLM_BY49 ,    PLLM_BY50 ,  PLLM_BY51 ,  PLLM_BY52 ,  PLLM_BY53 ,  PLLM_BY54 ,  PLLM_BY55 ,  PLLM_BY56 ,  PLLM_BY57 ,
    PLLM_BY58 ,    PLLM_BY59 ,  PLLM_BY60 ,  PLLM_BY61 ,  PLLM_BY62 ,  PLLM_BY63
}PLLM_t;



/**
 * @enum  : @AHB_PRE_t
 * @brief : This Enum Holds All Available Prescalers Options for AHB
 *
 */
typedef enum
{
	SYS_CLK_BY1 , SYS_CLK_BY2 = 8 , SYS_CLK_BY4 , SYS_CLK_BY8 , SYS_CLK_BY16 , SYS_CLK_BY64 , SYS_CLK_BY128 , SYS_CLK_BY256 , SYS_CLK_BY512
}AHB_PRE_t;



/**
 * @enum  : @APB_PRE_t
 * @brief : This Enum Holds All Available Prescalers Options for APB1 & APB2
 *
 */
typedef enum
{
   AHB_CLK_BY1 , AHB_CLK_BY2 = 4 , AHB_CLK_BY4 , AHB_CLK_BY8 , AHB_CLK_BY16
}APB_PRE_t;


/**
 * @enum  : @CLK_Type_t
 * @brief : This Enum Holds All Available Options For Clocks To Enable Or Disable
 *
 */
typedef enum
{
	HSI ,	PLLSAI  = 28 ,	PLLI2S  = 26 ,	MainPLL = 24 ,  HSE  = 16

}CLK_Type_t;



/**
 * @enum  : @CLK_State_t
 * @brief : This Enum Holds Options for Clock Status ( ON or OFF )
 *
 */
typedef enum
{
	OFF,
	ON

}CLK_State_t;



/**
 * @enum  : @SYS_CLK
 * @brief : This Enum Holds All Available Options for SYS Clock To Choose From
 *
 */
typedef enum
{
	HSI_SYS_CLK ,
	HSE_SYS_CLK ,
	PLL_P ,
	PLL_R ,

}SYS_CLK_t;



/**
 * @enum  : @Peripheral_BUS_t
 * @brief : This Enum Holds All Available Options for Bus Interfaces in our MCU to Control Peripherals on it
 *
 */
typedef enum
{
	AHB1 ,
	AHB2 ,
	AHB3 ,
	APB1 ,
	APB2
}Peripheral_BUS_t;



/**
 * @enum  : @AHB1_Peripheral_t
 * @brief : This Enum Holds All Available Values for AHB1 Peripherals to Enable or Disable
 *
 */
typedef enum
{
	AHB1_GPIOA , AHB1_GPIOB , AHB1_GPIOC , AHB1_GPIOD , AHB1_GPIOE , AHB1_GPIOF , AHB1_GPIOG , AHB1_GPIOH ,
	AHB1_CRC = 12 , AHB1_BKPSRAM = 18 , AHB1_DMA1 = 21 , AHB1_DMA2 , AHB1_OTGHS = 29 , AHB1_OTGHSULPI
}AHB1_Peripheral_t;



/**
 * @enum  : @AHB2_Peripheral_t
 * @brief : This Enum Holds All Available Values for AHB2 Peripherals to Enable or Disable
 *
 */
typedef enum
{
	AHB2_DCMI , AHB2_OTGFS = 7
}AHB2_Peripheral_t;



/**
 * @enum  : @AHB3_Peripheral_t
 * @brief : This Enum Holds All Available Values for AHB3 Peripherals to Enable or Disable
 *
 */
typedef enum
{
	AHB3_FMCEN , AHB3_QSPI ,
}AHB3_Peripheral_t;



/**
 * @enum  : @APB1_Peripheral_t
 * @brief : This Enum Holds All Available Values for APB1 Peripherals to Enable or Disable
 *
 */
typedef enum
{
	 APB1_TIM2 , APB1_TIM3 , APB1_TIM4 , APB1_TIM5 , APB1_TIM6 , APB1_TIM7 , APB1_TIM12 ,
	 APB1_TIM13 , APB1_TIM14 , APB1_WWDG = 11 , APB1_SPI2 = 14 , APB1_SPI3 , APB1_SPDIFRX ,
	 APB1_USART2 , APB1_USART3 , APB1_UART4 , APB1_UART5 , APB1_I2C1 , APB1_I2C2 , APB1_I2C3 ,
	 APB1_FMPI2C1 ,	 APB1_CAN1 , APB1_CAN2 , APB1_CEC ,	APB1_PWR , APB1_DAC
}APB1_Peripheral_t;


/**
 * @enum  : @APB2_Peripheral_t
 * @brief : This Enum Holds All Available Values for APB2 Peripherals to Enable or Disable
 *
 */
typedef enum
{
	APB2_TIM1 ,	APB2_TIM8 ,	APB2_USART1 = 4 , APB2_USART6 ,	APB2_ADC1 = 8 ,	APB2_ADC2 ,
	APB2_ADC3 ,	APB2_SDIO ,	APB2_SPI1 ,	APB2_SPI4 ,	APB2_SYSCFG , APB2_TIM9 = 16 , APB2_TIM10 ,
	APB2_TIM11 , APB2_SAI1 = 22 , APB2_SAI2

}APB2_Peripheral_t;

/**
 * @enum  : @HSE_CONFIG_t
 * @brief : This Enum Holds Available Configurations of ByPassing For HSE Clock
 *
 */
typedef enum
{
	HSE_NOT_BYPASSED , HSE_BYPASSED
}HSE_CONFIG_t;


/* ---------------------------------------------------------------------------------------- */
/* ------------------------------- RCC PLL Config Structure ------------------------------- */
/* ---------------------------------------------------------------------------------------- */
typedef struct
{
	PLLR_t PLLR_FACTOR ;
	PLLQ_t PLLQ_FACTOR ;
	PLL_SRC_t PLL_SRC  ;
	PLLP_t PLLP_FACTOR ;
	PLLN_t PLLN_FACTOR ;
	PLLM_t PLLM_FACTOR ;

}RCC_PLL_CONFIG_t;



/* ------------------------------------------------------------------------------------------------ */
/* ------------------------------- FUCTION PROTOTYPES SECTION START ------------------------------- */
/* ------------------------------------------------------------------------------------------------ */


/**
 * @fn	  : RCC_SetCLKStatus
 * @brief : Select a Certain Clock and Enable it or Disable it
 * @param : CLK_Type_t -> Clock Type From Enum ( @CLK_Type_t ) => HSI ,	PLLSAI , PLLI2S , MainPLL , HSE
 * @param : CLK_State_t -> State of Clock ON or OFF From Enum( @CLK_State_t ) => ON , OFF
 * @retval: Error Status  that Return Errors Dependening on Type of Error
 *                 -> OK , TIME_OUT_ERROR , CLK_STATE_ERROR , CLK_TYPE_ERROR
 * @note	  : IF you are using PLL or HSE Clock you must Set the Configuration of the Clock First Before Enabling it ( Using this Function )
 **/

ERRORS_t RCC_SetCLKStatus( CLK_Type_t Copy_eClockType , CLK_State_t Copy_eClockState ) ;



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

ERRORS_t RCC_SetPLLConfig(const RCC_PLL_CONFIG_t * Copy_psPLLConfig ) ;


/**
 * @fn		: RCC_SetSysCLK
 * @brief   : Select a Certain Clock as a System Clock
 * @param   : SYS_CLK_t -> Clock Type  From enum ( @SYS_CLK_t ) => HSI_SYS_CLK , HSE_SYS_CLK , PLL_P , PLL_R
 * @retval	: Error Status that Return Errors Dependening on Type of Error
 *                 -> SYS_CLK_ERROR
 * @note	: Clock should be Ready Before Switching to it , if not Switch will not be done untill clock is ready
 **/

ERRORS_t RCC_SetSysCLK( SYS_CLK_t Copy_eCLKType ) ;



/**
 * @fn		: RCC_GetSysCLK
 * @brief	: Return Whick Clock is the SYSCLK
 * @retval	: Returns Value From Enum ( @SYS_CLK_t ) => Indicate Which Clock Source is Used as System Clock
 *                 1- HSI_SYS_CLK = 0
 *	               2- HSE_SYS_CLK = 1
 *				   3- PLL_P = 2
 *				   4- PLL_R = 3
 **/

SYS_CLK_t RCC_GetSysCLK( void ) ;



/**
 * @fn		: RCC_SetAHBPRE
 * @brief	: Set AHB Prescaler
 * @param   : Prescaler of AHB Bus From Enum ( @AHB_PRE_t )
 * @retval	: Error Status that Return Errors Dependening on Type of Error
 *                 -> AHB_PRE_ERROR
 **/

ERRORS_t RCC_SetAHBPRE( AHB_PRE_t Copy_eAHBPrescaler ) ;


/**
 * @fn		: RCC_SetAPB1PRE
 * @brief	: Set APB1 Prescaler
 * @param   : Prescaler of APB1 Bus From Enum ( @APB_PRE_t )
 * @retval	: Error Status that Return Errors Dependening on Type of Error
 *                 -> APB1_PRE_ERROR
 **/

ERRORS_t RCC_SetAPB1PRE( APB_PRE_t Copy_eAPB1Prescaler ) ;



/**
 * @fn		: RCC_SetAPB2PRE
 * @brief	: Set APB2 Prescaler Bus
 * @param   : Prescaler of APB2 Bus From Enum ( @APB_PRE_t )
 * @retval	: Error Status that Return Errors Dependening on Type of Error
 *                 -> APB2_PRE_ERROR
 **/

ERRORS_t RCC_SetAPB2PRE( APB_PRE_t Copy_eAPB2Prescaler ) ;




/**
 * @fn		: RCC_HSEByPass
 * @brief	: This Function Allow you to Select if HSE is Bypassed or Not
 * @param   : Copy_eHSEConfig From Enum ( @HSE_CONFIG_t )
 *                    -> HSE_NOT_BYPASSED , HSE_BYPASSED
 * @retval	: Error Status that Return Errors Dependening on Type of Error
 *                 -> HSE_CONFIG_ERROR
 **/

ERRORS_t RCC_HSEBypass( HSE_CONFIG_t Copy_eHSEConfig ) ;




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

ERRORS_t RCC_EnablePeripheral( Peripheral_BUS_t Copy_eBus , uint8_t Copy_ePeripheral  ) ;



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

ERRORS_t RCC_DisablePeripheral( Peripheral_BUS_t Copy_eBus , uint8_t Copy_ePeripheral  );

/* ------------------------------------------------------------------------------------------------ */
/* ------------------------------- FUCTION PROTOTYPES SECTION END   ------------------------------- */
/* ------------------------------------------------------------------------------------------------ */

#endif /* RCC_RCC_INTERFACE_H_ */
