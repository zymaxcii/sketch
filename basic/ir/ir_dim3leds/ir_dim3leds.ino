// ir_dim3leds.ino
// Use infrared remote control to control brighten and dim 3 leds
// keys used are 1-9 and OK
// buttons 1,4,7: brighten, dim, off red led
// buttons 2,5,8: same with 2nd led, yellow
// buttons 3,6,9: same with 4rd led, green
// button OK: all leds off
// code works with IRremote library 2.x

// https://www.the-diy-life.com/controlling-an-arduino-with-an-infrared-remote-control/
// The DIY Life
// Michael Klements
// 24 January 2020

// My standard hardware setup
// ir receiver:  D11
// led : D4, D5, D6
// using remote control supplied with the module


#include <IRremote.h>

#define ONE      0xFFA25D
#define TWO      0xFF629D
#define THREE    0xFFE21D
#define FOUR     0xFF22DD
#define FIVE     0xFF02FD
#define SIX      0xFFC23D
#define SEVEN    0xFFE01F
#define EIGHT    0xFFA857
#define NINE     0xFF906F
#define ZERO     0xFF9867
#define ASTERISK 0xFF6897
#define HASH     0xFFB04F
#define OK       0xFF38C7
#define UP       0xFF18E7
#define DOWN     0xFF4AB5
#define RIGHT    0xFF5AA5
#define LEFT     0xFF10EF

int iRPin = 11;               // IR sensor connected to Pin 11
IRrecv irrecv(iRPin);         // Create an IR object of the class
decode_results results;

int ledRPin = 4;              // Define LED pin numbers
int ledGPin = 5;
int ledBPin = 6;

int rVal = 512;               // Define initial brightness values - mid brightness
int gVal = 512;
int bVal = 512;


void setup()
{
  irrecv.enableIRIn();        // Start the IR receiver
  
  pinMode(ledRPin, OUTPUT);   // Define the LED pins
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
}


void loop()
{
  if (irrecv.decode(&results))              // Wait for an IR signal to be received
  {
    //Serial.println(results.value, HEX);   // Only used to get HEX value for each button
    changeLED(results.value);               // Change the LED accordingly
    delay(100);                             // critical 200 better
    irrecv.resume();                        // Wait for next signal
  }
}


void changeLED(unsigned long value)
{
  switch (value)                            // Determine which button has been pressed
  {
    case ONE:                               // Button 1 Pressed - Brighten Red 0xFD08F7
      if (rVal<=973)                        // Stops red value from going too high, out of range
        rVal = rVal + 50;                   // Increase red brightness
      analogWrite(ledRPin,rVal);
      break;
      
    case FOUR:                              // Button 4 Pressed - Dim Red 0xFD28D7
      if(rVal>=50)                          // Stops red value from going too low, out of range
        rVal = rVal - 50;                   // Decrease red brightness
      analogWrite(ledRPin,rVal);
      break;
      
    case SEVEN:                             // Button 7 Pressed - Turn Red Off 0xFD18E7
      analogWrite(ledRPin,0);
      break;
      
    case TWO:                               // Button 2 Pressed - Brighten Green 0xFD8877
      if(gVal<=973)
        gVal = gVal + 50;
      analogWrite(ledGPin,gVal);
      break;
      
    case FIVE:                              // Button 5 Pressed - Dim Green 0xFDA857
      if(gVal>=50)
        gVal = gVal - 50;
      analogWrite(ledGPin,gVal);
      break;
      
    case EIGHT:                             // Button 8 Pressed - Turn Green Off 0xFD9867
      analogWrite(ledGPin,0);
      break;
      
    case THREE:                             // Button 3 Pressed - Brighten Blue 0xFD48B7
      if(bVal<=973)
        bVal = bVal + 50;
      analogWrite(ledBPin,bVal);
      break;
      
    case SIX:                               // Button 6 Pressed - Dim Blue 0xFD6897
      if(bVal>=50)
        bVal = bVal - 50;
      analogWrite(ledBPin,bVal);
      break;
      
    case NINE:                              // Button 9 Pressed - Turn Blue Off 0xFD58A7
      analogWrite(ledBPin,0);
      break;
      
    case OK:                                // Power Button Pressed - Turn All LEDs Off 0xFD00FF
      analogWrite(ledRPin,0);
      analogWrite(ledGPin,0);
      analogWrite(ledBPin,0);
      break;
  }
}
