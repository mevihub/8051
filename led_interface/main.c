#include<AT89x51.H>

sfr led = 0xA0;

void delay(unsigned int t)
{
	unsigned int i;
	while(t--)
		for(i=0;i<1257;i++);
}

main()
{
	led = 0x00;
	while(1)
	{
		led = 0xff;
		delay(100);
		led= 0x00;
		delay(100);
	}
}
