// ir_printHexCode.ino
// Print remote control's key value to serial monitor
// aka ir_simpleReceiver.ino
// code works with IRremote library 2.x

// https://www.instructables.com/Arduino-Infrared-Remote-tutorial/

// My standard hardware setup
// ir receiver: D11
// can use any remote control

#include <IRremote.h>

int RECV_PIN = 11;
uint32_t Previous;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();                       // Start the receiver
  Serial.println("setup done");
}


void loop()
{
  if (irrecv.decode(&results))
  {
    // if we have received an IR signal
    if (results.value==0xFFFFFFFF)           // repeat code when key is held down
    {
      results.value=Previous;
    }
    Serial.print("hex code: ");
    Serial.println(results.value, HEX);
    delay(200);                            // critical delay: get invalid code w/o this delay
    irrecv.resume();                       // Receive the next value
  }
  else
  {
     // Serial.println("no ir signal");
  }
}
