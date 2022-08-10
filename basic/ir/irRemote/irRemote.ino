// ir_Remote.ino
// ir_2Btns.ino?

// https://www.youtube.com/watch?v=3jeSfsnQOWk

// hardware setup
// ir remote
// led : D12


#include <IRremote.h>

#define Button_1 0xFFA25D          // 0xFF6897
#define Button_2 0xFF629D          // 0xFF9867

int receiver = 8;       // initialize pin 13 as recevier pin
uint32_t Previous; 
IRrecv irrecv(receiver); // create a new instance of receiver
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();   // start the receiver
  pinMode(4, OUTPUT);   // led?
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
      case Button_1 : digitalWrite(4, HIGH); break;
      case Button_2 : digitalWrite(4, LOW);  break;
    }
    
    Serial.println (results.value, HEX); // display HEX results 
    irrecv.resume();                     // next value
  }
  Previous=results.value;
}
