#include <lpc21xx.h>
void delay(void);
void extint0_ISR(void);
void delay(void);
void serial(void);
unsigned char msg[]="ROHIT";
unsigned int i;

//unsigned char mg;


int main(void)
{
	PINSEL1=0x00000001;
	EXTMODE=0x01;
	VICVectAddr0=(unsigned long)extint0_ISR;
	VICVectCntl0=0x20|14;
	VICIntEnable |= 0X00004000;
	while(1);
}
void send(unsigned char mg)
{
		 while(!(U0LSR&0X20));
     U0THR=mg;
}
void serial(void)
{
		PINSEL0=0x05;
		U0LCR=0x83;
		U0DLL=0x61;
		U0LCR=0x03;
}
void extint0_ISR(void)
{
	serial();
  for(i=0;msg[i]!='\0';i++)
  {
		send(msg[i]);
  }
  EXTINT !=0x00000001;
  VICVectAddr=0;
}		
void delay()
{
		unsigned int i;
		for(i=0;i<10000;i++);
}
