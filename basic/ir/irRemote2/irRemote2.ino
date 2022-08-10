// ir_Remote2.ino

// https://www.instructables.com/Arduino-Infrared-Remote-tutorial/


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
