// ir_control2Led.ino
// Button 1 turns red led on then 2sec later off
// Button 2 toggles yellow led

/*
IR Receiver Demonstration 3
IR-Rcv-Demo3.ino
Control LED's using Unused IR Remote keys
DroneBot Workshop 2017
http://dronebotworkshop.com
*/

// my standard hardware setup
// ir receiver D11
// red led     D4
// yellow led  D5
// using the remote provided with the module


// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

// Define sensor pin
const int RECV_PIN = 11;

// Define LED pin constants
const int redPin = 4;
const int yellowPin = 5;

// Define integer to remember toggle state
int togglestate = 0;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  // Enable the IR Receiver
  irrecv.enableIRIn();
  
  // Set LED pins as Outputs
  pinMode(redPin,    OUTPUT);
  pinMode(yellowPin, OUTPUT);
}


void loop()
{
  if (irrecv.decode(&results))
  {
    switch(results.value)
    {
      case 0xFFA25D:
        // Button 1
        // Turn on LED for 2 Seconds
        digitalWrite(redPin, HIGH);
        delay(2000);
        digitalWrite(redPin, LOW);
        break;

      case 0xFF629D:
        // Button 2
        // Toggle LED On or Off
        if(togglestate==0)
        {
          digitalWrite(yellowPin, HIGH);
          togglestate=1;
        }
        else
        {
          digitalWrite(yellowPin, LOW);
          togglestate=0;
        }
        break;
   }
   delay(100);                   // critical
   irrecv.resume();
  }
}
