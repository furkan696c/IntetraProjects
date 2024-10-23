
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32f7xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */
#include "mcp9701.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{

  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_RCC_SYSCFG_CLK_ENABLE();

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/* USER CODE BEGIN 1 */
void HAL_ADC_MspInit(ADC_HandleTypeDef* adcHandle)
 {
   GPIO_InitTypeDef GPIO_InitStruct = {0};
   if(adcHandle->Instance==MCP_ADCBASE)
   {
 	 MCP_ADC_CLOCK_ON;
 	 MCP_GPIO_CLOCK_ON;
     GPIO_InitStruct.Pin = MCP_PIN;
     GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     HAL_GPIO_Init(MCP_PORT, &GPIO_InitStruct);
   }
 }
 void HAL_ADC_MspDeInit(ADC_HandleTypeDef* adcHandle)
 {
   if(adcHandle->Instance==MCP_ADCBASE)
   {
 	MCP_ADC_CLOCK_OFF;
     HAL_GPIO_DeInit(MCP_PORT, MCP_PIN);
   }
 }

/* USER CODE END 1 */
