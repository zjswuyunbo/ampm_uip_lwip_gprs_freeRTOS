/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HW_CONFIG_H__
#define __HW_CONFIG_H__

#include "stm32f10x.h"
#include <stdint.h>

#define PAGE_SIZE                         (0x400)    /* 1 Kbyte */
#define FLASH_SIZE                        (0x20000)  /* 128 KBytes */

#define ApplicationAddress    0x8003000
#define EEPROM_START_ADDRESS ((uint32_t)(0x8060000 - PAGE_SIZE*2)) /* EEPROM emulation start address: after 64KByte of used Flash memory */

#define CONFIG_AREA_SIZE		0x400
#define CONFIG_AREA_START ((uint32_t)(0x08000000 + FLASH_SIZE - PAGE_SIZE*(CONFIG_AREA_SIZE/PAGE_SIZE)))		




/*
	PRIORITY CONFIG
*/

#define GSM_PRIORITY  				1
#define RTC_ALARM_PRIORITY		1
#define TICK_PRIORITY 				1
#define RTCALARM_PRIORITY 		4
#define MODEMRI_PRIORITY 			1
#define TMR2_PRIORITY					4

#define ALARM_TIME		300//5min


#define TIMER_PERIOD	1	//ms

#define PHASEA_PORT			GPIOB
#define PHASEA_PIN			GPIO_IDR_IDR5
#define PHASEA_PIN_SET_INPUT		PHASEA_PORT->CRL	&= ~(GPIO_CRL_MODE5 | GPIO_CRL_CNF5);\
																												PHASEA_PORT->CRL	|=  GPIO_CRL_CNF5_1;\
																												PHASEA_PORT->ODR	|=  PHASEA_PIN
#define PHASEA_GET() 	(PHASEA_PORT->IDR & PHASEA_PIN)

#define PHASEB_PORT			GPIOB
#define PHASEB_PIN			GPIO_IDR_IDR8
#define PHASEB_PIN_SET_INPUT		PHASEB_PORT->CRH	&= ~(GPIO_CRH_MODE8 | GPIO_CRH_CNF8);\
																												PHASEB_PORT->CRH	|=  GPIO_CRH_CNF8_1;\
																												PHASEB_PORT->ODR	|=  PHASEB_PIN
#define PHASEB_GET() 	(PHASEB_PORT->IDR & PHASEB_PIN)

#define PHASEC_PORT			GPIOB
#define PHASEC_PIN			GPIO_IDR_IDR9
#define PHASEC_PIN_SET_INPUT		PHASEC_PORT->CRH	&= ~(GPIO_CRH_MODE9 | GPIO_CRH_CNF9);\
																												PHASEC_PORT->CRH	|=  GPIO_CRH_CNF9_1;\
																												PHASEC_PORT->ODR	|=  PHASEC_PIN
#define PHASEC_GET() 	(PHASEC_PORT->IDR & PHASEC_PIN)


#define PGOOD_PORT	GPIOB
#define PGOOD_PIN		GPIO_BSRR_BS1
#define PGOOD_PIN_SET_INPUT		PGOOD_PORT->CRL	&= ~(GPIO_CRL_MODE1 | GPIO_CRL_CNF1); PGOOD_PORT->CRL	|=  GPIO_CRL_CNF1_0
#define PGOOD_GET()								(PGOOD_PORT->IDR & PGOOD_PIN)

#define RS485_DIR_PORT	GPIOA
#define RS485_DIR_PIN		GPIO_BSRR_BS1
#define RS485_DIR_PIN_SET_OUTPUT	RS485_DIR_PORT->CRL	&= ~(GPIO_CRL_MODE1 | GPIO_CRL_CNF1); RS485_DIR_PORT->CRL	|= (GPIO_CRL_MODE1_0 | GPIO_CRL_MODE1_1)
#define RS485_DIR_PIN_SET					RS485_DIR_PORT->BSRR = RS485_DIR_PIN
#define RS485_DIR_PIN_CLR					RS485_DIR_PORT->BRR = RS485_DIR_PIN
#define RS485_DIR_GET()								(RS485_DIR_PORT->IDR & RS485_DIR_PIN)


#define RS232_PORT	GPIOB	
#define RS232_PIN		GPIO_BSRR_BS2
#define RS232_PIN_SET_OUTPUT	RS232_PORT->CRL	&= ~(GPIO_CRL_MODE2 | GPIO_CRL_CNF2); RS232_PORT->CRL	|= (GPIO_CRL_MODE2_0 ) 
#define RS232_PIN_SET_INPUT		RS232_PORT->CRL	&= ~(GPIO_CRL_MODE2 | GPIO_CRL_CNF2); RS232_PORT->CRL	|=  GPIO_CRL_CNF2_0
#define RS232_PIN_SET					RS232_PORT->BSRR = RS232_PIN
#define RS232_PIN_CLR					RS232_PORT->BRR = RS232_PIN

#define GSM_POWER_PORT	GPIOA
#define GSM_POWER_PIN		GPIO_BSRR_BS0
#define GSM_POWER_PIN_SET_OUTPUT	GSM_POWER_PORT->CRL	&= ~(GPIO_CRL_MODE0 | GPIO_CRL_CNF0); GSM_POWER_PORT->CRL	|= (GPIO_CRL_MODE0_0 ) //open drain
#define GSM_POWER_PIN_SET					GSM_POWER_PORT->BSRR = GSM_POWER_PIN
#define GSM_POWER_PIN_CLR					GSM_POWER_PORT->BRR = GSM_POWER_PIN

#define POWER_PORT	GPIOB
#define POWER_PIN		GPIO_BSRR_BS4
#define POWER_PIN_SET_OUTPUT	POWER_PORT->CRL	&= ~(GPIO_CRL_MODE4 | GPIO_CRL_CNF4); POWER_PORT->CRL	|= (GPIO_CRL_MODE4_0 | GPIO_CRL_CNF4_0) //open drain
#define POWER_PIN_SET					POWER_PORT->BSRR = POWER_PIN
#define POWER_PIN_CLR					POWER_PORT->BRR = POWER_PIN


#define RESET_PORT	GPIOB
#define RESET_PIN		GPIO_BSRR_BS3
#define RESET_PIN_SET_OUTPUT	RESET_PORT->CRL	&= ~(GPIO_CRL_MODE3 | GPIO_CRL_CNF3); RESET_PORT->CRL	|= (GPIO_CRL_MODE3_0 | GPIO_CRL_CNF3_0) 
#define RESET_PIN_SET					RESET_PORT->BSRR = RESET_PIN
#define RESET_PIN_CLR					RESET_PORT->BRR = RESET_PIN


#define RTS_PORT	GPIOA
#define RTS_PIN		GPIO_BSRR_BS12
#define RTS_PIN_SET_OUTPUT	RTS_PORT->CRH	&= ~(GPIO_CRH_MODE12 | GPIO_CRH_CNF12); RTS_PORT->CRH	|= (GPIO_CRH_MODE12_0 | GPIO_CRH_MODE12_1 | GPIO_CRH_CNF12_1) 
#define RTS_PIN_SET				RTS_PORT->BSRR = RTS_PIN
#define RTS_PIN_CLR					RTS_PORT->BRR = RTS_PIN

#define CTS_PORT	GPIOA
#define CTS_PIN		GPIO_BSRR_BS11
#define CTS_PIN_SET_INPUT		CTS_PORT->CRH	&= ~(GPIO_CRH_MODE11 | GPIO_CRH_CNF11); CTS_PORT->CRH	|=  GPIO_CRH_CNF11_0


#define DTR_PORT									GPIOB
#define DTR_PIN										GPIO_BSRR_BS14
#define DTR_PIN_SET_OUTPUT				DTR_PORT->CRH	&= ~(GPIO_CRH_MODE14 | GPIO_CRH_CNF14); DTR_PORT->CRH	|= (GPIO_CRH_MODE14_0) 
#define DTR_PIN_SET_INPUT					DTR_PORT->CRH	&= ~(GPIO_CRH_MODE14 | GPIO_CRH_CNF14); DTR_PORT->CRH	|=  GPIO_CRH_CNF14_0
#define DTR_PIN_SET								DTR_PORT->BSRR = DTR_PIN
#define DTR_PIN_CLR								DTR_PORT->BRR = DTR_PIN


#define DCD_PORT	GPIOB
#define DCD_PIN		GPIO_BSRR_BS15
#define DCD_PIN_SET_INPUT		DCD_PORT->CRH	&= ~(GPIO_CRH_MODE15 | GPIO_CRH_CNF15); DCD_PORT->CRH	|=  GPIO_CRH_CNF15_0
#define MODEM_DCD()								(DCD_PORT->IDR & DCD_PIN)


#define RI_PORT			GPIOA
#define RI_PIN			GPIO_IDR_IDR8
#define GET_RI_PIN 	(RI_PORT->IDR & RI_PIN)
#define RI_PIN_SET_INPUT		RI_PORT->CRH	&= ~(GPIO_CRH_MODE8 | GPIO_CRH_CNF8);\
														RI_PORT->CRH	|=  GPIO_CRl_CNF8_1;\
														RI_PORT->ODR	|=  RI_PIN



	
typedef enum{
	SYS_INIT = 0xA5A5,
	SYS_DEINIT = 0x5A5A,
	SYS_OK = 0
}SYS_STATUS;



#endif  /*__HW_CONFIG_H*/

