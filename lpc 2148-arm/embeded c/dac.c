#include<lpc214x.h>
#include<stdint.h>

void delay (int j)
{
	int i;
	for(i=0;i<j;i++);
}
int main (void)
{
	int value;
	PINSEL1 = 	0x00080000;
	while(1)
	{
		
		value = 1023;
		DACR = ((1<<16)|(value<<6));
		delay(100);
		value=0;
		DACR = ((1<<16)|(value<<6));
		delay(100);
 }
	}
