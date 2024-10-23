#include "stm32f7xx_hal.h"
void led1Config_Init(void);
void led2Config_Init(void);
void led3Config_Init(void);
void led4Config_Init(void);
#define LED1_TOGGLE HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_2)
#define LED2_TOGGLE HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_3)
#define LED3_TOGGLE HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_4)
#define LED4_TOGGLE HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_5)

#define LED1_ON HAL_GPIO_WritePin(GPIOF,GPIO_PIN_2,GPIO_PIN_SET)
#define LED2_ON HAL_GPIO_WritePin(GPIOF,GPIO_PIN_3,GPIO_PIN_SET)
#define LED3_ON HAL_GPIO_WritePin(GPIOF,GPIO_PIN_4,GPIO_PIN_SET)
#define LED4_ON HAL_GPIO_WritePin(GPIOF,GPIO_PIN_5,GPIO_PIN_SET)

#define LED1_OFF HAL_GPIO_WritePin(GPIOF,GPIO_PIN_2,GPIO_PIN_RESET)
#define LED2_OFF HAL_GPIO_WritePin(GPIOF,GPIO_PIN_3,GPIO_PIN_RESET)
#define LED3_OFF HAL_GPIO_WritePin(GPIOF,GPIO_PIN_4,GPIO_PIN_RESET)
#define LED4_OFF HAL_GPIO_WritePin(GPIOF,GPIO_PIN_5,GPIO_PIN_RESET)
