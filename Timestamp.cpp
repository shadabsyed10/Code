//System is 32 - bit.Clock is 64 - bit split across two independent 32 - bit registers.Implement  a function to get time.

#if 0
#define CLOCK_FREQUENCY 1000000
#define TICK_TIME (1/CLOCK_FREQUENCY) 

#define TIMER_RESISTOR 0x00001000

#define HI (volatile uint32_t *)0x1234
#define LO (volatile uint32_t *)0x1230
typedef unsigned int uint64_t;
typedef struct TimeStamp
{
	uint64_t previousCount;
	uint64_t currentCount;
} TIMESTAMP;

TIMESTAMP TimeStamp;

uint64_t get_time(void)
{
	uint64_t timestamp = 0;
	volatile uint32_t high = 0;
	volatile uint32_t low = 0;

	disableInterrupts();

	do
	{
		high = *(HI);
		low = *(LO);
	} while ((*(HI)!high));

	volatile uint64_t time = ((high << 32) | low) * TICK_TIME);
	timestamp = time;

	enableInterrupts();

	return (timestamp);
}

#endif

#if 0
#include <stdint.h>
#define GPIO0 0x08004000 //ADDRESS
#define PORT0_BIT_2 2
void toggle_led(void)
{

	volatile uint32_t * pValue = (uint32_t *)GPIO0;

	*pValue = *pValue ^ (1 << PORT0_BIT_2);
}

static uint32_t v = 0;

void toggle_led_bug(void) //Read from GPIO0 always returns 0. 
{
	volatile uint32_t * pValue = (uint32_t *)GPIO0;

#if 0
	if (v & (1 << PORT0_BIT_2))
	{
		v &= ~(1 << PORT0_BIT_2); //RESET
	}
	else
	{
		v |= (1 << PORT0_BIT_2); //SET
	}
#endif

	v = v ^ (1 << PORT0_BIT_2);
	*pValue |= v;
}
#endif