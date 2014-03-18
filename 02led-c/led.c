#include <stdio.h>
#define GPBCON (*(volatile unsigned int *)0x56000010)
#define GPBDAT (*(volatile unsigned int *)0x56000014)

#define led4_GPB8_pin_out ((GPBCON | (1<<16)) && (CPBCON & ~(1<<17)))
#define led4_on (GPBDAT & ~(1<<8))
#define led4_off (GPBDAT | (1<<8))
void delay(void)
{
	int i;
	for(i = 0; i< 1000; i++)
		;
}

int main(void)
{
	while(1)
	{
		led4_on;
		delay();
		led4_off;
	}
	return 0;
}
