// tm1638_display10to11K.ino
// Display numbers from 10000 to 11000

// https://www.instructables.com/Arduino-and-TM1638-LED-Display-Modules/

// My standard hardware setup
// Led-Key module
// VCC 3.5V
// GND GND
// STB D7
// CLK D9
// DIO D8
//

#include <TM1638.h>

// define a module on data pin 8, clock pin 9 and strobe pin 7
TM1638 module(8, 9, 7);

unsigned long a = 1;


void setup(){}


void loop()
{
  for (a=10000; a<11000; a++)
  {
    module.setDisplayToDecNumber(a, 4, false);
    delay(1);
  }

  for (a=10000; a<11000; a++)
  {
    module.setDisplayToDecNumber(a, 0, true);
    delay(1);
 }
}
