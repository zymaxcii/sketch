// ir_control1Led.ino
// On remote control, button 1 turns on led, button 2 turns off led
// ignore all other keys

// https://www.youtube.com/watch?v=3jeSfsnQOWk

// My standard hardware setup
// ir receiver: D8
// led : D4


#include <IRremote.h>

#define Button_1 0xFFA25D
#define Button_2 0xFF629D

int receiver = 8;
uint32_t Previous; 
IRrecv irrecv(receiver);                                  // create a new instance of receiver
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();                                    // start the receiver
  pinMode(4, OUTPUT);                                     // led
}


void loop()
{
  if (irrecv.decode(&results))
  {
    // if we have received an IR signal
    if (results.value==0xFFFFFFFF)
    {
      results.value=Previous;
    }

    switch (results.value)
    {
      case Button_1 : digitalWrite(12, HIGH); break;      // led on
      case Button_2 : digitalWrite(12, LOW);  break;      // led off
    }
    
    Serial.println (results.value, HEX);                  // display HEX results 
    irrecv.resume();                                      // next value
  }
  Previous=results.value;
}
