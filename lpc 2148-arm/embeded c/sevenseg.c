#include <lpc21xx.h>
void delay(void);
void delay(void)
 {
	 unsigned long int j; 
	   for (j=0;j<500000;j++);
 }
  int main()
	{
		unsigned char i;
		unsigned int Disp[16]={0x0003f000,0x00060000,0x005b000,0x004F0000,0X00660000,0X006D0000,0X007D0000,0X00070000,0X007F0000,0X006F0000,
			0X00770000,0X007C0000,0X00390000,0X005E50000,0X00790000,0X00710000};
		PINSEL1=0X00000000;
		PINSEL0=0X00000000;
		IODIR0=0XC0FF0000;
		IOSET0=0X00000000;
		IOCLR0=0X00FF0000;
		
		while(1)
		{
			for(i=0;i<10;i++)
			{
				IOSET0=Disp[i];
				delay();
				delay();
				delay();
				delay();
				delay();
				delay();
				delay();
				IOCLR0=0X00FF0000;
			}
		}
	}

	   
	