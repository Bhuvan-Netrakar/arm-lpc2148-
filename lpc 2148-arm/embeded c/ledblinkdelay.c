#include<lpc21xx.h>
#define DESIRED_COUNT 1000
#define PRESCALER 11999
void Inittimer0(void);
void Inittimer0(void)
{ T0PR=PRESCALER;
	T0MR0=DESIRED_COUNT;
	T0MCR=3;
	T0TCR=2;
}
int main(void)
{  PINSEL0=0X00000000;
	 IODIR0=0X000F0000;
	 Inittimer0();
	 T0TCR=0X01;
	while(1)
	{ while(!(T0IR==0X01));
		T0IR=0X01;
		IOCLR0=0X000F0000;
		while(!(T0IR==0X01));
		IOSET0=0X000F0000;
		T0IR=0X01;
	}
		
}
		