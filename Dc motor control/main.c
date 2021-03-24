#include<reg51.h>

sbit motor_1 = P2^0;
sbit motor_2 = P2^1;
sbit motor_3 = P2^2;
sbit motor_4 = P2^3;
// add delay function

void delay(unsigned int t)
{
	unsigned int i;
	while(t--)
		for(i=0;i<1257;i++);
}

void main()
{
  while(1)
  {
    motor_1 = 1;
    motor_2 = 0; //Rotates Motor  Clockwise
		motor_3 = 1;
    motor_4 = 0; //Rotates Motor  Clockwise
    delay(100);
    motor_1 = 1;
    motor_2 = 1; //Stops Motor
		motor_3 = 1;
    motor_4 = 1; //Stops Motor
    delay(100);
    motor_1 = 0;
    motor_2 = 1; //Rotates Motor anti Clockwise
		motor_3 = 0;
    motor_4 = 1; //Rotates Motor anti Clockwise
    delay(100);
    motor_1 = 0;
    motor_2 = 0; //Stops Motor
		motor_3 = 0;
    motor_4 = 0; //Stops Motor
    delay(10);
  }
}