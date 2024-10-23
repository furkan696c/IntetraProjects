/*
 * mcp9701.h
 *
 *  Created on: Jul 1, 2024
 *      Author: ASUS
 */

#ifndef INC_MCP9701_H_
#define INC_MCP9701_H_



#endif /* INC_MCP9701_H_ */

#include "main.h"
/*sensor define*/

#define MCP_PIN GPIO_PIN_0
#define MCP_PORT GPIOA
#define MCP_ADCBASE ADC1
#define MCP_ADC_CHANNEL ADC_CHANNEL_0

#define MCP_ADC_CLOCK_ON  __HAL_RCC_ADC1_CLK_ENABLE()
#define MCP_ADC_CLOCK_OFF __HAL_RCC_ADC1_CLK_DISABLE()
#define MCP_GPIO_CLOCK_ON __HAL_RCC_GPIOA_CLK_ENABLE()

/*relay define*/
#define TRIGGER_PIN GPIO_PIN_12
#define TRIGGER_PORT GPIOE

#define RELAY_CLOCK_ENABLE __HAL_RCC_GPIOE_CLK_ENABLE()
#define RELAY_CLOCK_DISABLE __HAL_RCC_GPIOE_CLK_DISABLE()

#define RELAY_ON HAL_GPIO_WritePin(TRIGGER_PORT, TRIGGER_PIN, GPIO_PIN_SET)
#define RELAY_OFF HAL_GPIO_WritePin(TRIGGER_PORT, TRIGGER_PIN, GPIO_PIN_RESET)

#define TRIGGER_DEG 25 //temperature value at which the relay will be triggered.
#define HYSTERESIS 2 //

void mcp9701Init(void);
uint32_t mcpGetValue(void);
void RELAY_DRIVE(uint32_t temp);

