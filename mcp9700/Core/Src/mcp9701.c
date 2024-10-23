/*
 * mcp9701.c
 *
 *  Created on: Jul 1, 2024
 *      Author: FURKAN ÇALIŞKAN
 */
#include "mcp9701.h"
ADC_HandleTypeDef hadc1;
void mcp9701Init(void)
{
	 ADC_ChannelConfTypeDef sConfig = {0};
	 hadc1.Instance = MCP_ADCBASE;

	 hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	 hadc1.Init.Resolution = ADC_RESOLUTION_10B;
	 hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
	 hadc1.Init.ContinuousConvMode = ENABLE;
	 hadc1.Init.DiscontinuousConvMode = DISABLE;
	 hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	 hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	 hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	 hadc1.Init.NbrOfConversion = 1;
	 hadc1.Init.DMAContinuousRequests = DISABLE;
	 hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	  if (HAL_ADC_Init(&hadc1) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sConfig.Channel = MCP_ADC_CHANNEL;
	  sConfig.Rank = ADC_REGULAR_RANK_1;
	  sConfig.SamplingTime = ADC_SAMPLETIME_112CYCLES;
	  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	/* GPIO Ports Clock Enable */
	    RELAY_CLOCK_ENABLE;
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(TRIGGER_PORT, TRIGGER_PIN, GPIO_PIN_RESET);

	/*Configure GPIO pin : PE12 */
	GPIO_InitStruct.Pin = TRIGGER_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(TRIGGER_PORT, &GPIO_InitStruct);
}

uint32_t mcpGetValue(void)
{
	uint32_t ADC_value;
	int32_t temperature_value;
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 1000);
	ADC_value = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);
	temperature_value = ((ADC_value * 3.3) / 1024 - 0.5) / 0.0195;
	return temperature_value;
	//return ADC_value;
}
void RELAY_DRIVE(uint32_t temp)//Enter the temperature value at which the relay will be triggered.value must be between -50,150
{
	if (temp >= TRIGGER_DEG)
	{
		RELAY_ON;
	}
	if((TRIGGER_DEG-HYSTERESIS)>=temp)
	{
		RELAY_OFF;
	}
}
