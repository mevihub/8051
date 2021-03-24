#include<AT89X51.H>

sbit led = P2^7;
sbit sw = P2^0;

void delay(unsigned int t)
{
	unsigned int i;
	while(t--)
		for(i=0;i<1257;i++);
}

main()
{
	led = 0;
	sw = 1;
	while(1)
	{
		if(sw == 0)
		{
			delay(10);
			led = 1;
		}
		else
			led = 0;
	}
}
