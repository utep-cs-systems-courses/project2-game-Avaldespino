#include <msp430.h>
#include "leds.h"
#include "switches.h"

unsigned char red = 0, green = 0;
unsigned char change = 0;


static char Value_Red[] = {0,LED_RED}, Value_Green[] = {0,LED_GREEN};

void Led_Init(){
  P1DIR |= LEDS; //Set bits for output
  change = 1;
  Led_Update();
}


void Led_Update(){
  if(change){
    char led = Value_Red[red] | Value_Green[green];// Or the bit0 and bit 6

    P1OUT  &= ~LEDS; //Turn off leds
    P1OUT |= led; // turn on new led pattern

    change = 0;//Set change to 0
  }
}
