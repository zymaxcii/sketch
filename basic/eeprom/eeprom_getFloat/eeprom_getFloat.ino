// eeprom_getFloat.ino
// Read a float value from eeprom
// http://electronoobs.com/eng_arduino_tut167.php


#include <EEPROM.h>

float brightness;


void setup()
{
  Serial.begin(9600);
}


void loop()
{
  // read a float starting on address "0" and store the value on "brightness"
  EEPROM.get(0, brightness);      // EEPROM.get(start address, variable);
  Serial.println(brightness);
  delay(500);
}
