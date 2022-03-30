// keypad.ino
// work with membrane and normal keypads

#include "Keypad.h"
 
const byte ROWS = 4;       // number of rows
const byte COLS = 4;       // number of columns

char keys[ROWS][COLS] =
{
  {'M','A','L','I'},
  {'P','@','G','M'},
  {'A','I','L','.'},
  {'C','O','M','A'}
};

// row pinouts of the keypad R1,R2,R,R4: D9,D8,D7,D6
byte rowPins[ROWS] = {9, 8, 7, 6};

// column pinouts of the keypad C1,C2,C3,C4: D5,D4,D3,D2
byte colPins[COLS] = {5, 4, 3, 2};

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
