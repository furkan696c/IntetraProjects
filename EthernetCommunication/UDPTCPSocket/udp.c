#include "udp.h"
#include "led.h"

#include "string.h"

int32_t udp_soc;
NET_ADDR addr={NET_ADDR_IP4,SERVERPORT,SERVERIP};
uint8_t mac_addr [NET_ADDR_ETH_LEN];
uint8_t ip4_addr [NET_ADDR_IP4_LEN];


/*
*The function is defined to get socket information. The callback function runs when a message arrives.
*/

 uint32_t __WEAK udp_cb_func (int32_t socket, const NET_ADDR *addr, const uint8_t *buf, uint32_t len)
{
	return (0);
}

void udpInit(void)
{
	netInitialize();	
	
	udp_soc = netUDP_GetSocket(udp_cb_func);
	if(udp_soc >0)
	{
  netUDP_Open(udp_soc, 0); //If you set the port value to 0, it will automatically assign the port value.
	}	
	
	netUDP_SetOption (udp_soc, netUDP_OptionTTL, 2);
	netIP_aton ("192.168.50.17", NET_ADDR_IP4, ip4_addr);
}

/*
* maximum UDP payload size over IPv4 is between 8-10 kbytes
*/

void sendUDP (uint8_t *sendbuf,uint16_t size)
{
			while (netARP_GetMAC (NET_IF_CLASS_ETH | 0, ip4_addr, mac_addr) != netOK)
				{
  // Requested IP address not yet cached
		netARP_CacheIP (NET_IF_CLASS_ETH | 0, ip4_addr, netARP_CacheTemporaryIP);	
				}
			  
			uint8_t *senddata;
			senddata=netUDP_GetBuffer (size);
				for(int i = 0;i<size;i++)
				{
					senddata[i]=sendbuf[i];
				}

			netUDP_Send(udp_soc,(NET_ADDR *)&addr,senddata,size);
}



//uint8_t *senddata;
//senddata= netudp_getbuffer(2);
//senddata[0]=0x61;
//senddata[1]=0x62;
//netUDP_Send(udp_soc,(NET_ADDR *)&addr,senddata,size);


//uint8_t data[2]
//data[0]=0x61;
//data[1]=0x61;
//data= netudp_getbuffer(2) !!!!!
//netUDP_Send(udp_soc,(NET_ADDR *)&addr,senddata,size); -->netInvalidParameter

