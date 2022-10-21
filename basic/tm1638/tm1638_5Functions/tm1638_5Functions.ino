// tm1638-readButtons.ino
// Read buttons 1 to 5
// button 1: display frequency count
// button 2: display temperature and humidity
// button 3: display bar graph according to A7 analog input
// button 4: display scrolled text
// button 5: display binary count

// https://akuzechie.blogspot.com/2021/02/tm1638-module-executing-multiple.html

// My standard hardware setup
// Led-Key module
// VCC 3.5V
// GND GND
// STB D7
// CLK D9
// DIO D8
//
// DHT22
// VCC 5V
// GND GND
// S D6
//
// Pot A7



// TM1638: Multiple Functions
#include <FreqCount.h>
#include <DHT.h>


DHT dht(5, DHT11);      // DHT11 is blue

int stb=7, clk=9, dio=8; uint8_t buttons;

int digit[]  = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int letter[] = {0x76,0x79,0x38,0x38,0x3F};
unsigned long freq; int temp, hum, pot, value[7];

// In local folder
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
  pinMode(dio, OUTPUT);

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
