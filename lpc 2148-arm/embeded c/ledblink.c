#include<LPC21xx.h>
int main()
{
	 
	unsigned int i;
	PINSEL1 = 0x00000000;
        IO0DIR = 0X000F0000;
	while (1)
	{
		IO0CLR = 0X000F0000;
		for (i=0;i<40000000;i++);
		IO0SET = 0x000f0000;
	  for(i=0;i<40000000;i++);
	
	}
} 
