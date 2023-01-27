// eeprom_putFloat.ino
// Write a float and then read back
// http://electronoobs.com/eng_arduino_tut167.php


#include <EEPROM.h>

float brightness;


void setup()
{
  Serial.begin(9600);
  float sensor_read = 70000;
  EEPROM.put(0, sensor_read);      // Write that value starting on address 0
}


void loop()
{
  // read a float starting on address "0" and store the value on "brightness"
  EEPROM.get(0, brightness);
  Serial.println(brightness);
  delay(500);
}