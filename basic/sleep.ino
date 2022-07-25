// https://wattsworth.wordpress.com/
// Running ATmega328 on Capacitor Power


#include <JeeLib.h>

int led_pin = 13;
ISR(WDT_vect) {Sleepy::watchdogEvent();}

void setup(){
 pinMode(led_pin, OUTPUT);
}
 
void loop(){
 digitalWrite(led_pin, HIGH);
 Sleepy::loseSomeTime(25); 
 digitalWrite(led_pin, LOW);
 Sleepy::loseSomeTime(4975);
}

