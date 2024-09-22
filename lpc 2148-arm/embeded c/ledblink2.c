#include<lpc21xx.h>
void delay(void);
unsigned int i;

 int main()
{
	PINSEL0=0X00000000;
	PINSEL1=0X00000000;
  IODIR0=0x000f0000;
	IOSET0=0x000f0000;
  while(1)
	{
		if((IOPIN0&0x00001000)==0x00001000)
		{
			IOCLR0=0x000f0000;
			delay();
			IOSET0=0x000f0000;
			delay();
		}
		else
		{
			IOSET0=0x000f0000;
		}
	}
}
void delay()
{
	for(i=0;i<=1000000;i++);
}
		
