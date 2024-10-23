#include "stm32f7xx_hal.h"
#include "rl_net_ds.h"
#ifdef _RTE_
#include "RTE_Components.h"             // Component selection
#endif
#ifdef RTE_CMSIS_RTOS2                  // when RTE component CMSIS RTOS2 is used
#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
#endif


#define SERVERIP {192,168,50,17}
#define SERVERPORT 2000


uint32_t __WEAK udp_cb_func (int32_t socket, const NET_ADDR *addr, const uint8_t *buf, uint32_t len);
void sendUDP (uint8_t *sendbuf,uint16_t size);
void udpInit(void);
