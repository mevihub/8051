#include<reg52.h>

sbit motor_pin = P2^0;

// add delay function

void Delay(unsigned int t)
{
	unsigned int i;
	while(t--)
	for(i=0;i<1257;i++);
	
}


void main()
{
  motor_pin = 0;

  while(1)
  {
    //Turn to 0 degree
    motor_pin = 1;
    Delay(100);
    motor_pin = 0;

    Delay(100);

    
  }
}
