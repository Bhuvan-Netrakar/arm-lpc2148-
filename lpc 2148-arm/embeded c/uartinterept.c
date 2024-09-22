#include<stdio.h>
void serial(void);
void delayuart(void);
void delay(unsigned int);
void extint0_ISR(void)__irq;
void delay(unsigned int);
int main(void)
{
	PINSEL1=0x00000001;
	EXTMODE=0x00000001;
	VICVectAddr0=(unsigned long)extint0_ISR;
	VI#include<lpc21xx.h>
CVectCntl0=0x20|14;
	VICIntEnable |= 0x00004000;
	while(1);
}
void extint0_ISR(void)__irq

	{
	unsigned int mg;
	unsigned int i;
	unsigned char msg[]=("BHUVAN");
	//serial();
	//while(1)
	//{
		for(i=0;i<6;i++)
		{
		 while(!(U0LSR&0x20));
			U0THR=msg[i];
			delay(1000000);
			EXTINT |=0x00000001;
      VICVectAddr=0; 
		}
	}

void delay(unsigned int x)
{
	unsigned int i;
	for(i=0;i<x;i++);
}
 void serial()
	{
		PINSEL0=0x00000005;
		U0LCR=0x83;
		U0DLL=0x61;
		U0LCR=0x03;
	}
		