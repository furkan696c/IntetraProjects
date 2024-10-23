/*
 * SEVENSEGMENT.h
 *
 *  Created on: Jun 28, 2024
 *      Author: FURKAN ÇALIŞKAN
 */
#include "stm32f7xx_hal.h"

#ifndef INC_SEVENSEGMENT_H_
#define INC_SEVENSEGMENT_H_

#endif /* INC_SEVENSEGMENT_H_ */

#define DPY_D0 GPIO_PIN_14
#define DPY_D1 GPIO_PIN_11
#define DPY_D2 GPIO_PIN_10
#define DPY_D3 GPIO_PIN_13
#define DPY_BL_1 GPIO_PIN_15
#define DPY_LE_1 GPIO_PIN_14
#define DPY_BL_2 GPIO_PIN_0
#define DPY_LE_2 GPIO_PIN_2

#define DPY_D0_PORT GPIOE
#define DPY_D1_PORT GPIOE
#define DPY_D2_PORT GPIOE
#define DPY_D3_PORT GPIOE

#define DPY_BL_2_PORT GPIOC
#define DPY_LE_2_PORT GPIOC

#define DPY_BL_1_PORT GPIOE
#define DPY_LE_1_PORT GPIOD
#define Display1_Delay 5
#define Display2_Delay 2

void display_Init(void);
void segmentDISPLAY(uint8_t x);

void display_Write(int8_t number);
