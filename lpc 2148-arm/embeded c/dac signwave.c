#include <lpc214x.h>
#include <stdio.h>

unsigned int i;

void delay(unsigned long int r1)
{
    unsigned long int j;
    for(j = 0; j < r1; j++);
}

unsigned int dac_value = 0;
char val[30];

void serial()
{
    PINSEL0 = 0x00000005;
    U0LCR = 0x83;
    U0DLM = 0x00;
    U0DLL = 0x61;
    U0LCR = 0x03;
}

void dac_init()
{
    PINSEL1 |= (1 << 20); // Configure P0.26 as AOUT (DAC output)
}

void dac_output(unsigned int value)
{
    DACR = (value << 6) | (1 << 16); // Set DAC output value and enable the DAC
}

int main()
{
    PINSEL1 = 0x00040000;
    serial();
    dac_init();
    
    while(1)
    {
        // Update DAC value
        dac_output(dac_value);

        // Increment DAC value for next iteration
        dac_value = (dac_value + 100) % 1024;

        // Transmit DAC value over serial
        sprintf(val, "DAC Value: %d\n", dac_value);
        i = 0;                                                               
        while(val[i] != '\0')
        {
            while(!(U0LSR & 0x20));
            U0THR = val[i];
            i++;
        }

        // Delay for observation
        delay(20000);
    }
}
