#include<lpc214x.h>
void anti_clockwise(void);
void clockwise(void);

unsigned long int var1,var2;
unsigned int i=0,j=0,k=0;

int main(void)
{
	PINSEL0=0x00ffffff;
	IO0DIR |=0x00ffffff;
	while(1)
	{
		for(j=0;j<50;j++)
		{
		clockwise();
		}
		for(j=0;j<50;j++)
		{
			anti_clockwise();
		}
	}
}

void clockwise()
{
	var1=0x00000800;
	for(i=0;i<=3;i++)
	{
		var1=var1<<1;
		IO0PIN=var1;
		for(k=0;k<30000;k++);
	}
}
	
	void anti_clockwise()
{
	var1=0x00010000;
	for(i=0;i<=3;i++)
	{
		var1=var1>>1;
		IO0PIN=var1;
		for(k=0;k<30000;k++);
	}
}