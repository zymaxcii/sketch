// tm1638_count100.ino
// Dislay numbers from 1 to 100

// http://arduinolearning.com/learning/basics/arduino-tm1638-module.php

// My standard hardware setup
// Led-Key module
// VCC 3.5V
// GND GND
// STB D7
// CLK D9
// DIO D8


#include <TM1638.h>

// define a module on data pin 8, clock pin 9 and strobe pin 7
TM1638 module(8, 9, 7);

unsigned long a = 1;


void setup()
{
}

 
void loop()
{
  for (a=1; a<=500; a++)
  {
    module.setDisplayToDecNumber(a, 0, false);
    delay(100);
  }
  module.setDisplayToString("Complete");
  delay(1000);
}
