#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

int slayer[] = {156,156,156, 311,880,932,880, 350,880,830, 329.830,783};



void stateOne(){
  //Here we play a continous buzzer sounds and turn on 01, red on, green off.

}

void stateTwo(){
  //Here we play a song(Raining blood by Slayer. The intro riff) and turn on 10, green on, red off.

}

void stateThree(){
  //Play a alarm sound and turn on 11, green on, red on.
  

}

void stateOFF(){
  //Here because we can only play so much with madness, we turn off the buzzer and leds. 

}

void stateChange(){
  //Change the state

  
}
