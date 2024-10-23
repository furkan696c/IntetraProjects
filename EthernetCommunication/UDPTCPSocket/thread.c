	#include "thread.h"
uint8_t command;
uint8_t receiveCommandFlag;

uint8_t led1onData[]="LED1_ON\n";
uint8_t led1offData[]="LED1_OFF\n";
uint8_t led2onData[]="LED2_ON\n";
uint8_t led2offData[]="LED2_OFF\n";
uint8_t led3onData[]="LED3_ON\n";
uint8_t led3offData[]="LED3_OFF\n";
uint8_t led4onData[]="LED4_ON\n";
uint8_t led4offData[]="LED4_OFF\n";
uint8_t led1toggleData[]="LED1_TOGGLE\n";
uint8_t led2toggleData[]="LED2_TOGGLE\n";
uint8_t led3toggleData[]="LED3_TOGGLE\n";
uint8_t led4toggleData[]="LED4_TOGGLE\n";

uint8_t overmessageError[]="Can take values from 0 to 11\n";
/*
*If you are using udp enable the following function
*/

//		uint32_t udp_cb_func (int32_t socket, const NET_ADDR *addr, const uint8_t *buf, uint32_t len)
//{
//	UNUSED(socket);
//	UNUSED(addr);
//	UNUSED(len);
//if(buf[0]<=11)
//{
//	command = buf[0];
//}	
//else
//{
//	command=errorMessage;
//}

//	switch(command)
//	{
//		case LED1ON:
//			sendUDP(led1onData,sizeof(led1onData));
//			LED1_ON;
//		break;
//		case LED2ON:
//			sendUDP(led2onData,sizeof(led2onData));	
//			LED2_ON;
//		break;
//		case LED3ON:
//			sendUDP(led3onData,sizeof(led3onData));	
//		  LED3_ON;
//		break;
//		case LED4ON:
//			sendUDP(led4onData,sizeof(led4onData));
//			LED4_ON;		
//		break;
//		case LED1OFF:
//			sendUDP(led1offData,sizeof(led1offData));	
//			LED1_OFF;
//		break;
//		case LED2OFF:		
//			sendUDP(led2offData,sizeof(led2offData));
//			LED2_OFF;		
//		break;
//		case LED3OFF:		
//			sendUDP(led3offData,sizeof(led3offData));	
//			LED3_OFF;		
//		break;	
//		case LED4OFF:		
//			sendUDP(led4offData,sizeof(led4offData));	
//			LED4_OFF;		
//		break;	
//		case LED1TOGGLE:
//			sendUDP(led1toggleData,sizeof(led1toggleData));
//			LED1_TOGGLE;
//		break;
//		case LED2TOGGLE:
//			sendUDP(led2toggleData,sizeof(led2toggleData));
//			LED2_TOGGLE;		
//		break;
//		case LED3TOGGLE:
//			sendUDP(led3toggleData,sizeof(led3toggleData));
//			LED3_TOGGLE;		
//		break;
//		case LED4TOGGLE:
//			sendUDP(led4toggleData,sizeof(led4toggleData));
//			LED4_TOGGLE;		
//		break;
//		case errorMessage:
//			sendUDP(overmessageError,sizeof(overmessageError));
//		break;

//	}
//	return(0);
//}
uint32_t tcp_cb_func (int32_t socket, netTCP_Event event,const NET_ADDR *addr, const uint8_t *buf, uint32_t len)
{
		switch (event) {
    case netTCP_EventConnect:
      // Connect request received in server mode
      if (addr->addr_type == NET_ADDR_IP4) {
        // IPv4 client
        if (addr->addr[0] == 192  &&
            addr->addr[1] == 168  &&
            addr->addr[2] == 50    &&
            addr->addr[3] == 17) 
			  {
          // Accept connection from client at 192.168.50.17
          return (1);
        }
			}
			
      // Deny connection.
      return (0);	
    case netTCP_EventEstablished:
      // Connection established
      break;
 
    case netTCP_EventClosed:
      // Connection was properly closed
      break;
 
    case netTCP_EventAborted:
      // Connection is for some reason aborted
      break;
 
    case netTCP_EventACK:
      // Previously sent data acknowledged
      break;
 
    case netTCP_EventData:
      // Data received
if(buf[0]<=11)
{
	command = buf[0];
}	
else
{
	command=errorMessage;
}
receiveCommandFlag =1;

      break;
  }
  return (0);
}

		
 	__NO_RETURN void ledblinkThread (void *arg)
{

    (void)arg;

	for(;;)
	{
		if(receiveCommandFlag==1)
		{
					receiveCommandFlag=0;
			switch(command)
				{
				case LED1ON:
					sendTCP(led1onData,sizeof(led1onData));
					LED1_ON;
				break;
				case LED2ON:
					sendTCP(led2onData,sizeof(led2onData));	
					LED2_ON;
				break;
				case LED3ON:
					sendTCP(led3onData,sizeof(led3onData));	
					LED3_ON;
				break;
				case LED4ON:
					sendTCP(led4onData,sizeof(led4onData));
					LED4_ON;		
				break;
				case LED1OFF:
					sendTCP(led1offData,sizeof(led1offData));	
					LED1_OFF;
				break;
				case LED2OFF:		
					sendTCP(led2offData,sizeof(led2offData));
					LED2_OFF;		
				break;
				case LED3OFF:		
					sendTCP(led3offData,sizeof(led3offData));	
					LED3_OFF;		
				break;	
				case LED4OFF:		
					sendTCP(led4offData,sizeof(led4offData));	
					LED4_OFF;		
				break;	
				case LED1TOGGLE:
					sendTCP(led1toggleData,sizeof(led1toggleData));
					LED1_TOGGLE;
				break;
				case LED2TOGGLE:
					sendTCP(led2toggleData,sizeof(led2toggleData));
					LED2_TOGGLE;		
				break;
				case LED3TOGGLE:
					sendTCP(led3toggleData,sizeof(led3toggleData));
					LED3_TOGGLE;		
				break;
				case LED4TOGGLE:
					sendTCP(led4toggleData,sizeof(led4toggleData));
					LED4_TOGGLE;		
				break;
				case errorMessage:
					sendTCP(overmessageError,sizeof(overmessageError));
				break;
				}	
			}
	}
}