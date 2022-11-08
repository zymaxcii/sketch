// ir_protocolFinder.ino
// Infrared remote control protocol finder
// aka printMfgCode.ino
// print manufacturer codes
// works with IRremote 2.x library
// compile well with IRremote 2.5: no error

// https://www.makerguides.com/ir-receiver-remote-arduino-tutorial/

// My standard hardware setup
// ir receiver: D11                                        // any digital pin will do
// can use any remote control


#include <IRremote.h>

#define RECEIVER_PIN 11
IRrecv receiver(RECEIVER_PIN);
decode_results results;
unsigned long key_value = 0;                               // variable to store the pressed key value


void setup()
{
  Serial.begin(9600);
  receiver.enableIRIn();
  receiver.blink13(true);
}


void loop()
{
  if (receiver.decode(&results))
  {
    if (results.value == 0XFFFFFFFF)
    {
      results.value = key_value;
    }
    
    Serial.println(results.value, HEX);
    
    switch (results.decode_type)
    {
      case NEC:
        Serial.println("NEC");
        break;
        
      case SONY:
        Serial.println("SONY");
        break;
        
      case RC5:
        Serial.println("RC5");
        break;
        
      case RC6:
        Serial.println("RC6");
        break;
        
      case DISH:
        Serial.println("DISH");
        break;
        
      case SHARP:
        Serial.println("SHARP");
        break;
        
      case JVC:
        Serial.println("JVC");
        break;
        
      case SANYO:
        Serial.println("SANYO");
        break;
        
      case MITSUBISHI:
        Serial.println("MITSUBISHI");
        break;
        
      case SAMSUNG:
        Serial.println("SAMSUNG");
        break;
        
      case LG:
        Serial.println("LG");
        break;
        
      case WHYNTER:
        Serial.println("WHYNTER");
        break;
        
      case AIWA_RC_T501:
        Serial.println("AIWA_RC_T501");
        break;
        
      case PANASONIC:
        Serial.println("PANASONIC");
        break;
        
      case DENON:
        Serial.println("DENON");
        break;
        
      case BOSEWAVE:
        Serial.println("BOSEWAVE");
        break;
        
      case LEGO_PF:
        Serial.println("LEGO_PF");
        break;
        
      case MAGIQUEST:
        Serial.println("MAGIQUEST");
        break;
        
      default:
      case UNKNOWN:
        Serial.println("UNKNOWN");
        break;
    }
    
    key_value = results.value;
    delay(100);                   // critical delay
    receiver.resume();
  }
}
