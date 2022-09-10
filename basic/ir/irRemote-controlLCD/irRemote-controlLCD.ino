// ir_Remote-controlLCD.ino
// redundant? to delete?

// https://www.makerguides.com/ir-receiver-remote-arduino-tutorial/


/* Example code to control LEDs with an IR remote and receiver with Arduino. More info: https://www.makerguides.com/ */

// hardware setup
// 4 leds: D2, D3, D4, D5
// ir: D6

#include <IRremote.h>

#define RECEIVER_PIN 6                         // define the connections

#define RED_LED_PIN 2
#define YELLOW_LED_PIN 3
#define GREEN_LED_PIN 4
#define BLUE_LED_PIN 5

IRrecv receiver(RECEIVER_PIN);                 // create a receiver object of the IRrecv class
decode_results results;                        // create a results object of the decode_results class

unsigned long key_value = 0;


void setup()
{
  Serial.begin(9600);
  receiver.enableIRIn();                       // enable the receiver
  receiver.blink13(true);                      // enable blinking of the built-in LED when an IR signal is received
  
  pinMode(RED_LED_PIN,    OUTPUT);             // set the LED pins as output
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN,  OUTPUT);
  pinMode(BLUE_LED_PIN,   OUTPUT);
  
  digitalWrite(RED_LED_PIN,    LOW);              // turn all the LEDs off
  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN,  LOW);
  digitalWrite(BLUE_LED_PIN,   LOW);
}


void loop()
{
  if (receiver.decode(&results))
  {
    if (results.value == 0xFFFFFFFF)
    {
      results.value = key_value;
    }

    switch (results.value)
    {
      case 0xFD00FF:
        Serial.println("POWER");
        break;
        
      case 0xFD807F:
        Serial.println("VOL+");
        break;
        
      case 0xFD40BF:
        Serial.println("FUNC/STOP");
        break;
        
      case 0xFD20DF:
        Serial.println("|<<");
        break;
        
      case 0xFDA05F:
        Serial.println(">||");
        break;
        
      case 0xFD609F:
        Serial.println(">>|");
        break;
        
      case 0xFD10EF:
        Serial.println("DOWN");
        break;
        
      case 0xFD906F:
        Serial.println("VOL-");
        break;
        
      case 0xFD50AF:
        Serial.println("UP");
        break;
        
      case 0xFD30CF:
        Serial.println("0");
        break;
        
      case 0xFDB04F:
        Serial.println("EQ");
        break;
        
      case 0xFD708F:
        Serial.println("ST/REPT");
        break;
        
      case 0xFD08F7:
        Serial.println("1");
        toggleLED(RED_LED_PIN); // run the toggle LED function with the red LED pin as input
        break;
        
      case 0xFD8877:
        Serial.println("2");
        toggleLED(YELLOW_LED_PIN);
        break;
        
      case 0xFD48B7:
        Serial.println("3");
        toggleLED(GREEN_LED_PIN);;
        break;
        
      case 0xFD28D7:
        Serial.println("4");
        toggleLED(BLUE_LED_PIN);
        break;
        
      case 0xFDA857:
        Serial.println("5");
        break;
        
      case 0xFD6897:
        Serial.println("6");
        break;
        
      case 0xFD18E7:
        Serial.println("7");
        break;
        
      case 0xFD9867:
        Serial.println("8");
        break;
        
      case 0xFD58A7:
        Serial.println("9");
        break;
    }

    key_value = results.value;    // missing critical delay
    receiver.resume();
  }
}


void toggleLED(int pin)
{
  // function to toggle the LED on and off
  if (digitalRead(pin) == HIGH)
  {
    // if the LED is on
    digitalWrite(pin, LOW);                 // turn it off
  }
  else
  {
    digitalWrite(pin, HIGH);                // turn it on
  }
}
