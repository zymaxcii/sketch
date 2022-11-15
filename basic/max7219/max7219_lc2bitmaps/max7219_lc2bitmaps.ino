// max7219_lc2bitmaps.ino
// using Led Control library to display 2 8x8 bitmaps
// work on 1 max7219 device

// Mario's Ideas
// MAX7219 - using Led Control library to display 8x8 bitmap
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
int CS  = 10;
int CLK = 13;

LedControl lc = LedControl(DIN, CLK, CS, 0);

int Cat[8] =
{
  B10001000,
  B11111000,
  B10101000,
  B01110001,
  B00100001,
  B01111001,
  B01111101,
  B10111110
};


byte Apple [8] =
{
  B00011000,
  B00001000,
  B01110110,
  B11111111,
  B11111111,
  B11111111,
  B01111010,
  B00110100
};


void setup()
{
  lc.shutdown(0, false);
  lc.setIntensity(0, 0);
  lc.clearDisplay(0);
}

  
void loop()
{
  for (int i=0; i<8; i++)
  {
    lc.setRow(0, i, Apple[i]);
  }
  delay(5000);
  
  lc.clearDisplay(0);
  
  for (int i=0; i<8; i++)
  {
    lc.setRow(0, i, Cat[i]);
  }
  delay(5000);
  lc.clearDisplay(0);
}
