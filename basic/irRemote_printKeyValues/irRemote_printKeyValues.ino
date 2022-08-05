// irRemote_printKeyValues.ino

// https://www.makerguides.com/ir-receiver-remote-arduino-tutorial/


/* IR remote and receiver Arduino example code. Print key values in the Serial Monitor. More info: https://www.makerguides.com */

#include <IRremote.h> // include the IRremote library

#define RECEIVER_PIN 2 // define the IR receiver pin
IRrecv receiver(RECEIVER_PIN); // create a receiver object of the IRrecv class
decode_results results; // create a results object of the decode_results class
unsigned long key_value = 0; // variable to store the key value

void setup() {
  Serial.begin(9600); // begin serial communication with a baud rate of 9600
  receiver.enableIRIn(); // enable the receiver
  receiver.blink13(true); // enable blinking of the built-in LED when an IR signal is received
}

void loop()
{
  if (receiver.decode(&results))
  { // decode the received signal and store it in results
    if (results.value == 0xFFFFFFFF)
    { // if the value is equal to 0xFFFFFFFF
      results.value = key_value; // set the value to the key value
    }
    
    switch (results.value)
    {
      // compare the value to the following cases
      case 0xFD00FF: // if the value is equal to 0xFD00FF
        Serial.println("POWER"); // print "POWER" in the Serial Monitor
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
        break ;
      case 0xFD609F:
        Serial.println(">>|");
        break ;
      case 0xFD10EF:
        Serial.println("DOWN");
        break ;
      case 0xFD906F:
        Serial.println("VOL-");
        break ;
      case 0xFD50AF:
        Serial.println("UP");
        break ;
      case 0xFD30CF:
        Serial.println("0");
        break ;
      case 0xFDB04F:
        Serial.println("EQ");
        break ;
      case 0xFD708F:
        Serial.println("ST/REPT");
        break ;
      case 0xFD08F7:
        Serial.println("1");
        break ;
      case 0xFD8877:
        Serial.println("2");
        break ;
      case 0xFD48B7:
        Serial.println("3");
        break ;
      case 0xFD28D7:
        Serial.println("4");
        break ;
      case 0xFDA857:
        Serial.println("5");
        break ;
      case 0xFD6897:
        Serial.println("6");
        break ;
      case 0xFD18E7:
        Serial.println("7");
        break ;
      case 0xFD9867:
        Serial.println("8");
        break ;
      case 0xFD58A7:
        Serial.println("9");
        break ;
    }
    key_value = results.value;     // store the value as key_value
    receiver.resume();             // reset the receiver for the next code
  }
}
