#include<reg51.h>

void UART_Init()
{
	SCON=0X50;//8 bit 1 start
	TMOD=0X20;//8 bit mode2
	TH1=0Xfd;//baud rate 9600
	TR1=1;//start timer
}

unsigned char recieve()
{
unsigned char ch;
while(RI==0);//wait for receive
ch=SBUF;//save ch
RI=0;
return(ch);
}


main()
{
P2=0X00;
UART_Init();
while(1)
{
P2=recieve();
}
}
	
	