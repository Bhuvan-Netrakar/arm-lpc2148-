#include<lpc21xx.h>
void delay()
{
	unsigned int i;
	for (i=0;i<=1000000;i++);
}
void stapermoter()
{
{
	PINSEL0=0x00ffffff;
	IO0DIR |=0x00ffffff;
	while(1)
	{
		for(j=0;j<50;j++)
		{
		staperclockwise();
		}
	}
}
}
void staperclockwise()
{
	var1=0x00000800;
	for(i=0;i<=3;i++)
	{
		var1=var1<<1;
		IO0PIN=var1;
		for(k=0;k<30000;k++);
	}
}
 
void dcmoter()
{
	{
	IO0DIR=0x00000900;
	IO0SET=0x00000100;
	while(1)
	{
	 x=IO0PIN;
	 x=x&0x00000100;
		if(x==0x00001000)
		{
			dcanti_clockwise();
			for(j=0;j<400000;j++);
		}
	}
}
	}
 void dcanti_clockwise(void)
{
	IO0CLR=0X00000100;
	for(j=0;j<=1000000;j++);
	IO0SET = 0x00000100;
}
int main()
{
	 
	unsigned int i;
	PINSEL1 = 0x00000000;
  IO0DIR = 0X000F0000;
  IOSET0=0x000f0000;
	while (1)
	{
	if((IOPIN0&0x0000f000)==0x0000f000)
	{
		dcmoter();
		delay();
	}
 else
 { 
	 dcanti_clockwise();
	 delay();
	 
 }
 }
}
