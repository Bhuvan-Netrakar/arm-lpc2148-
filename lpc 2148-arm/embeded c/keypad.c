#include<lpc21xx.h>
void delay(unsigned int);
void disp(unsigned int);
int main()
{
unsigned long int value,i;
unsigned int row0[4]={0x00ee0000,0x00ed0000,0x00eb0000,0x00e70000};
unsigned int row1[4]={0x00de0000,0x00dd0000,0x00db0000,0x00d70000};
unsigned int row2[4]={0x00be0000,0x00bd0000,0x00bb0000,0x00b70000};
unsigned int row3[4]={0x007e0000,0x007d0000,0x007b0000,0x00770000};
IODIR1=0xFFF0FFFF;
PINSEL1=0x00000000;
IODIR0=0xF0FF0000;
IOSET0=0xF0000000;
while(1)
{
IOPIN1=0x00ff0000;
IOCLR1=0x00100000;
value=IOPIN1;
delay(50000);
value=value&0x00FF0000;
for(i=0;i<4;i++)
{
if(value==row0[i])
{
	disp(i);
delay(650000);
	delay(650000);
	delay(650000);
	delay(650000);
	delay(650000);
}
}
IOPIN1=0x00ff0000;
IOCLR1=0x00200000;
value=IOPIN1;
delay(5000000);delay(5000000);
value=value&0x00FF0000;
for(i=0;i<4;i++)
{
if(value==row1[i])
{
	disp(i+4);
delay(650000);
	delay(650000);
	delay(650000);
	delay(650000);
	delay(650000);
}
}
IOPIN1=0x00ff0000;
IOCLR1=0x00400000;
value=IOPIN1;
delay(650000);
delay(650000);
delay(650000);
delay(650000);
delay(650000);
value=value&0x00FF0000;
for(i=0;i<4;i++)
{
if(value==row2[i])
{
	disp(i+8);
delay(500000);
}
}
IOPIN1=0x00ff0000;
IOCLR1=0x00800000;
value=IOPIN1;
delay(650000);
delay(650000);
delay(650000);
delay(650000);
delay(650000);
value=value&0x00FF0000;
for(i=0;i<4;i++)
{
if(value==row3[i])
{
	disp(i+12);
delay(650000);
	delay(650000);
	delay(650000);
	delay(650000);
	delay(650000);
}
}
}
}
void disp( unsigned int temp)
{unsigned int i;
unsigned int da[16]={0x003f0000,0x00060000,0x005b0000,0x004F0000,0X00660000,0X006D0000,0X007D0000,0X00070000,0X007F0000,0X006F0000,0X00770000,0X007C0000,0X00390000,0X005E0000,0X00790000,0X00710000};
IOCLR0=0x00ff0000;
i=temp;
IOSET0=da[i];
delay(650000);delay(650000);delay(650000);delay(650000);delay(650000);
IOCLR0=0x00ff0000;
}
void delay(unsigned int del)
{
unsigned int k;
for(k=0;k<del;k++);
} 
