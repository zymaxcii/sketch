// sleep.ino
// compile ok, upload ok
// Supposely it can run on capacitive power for a long time due to the sleep mode
// I cannot test this because I am running Mega from USB charger

// https://wattsworth.wordpress.com/
// Running ATmega328 on Capacitor Power


#include <JeeLib.h>          // what library is this?

int led_pin = 13;


// Interrupt service routine
ISR(WDT_vect)
{
  Sleepy::watchdogEvent();
}


void setup()
{
  pinMode(led_pin, OUTPUT);
}


void loop()
{
  digitalWrite(led_pin, HIGH);
  Sleepy::loseSomeTime(25); 
  
  digitalWrite(led_pin, LOW);
  Sleepy::loseSomeTime(4975);
}
