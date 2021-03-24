#include<reg51.h>

sfr SEG=0XA0;

// add delay function


void Delay(unsigned int t)
{
unsigned int i;
while(t--)
for(i=0;i<1257;i++);
}

main()
{
unsigned char Val[10]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};//common anode
int i;
SEG=0X00;
while(1)
{
	for(i=0;i<10;i++)
	{
		SEG=Val[i];
		Delay(200);
	}
}
}
