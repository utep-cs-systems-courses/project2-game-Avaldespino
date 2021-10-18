#ifndef leds_included
#define leds_included
#include <msp430.h>



#define LED_RED BIT0               // P1.0

#define LED_GREEN BIT6             // P1.6

#define LEDS (BIT0 | BIT6)



extern unsigned char red, green;

extern unsigned char change;



void Led_Init();//Set up leds

void Led_Update();// Update leds when called



#endif
