#define gpbcon (*(volatile unsigned int *)0x56000010)
#define gpbdat (*(volatile unsigned int *)0x56000014)

#define led1_out (1<<(5*2))
#define led2_out (1<<(6*2))
#define led3_out (1<<(7*2))
#define led4_out (1<<(8*2))

void led1_on (void)
{
	gpbdat &= ~(1<<5);
}

void led1_off (void)
{
	gpbdat |= (1<<5);
}

void delay(volatile unsigned long time)
{
	for(; time > 0; time--)
		;
}

int main(void)
{
	gpbcon = (led1_out | led2_out | led3_out | led4_out);
	while(1)
	{
		delay(30000);
		led1_on();
		delay(30000);
		led1_off();
		
	}

	return 0;
}
