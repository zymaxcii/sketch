// keypad_toSerial.ino
// work with membrane and normal keypads
// status: compile ok, upload ok


#include "Keypad.h"
 
const byte ROWS = 4;       // number of rows
const byte COLS = 4;       // number of columns

char keys[ROWS][COLS] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// row pinouts of keypad R1,R2,R3,R4
byte rowPins[ROWS] = {26, 27, 28, 29};

// column pinouts of keypad C1,C2,C3,C4
byte colPins[COLS] = {22, 23, 24, 25};

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
