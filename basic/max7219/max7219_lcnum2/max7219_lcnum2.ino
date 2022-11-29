// max7219_lcnum2.ino
// Work on max7219 8-digit 7-segment display

// https://www.pjrc.com/teensy/td_libs_LedControl.html

#include <LedControl.h>

//                       DIN, CLK, CS
LedControl mydisplay = LedControl(11,13,10,1); // 1 unit 


void setup()
{
  mydisplay.shutdown(0, false);         // turns on display
  mydisplay.setIntensity(0, 1);         // 15 = brightest
  
  mydisplay.setDigit(0, 0, 9, false);
  mydisplay.setDigit(0, 1, 8, false);
  mydisplay.setDigit(0, 2, 7, false);
  mydisplay.setDigit(0, 3, 6, false);
  mydisplay.setDigit(0, 4, 5, true);     // true for dot
  mydisplay.setDigit(0, 5, 4, false);
  mydisplay.setDigit(0, 6, 3, false);
  mydisplay.setDigit(0, 7, 2, false);
}


void loop()
{ }
