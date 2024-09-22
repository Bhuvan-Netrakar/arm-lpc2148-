#include<lpc213x.h>
#include<string.h>
#define SLAVE_ADDR 78    
#define MAX        12
#define AA         2
#define SI         3
#define STO        4
#define STA        5
#define I2EN       6

wait(int count)
	{
      while(count-- );
}

void I2C_Init (void)
{
   VPBDIV    =   0x02;        // sets FOSC =  60MHHZ
   PINSEL0   =   0x00000050;  // set po.2,p0.3 to sda scl
   I2C0SCLH   =   150;        //50%duty,I2CFreq->100KHz,PCLK=30MHz
   I2C0SCLL   =   150;
   I2C0CONSET  =  (1<<I2EN);  //Enable I2C module
	 //PINSEL1 = 0x00000000 ;		// Configure P0.16 to P0.31 as GPIO
	// IO0DIR  = 0x000F0000 ;
	// IO0CLR = 0x000F0000;
}
//////////////////////////
//     Enter Master 
//     transmitter Mode
//
int I2C_Start ()
{
   I2C0CONCLR   =   1 << STO; 
   I2C0CONCLR = 1 << SI;   
   I2C0CONSET   =   1 << STA; 
   return 0;
}

//////////////////////////////////////
//      Delay function
//
//
void delay_ms(int count)
{
  int j=0,i=0;
 
  for(j=0;j<count;j++)
  {
    /* At 60Mhz, the below loop introduces
    delay of 10 us */
    for(i=0;i<35;i++);
  }
}
///////////////////////////////////////////////////////
//      Function to send data from Master to slave I2C
//      device
//


//      Function to send a byte of char data
//      EX:if data = 0x12 higher nibble 
//      is sent first in this case 0x1 and then lower
//      nibble.whyy? Because slave is set to 4bit mode.
//      The Format shud be :7  6  5   4  3 2 1 0
//                          0  E  RW  RS|D A T A
//

void senddata(char data){ 
     while(!(I2C0CONSET & 0x08)); 		 
		 I2C0DAT      =   data; 
		 I2C0CONCLR   =   1 << SI;
		 delay_ms(200);
} 
void LCD_Command (char cmnd)	/* LCD16x2 command funtion */
{
	char data;
	data = (cmnd & 0xF0)|0x04|0x08;/* Send upper nibble */     // 0X08 NEED TO CHK
	//rs=0;	rw=0;	en=1; 0100 = 0x04 LSB
	senddata(data);
	delay_ms(100);
	//en=0;
	data = (cmnd & 0xF0)|0x08;
	senddata(data);
	delay_ms(100);
	
	data = (cmnd << 4)|0x04|0x08;/* Send lower nibble */
	senddata(data);
	delay_ms(100);
	//en=0;
	data = (cmnd << 4)|0x08;
	senddata(data);
	delay_ms(100);
}
void LCD_Char (char char_data)	/* LCD data write function */
{
	char data;
	//rs=1;		rw=0;		en=1;
	data =(char_data & 0xF0)|0x08|0x05;/* Send upper nibble */
	senddata(data);
	delay_ms(1);
	//rs=1; rw =0 ; en=0;
	data =(char_data & 0xF0)|0x08|0x01;
	senddata(data);
	delay_ms(2);

	////rs=1; rw =0 ; en=1;
	data = (char_data << 4)|0x08|0x05;/* Send lower nibble */
	senddata(data);
	delay_ms(1);
	////rs=1; rw =0 ; en=0;
	data = (char_data << 4)|0x08|0x01;
	senddata(data);
	delay_ms(5);
	senddata(0x08);
}
void LCD_String (char *str)	/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)  /* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);  /* Call LCD data write */
		delay_ms(1000);
	}
}
int main()
{
	int cmd[7]={0x20,0x28,0xe,0x06,0x0c,0x01,0x80};
	int j;
		  char code =  SLAVE_ADDR;// 0x6e;
		  
		  char str[] = "   ^_^   ";
		  int i =0;
		  I2C_Init();                  //Initialize I2C moodule		
		  I2C_Start();                 //start I2C module 
     	wait(4000);

			while(!(I2C0CONSET & 0x08)); //wait till SI bit set
			
      I2C0CONCLR	 =	 1 << STO;
			I2C0CONCLR	 =	 1 << STA;				
			I2C0CONSET   =   1 << AA;
			I2C0DAT      =  code;
			
			I2C0CONCLR   =   1 << SI; 
			
			while(!(I2C0CONSET & 0x08));
								
			if(I2C0STAT == 0x18)                     //SLA+W has been transmitted; ACK has been received
			{	  
						   	 
				   I2C0CONSET   =   1 << AA;
					 I2C0DAT      =   0x00;//x00;//Buff[index]; 
				   I2C0CONCLR   =   1 << SI; 
			
				   while(!(I2C0CONSET & 0x08));
					 for(i=0; i < 2000;i++)wait(800);
				   if(I2C0STAT == 0x28)   //Data byte in I2DAT has been transmitted; ACK has been received
					 { 	
						
						 
						 
						 
	for(j=0;j<7;j++)  /* Send each char of string till the NULL */
	{
		LCD_Command(cmd[j]);  /* Call LCD data write */
		delay_ms(10000);
	}					
																	
						LCD_String(str);
						 					 
										while(100000);


	} 
	}
}