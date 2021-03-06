#include <msp430.h>
#include "stateMachine.h"
#include "leds.h"
#include "buzzer.h"

int slayer[] = {156,0,156,0,156,0, 311,880,932,880, 350,880,830, 329,830,783};
static int buzzer = 1100;
static int alarm1 = 1400;
static int alarm2 = 2000;
char button = 0;
void stateOne(){
  //Here we play a continous buzzer sounds and turn on 01, red on, dimming green.
  green = 0;
  red = 1;
  buzzer_set_period(buzzer);
  //Green button is off 80% of the time
  static int greenState = 0;
  switch(greenState){
  case 0: greenState++; green = 1;
  case 1: greenState++; green = 0;
  case 2: greenState++; green = 0;
  case 3: greenState++; green = 0;
  case 4: greenState++; green = 0;
}
}

void stateTwo(){
  //Here we play a song(Raining blood by Slayer. The intro riff) and turn on 10, green on, red off.
  static int timer = 0;
  static int pause = 0;
  static int tempo = 35;
  static int tempo_state = 0;
  static int play = 1;
  static int i = 0;
  green = 1;
  red = 0;
  if((++pause > 5) & (i<3)){play = 0; pause = 0;}
  else{play = 1;}

  
 
  if(play){
  if(i == 25) i = 0;
  if(timer++>tempo){
   timer = 0;
    buzzer_set_period(2000000/slayer[i++]);
    }
    }
}

void stateThree(){
  //Play a alarm sound and turn on 11, green on, red on.
  green = 1;
  red = 1;

  if(alarm1 < 1800){
    buzzer_set_period(2000000/alarm1);
    alarm1++;
      
  }
  else{alarm1 = 1400;}

}

void stateOFF(){
  //Here because we can only play so much with madness, we turn off the buzzer and leds. 
  buzzer_set_period(0);
  red = 0;
  green = 0;
}

void stateChange(char state){
  //Change the state
  switch(state){
  case 1: button = 1; break;
  case 2: button = 2; break;
  case 3: button = 3; break;
  case 4: button = 4; break;
  }
}
void nextState(){
    char changed = 0;

    switch(button){
    case 1: stateOne(); changed = 1; break;
    case 2: stateTwo(); changed = 1; break;
    case 3: stateThree(); changed = 1; break;
    case 4: stateOFF();changed = 1; break;
    }
    change = changed;
    Led_Update();
  }
  

