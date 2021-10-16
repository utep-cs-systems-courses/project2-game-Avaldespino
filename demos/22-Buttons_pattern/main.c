#include <msp430.h>
#include "libTimer.h"

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

#define SW1 BIT0                /* switch1 is p2.0 and so on til p2.3 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (BIT0|BIT1|BIT2|BIT3)		/*Now use all 4..... only 1 switch on this board */

void main(void) 
{  
  configureClocks();

  P1DIR |= LEDS;
  P1OUT &= ~LEDS;		/* leds initially off */
  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */

  or_sr(0x18);  // CPU off, GIE on
} 

void
switch_interrupt_handler()
{
  char p1val = P2IN;		/* switch is in P2 */

/* update switch interrupt sense to detect changes from current buttons */
  P2IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */

/* up=red, down=green 
  if (p1val & SW1) {
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;
  } else {
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
    }*/
  if(!(p1val & SW1)){
    P1OUT &= ~LED_GREEN;
    P1OUT &= ~LED_RED;

  }
   if(!(p1val & SW2)){
   P1OUT |= LED_GREEN;
   P1OUT &= ~LED_RED;

   }
  
   if(!(p1val & SW3)){
    P1OUT &= ~LED_GREEN;
    P1OUT |= LED_RED;

  }
  if(!(p1val & SW4)){
    P1OUT |= LED_GREEN;
    P1OUT |= LED_RED;

    }
  /*
  switch(p1val){
    case '1':
      P1OUT ^= LED_GREEN;
      P1OUT ^= LED_RED;
      
      break;
    case '2':
      P1OUT ^= LED_GREEN;
      
      break;
    case '3':
      P1OUT ^= LED_GREEN;
      P1OUT ^= LED_RED;
      
      break;
    case '4':
      P1OUT |= LED_RED;
      P1OUT |= LED_GREEN;
     
      break;
      
    }
  */
}


/* Switchs on P2 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {             /* did a button cause this interrupt? */
    /*p1IFG = Port 1 interrupt Flags*/
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}
