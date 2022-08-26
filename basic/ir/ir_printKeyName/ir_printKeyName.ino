// ir_printKeyName.ino
// Print name of key pressed on remote control to Serial Monitor

// https://www.makerguides.com/ir-receiver-remote-arduino-tutorial/

// My standard hardware setup
// ir receiver: D11

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

#define RECEIVER_PIN 11                                   // define the IR receiver pin
IRrecv receiver(RECEIVER_PIN);                            // create a receiver object of the IRrecv class
decode_results results;                                   // create a results object of the decode_results class
unsigned long key_value = 0;                              // variable to store the key value


void setup()
{
  Serial.begin(9600);
  receiver.enableIRIn();                                  // enable the receiver
  receiver.blink13(true);                                 // enable blinking of the built-in LED when an IR signal is received
}


void loop()
{
  if (receiver.decode(&results))
  {
    if (results.value == 0xFFFFFFFF)
    {
      results.value = key_value;                          // set the value to the key value
    }
    
    switch (results.value)
    {
      case OK:
        Serial.println("OK");
        break;
        
      case ASTERISK:
        Serial.println("*");
        break;
        
      case HASH:
        Serial.println("#");
        break;
        
      case LEFT:
        Serial.println("<");
        break;
        
      case RIGHT:
        Serial.println(">");
        break;
        
      case DOWN:
        Serial.println("DOWN");
        break;
        
      case UP:
        Serial.println("UP");
        break;
        
      case ZERO:
        Serial.println("0");
        break;
        
      case ONE:
        Serial.println("1");
        break;
        
      case TWO:
        Serial.println("2");
        break;
        
      case THREE:
        Serial.println("3");
        break;
        
      case FOUR:
        Serial.println("4");
        break;
        
      case FIVE:
        Serial.println("5");
        break;
        
      case SIX:
        Serial.println("6");
        break;
        
      case SEVEN:
        Serial.println("7");
        break;
        
      case EIGHT:
        Serial.println("8");
        break;
        
      case NINE:
        Serial.println("9");
        break;
    }
    
    key_value = results.value;
    delay(100);                           // critical
    receiver.resume();
  }
}
