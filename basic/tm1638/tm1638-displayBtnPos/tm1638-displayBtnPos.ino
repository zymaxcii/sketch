// tm1638-displayBtnPos.ino
// Display a number corresponding to position of buttons pressed

// https://www.instructables.com/Arduino-and-TM1638-LED-Display-Modules/


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

byte buttons;


void setup(){}


void loop()
{
 buttons = module.getButtons();
 
 module.setDisplayToDecNumber(buttons, 0, false);
}
