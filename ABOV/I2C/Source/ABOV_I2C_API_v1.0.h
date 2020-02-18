/***************************************************************************//**
*   @file					ABOV_USI_I2C.h
*   @brief				USI Peripheral Function 
*   @author		PTS Team, ABOV Semiconductor Co., Ltd.
*   @version		V0.0.1
*   @date				04. Feb. 2020
*
* Copyright(C) 2020, ABOV Semiconductor
* All rights reserved.
*
********************************************************************************
* DISCLAIMER 
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, ABOV SEMICONDUCTOR DISCLAIMS ALL LIABILITIES FROM ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
*******************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USI_I2C_H_
#define __USI_I2C_H_
/*******************************************************************************
* Included File
*******************************************************************************/
#include <stdint.h>


/*******************************************************************************
* I2C Mode Selection
*******************************************************************************/
#if 1	// I2C Interrupt Mode
#define	I2C_INTERRUPT
#else	// I2C Polling Mode
#define	I2C_POLLING
#endif


/*******************************************************************************
* Public Macro
*******************************************************************************/
#define I2C_DEVICE_ADDRESS			0xA0
#define I2C_SLAVE_OWN_ADDR		0xA0
#define I2C_SPEED											10000

#define I2C_MAX_BUFFER_SIZE		20
#define I2C_MAX_CHANNEL					2

#define I2C_CH0														0
#define I2C_CH1														1

#define I2C_ACK_DISABLE						0
#define I2C_ACK_ENABLE							1

#define I2C_WRITE_MODE						0
#define I2C_READ_MODE							1

#define I2C_IDLE													0
#define I2C_BUSY												1

#define I2C_TRUE												1
#define I2C_FALSE												0
/*******************************************************************************
* Public Typedef
*******************************************************************************/
enum  i2c_control_flags{								// I2C Control Register Flags
	fI2CnEN					= (1<<7),
	fTXDLYENBn		= (1<<6),
	fI2CnIEN					= (1<<5),
	fI2CnIFLAG			= (1<<4),
	fACKnEN					= (1<<3),
	fIMASTERn			= (1<<2),
	fSTOPCn				= (1<<1),
	fSTARTCn			= (1<<0),
};
enum  i2c_status_flags{								// I2C Status Register Flags
	fGCALL						= (1<<7),
	fTEND							= (1<<6),
	fSTOPD					= (1<<5),
	fSSEL							= (1<<4),
	fMLOST					= (1<<3),
	fBUSY						= (1<<2),
	fTMODE					= (1<<1),
	fRXACK						= (1<<0),
};

/*******************************************************************************
* Exported Public Function
*******************************************************************************/
void USI_I2C_Initial(uint8_t ch, uint32_t speed, uint8_t addr, uint8_t ack);
void USI_I2C_Enable(uint8_t ch, uint8_t enable);
void USI_I2C_ConfigureGerneralCall(uint8_t ch, uint8_t enable);
void USI_I2C_ConfigureAcknowledge(uint8_t ch, uint8_t enable);
void USI_I2C_SoftwareReset(uint8_t ch, uint8_t enable);

void USI_I2C_MasterTransferData(uint8_t ch, uint8_t dev_addr, uint8_t *write_data, uint8_t write_len, uint8_t *read_data, uint8_t read_len);
void USI_I2C_ConfigureInterrupt(uint8_t ch, uint8_t enable);
uint8_t USI_I2C_GetInterruptStatus(uint8_t ch);
void USI_I2C_InterruptHandler(uint8_t ch);

void USI_I2C_SetSlaveData(uint8_t ch);

#endif  /* End of __USI_I2C_H_ */
/************************ (C) COPYRIGHT ABOV SEMICONDUCTOR *****END OF FILE****/