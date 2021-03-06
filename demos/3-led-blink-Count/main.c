//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT &= ~LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);			/* CPU off, GIE on */
}

// global state var to count time
int secondCount = 0;
int state = 1;

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  secondCount ++;
  if (secondCount >= 250) { 	/* once each sec... */
    secondCount = 0;            /* reset count */
    switch(state){
    case 1:
      P1OUT ^= LED_GREEN;
      P1OUT ^= LED_RED;
      state++;
      break;
    case 2:
      P1OUT ^= LED_GREEN;
      state++;
      break;
    case 3:
      P1OUT ^= LED_GREEN;
      P1OUT ^= LED_RED;
      state++;
      break;
    case 4:
      P1OUT |= LED_RED;
      P1OUT |= LED_GREEN;
      state = 1;
      break;
      
    }
    
    		
  }
} 

