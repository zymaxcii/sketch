// ir_printHexCode.ino
// Print remote control's key value to serial monitor
// code works with IRremote library 2.x

// https://www.instructables.com/Arduino-Infrared-Remote-tutorial/

// My standard hardware setup
// ir receiver: D8


#include <IRremote.h>

int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();                       // Start the receiver
}


void loop()
{
  if (irrecv.decode(&results))
    {
      Serial.println(results.value, HEX);
      irrecv.resume();                       // Receive the next value
    }
}
