#include "stm32f7xx_hal.h"
#include "udp.h"
#include "tcp.h"
#include "led.h"

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef _RTE_
#include "RTE_Components.h"             // Component selection
#endif
#ifdef RTE_CMSIS_RTOS2                  // when RTE component CMSIS RTOS2 is used
#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
#endif


__NO_RETURN void ledblinkThread (void *arg);

enum toggleState {
	LED1ON = 0,
	LED2ON,
	LED3ON,
	LED4ON,
	LED1OFF,
	LED2OFF,
	LED3OFF,
	LED4OFF,
	LED1TOGGLE,
	LED2TOGGLE,
	LED3TOGGLE,
	LED4TOGGLE,
	errorMessage
};
	