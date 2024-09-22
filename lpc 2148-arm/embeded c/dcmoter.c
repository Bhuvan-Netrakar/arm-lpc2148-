#include<lpc214x.h>
void anti_clockwise(void);
unsigned int j=0,x;
int main()
{
	IO0DIR=0x00000900;
	IO0SET=0x00000100;
	while(1)
	{x=IO0PIN;
	 x=x&0x00000100;
		if(x==0x00001000)
		{
			anti_clockwise();
			for(j=0;j<400000;j++);
		}
	}
}
 void anti_clockwise(void)
{
	IO0CLR=0X00000100;
	for(j=0;j<=1000000;j++);
	IO0SET = 0x00000100;
}
