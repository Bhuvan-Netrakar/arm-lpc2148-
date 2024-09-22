#include <lpc21xx.h>
void delay(void);
void serial(void);
void clockwise(void);
void anti_clockwise(void);
unsigned char mg;
int i,j,k;
unsigned long int var1,var2;

int main()
{
	//unsigned char msg[]=("bvb");
	serial();
	while(1)
	{
		serial();
		//for(i=0;i<3;i++)
		//{
		 while(!(U0LSR&0x20));
			//U0THR=msg[i];
			 
		//}
		//while(!(U0LSR&0x01));
		//mg=U0RBR;
		U0THR=mg;
	//	delay();
		if(mg=='c')
		{
			PINSEL0=0x00000000;
			IO0DIR|=0x0000f000;
			for(j=0;j<5;j++)
		{
		clockwise();
		for(k=0;k<65000;k++);
		for(k=0;k<65000;k++);
		}
		}
	 if(mg=='a')
		{
			PINSEL0=0x00000000;
			IO0DIR|=0x0000f000;
			for(j=0;j<5;j++)
		{
			anti_clockwise();
			for(k=0;k<65000;k++);
		for(k=0;k<65000;k++);
		}
		}
		else
		{
			while(!(U0LSR&0x01));
			mg=U0RBR;
		U0THR=mg;
		delay();
		}
	}
}
     void serial()
	{
		PINSEL0=0x00000005;
		U0LCR=0x83;
		U0LCR=0x03;
	}
		void delay()
	{
		unsigned int i;
		for(i=0;i<10000;i++);
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