// max7219_lc1.ino
// https://tronixstuff.com/2013/10/11/tutorial-arduino-max7219-led-display-driver-ic/


#include "LedControl.h"                 // need the library

//                       DIN, CLK, CS
LedControl lc = LedControl(11,13,10,4); // 1 unit 

// pin 12 is connected to the MAX7219 pin 1 DIN
// pin 11 is connected to the CLK pin 13
// pin 10 is connected to LOAD pin 12 CS
// 1 as we are only using 1 MAX7219

void setup()
{
  // the zero refers to the MAX7219 number, it is zero for 1 chip
  lc.shutdown(0,false);                  // turn off power saving, enables display
  lc.setIntensity(0,1);                  // sets brightness (0~15 possible values)
  lc.clearDisplay(0);                    // clear screen
}


void loop()
{
  for (int row=0; row<8; row++)
  {
    for (int col=0; col<8; col++)
    {
      lc.setLed(0, col, row, true);      // turns on LED at col, row
      delay(25);
    }
  }

  for (int row=0; row<8; row++)
  {
    for (int col=0; col<8; col++)
    {
      lc.setLed(0, col, row, false);     // turns off LED at col, row
      delay(25);
    }
  }
}
