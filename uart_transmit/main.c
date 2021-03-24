#include<reg51.h>

// uart init

void UART_Init()
{
	SCON=0X50;//8 bit 1 start
	TMOD=0X20;//8 bit mode2
	TH1=0Xfd;//253 baud rate 9600
	TR1=1;//start timer
}

// uart send charector

void send_char(unsigned char ch)
{
	SBUF=ch;
	while(TI==0);//wait for transmit
	TI=0;
}

// uart send string 

void send(unsigned char *str)
{
	while(*str)
	{
		send_char(*str);
		str++;
	}
}

main()
{
	UART_Init();
	while(1)
	{
		
	send("welcome to embedded system\r\n");
	}
	
}
