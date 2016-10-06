#include <msp430.h>
#include "ws2812.h"

void gradualFill(u_int n, u_char r, u_char g, u_char b);

int main(void) {
    WDTCTL = WDTPW + WDTHOLD;  // Stop WDT
    if (CALBC1_16MHZ==0xFF)    // If calibration constant erased
    {
        while(1);              // do not load, trap CPU!!
    }

    // configure clock to 16 MHz
    BCSCTL1 = CALBC1_16MHZ;    // DCO = 16 MHz
    DCOCTL = CALDCO_16MHZ;

    // initialize LED strip
    initStrip();  // ***** HAVE YOU SET YOUR NUM_LEDS DEFINE IN WS2812.H? ******

    // set strip color red
    fillStrip(0xFF, 0x00, 0x00);

    // show the strip
    showStrip();

    // gradually fill for ever and ever
    while (1) {
        gradualFill(NUM_LEDS, 0x00, 0xFF, 0x00);  // green
        gradualFill(NUM_LEDS, 0x00, 0x00, 0xFF);  // blue
        gradualFill(NUM_LEDS, 0xFF, 0x00, 0xFF);  // magenta
        gradualFill(NUM_LEDS, 0xFF, 0xFF, 0x00);  // yellow
        gradualFill(NUM_LEDS, 0x00, 0xFF, 0xFF);  // cyan
        gradualFill(NUM_LEDS, 0xFF, 0x00, 0x00);  // red
    }
}

void gradualFill(u_int n, u_char r, u_char g, u_char b){
    int i;
    for (i = 0; i < n; i++){        // n is number of LEDs
        setLEDColor(i, r, g, b);
        showStrip();
        _delay_cycles(1000000);       // lazy delay
    }
}
