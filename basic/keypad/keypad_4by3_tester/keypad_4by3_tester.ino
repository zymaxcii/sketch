// keypad_4by3_tester.ino
// status: compile ok, upload ok

// can work on my 4 by 4 keypad; just disable last col
// Arduino_with_Keypad.ino

#include "Keypad.h"
 
const byte ROWS = 4;               // number of rows
const byte COLS = 3;               // number of columns

char keys[ROWS][COLS] =
{
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};


// use analog pins as digital outputs
// Nano: A0 to A5; not A6 or A7 (analog inputs only)

// column pinouts of the keypad C1,C2,C3
byte colPins[COLS] = {22,23,24};   

// row pinouts of the keypad R1,R2,R3,R4
byte rowPins[ROWS] = {26,27,28,29};

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
