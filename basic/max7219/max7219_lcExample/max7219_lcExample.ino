// max7219_lcExample.ino
// Only work on max7219-based 8-digit 7 segment display
// PJRC>Teensy>Teensyduino>Libraries>LedControl

// My standard hardware setup
// DIN D11
// CLK D13
// CS  D10
// Using hardware SPI DIN and CLK are fixed at D11 and D13 respectively
// So the only choice to make is CS to D10

#include <LedControl.h>

//                       DIN, CLK, CS
LedControl mydisplay = LedControl(11, 13, 10, 4);  // last parameter: # of MAX7219 devices

// inputs: DIN pin, CLK pin, LOAD pin. number of chips
// LedControl mydisplay = LedControl(45, 44, 43, 1);


void setup()
{
  mydisplay.shutdown(0, false);  // turns on display
  mydisplay.setIntensity(0, 1); // 15 = brightestmydisplay.setDigit(0,
  
  mydisplay.setDigit(0, 0, 9, false);
  mydisplay.setDigit(0, 1, 8, false);
  mydisplay.setDigit(0, 2, 7, false);
  mydisplay.setDigit(0, 3, 6, false);
  mydisplay.setDigit(0, 4, 5, true);
  mydisplay.setDigit(0, 5, 4, false);
  mydisplay.setDigit(0, 6, 3, false);
  mydisplay.setDigit(0, 7, 2, false);
}


void loop() { }
