#include <msp430.h>
#include "switches.h"
#include "stateMachine.h"
#include "leds.h"

static char check_switches(){
  char p2val = P2IN;
  //Check if there is a change
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */
  return p2val;




}
void switch_init(){
  P2REN |= SWITCHES; //Sets up resisters for switches
  P2IE |= SWITCHES; //Enables interrupts
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES; // set switches for input
  
}

void handle_switches(){
  //If state is 0, buttons are up otherwise pass on the next button press.
  char p2val = check_switches();
  char state = (p2val & SW1) ? 0 : 1;
  if (state == 0) state = (p2val & SW2) ? 0 : 2; 
  if (state == 0) state = (p2val & SW3) ? 0 : 3; 
  if (state == 0) state = (p2val & SW4) ? 0 : 4; 
  stateChange(state); 
} 
