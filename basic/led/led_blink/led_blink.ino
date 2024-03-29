// led_blink.ino
// status: compile , upload 


/*
blink.ino
Turns on an LED for one second, then off for one second, repeatedly
This example code is in the public domain
*/

// don't need any boards to run

// Pin 13 has an LED connected on most Arduino boards
// connect an external LED with resistor to pin 13
// then change to pin D7

// give it a name
int led = 13;

// the setup routine runs once when you press reset
void setup()
{
  // initialize the digital pin as an output
  pinMode(led, OUTPUT);
}


// the loop routine runs over and over again forever
void loop()
{
  digitalWrite(led, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);             // wait for a second
  digitalWrite(led, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);             // wait for a second
}
