#include <msp430.h>
#include "libTimer.h"
#include "led.h".
#include "switches.h"
#include "buzzer.h"


void main(){
  configureClocks();
  buzzer_init(); //Setup our buzzer for use
  led_init();



}
