/*
 ******************************************************************************
 * @file           : STM32F446xx.h
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : Device Specific File
 * @Date           : May 3, 2023
 * @Target         : STM32F446xx
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 *
 ******************************************************************************
 */
#ifndef REGISTERS_H_
#define REGISTERS_H_

/* ---------------------------------------------------------------------- */
/* ------------------------------- MACROS ------------------------------- */
/* ---------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- */
/* ------------------------------- BIT BAND MACROS ------------------------------- */
/* ------------------------------------------------------------------------------- */
#define ALIAS_BASE_ADDRESS 0x22000000UL
#define BIT_BAND_BASE_ADDRESS 0x20000000UL

/* ------------------------------------------------------------------------------------------------ */
/* ------------------------------- ALIAS ADDRESS FUNCION LIKE MACRO ------------------------------- */
/* ------------------------------------------------------------------------------------------------ */
#define ALIAS_ADDRESS(BIT_BAND_ADDRESS, BIT_NO) (ALIAS_BASE_ADDRESS + (BIT_NO * 4UL) + (32UL * ((uint32_t)BIT_BAND_ADDRESS - BIT_BAND_BASE_ADDRESS)))

/* ------------------------------------------------------------------------------------------------------- */
/* ------------------------------- VARIOUS MEMORIES BASE ADDRESSES SECTION ------------------------------- */
/* ------------------------------------------------------------------------------------------------------- */
#define FLASH_BASE_ADDRESS 0x08000000UL
#define SRAM_BASE_ADDRESS 0x20000000UL
#define ROM_BASE_ADDRESS 0x1FFF0000UL

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------- AHB1 PERIPHERAL BASE ADDRESSES ------------------------------- */
/* ---------------------------------------------------------------------------------------------- */
#define GPIOA_BASE_ADDRESS 0x40020000UL
#define GPIOB_BASE_ADDRESS 0x40020400UL
#define GPIOC_BASE_ADDRESS 0x40020800UL
#define GPIOD_BASE_ADDRESS 0x40020C00UL
#define GPIOE_BASE_ADDRESS 0x40021000UL
#define GPIOF_BASE_ADDRESS 0x40021400UL
#define GPIOG_BASE_ADDRESS 0x40021800UL
#define GPIOH_BASE_ADDRESS 0x40021C00UL

#define RCC_BASE_ADDRESS 0x40023800UL

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------- AHB2 PERIPHERAL BASE ADDRESSES ------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------- AHB3 PERIPHERAL BASE ADDRESSES ------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------- APB1 PERIPHERAL BASE ADDRESSES ------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------- APB2 PERIPHERAL BASE ADDRESSES ------------------------------- */
/* ---------------------------------------------------------------------------------------------- */
#define EXTI_BASE_ADDRESS 0x40013C00UL
#define SYSCFG_BASE_ADDRESS 0x40013800UL

/* ------------------------------------------------------------------------------------------------------------- */
/* ------------------------------- CORTEX-M4 INTERNAL PERIPHERALS BASE ADDRESSES ------------------------------- */
/* ------------------------------------------------------------------------------------------------------------- */
#define SYSTICK_BASE_ADDRESS 0xE000E010UL
#define NVIC_BASE_ADDRESS 0xE000E100UL
#define SCB_BASE_ADDRESS 0xE000E008UL

/* -------------------------------------------------------------------------------------------------- */
/* ------------------------------- RCC REGISTERS Definition Structure ------------------------------- */
/* -------------------------------------------------------------------------------------------------- */

typedef struct
{
	volatile uint32_t CR;		  /*!< RCC clock control register                                   >!*/
	volatile uint32_t PLLCFGR;	  /*!< RCC PLL configuration register                               >!*/
	volatile uint32_t CFGR;		  /*!< RCC clock configuration register                             >!*/
	volatile uint32_t CIR;		  /*!< RCC clock interrupt register                                 >!*/
	volatile uint32_t AHB1RSTR;	  /*!< RCC AHB1 peripheral reset register                           >!*/
	volatile uint32_t AHB2RSTR;	  /*!< RCC AHB2 peripheral reset register                           >!*/
	volatile uint32_t AHB3RSTR;	  /*!< RCC AHB3 peripheral reset register                           >!*/
	uint32_t RESERVED0;			  /*!< Reserved, 0x1C                                               >!*/
	volatile uint32_t APB1RSTR;	  /*!< RCC APB1 peripheral reset register                           >!*/
	volatile uint32_t APB2RSTR;	  /*!< RCC APB2 peripheral reset register                           >!*/
	uint32_t RESERVED1[2];		  /*!< Reserved, 0x28-0x2C                                          >!*/
	volatile uint32_t AHB1ENR;	  /*!< RCC AHB1 peripheral clock register                           >!*/
	volatile uint32_t AHB2ENR;	  /*!< RCC AHB2 peripheral clock register                           >!*/
	volatile uint32_t AHB3ENR;	  /*!< RCC AHB3 peripheral clock register                           >!*/
	uint32_t RESERVED2;			  /*!< Reserved, 0x3C                                               >!*/
	volatile uint32_t APB1ENR;	  /*!< RCC APB1 peripheral clock enable register                    >!*/
	volatile uint32_t APB2ENR;	  /*!< RCC APB2 peripheral clock enable register                    >!*/
	uint32_t RESERVED3[2];		  /*!< Reserved, 0x48-0x4C                                          >!*/
	volatile uint32_t AHB1LPENR;  /*!< RCC AHB1 peripheral clock enable in low power mode register  >!*/
	volatile uint32_t AHB2LPENR;  /*!< RCC AHB2 peripheral clock enable in low power mode register  >!*/
	volatile uint32_t AHB3LPENR;  /*!< RCC AHB3 peripheral clock enable in low power mode register  >!*/
	uint32_t RESERVED4;			  /*!< Reserved, 0x5C                                               >!*/
	volatile uint32_t APB1LPENR;  /*!< RCC APB1 peripheral clock enable in low power mode register  >!*/
	volatile uint32_t APB2LPENR;  /*!< RCC APB2 peripheral clock enable in low power mode register  >!*/
	uint32_t RESERVED5[2];		  /*!< Reserved, 0x68-0x6C                                          >!*/
	volatile uint32_t BDCR;		  /*!< RCC Backup domain control register                           >!*/
	volatile uint32_t CSR;		  /*!< RCC clock control & status register                          >!*/
	uint32_t RESERVED6[2];		  /*!< Reserved, 0x78-0x7C                                          >!*/
	volatile uint32_t SSCGR;	  /*!< RCC spread spectrum clock generation register                >!*/
	volatile uint32_t PLLI2SCFGR; /*!< RCC PLLI2S configuration register                            >!*/
	volatile uint32_t PLLSAICFGR; /*!< RCC PLLSAI configuration register                            >!*/
	volatile uint32_t DCKCFGR;	  /*!< RCC Dedicated Clocks configuration register                  >!*/
	volatile uint32_t CKGATENR;	  /*!< RCC Clocks Gated ENable Register                             >!*/
	volatile uint32_t DCKCFGR2;	  /*!< RCC Dedicated Clocks configuration register 2                >!*/

} RCC_RegDef_t;

/* ----------------------------------------------------------------------------------------- */
/* ------------------------------- RCC Peripheral Definition ------------------------------- */
/* ----------------------------------------------------------------------------------------- */

#define RCC ((RCC_RegDef_t *)RCC_BASE_ADDRESS)

/* ---------------------------------------------------------------------------------- */
/* ------------------------------- RCC REGISTERS Bits ------------------------------- */
/* ---------------------------------------------------------------------------------- */

/* RCC_CR REG BITS */
#define CR_PLLSAIRDY 29 /* PLLSAI Clock Ready Flag */
#define CR_PLLSAION 28	/* PLLSAI Enable */
#define CR_PLLI2SRDY 27 /* PLLI2S Clock Ready Flag */
#define CR_PLLI2SON 26	/* PLLI2S Enable */
#define CR_PLLRDY 25	/* Main PLL Clock Ready Flag */
#define CR_PLLON 24		/* Main PLL Enable */
#define CR_CSSON 19		/* Clock Security System Enable */
#define CR_HSEBYP 18	/* HSE Clock ByPass */
#define CR_HSERDY 17	/* HSE Clock Ready Flag */
#define CR_HSEON 16		/* HSE Clock Enable */
#define CR_HSITRIM 3	/* HSI Clock Trimming */
#define CR_HSIRDY 1		/* HSI Clock Ready Flag */
#define CR_HSION 0		/* HSI Clock Enable */

/* RCC_PLLCFGR REG BITS */
#define PLLCFGR_PLLR 28	  /* Main PLL Division Factor For I2Ss,SAIs & SYSTEM  */
#define PLLCFGR_PLLQ 24	  /* Main PLL Division Factor For USB OTG , SDIO */
#define PLLCFGR_PLLSRC 22 /* Main PLL & PLLI2S entry Clock Source */
#define PLLCFGR_PLLP 16	  /* Main PLL Division Factor For Main System Clock */
#define PLLCFGR_PLLN 6	  /* Main PLL Multiplication Factor */
#define PLLCFGR_PLLM 0	  /* Division Factor For Main PLL Input Clock */

/* RCC_CFGR */
#define CFGR_MCO2 30	/* Microcontroller Clock Output 2 */
#define CFGR_MCO2PRE 27 /* MCO2 Prescaler */
#define CFGR_MCO1PRE 24 /* MCO1 Prescaler */
#define CFGR_MCO1 21	/* Microcontroller Clock Output 1 */
#define CFGR_RTCPRE 16	/* HSE Division Fator for RTC Clock */
#define CFGR_PPRE2 13	/* APB2 Prescaler */
#define CFGR_PPRE1 10	/* APB1 Prescaler */
#define CFGR_HPRE 4		/* AHB Prescaler */
#define CFGR_SWS 2		/* System Clock Switch Status */
#define CFGR_SW 0		/* System Clock Switch */

/* --------------------------------------------------------------------------------------------------- */
/* ------------------------------- GPIO REGISTERS Definition Structure ------------------------------- */
/* --------------------------------------------------------------------------------------------------- */

typedef struct
{
	volatile uint32_t MODER;   /*!< GPIO PORT Mode Register              >!*/
	volatile uint32_t OTYPER;  /*!< GPIO PORT Output Type Register       >!*/
	volatile uint32_t OSPEEDR; /*!< GPIO PORT Output Speed Register      >!*/
	volatile uint32_t PUPDR;   /*!< GPIO PORT Pull-Up/Pull-Down Register >!*/
	volatile uint32_t IDR;	   /*!< GPIO PORT Input Data Register        >!*/
	volatile uint32_t ODR;	   /*!< GPIO PORT Output Data Register       >!*/
	volatile uint32_t BSRR;	   /*!< GPIO PORT Bit Set/Reset Register     >!*/
	volatile uint32_t LCKR;	   /*!< GPIO PORT                            >!*/
	volatile uint32_t AFR[2];  /*!< GPIO PORT                            >!*/

} GPIO_RegDef_t;

/* ------------------------------------------------------------------------------------------- */
/* ------------------------------- GPIO Peripheral Definitions ------------------------------- */
/* ------------------------------------------------------------------------------------------- */
#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_RegDef_t *)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASE_ADDRESS)
#define GPIOD ((GPIO_RegDef_t *)GPIOD_BASE_ADDRESS)
#define GPIOE ((GPIO_RegDef_t *)GPIOE_BASE_ADDRESS)
#define GPIOF ((GPIO_RegDef_t *)GPIOF_BASE_ADDRESS)
#define GPIOG ((GPIO_RegDef_t *)GPIOG_BASE_ADDRESS)
#define GPIOH ((GPIO_RegDef_t *)GPIOH_BASE_ADDRESS)

/* ------------------------------------------------------------------------------------------------------ */
/* ------------------------------- SYSTICK REGISTERS Definition Structure ------------------------------- */
/* ------------------------------------------------------------------------------------------------------ */
typedef struct
{
	volatile uint32_t SYST_CSR;	  /*<! SYSTICK Control and Status Register  >!*/
	volatile uint32_t SYST_RVR;	  /*<! SYSTICK Reload Value Register        >!*/
	volatile uint32_t SYST_CVR;	  /*<! SYSTICK Current Value Register       >!*/
	volatile uint32_t SYST_CALIB; /*<! SYSTICK Calibration Value Register   >!*/
} SYSTICK_RegDef_t;

/* --------------------------------------------------------------------------------------------- */
/* ------------------------------- SYSTICK Peripheral Definition ------------------------------- */
/* --------------------------------------------------------------------------------------------- */
#define SYSTICK ((SYSTICK_RegDef_t *)SYSTICK_BASE_ADDRESS)

/* -------------------------------------------------------------------------------------- */
/* ------------------------------- SYSTICK REGISTERS Bits ------------------------------- */
/* -------------------------------------------------------------------------------------- */

/* SYST_CSR */
#define CSR_COUNTFLAG 16
#define CSR_CLKSOURCE 2
#define CSR_TICKINT 1
#define CSR_ENABLE 0

/* -------------------------------------------------------------------------------------------------- */
/* ------------------------------- NVIC REGISTERS Definition Structure ------------------------------ */
/* -------------------------------------------------------------------------------------------------- */
typedef struct
{
	volatile uint32_t ISER[8]; /* Interrupt Set Enable Registers */
	uint32_t RESERVED0[24];
	volatile uint32_t ICER[8]; /* Interrupt Clear Enable Registers */
	uint32_t RESERVED1[24];
	volatile uint32_t ISPR[8]; /* Interrupt Set Pending Registers */
	uint32_t RESERVED2[24];
	volatile uint32_t ICPR[8]; /* Interrupt Clear Pending Registers */
	uint32_t RESERVED3[24];
	volatile uint32_t IABR[8]; /* Interrupt Active Bit Registers */
	uint32_t RESERVED4[56];
	volatile uint8_t IPR[240]; /* Interrupt Priority Registers */
	uint32_t RESERVED5[643];
	volatile uint32_t STIR; /* Software Trigger Interrupt Register */
} NVIC_RegDef_t;

/* ------------------------------------------------------------------------------------------ */
/* ------------------------------- NVIC Peripheral Definition ------------------------------- */
/* ------------------------------------------------------------------------------------------ */
#define NVIC ((NVIC_RegDef_t *) NVIC_BASE_ADDRESS)


/* ------------------------------------------------------------------------------------------------- */
/* ------------------------------- SCB REGISTERS Definition Structure ------------------------------ */
/* ------------------------------------------------------------------------------------------------- */
typedef struct
{
   volatile uint32_t ACTLR ; /* Auxilary Control Register */
   uint32_t RESERVED0[829] ;
   volatile uint32_t CPUID ; /* CPUID Base Register */
   volatile uint32_t ICSR ; /* Interrupt Control and State Register */
   volatile uint32_t VTOR ; /* Vector Table Offset Register */
   volatile uint32_t AIRCR ; /* Application Interrupt and Reset Control Register */
   volatile uint32_t SCR ; /* System Control Register */
   volatile uint32_t CCR ; /* Configuration and Control Register */
   volatile uint32_t SHPR[3] ; /* Sytem Handler Priority Registers */
   volatile uint32_t SHCSR ; /* System Handler Control and State Register */
   volatile uint8_t MMFSR ; /* MemManage Fault Status Register */
   volatile uint8_t BFSR ; /* BusFault Status Register */
   volatile uint16_t UFSR ; /* UsageFault Status Register */
   volatile uint32_t HFSR ; /* HardFault Status Register */
   uint32_t RESERVED1 ;
   volatile uint32_t MMAR ; /* MemManage Fault Address Register */
   volatile uint32_t BFAR ; /* BusFault Address Register */
   volatile uint32_t AFSR ; /* Auxiliary Fault Status Register */
}SCB_RegDef_t;


/* ----------------------------------------------------------------------------------------- */
/* ------------------------------- SCB Peripheral Definition ------------------------------- */
/* ----------------------------------------------------------------------------------------- */
#define SCB ( (SCB_RegDef_t *)SCB_BASE_ADDRESS )





/* ---------------------------------------------------------------------------------------------------- */
/* ------------------------------- SYSCFG REGISTERS Definition Structure ------------------------------ */
/* ---------------------------------------------------------------------------------------------------- */

typedef struct
{
	volatile uint32_t MEMRMP ; /* SYSCFG Memory Remap Register */
	volatile uint32_t PMC ; /* SYSCFG Peripheral Mode Configuration Register */
	volatile uint32_t EXTICR[ 4 ] ; /* SYSCFG External Interrupt Configuration Registers*/
	uint32_t RESERVED0[2] ;
	volatile uint32_t CMPCR ; /* Compensation Cell Control Register */
	volatile uint32_t CFGR ; /* SYSCFG Configuration Register */
	uint32_t RESERVED1[2] ;

}SYSCFG_RegDef_t;

/* -------------------------------------------------------------------------------------------- */
/* ------------------------------- SYSCFG Peripheral Definition ------------------------------- */
/* -------------------------------------------------------------------------------------------- */
#define SYSCFG  ( ( SYSCFG_RegDef_t * ) SYSCFG_BASE_ADDRESS )


/* -------------------------------------------------------------------------------------------------- */
/* ------------------------------- EXTI REGISTERS Definition Structure ------------------------------ */
/* -------------------------------------------------------------------------------------------------- */
typedef struct
{
	volatile uint32_t IMR ; /* Interrupt Mask Register */
	volatile uint32_t EMR ; /* Event Mask Register */
	volatile uint32_t RTSR ; /* Rising Trigger Selection Register */
	volatile uint32_t FTSR ; /* Falling Trigger Selection Register */
	volatile uint32_t SWIER ; /* Software Interrupt Event Register */
	volatile uint32_t PR ; /* Pending Register */
}EXTI_RegDef_t;


/* ------------------------------------------------------------------------------------------ */
/* ------------------------------- EXTI Peripheral Definition ------------------------------- */
/* ------------------------------------------------------------------------------------------ */
#define EXTI ( ( EXTI_RegDef_t * ) EXTI_BASE_ADDRESS )


#endif /* STM32F446XX_H_ */
