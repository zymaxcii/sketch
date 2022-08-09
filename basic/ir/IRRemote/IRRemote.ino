// ir_3led.ino?
// IRremote.ino

// https://www.the-diy-life.com/controlling-an-arduino-with-an-infrared-remote-control/


// The DIY Life
// Michael Klements
// 24 January 2020

// hardware setup
// ir remote
// 3 leds: D5, D9, D6

#include <IRremote.h>

int iRPin = 4;            // IR sensor connected to Pin 4
IRrecv irrecv(iRPin);     // Create an IR object of the class
decode_results results;

int ledRPin = 5;          // Define LED pin numbers
int ledGPin = 9;
int ledBPin = 6;

int rVal = 512;           // Define initial brightness values - mid brightness
int gVal = 512;
int bVal = 512;


void setup()
{
  //Serial.begin(9600);       // Only used to get HEX value for each button
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
    irrecv.resume();                        // Wait for next signal
    delay(100);
  }
}


void changeLED(unsigned long value)
{
  switch (value)                            // Determine which button has been pressed
  {
    case 0xFD08F7:                          // Button 1 Pressed - Brighten Red
      if (rVal<=973)                        // Stops red value from going too high, out of range
        rVal = rVal + 50;                   // Increase red brightness
      analogWrite(ledRPin,rVal);
      break;
      
    case 0xFD28D7:                          // Button 4 Pressed - Dim Red
      if(rVal>=50)                          // Stops red value from going too low, out of range
        rVal = rVal - 50;                   // Decrease red brightness
      analogWrite(ledRPin,rVal);
      break;
      
    case 0xFD18E7:                          // Button 7 Pressed - Turn Red Off
      analogWrite(ledRPin,0);
      break;
      
    case 0xFD8877:                          // Button 2 Pressed - Brighten Green
      if(gVal<=973)
        gVal = gVal + 50;
      analogWrite(ledGPin,gVal);
      break;
      
    case 0xFDA857:                          // Button 5 Pressed - Dim Green
      if(gVal>=50)
        gVal = gVal - 50;
      analogWrite(ledGPin,gVal);
      break;
      
    case 0xFD9867:                          // Button 8 Pressed - Turn Green Off
      analogWrite(ledGPin,0);
      break;
      
    case 0xFD48B7:                          // Button 3 Pressed - Brighten Blue
      if(bVal<=973)
        bVal = bVal + 50;
      analogWrite(ledBPin,bVal);
      break;
      
    case 0xFD6897:                          // Button 6 Pressed - Dim Blue
      if(bVal>=50)
        bVal = bVal - 50;
      analogWrite(ledBPin,bVal);
      break;
      
    case 0xFD58A7:                         // Button 9 Pressed - Turn Blue Off
      analogWrite(ledBPin,0);
      break;
      
    case 0xFD00FF:                         // Power Button Pressed - Turn All LEDs Off
      analogWrite(ledRPin,0);
      analogWrite(ledGPin,0);
      analogWrite(ledBPin,0);
      break;
  }
}
