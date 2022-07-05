// upDownCounter.ino
// https://mytectutor.com/tm1637-4-digit-7-segment-display-with-arduino-digital-clock-example/
// with TM1637

#include <TM1637Display.h>

#define UP 2
#define DOWN 3
 
const int CLK = 8; //Set the CLK pin connection to the display
const int DIO = 9; //Set the DIO pin connection to the display

const uint8_t blank[] = {0x00, 0x00, 0x00,0x00};

TM1637Display display(CLK, DIO); //set up the 4-Digit Display.

int num = 0;

void setup()
{
    pinMode(UP, INPUT_PULLUP);
    pinMode(DOWN,
INPUT_PULLUP);
    display.setBrightness(0x0a); //set the diplay to maximum brightness
    display.setSegments(blank);//clear display
}

void loop()
{
   display.showNumberDec(num, true, 4, 0);
   delay(200); //wait 200 milliseconds
 
  if( digitalRead(UP) )
  { // if the UP button is presses
    num++;         // increment 'num'
    if(num > 9999)
      num = 0;
  }
 
  if( digitalRead(DOWN) )
  { // if the DOWN button is presses
    num--;        // decrement 'num'
    if(num < 0)
      num = 9999;
  }
 
}
