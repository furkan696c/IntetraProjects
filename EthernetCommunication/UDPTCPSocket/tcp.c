#include "tcp.h"
	  int32_t tcp_sock;

uint32_t __WEAK tcp_cb_func (int32_t socket, netTCP_Event event,const NET_ADDR *addr, const uint8_t *buf, uint32_t len)
{
  return (0);
}

void tcpInit(void)
{
 	netInitialize ();
	  // Initialize TCP Socket and start listening on port 49152
  tcp_sock = netTCP_GetSocket (tcp_cb_func);
  if (tcp_sock >= 0) {
    netTCP_Listen (tcp_sock,TCPSERVERPORT);
  }
}
void sendTCP(uint8_t *sendbuf,uint16_t size)
{
	uint8_t *sendData;
	if(netTCP_SendReady(tcp_sock))
	{
	sendData = netTCP_GetBuffer (size);
		for(int i = 0 ;i<size;i++)
		{
			sendData[i]=sendbuf[i];
		}

 netTCP_Send (tcp_sock, sendData, size);
	}
}
