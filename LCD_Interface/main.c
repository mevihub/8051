
#include <reg51.h>

sbit RS=P3^0;
sbit RW=P3^1;
sbit EN=P3^2;

sfr LCD=0XA0;

// delay function 
void Delay(unsigned int t)
{
unsigned int i;
while(t--)
for(i=0;i<1257;i++);
}

// lcd cmd lines

void lcd_cmd(unsigned char ch)
{
LCD=ch;
RS=0;
RW=0;
EN=1;
Delay(3);
EN=0;
}

// lcd data commands 

void lcd_data(unsigned char ch)
{
LCD=ch;
RS=1;
RW=0;
EN=1;
Delay(3);
EN=0;
}


// lcd init fuction

void lcd_init()
{
lcd_cmd(0X38);//Use 2 lines and 5×7 matrix
lcd_cmd(0X06);//Increment cursor
lcd_cmd(0X0C);//Display ON ,Cursor blinking OFF
lcd_cmd(0X01);//Clear screen
lcd_cmd(0X80);//start display from first line first charcater
}
 
// lcd print 

void lcd_print(unsigned char *str)
{
while(*str)
{
lcd_data(*str);
str++;	}
}

main()
{
	while(1)
	{
	lcd_init();
	lcd_cmd(0X80);//Cursor line 1 position 4
	lcd_print("WelCome embedded");
	lcd_cmd(0XC0);//For  2nd line
	lcd_print("LCD INTERFACING");
	lcd_cmd(0X94);//for third line
	lcd_print("well come");
	lcd_cmd(0XD4);//for fourth line
	lcd_print("DEVIL ");
	}
}