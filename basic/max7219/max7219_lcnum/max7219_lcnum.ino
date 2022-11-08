// max7219_lcnum.ino
// Numeric display
// On 4 MAX7219, it did not display correctly
// Don't know what is supposed to be displayed

// https://tronixstuff.com/2013/10/11/tutorial-arduino-max7219-led-display-driver-ic/

#include "LedControl.h"               //  need the library

//                       DIN, CLK, CS
LedControl lc = LedControl(11,13,10,4); // 1 unit 

// pin 12 is connected to the MAX7219 pin 1
// pin 11 is connected to the CLK pin 13
// pin 10 is connected to LOAD pin 12
// 1 as we are only using 1 MAX7219


void setup()
{
  // the zero refers to the MAX7219 number, it is zero for 1 chip
  lc.shutdown(0, false);                 // turn off power saving, enables display
  lc.setIntensity(0, 8);                 // sets brightness (0~15 possible values)
  lc.clearDisplay(0);                    // clear screen
}


void loop()
{
  for (int a=0; a<8; a++)
  {
    lc.setDigit(0,a,a,true);
    delay(100);
  }
  
  for (int a=0; a<8; a++)
  {
    lc.setDigit(0,a,8,1);
    delay(100);
  }
  
  for (int a=0; a<8; a++)
  {
    lc.setDigit(0,a,0,false);
    delay(100);
  }
  
  for (int a=0; a<8; a++)
  {
    lc.setChar(0,a,' ',false);
    delay(100);
  }
  
  for (int a=0; a<8; a++)
  {
    lc.setChar(0,a,'-',false);
    delay(100);
  }
  
  for (int a=0; a<8; a++)
  {
    lc.setChar(0,a,' ',false);
    delay(100);
  }
}
