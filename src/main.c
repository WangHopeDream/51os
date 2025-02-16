#include <mcs51/8051.h>

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i=0; i<ms; i++)
        for(j=0; j<1275; j++);
}

void main(void) {
    while(1) {
        P3_5 = 0;  // LED 亮
        delay_ms(500);
        P3_5 = 1;  // LED 灭
        delay_ms(500);
    }
}
