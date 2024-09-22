#include<lpc21xx.h>
#include<stdio.h>
void delay(unsigned int);
void extint0_ISR(void)__irq;
void delay(unsigned int);
int main(void)
{
	PINSEL1=0x00000001;
	EXTMODE=0x00000001;
	VICVectAddr0=(unsigned long)extint0_ISR;
	VICVectCntl0=0x20|14;
	VICIntEnable |= 0x00004000;
	while(1);
}
void extint0_ISR(void)__irq
{
	PINSEL0=0X0000000;
	IODIR0=0X000f0000;
	IOCLR0=0x000f0000;
  delay(100000);
	IOSET0=0x0000f000;
	delay(100000);
	EXTINT |=0x00000001;
  VICVectAddr=0;
}
void delay(unsigned int x)
{
	unsigned int i;
	for(i=0;i<x;i++);
}