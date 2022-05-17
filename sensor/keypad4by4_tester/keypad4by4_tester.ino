// keypad4by4_tester.ino
// testing 4 by 4 keypad
// keypad: no need to connect to VCC or GND

// Arduino_with_Keypad.ino

#include "Keypad.h"
 
const byte ROWS = 4;               // number of rows
const byte COLS = 4;               // number of columns

char keys[ROWS][COLS] =
{
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'9','0','A','B'},
  {'C','D','E','F'}
};

// use analog pins as digital outputs
// Nano: A0 to A5; not A6 or A7 (analog inputs only)

// column pinouts of the keypad C1,C2,C3,C4
byte colPins[COLS] = {4,5,6,7};   

// row pinouts of the keypad R1,R2,R3,R4
byte rowPins[ROWS] = {8,9,10,11};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

 
void setup()
{
  Serial.begin(9600);
}

 
void loop()
{
  char key = keypad.getKey(); 
  if (key != NO_KEY)
    Serial.println(key);
}
