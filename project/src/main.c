#include <msp430.h>
#include "libTimer.h"
#include "leds.h"
#include "switches.h"
#include "buzzer.h"


void main(){
  configureClocks();
  buzzer_init(); //Setup our buzzer for use
  switch_init();
  Led_Init();
  enableWDTInterrupts();
  or_sr(0x18);



}
