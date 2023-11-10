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
#define _vo volatile

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

#define DMA1_BASE_ADDRESS 0x40026000UL
#define DMA2_BASE_ADDRESS 0x40026400UL

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------- AHB2 PERIPHERAL BASE ADDRESSES ------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------- AHB3 PERIPHERAL BASE ADDRESSES ------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------- APB1 PERIPHERAL BASE ADDRESSES ------------------------------- */
/* ---------------------------------------------------------------------------------------------- */
#define UART5_BASE_ADDRESS 0x40005000UL
#define UART4_BASE_ADDRESS 0x40004C00UL
#define USART3_BASE_ADDRESS 0x40004800UL
#define USART2_BASE_ADDRESS 0x40004400UL

#define SPI3_BASE_ADDRESS 0x40003C00UL
#define SPI2_BASE_ADDRESS 0x40003800UL

#define I2C3_BASE_ADDRESS 0x40005C00UL
#define I2C2_BASE_ADDRESS 0x40005800UL
#define I2C1_BASE_ADDRESS 0x40005400UL

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------- APB2 PERIPHERAL BASE ADDRESSES ------------------------------- */
/* ---------------------------------------------------------------------------------------------- */
#define EXTI_BASE_ADDRESS 0x40013C00UL
#define SYSCFG_BASE_ADDRESS 0x40013800UL

#define USART6_BASE_ADDRESS 0x40011400UL
#define USART1_BASE_ADDRESS 0x40011000UL

#define SPI4_BASE_ADDRESS 0x40013400UL
#define SPI1_BASE_ADDRESS 0x40013000UL

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
#define NVIC ((NVIC_RegDef_t *)NVIC_BASE_ADDRESS)

/* ------------------------------------------------------------------------------------------------- */
/* ------------------------------- SCB REGISTERS Definition Structure ------------------------------ */
/* ------------------------------------------------------------------------------------------------- */
typedef struct
{
	volatile uint32_t ACTLR; /* Auxilary Control Register */
	uint32_t RESERVED0[829];
	volatile uint32_t CPUID;   /* CPUID Base Register */
	volatile uint32_t ICSR;	   /* Interrupt Control and State Register */
	volatile uint32_t VTOR;	   /* Vector Table Offset Register */
	volatile uint32_t AIRCR;   /* Application Interrupt and Reset Control Register */
	volatile uint32_t SCR;	   /* System Control Register */
	volatile uint32_t CCR;	   /* Configuration and Control Register */
	volatile uint32_t SHPR[3]; /* Sytem Handler Priority Registers */
	volatile uint32_t SHCSR;   /* System Handler Control and State Register */
	volatile uint8_t MMFSR;	   /* MemManage Fault Status Register */
	volatile uint8_t BFSR;	   /* BusFault Status Register */
	volatile uint16_t UFSR;	   /* UsageFault Status Register */
	volatile uint32_t HFSR;	   /* HardFault Status Register */
	uint32_t RESERVED1;
	volatile uint32_t MMAR; /* MemManage Fault Address Register */
	volatile uint32_t BFAR; /* BusFault Address Register */
	volatile uint32_t AFSR; /* Auxiliary Fault Status Register */
} SCB_RegDef_t;

/* ----------------------------------------------------------------------------------------- */
/* ------------------------------- SCB Peripheral Definition ------------------------------- */
/* ----------------------------------------------------------------------------------------- */
#define SCB ((SCB_RegDef_t *)SCB_BASE_ADDRESS)

/* ---------------------------------------------------------------------------------------------------- */
/* ------------------------------- SYSCFG REGISTERS Definition Structure ------------------------------ */
/* ---------------------------------------------------------------------------------------------------- */

typedef struct
{
	volatile uint32_t MEMRMP;	 /* SYSCFG Memory Remap Register */
	volatile uint32_t PMC;		 /* SYSCFG Peripheral Mode Configuration Register */
	volatile uint32_t EXTICR[4]; /* SYSCFG External Interrupt Configuration Registers*/
	uint32_t RESERVED0[2];
	volatile uint32_t CMPCR; /* Compensation Cell Control Register */
	uint32_t RESERVED1[2];
	volatile uint32_t CFGR; /* SYSCFG Configuration Register */

} SYSCFG_RegDef_t;

/* -------------------------------------------------------------------------------------------- */
/* ------------------------------- SYSCFG Peripheral Definition ------------------------------- */
/* -------------------------------------------------------------------------------------------- */
#define SYSCFG ((SYSCFG_RegDef_t *)SYSCFG_BASE_ADDRESS)

/* -------------------------------------------------------------------------------------------------- */
/* ------------------------------- EXTI REGISTERS Definition Structure ------------------------------ */
/* -------------------------------------------------------------------------------------------------- */
typedef struct
{
	volatile uint32_t IMR;	 /* Interrupt Mask Register */
	volatile uint32_t EMR;	 /* Event Mask Register */
	volatile uint32_t RTSR;	 /* Rising Trigger Selection Register */
	volatile uint32_t FTSR;	 /* Falling Trigger Selection Register */
	volatile uint32_t SWIER; /* Software Interrupt Event Register */
	volatile uint32_t PR;	 /* Pending Register */
} EXTI_RegDef_t;

/* ------------------------------------------------------------------------------------------ */
/* ------------------------------- EXTI Peripheral Definition ------------------------------- */
/* ------------------------------------------------------------------------------------------ */
#define EXTI ((EXTI_RegDef_t *)EXTI_BASE_ADDRESS)

/* ------------------------------------------------------------------------------------------------- */
/* ------------------------------- DMA REGISTERS Definition Structure ------------------------------ */
/* ------------------------------------------------------------------------------------------------- */

typedef struct
{
	volatile uint32_t CR;	/* DMA Stream x Configuration Register */
	volatile uint32_t NDTR; /* DMA Stream x Number of Data Register */
	volatile uint32_t PAR;	/* DMA Stream x Peripheral Address Register */
	volatile uint32_t M0AR; /* DMA Stream x Memory 0 Address Register */
	volatile uint32_t M1AR; /* DMA Stream x Memory 1 Address Register */
	volatile uint32_t FCR;	/* DMA Stream x FIFO Control Register */

} DMA_Stream_RegDef_t;

typedef struct
{
	volatile uint16_t ISR[4];				/* DMA Interrupt Status Registers */
	volatile uint16_t IFCR[4];				/* DMA Interrupt Flag Clear Registers */
	volatile DMA_Stream_RegDef_t STREAM[8]; /* DMA Stream Registers */

} DMA_RegDef_t;

/* ----------------------------------------------------------------------------------------- */
/* ------------------------------- DMA Peripheral Definition ------------------------------- */
/* ----------------------------------------------------------------------------------------- */
#define DMA1 ((DMA_RegDef_t *)DMA1_BASE_ADDRESS)
#define DMA2 ((DMA_RegDef_t *)DMA2_BASE_ADDRESS)

/* ---------------------------------------------------------------------------------- */
/* ------------------------------- DMA REGISTERS Bits ------------------------------- */
/* ---------------------------------------------------------------------------------- */

typedef enum
{
	EN = 0,		 /* DMA Stream Enable */
	DMEIE = 1,	 /* Direct Mode Error Interrupt Enable */
	TEIE = 2,	 /* Transfer Error Interrupt Enable */
	HTIE = 3,	 /* Half Transfer Interrupt Enable */
	TCIE = 4,	 /* Transfer Complete Interrupt Enable */
	PFCTRL = 5,	 /* Peripheral Flow Controller */
	DIR = 6,	 /* Data Transfer Direction */
	CIRC = 8,	 /* Circular Mode */
	PINC = 9,	 /* Peripheral Increment Mode */
	MINC = 10,	 /* Memory Increment Mode */
	PSIZE = 11,	 /* Peripheral Size */
	MSIZE = 13,	 /* Memory Size */
	PINCOS = 15, /* Peripheral Increment Offset Size */
	PL = 16,	 /* Priority Level */
	DBM = 18,	 /* Double Buffer Mode */
	CT = 19,	 /* Current Target Memory */
	PBURST = 21, /* Peripheral Burst Transfer Configuration */
	MBURST = 23, /* Memory Burst Transfer Configuration */
	CHSEL = 25	 /* Channel Selection */

} DMA_STREAM_CONFIGURATION_BITS_t;

typedef enum
{
	FTH = 0,   /* FIFO Threshold Selection */
	DMDIS = 2, /* Direct Mode Disable */
	FS = 3,	   /* FIFO Status */
	FEIE = 7   /* FIFO Error Interrupt Enable */

} DMA_FIFO_CONTROL_BITS_t;

/* --------------------------------------------------------------------------------------------------- */
/* ------------------------------- USART REGISTERS Definition Structure ------------------------------ */
/* --------------------------------------------------------------------------------------------------- */

typedef struct
{
	volatile uint16_t SR; /* USART Status Register */
	uint16_t RESERVED0;
	volatile uint16_t DR; /* USART Data Register */
	uint16_t RESERVED1;
	volatile uint16_t BRR; /* USART Baud Rate Register */
	uint16_t RESERVED2;
	volatile uint16_t CR1; /* USART Control Register 1 */
	uint16_t RESERVED3;
	volatile uint16_t CR2; /* USART Control Register 2 */
	uint16_t RESERVED4;
	volatile uint16_t CR3; /* USART Control Register 3 */
	uint16_t RESERVED5;
	volatile uint16_t GTPR; /* USART Guard Time and Prescaler Register */
	uint16_t RESERVED6;

} USART_RegDef_t;

/* ------------------------------------------------------------------------------------------- */
/* ------------------------------- USART Peripheral Definition ------------------------------- */
/* ------------------------------------------------------------------------------------------- */
#define USART1 ((USART_RegDef_t *)USART1_BASE_ADDRESS)
#define USART2 ((USART_RegDef_t *)USART2_BASE_ADDRESS)
#define USART3 ((USART_RegDef_t *)USART3_BASE_ADDRESS)
#define UART4 ((USART_RegDef_t *)UART4_BASE_ADDRESS)
#define UART5 ((USART_RegDef_t *)UART5_BASE_ADDRESS)
#define USART6 ((USART_RegDef_t *)USART6_BASE_ADDRESS)

/* ------------------------------------------------------------------------------------ */
/* ------------------------------- USART REGISTERS Bits ------------------------------- */
/* ------------------------------------------------------------------------------------ */

typedef enum
{
	DIV_FRACTION = 0, /* fraction of USARTDIV */
	DIV_MANTISSA = 4  /* mantissa of USARTDIV */

} USART_BaudRateBits_t;

typedef enum
{
	SBK = 0,	   /* Send Break */
	RWU = 1,	   /* Receiver Wakeup */
	RE = 2,		   /* Receiver Enable */
	TE = 3,		   /* Transmitter Enable */
	IDLEIE = 4,	   /* IDLE Interrupt Enable */
	RXNEIE = 5,	   /* RXNE Interrupt Enable */
	TRANS_CIE = 6, /* Transmission Complete Interrupt Enable */
	TXEIE = 7,	   /* TXE Interrupt Enable */
	PEIE = 8,	   /* PE Interrupt Enable */
	PS = 9,		   /* Parity Selection */
	PCE = 10,	   /* Parity Control Enable */
	WAKE = 11,	   /* Wakeup Method */
	M = 12,		   /* Word Length */
	UE = 13,	   /* USART Enable */
	OVER8 = 15,	   /* Oversampling Mode */

} USART_CR1_BITS_t;

typedef enum
{
	ADD = 0,	/* Address of the USART node */
	LBDL = 5,	/* LIN Break Detection Length */
	LBDIE = 6,	/* LIN Break Detection Interrupt Enable */
	LBCL = 8,	/* Last Bit Clock Pulse */
	CPHA = 9,	/* Clock Phase */
	CPOL = 10,	/* Clock Polarity */
	CLKEN = 11, /* Clock Enable */
	STOP = 12,	/* STOP bits */
	LINEN = 14, /* LIN mode enable */

} USART_CR2_BITS_t;

typedef enum
{
	EIE = 0,	/* Error Interrupt Enable */
	IREN = 1,	/* IrDA mode Enable */
	IRLP = 2,	/* IrDA Low-Power */
	HDSEL = 3,	/* Half-Duplex Selection */
	NACK = 4,	/* Smartcard NACK enable */
	SCEN = 5,	/* Smartcard mode enable */
	DMAR = 6,	/* DMA Enable Receiver */
	DMAT = 7,	/* DMA Enable Transmitter */
	RTSE = 8,	/* RTS Enable */
	CTSE = 9,	/* CTS Enable */
	CTSIE = 10, /* CTS Interrupt Enable */
	ONEBIT = 11 /* One sample bit method enable */

} USART_CR3_BITS_t;

typedef enum
{
	PSC = 0, /* Prescaler value */
	GT = 8	 /* Guard time value */

} USART_GTPR_BITS_t;

/* ------------------------------------------------------------------------------------------------- */
/* ------------------------------- SPI REGISTERS Definition Structure ------------------------------ */
/* ------------------------------------------------------------------------------------------------- */

typedef struct
{
	volatile uint16_t CR1; /* SPI Control Register 1 */
	uint16_t RESERVED0;
	volatile uint16_t CR2; /* SPI Control Register 2 */
	uint16_t RESERVED1;
	volatile uint16_t SR; /* SPI Status Register */
	uint16_t RESERVED2;
	volatile uint16_t DR; /* SPI Data Register */
	uint16_t RESERVED3;
	volatile uint16_t CRCPR; /* SPI CRC Polynomial Register */
	uint16_t RESERVED4;
	volatile uint16_t RXCRCR; /* SPI RX CRC Register */
	uint16_t RESERVED5;
	volatile uint16_t TXCRCR; /* SPI TX CRC Register */
	uint16_t RESERVED6;
	volatile uint16_t I2SCFGR; /* SPI_I2S Configuration Register */
	uint16_t RESERVED7;
	volatile uint16_t I2SPR; /* SPI_I2S Prescaler Register */
	uint16_t RESERVED8;
} SPI_RegDef_t;

/* ----------------------------------------------------------------------------------------- */
/* ------------------------------- SPI Peripheral Definition ------------------------------- */
/* ----------------------------------------------------------------------------------------- */
#define SPI1 ((SPI_RegDef_t *)SPI1_BASE_ADDRESS)
#define SPI2 ((SPI_RegDef_t *)SPI2_BASE_ADDRESS)
#define SPI3 ((SPI_RegDef_t *)SPI3_BASE_ADDRESS)
#define SPI4 ((SPI_RegDef_t *)SPI4_BASE_ADDRESS)

/* ----------------------------------------------------------------------------------- */
/* ------------------------------- SPI REGISTERS' Bits ------------------------------- */
/* ----------------------------------------------------------------------------------- */

typedef enum
{
	SPI_CPHA = 0,	  /* Clock Phase */
	SPI_CPOL = 1,	  /* Clock Polarity */
	SPI_MSTR = 2,	  /* Master Selection */
	SPI_BR = 3,		  /* Baud Rate Control */
	SPI_SPE = 6,	  /* SPI Enable */
	SPI_LSBFIRST = 7, /* Direction */
	SPI_SSI = 8,	  /* Internal Slave Select */
	SPI_SSM = 9,	  /* Software Slave Management */
	SPI_RXONLY = 10,  /* Receive Only */
	SPI_DFF = 11,	  /* Data Frame Format */
	SPI_CRCNEXT = 12, /* CRC Transfer Next */
	SPI_CRCEN = 13,	  /* Hardware CRC Calculation Enable */
	SPI_BIDIOE = 14,  /* Output Enable in Bidirectional Mode */
	SPI_BIDIMODE = 15 /* Bidirectional Data Mode Enable */

} SPI_CR1_BITS_t;

typedef enum
{
	SPI_RXDMAEN = 0, /* Rx Buffer DMA Enable */
	SPI_TXDMAEN = 1, /* Tx Buffer DMA Enable */
	SPI_SSOE = 2,	 /* SS Output Enable */
	SPI_FRF = 4,	 /* Frame Format */
	SPI_ERRIE = 5,	 /* Error Interrupt Enable */
	SPI_RXNEIE = 6,	 /* RX Buffer Not Empty Interrupt Enable */
	SPI_TXEIE = 7,	 /* Tx Buffer Empty Interrupt Enable */

} SPI_CR2_BITS_t;

typedef enum
{
	SPI_CHSIDE = 2, /* Channel Side */
} SPI_SR_BITS_t;

/* ------------------------------------------------------------------------------------------------- */
/* ------------------------------- I2C REGISTERS Definition Structure ------------------------------ */
/* ------------------------------------------------------------------------------------------------- */

typedef struct
{
	_vo uint16_t I2C_CR1  	; /*!< I2C CONTROL REGISTER 1 		!>*/
		uint16_t RESERVED0  ;
	_vo uint16_t I2C_CR2  	; /*!< I2C CONTROL REGISTER 2 		!>*/
		uint16_t RESERVED1  ;
	_vo uint16_t I2C_OAR1 	; /*!< I2C OWN ADDRESS REGISTER 1 	!>*/
		uint16_t RESERVED2  ;
	_vo uint8_t I2C_OAR2  	; /*!< I2C OWN ADDRESS REGISTER 2 	!>*/
		uint8_t RESERVED3[3];
	_vo uint8_t I2C_DR    	; /*!< I2C DATA REGISTER			!>*/
		uint8_t RESERVED4[3];
	_vo uint16_t I2C_SR1  	; /*!< I2C STATUS REGISTER 1 		!>*/
		uint16_t RESERVED5	;
	_vo uint16_t I2C_SR2	; /*!< I2C STATUS REGISTER 2 		!>*/
		uint16_t RESERVED6	;
	_vo uint16_t I2C_CCR    ; /*!< I2C CLOCK CONTROL REGISTER	!>*/
		uint16_t RESERVED7	;
	_vo uint8_t I2C_TRISE   ; /*!< I2C TRISE REGISTER			!>*/
		uint8_t RESERVED8[3];
	_vo uint8_t I2C_FLTR	; /*!< I2C FILTER REGISTER   		!>*/
		uint8_t RESERVED9[3];
} I2C_RegDef_t;

/* ----------------------------------------------------------------------------------------- */
/* ------------------------------- I2C Peripheral Definition ------------------------------- */
/* ----------------------------------------------------------------------------------------- */
#define I2C1 ((I2C_RegDef_t*)I2C1_BASE_ADDRESS)
#define I2C2 ((I2C_RegDef_t*)I2C2_BASE_ADDRESS)
#define I2C3 ((I2C_RegDef_t*)I2C3_BASE_ADDRESS)

/* ----------------------------------------------------------------------------------- */
/* ------------------------------- I2C REGISTERS' Bits ------------------------------- */
/* ----------------------------------------------------------------------------------- */
typedef enum
{
	I2C_CR1_BIT_SWRST		= 15 ,     /*!< SOFTWARE RESET >!*/
	I2C_CR1_BIT_ACK			= 10 ,     /*!< ACKNOWLEDGE ENABLE >!*/
	I2C_CR1_BIT_STOP		=  9 ,     /*!< STOP GENERATION >!*/
	I2C_CR1_BIT_START		=  8 ,     /*!< START GENERATION >!*/
	I2C_CR1_BIT_NOSTRETCH  	=  7 ,     /*!< CLOCK STRETCHING DISABLE(SLAVE) >!*/
	I2C_CR1_BIT_ENGC		=  6 ,     /*!< GENERAL CALL ENABLE >!*/
	I2C_CR1_BIT_SMBUS		=  1 ,     /*!< SMBUS MODE >!*/
	I2C_CR1_BIT_PE			=  0       /*!< PERIPHERAL ENABLE >!*/

}I2C_CR1_BIT_t;

#define I2C_CCR_BIT_F_S        15

typedef enum
{
	I2C_CR2_BIT_LAST	= 12 ,         /*!< DMA LAST TRANSER >!*/
	I2C_CR2_BIT_DMAEN	= 11 ,         /*!< DMA REQUESTS ENABLE >!*/
	I2C_CR2_BIT_ITBUFEN	= 10 ,         /*!< BUFFER INTERRUPT ENABLE >!*/
	I2C_CR2_BIT_ITEVTEN	=  9 ,         /*!< EVENT INTERRUPT ENABLE >!*/
	I2C_CR2_BIT_ITERREN	=  8 ,         /*!< ERROR INTERRUPT ENABLE >!*/
	I2C_CR2_BIT_FREQ	=  0           /*!< PERIPHERAL CLOCK FREQUENCY >!*/

}I2C_CR2_BIT_t;

typedef enum
{
	I2C_OAR1_BIT_ADDMODE = 15 ,		   /*!< ADDRESSING MODE >!*/

}I2C_OAR1_BIT_t;

typedef enum
{
	I2C_OAR2_BIT_ADD 	= 1 ,			/*!< ADDRESS IN DUAL ADDRESSING MODE >!*/
	I2C_OAR2_BIT_ENDUAL = 0				/*!< DUAL ADDRESSING MODE ENABLE	 >!*/
}I2C_OAR2_BIT_t;

typedef enum
{
    I2C_SR1_TIMEOUT  = 14 ,  /*!< TIMEOUT ERROR >!*/
    I2C_SR1_OVR      = 11 ,  /*!< OVERRUN/UNDERRUN >!*/
    I2C_SR1_AF       = 10 ,  /*!< ACKNOWLEDGE FAILURE >!*/
    I2C_SR1_ARLO     =  9 ,  /*!< ARBITRATION LOST >!*/
    I2C_SR1_BERR     =  8 ,  /*!< BUS ERROR >!*/
    I2C_SR1_TXE      =  7 ,  /*!< DATA REGISTER EMPTY >!*/
    I2C_SR1_RXNE     =  6 ,  /*!< DATA REGISTER NOT EMPTY >!*/
    I2C_SR1_STOPF    =  4 ,  /*!< STOP DETECTION >!*/
    I2C_SR1_ADD10    =  3 ,  /*!< 10-BIT HEADER SENT >!*/
    I2C_SR1_BTF      =  2 ,  /*!< BYTE TRANSFER FINISHED >!*/
    I2C_SR1_ADDR     =  1 ,  /*!< ADDRESS SENT >!*/
	I2C_SR1_SB		 =  0  	 /*!< START BIT >!*/

}I2C_SR1_BIT_t;

typedef enum
{
    I2C_SR2_DUALF    =  7 ,  /*!< DUAL FLAG	>!*/
    I2C_SR2_GENCALL  =  4 ,  /*!< GENERAL CALL ADDRESS >!*/
    I2C_SR2_TRA      =  2 ,  /*!< TRANSMITTER/RECEIVER >!*/
    I2C_SR2_BUSY     =  1 ,  /*!< BUS IS BUSY >!*/
    I2C_SR2_MSL      =  0 ,  /*!< MASTER/SLAVE >!*/

}I2C_SR2_BIT_t;

#endif /* STM32F446XX_H_ */
