// elapsedMillis_led.ino
// status: compile , upload 
// non-blocking


/*  
  Simple example of using elapsedMillis library
  
  This example does thing more than blinking a LED... but the difference 
  here to just using delay(1000) to control the delay between blinks is that 
  you can do more in the loop - like get user input, check buttons, get sensor
  input and other tasks that take time - while you wait for the next time the 
  LED is to change state. All you need to do is add it before or after the 
  'if' statement that controls the check of the time elapsed. 
  
  This example code is in the public domain.
*/


#include <elapsedMillis.h>

elapsedMillis timeElapsed; // global
int led = 13;

// delay in milliseconds between blinks of the LED
unsigned int interval = 1000;

// state of the LED = LOW is off, HIGH is on
boolean ledState = LOW;


void setup() 
{                
  pinMode(led, OUTPUT);     
}


void loop()
{
  if (timeElapsed > interval) 
  {				
    ledState = !ledState;           // toggle state
    digitalWrite(led, ledState);
    
    // reset counter so counting starts over
    timeElapsed = 0;        
  }
}
