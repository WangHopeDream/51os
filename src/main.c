#include <mcs51/8052.h>

#define OSC_FREQ 12000000UL

#define TIMER_MODE0 0x00
#define TIMER_MODE1 0x01
#define TIMER_MODE2 0x02
#define TIMER_MODE3 0x03

volatile unsigned int count = 0;

void timer0_isr(void) __interrupt(1)
{
    count++;

    TH0 = (65536 - 1000 * (OSC_FREQ / 12000000)) >> 8;
    TL0 = (65536 - 1000 * (OSC_FREQ / 12000000)) & 0x00FF;
}

void timer0_init(void)
{
    TMOD &= 0xF0;
    TMOD |= TIMER_MODE1; /* Timer 0 work on 16-bit timer mode */
    TH0 = (65536 - 1000 * (OSC_FREQ / 12000000)) >> 8;
    TL0 = (65536 - 1000 * (OSC_FREQ / 12000000)) & 0x00FF;
    ET0 = 1; /* Enable timer 0 interrupt */
    EA = 1;
    TR0 = 1; /* Turn on timer 0 */
}
#define led1 P3_5

void delayms(unsigned int n)
{
    while (count <= n)
        ;

    count = 0;
}
void main(void)
{
    timer0_init();

    while (1)
    {
        led1 = 0;
        delayms(1000);
        led1 = 1;
        delayms(1000);
    }
}