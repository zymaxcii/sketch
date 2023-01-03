// max7219_lcnum.ino
// Numeric display
// On 4 MAX7219, it did not display correctly
// Don't know what is supposed to be displayed
// This code will work correctly on max7219-based 4-digit display

// https://tronixstuff.com/2013/10/11/tutorial-arduino-max7219-led-display-driver-ic/


#include "LedControl.h"

//                       DIN, CLK, CS
LedControl lc = LedControl(11,13,10,1);       // 1 unit 

// pin 12 is connected to the MAX7219 pin 1
// pin 11 is connected to the CLK pin 13
// pin 10 is connected to LOAD pin 12
// 1 as we are only using 1 MAX7219

int msec = 1000;

void setup()
{
  // the zero refers to the MAX7219 number, it is zero for 1 chip
  lc.shutdown(0, false);                 // turn off power saving, enables display
  lc.setIntensity(0, 1);                 // sets brightness (0~15 possible values)
  lc.clearDisplay(0);                    // clear screen
}


void loop()
{
  for (int a = 0; a < 8; a++)
  {
    lc.setDigit(0, a, a, true);
<<<<<<< Updated upstream
    delay(msec);
  }
  
  for (int a=0; a < 8; a++)               // display 8
  {
    lc.setDigit(0, a, 8, 1);
    delay(msec);
=======
    delay(100);
>>>>>>> Stashed changes
  }
  
  for (int a = 0; a < 8; a++)
  {
<<<<<<< Updated upstream
    lc.setDigit(0, a, 0, false);           // turn off display
    delay(msec);
  }
  
  for (int a=0; a < 8; a++)
  {
    lc.setChar(0, a, ' ', false);
    delay(msec);
  }
  
  for (int a = 0; a < 8; a++)              // display '-'
  {
    lc.setChar(0,a,'-',false);
    delay(msec);
=======
    lc.setDigit(0, a, 8, 1);
    delay(100);
  }
  
  for (int a = 0; a < 8; a++)
  {
    lc.setDigit(0, a, 0, false);
    delay(100);
  }
  
  for (int a = 0; a < 8; a++)
  {
    lc.setChar(0, a, ' ', false);
    delay(100);
  }
  
  for (int a = 0; a < 8; a++)
  {
    lc.setChar(0, a, '-', false);
    delay(100);
>>>>>>> Stashed changes
  }
  
  for (int a = 0; a < 8; a++)
  {
<<<<<<< Updated upstream
    lc.setChar(0,a,' ',false);
    delay(msec);
=======
    lc.setChar(0, a, ' ', false);
    delay(100);
>>>>>>> Stashed changes
  }
}
