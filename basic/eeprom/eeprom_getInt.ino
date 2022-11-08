// eeprom_getInt.ino
// http://electronoobs.com/eng_arduino_tut167.php

#include <EEPROM.h>

int brightness;         //Create an empty variable, type: integer

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read an integer starting on address "0" and store the value on "brightness"
  EEPROM.get(0, brightness);    //EEPROM.get(start address, variable);
  Serial.println(brightness);
  delay(500);
}
