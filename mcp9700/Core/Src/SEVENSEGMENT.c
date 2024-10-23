/*
 * SEVENSEGMENT.c
 *
 *  Created on: Jun 28, 2024
 *      Author: FURKAN ÇALIŞKAN
 */
#include <stdio.h>
#include "SEVENSEGMENT.h"

void display_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	 __HAL_RCC_GPIOC_CLK_ENABLE();
	 __HAL_RCC_GPIOE_CLK_ENABLE();
	 __HAL_RCC_GPIOD_CLK_ENABLE();
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC, DPY_BL_2| DPY_LE_2, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOE,
			DPY_D2 | DPY_D1 | DPY_D3 | DPY_D0 | DPY_BL_1,
			GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(DPY_LE_1_PORT, DPY_LE_1, GPIO_PIN_RESET);

	/*Configure GPIO pins : PCPin PCPin */
	GPIO_InitStruct.Pin = DPY_BL_2 | DPY_LE_2;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pin : PB1 */
	GPIO_InitStruct.Pin = GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : PEPin PEPin PEPin PEPin
	 PEPin */
	GPIO_InitStruct.Pin = DPY_D2 | DPY_D1 | DPY_D3 | DPY_D0
			| DPY_BL_1;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = DPY_LE_1;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(DPY_LE_1_PORT, &GPIO_InitStruct);
}

void segmentDISPLAY(uint8_t x)
{
	HAL_GPIO_WritePin(DPY_D0_PORT, DPY_D0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DPY_D1_PORT, DPY_D1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DPY_D2_PORT, DPY_D2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DPY_D3_PORT, DPY_D3, GPIO_PIN_RESET);

	uint8_t karsilastir=15;
	karsilastir=karsilastir&x;
	if (karsilastir & (1 << 0))
	{
		HAL_GPIO_WritePin(DPY_D0_PORT, DPY_D0, GPIO_PIN_SET);
	}
	if (karsilastir & (1 << 1))
	{
		HAL_GPIO_WritePin(DPY_D1_PORT, DPY_D1, GPIO_PIN_SET);
	}
	if (karsilastir & (1 << 2))
	{
		HAL_GPIO_WritePin(DPY_D2_PORT, DPY_D2, GPIO_PIN_SET);
	}
	if (karsilastir & (1 << 3))
	{
		HAL_GPIO_WritePin(DPY_D3_PORT, DPY_D3, GPIO_PIN_SET);
	}
}
void display_Write(int8_t number) //number value must be between 0-99 for two segment.
{
	if(number>99)
	{
		number = 99;
	}
	else if(number < 0)
	{
		number = 0;
	}

	uint8_t z;
	//display1 open
	HAL_GPIO_WritePin(DPY_BL_2_PORT, DPY_BL_2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(DPY_LE_2_PORT, DPY_LE_2, GPIO_PIN_RESET);
	z = number % 10;
	segmentDISPLAY(z);
	HAL_Delay(Display1_Delay);
	//display1 close
	HAL_GPIO_WritePin(DPY_BL_2_PORT, DPY_BL_2, GPIO_PIN_RESET);

	//display2 open
	HAL_GPIO_WritePin(DPY_BL_1_PORT, DPY_BL_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(DPY_LE_1_PORT, DPY_LE_1, GPIO_PIN_RESET);
	z = number / 10;
	segmentDISPLAY(z);
	HAL_Delay(Display2_Delay);

	//display2 close
	HAL_GPIO_WritePin(DPY_BL_1_PORT, DPY_BL_1, GPIO_PIN_RESET);
}
