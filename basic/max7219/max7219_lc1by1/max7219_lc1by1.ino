// max7219_lc1by1.ino
// Display all leds in a MAX7219 one by one

// Mario's Ideas
// MAX7219 - using Led Control library to display all leds one by one
// https://create.arduino.cc/projecthub/mdraber/controlling-8x8-dot-matrix-with-max7219-and-arduino-7314a7?ref=user&ref_id=1474727&offset=5
// https://www.youtube.com/watch?v=SGjQ-E3UD7A

// My standard hardware setup
// DIN D11
// CLK D13
// CS  D10
// Using hardware SPI DIN and CLK are fixed at D11 and D13 respectively
// So the only choice to make is CS to D10


#include <LedControl.h>

int DIN = 11;      // not used
int CS = 7;
int CLK = 13;

// LedControl lc=LedControl(DIN, CLK, CS,0);

//                       DIN, CLK, CS
LedControl lc = LedControl(11,13,10,0); // 1 unit: last parameter 1 or 0 also work. Why?


void setup()
{
  lc.shutdown(0, false);
  lc.setIntensity(0, 1);                // 0 also work!
  lc.clearDisplay(0);
}


void loop()
{
  for (int j = 0; j < 8; j++)        // row first
  {
     for (int i = 0; i < 8; i++)
     {
       lc.setLed(0, j,i, true);
       delay(100);
       lc.setLed(0, j,i, false);
     }
  }
}
