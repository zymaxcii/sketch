// max7219_lcScrollText.ino
// Scroll sample text using LedControl library
// Idea is there but cannot figure out the text
// seems to be mirror image or up side down
// scroll left to right?

// Mario's Ideas
//MAX7219 - using Led Control library to scroll the sample text
// https://create.arduino.cc/projecthub/mdraber/controlling-8x8-dot-matrix-with-max7219-and-arduino-7314a7?ref=user&ref_id=1474727&offset=5
// https://www.youtube.com/watch?v=SGjQ-E3UD7A

// My standard hardware setup
// DIN D11
// CLK D13
// CS  D10
// Using hardware SPI DIN and CLK are fixed at D11 and D13 respectively
// So the only choice to make is CS to D10


#include <LedControl.h>

int DIN = 11;
int CS = 10;
int CLK = 13;

LedControl lc=LedControl(DIN, CLK, CS, 1);      // why 0 in last parameter?

int position=0;

int Marios_ideas [8] [54] =
{
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,0,0,0,1,0,0,1,1,0,0,1,1,1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,1,1,0,0,0,1,1,0,0,0,0},
  {0,1,1,0,1,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0},
  {0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},
  {0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,0,0},
  {0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0},
  {0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0,1,0,0,0,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0}
};


void setup()
{
   lc.shutdown(0, false);
   lc.setIntensity(0, 0);
   lc.clearDisplay(0);
}


void loop()
{
  for (int j=0; j<8; j++)
  {
    for (int i=0; i<8; i++)
    {
      lc.setLed(0, i,j, Marios_ideas[j][(i+position)-abs((i+position)/54)*54]);  // don't understand
    }
  }
  delay(1000);                // 20
  position = position+1;
}  
