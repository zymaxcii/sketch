// irRemote-lcd.ino

// https://www.makerguides.com/ir-receiver-remote-arduino-tutorial/
/* IR remote and receiver with Arduino and character LCD example code. More info: https://www.makerguides.com/ */

// hardware setup
// lcd 1602
// ir module


#include <IRremote.h>                                    // include the IRremote library
#include <LiquidCrystal.h>                               // include the LiquidCrystal library

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


LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);     // create an LCD object with pin parameters (RS, E, D4, D5, D6, D7)

#define RECEIVER_PIN 11                                  // define the IR receiver pin
IRrecv receiver(RECEIVER_PIN);                           // create a receiver object of the IRrecv class
decode_results results;                                  // create a results object of the decode_results class
unsigned long key_value = 0;                             // variable to store the key value


void setup()
{
  lcd.begin(16, 2);                                      // enable LCD with 16 colums and 2 rows
  receiver.enableIRIn();                                 // enable the receiver
  receiver.blink13(true);                                // enable blinking of the built-in LED when an IR signal is received
}


void loop()
{
  if (receiver.decode(&results))
  {
    // decode the received signal and store it in results
    if (results.value == 0xFFFFFFFF)
    {
      // if the value is equal to 0xFFFFFFFF
      results.value = key_value; // set the value to the key value
    }

    lcd.print("Testing");
    
    switch (results.value)
    {
      // compare the value to the following cases
      case OK:                                     // if the value is equal to 0xFD00FF
        lcd.clear();                                     // clear the display
        break;
        
      case UP:
        lcd.print("VOL+ UP");
        break;
        
      case DOWN:
        lcd.print("DOWN");
        break;
        
      case LEFT:
        lcd.print("<");
        break;
        
      case RIGHT:
        lcd.print(">");
        break;
        
      case ONE:
        lcd.print("ONE");
        break;
        
      case TWO:
        lcd.print("TWO");
        break;
        
      case 0xFD906F:
        lcd.print("VOL-");
        break;
        
      case 0xFD50AF:
        lcd.print("UP");
        break;
        
      case 0xFD30CF:
        lcd.print("0");
        break;
        
      case 0xFDB04F:
        lcd.print("EQ");
        break;
        
      case 0xFD708F:
        lcd.print("ST/REPT");
        break;
        
      case 0xFD08F7:
        lcd.print("1");
        break;
        
      case 0xFD8877:
        lcd.print("2");
        break;
        
      case 0xFD48B7:
        lcd.print("3");
        break;
        
      case 0xFD28D7:
        lcd.print("4");
        break;
        
      case 0xFDA857:
        lcd.print("5");
        break;
        
      case 0xFD6897:
        lcd.print("6");
        break;
        
      case 0xFD18E7:
        lcd.print("7");
        break;
        
      case 0xFD9867:
        lcd.print("8");
        break;
        
      case 0xFD58A7:
        lcd.print("9");
        break;
    }
    key_value = results.value;                         // store the value as key_value
    // missing delay
    receiver.resume();                                 // reset the receiver for the next code
  }
}
