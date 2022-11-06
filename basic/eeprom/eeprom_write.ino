// eeprom_read.ino
// http://electronoobs.com/eng_arduino_tut167.php

#include <EEPROM.h> //include the library

int brightness;         //Create an empty integer variable

void setup() {
  Serial.begin(9600); 	//Start serial monitor 
  EEPROM.write(0, 25);  // write value 25 on address 0
  //Value must be between 0 and 255
}

void loop() {
  // read a byte from the address "0" of the EEPROM
  brightness = EEPROM.read(0);
  Serial.println(brightness);	//Print it to the monitor
  delay(500);
}
