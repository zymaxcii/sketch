// max7219_turnOnOff2.ino
// Turn on and off all LEDs in 2 MAX7219 devices
// column by column then row by row
// using LedControl library
// https://tronixstuff.com/2013/10/11/tutorial-arduino-max7219-led-display-driver-ic/

#include "LedControl.h"

// My standard hardware setup
// DIN D11
// CLK D13
// CS  D10
// Using hardware SPI DIN and CLK are fixed at D11 and D13 respectively
// So the only choice to make is CS to D10


//                       DIN, CLK, CS
LedControl lc = LedControl(11,13,10,2);  // 2 units


void setup()
{
  lc.shutdown(0, false);                  // turn off power saving, enables display
  lc.setIntensity(0, 1);                  // sets brightness (0~15 possible values)
  lc.clearDisplay(0);                     // clear screen

  lc.shutdown(1, false);                  // turn off power saving, enables display
  lc.setIntensity(1,1);                   // sets brightness (0~15 possible values)
  lc.clearDisplay(1);                     // clear screen
}


void loop()
{
  for (int row = 0; row < 8; row++)
  {
    for (int col = 0; col < 8; col++)
    {
      lc.setLed(0, col, row, true);        // turns on LED at col, row
      lc.setLed(1, col, row, false);       // turns off LED at col, row
      delay(25);
    }
  }

  for (int row = 0; row < 8; row++)
  {
    for (int col = 0; col < 8; col++)
    {
      lc.setLed(0, col, row, false);        // turns off LED at col, row
      lc.setLed(1, col, row, true);         // turns on LED at col, row      
      delay(25);
    }
  }
}
