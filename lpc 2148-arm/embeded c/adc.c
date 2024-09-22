#include<lpc214x.h>
#include<stdio.h> 
unsigned int i;
void delay(unsigned long int r1)
{
	unsigned long int r;
	for(r=0;r<r1;r++);
}
unsigned int adc_value=0,temp_adc=0;
char val[30];
void serial()
{
	PINSEL0=0x00000005;
	U0LCR=0x00000083;
	U0DLM=0x00;
	U0DLL=0x61;
	U0LCR=0x000000003;
}
int main()
{
PINSEL1=0x00040000;
serial();
	
while(1)
{
	AD0CR=0x09200010;
	delay(100);
	while(!(AD0GDR)==0x80000000);
	adc_value=AD0GDR;
	adc_value>>=6;
	adc_value&=0x000003ff;
	sprintf(val,"The digital value is %x\n",adc_value);
	while(val[i]!='\0')
	{
		while(!(U0LSR&0x20));
		U0THR=val[i];
		i++;
	}
	
	delay(20000);
	U0THR='\t';
	i=0;
}
}
