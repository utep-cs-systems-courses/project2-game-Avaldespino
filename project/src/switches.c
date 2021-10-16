#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"

static char switch_update_interrupt_sense(){





}
void switch_init(){
  P2REN |= SWITCHES; //Sets up resisters for switches
  P2IE |= SWITCHES; //Enables interrupts
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES; // set switches for input
  
}
