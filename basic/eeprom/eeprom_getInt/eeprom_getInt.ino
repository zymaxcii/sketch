// eeprom_getInt.ino
// Read an integer from eeprom
// http://electronoobs.com/eng_arduino_tut167.php


#include <EEPROM.h>

int brightness;


void setup()
{
  Serial.begin(9600);
  EEPROM.put(0, 1234);              // write an int
}


void loop()
{
  // Read an integer starting on address "0" and store the value on "brightness"
  EEPROM.get(0, brightness);        // EEPROM.get(start address, variable)
  Serial.println(brightness);
  delay(500);
}
