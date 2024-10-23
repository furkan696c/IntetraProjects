#include "led.h"
GPIO_InitTypeDef LED1pin;
void led1Config_Init(void)
{
	__HAL_RCC_GPIOF_CLK_ENABLE();
	LED1pin.Mode=GPIO_MODE_OUTPUT_PP;
	LED1pin.Pin=GPIO_PIN_2;
	HAL_GPIO_Init(GPIOF,&LED1pin);
	
}
GPIO_InitTypeDef LED2pin;
void led2Config_Init(void)
{
	__HAL_RCC_GPIOF_CLK_ENABLE();
	LED2pin.Mode=GPIO_MODE_OUTPUT_PP;
	LED2pin.Pin=GPIO_PIN_3;
	HAL_GPIO_Init(GPIOF,&LED2pin);
}
GPIO_InitTypeDef LED3pin;
void led3Config_Init(void)
{
	__HAL_RCC_GPIOF_CLK_ENABLE();
	LED3pin.Mode=GPIO_MODE_OUTPUT_PP;
	LED3pin.Pin=GPIO_PIN_4;
	HAL_GPIO_Init(GPIOF,&LED3pin);
}
GPIO_InitTypeDef LED4pin;
void led4Config_Init(void)
{
	__HAL_RCC_GPIOF_CLK_ENABLE();
	LED4pin.Mode=GPIO_MODE_OUTPUT_PP;
	LED4pin.Pin=GPIO_PIN_5;
	HAL_GPIO_Init(GPIOF,&LED4pin);
}