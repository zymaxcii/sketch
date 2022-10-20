// tm1638.ino
// https://akuzechie.blogspot.com/2021/02/tm1638-module-executing-multiple.html


// TM1638: Multiple Functions
#include <FreqCount.h>
#include <DHT.h>

DHT dht(6, DHT11);
int stb=7, clk=9, dio=8; uint8_t buttons;

int digit[]  = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int letter[] = {0x76,0x79,0x38,0x38,0x3F};
unsigned long freq; int temp, hum, pot, value[7];

#include "tm1638_Initialization.h"
#include "readButtons.h"
#include "setLED.h"
#include "setDisplay.h"
#include "scroll_2021.h"
#include "functions.h"


void setup()
{
  pinMode(stb, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(dio,OUTPUT);

  FreqCount.begin(1000);
  dht.begin();
  TM1638_Initialization();
}


void loop()
{
  setDisplay(0x6D,0); setDisplay(0x79,1);
  setDisplay(0x38,2); setDisplay(0x06,3);
  setDisplay(0x5B,4); setDisplay(0x4F,5);
  setDisplay(0x66,6); setDisplay(0x6D,7);
  
  buttons = readButtons();
  
  // button 1 pressed: frequency counter
  if (buttons == 1) freqCounter();

  // button 2 pressed: Temp & humidity
  if (buttons == 2) tempHumidity();

  // button 3 pressed: Bar Graph
  if (buttons == 4) barGraph();

  // button 4 pressed: scrolling text
  if (buttons == 8) scrollText();

  // button 5 pressed: 8-bit binary count
  if (buttons == 16) binaryCount();
  
  delay(200);
}
