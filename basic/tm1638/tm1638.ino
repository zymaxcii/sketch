// tm1638.ino
// https://akuzechie.blogspot.com/2021/02/tm1638-module-executing-multiple.html


//TM1638: Multiple Functions
#include <FreqCount.h>
#include <DHT.h>

DHT dht(6, DHT11);
int stb=2, clk=3, dio=4; uint8_t buttons;

int digit[]  = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int letter[] = {0x76,0x79,0x38,0x38,0x3F};
unsigned long freq; int temp, hum, pot, value[7];

#include "TM1638_Initialization.h"
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


Header file "functions.h":

// Convert frequency value to display characters
void value2DispConv(int n)
{
  for (int i=0; i<=n; i++)
  {
    switch(value[i])
    {
      case 0: value[i] = digit[0]; break;
      case 1: value[i] = digit[1]; break;
      case 2: value[i] = digit[2]; break;
      case 3: value[i] = digit[3]; break;
      case 4: value[i] = digit[4]; break;
      case 5: value[i] = digit[5]; break;
      case 6: value[i] = digit[6]; break;
      case 7: value[i] = digit[7]; break;
      case 8: value[i] = digit[8]; break;
      case 9: value[i] = digit[9]; break;
    }
  }
}


// Frequency display on TM1638
void freqCounter()
{
  for (int i=0; i<=7; i++) setDisplay(0, i);
  delay(200);
  buttons = readButtons();
  
  while (buttons == 0)
  {
    buttons = readButtons();
    if (FreqCount.available())
    {
      freq = FreqCount.read();

      for (int i=6; i>=0; i--)
      {
        value[i] = freq % 10;
        freq /= 10;
      } 
      value2DispConv(6);
    } 
    setDisplay(0x71, 0);
    for(int j=0; j<=6; j++) setDisplay(value[j], j+1);
  }
  
  for (int i=0; i<=7; i++) setDisplay(0, i);
}


// Temp & humidity display on TM1630
void tempHumidity()
{
  for (int i=0; i<=7; i++) setDisplay(0, i);
  delay(200);
  buttons = readButtons();

  while (buttons == 0)
  {
    buttons = readButtons();
    temp = dht.readTemperature();
    hum = dht.readHumidity();
    value[0] = (temp/10) % 10;
    value[1] = temp % 10;
    value[2] = (hum/10) % 10;
    value[3] = hum % 10;
    value2DispConv(3);
    setDisplay(value[0], 0);
    setDisplay(value[1], 1);
    setDisplay(0x39, 2);
    setDisplay(0x40, 3);
    setDisplay(0x40, 4);
    setDisplay(value[2], 5);
    setDisplay(value[3], 6);
    setDisplay(0x73, 7);
  }
  
  for (int i=0; i<=7; i++) setDisplay(0, i);
}


// Bar graph display on TM1630
void barGraph()
{
  for (int i=0; i<=7; i++) setDisplay(0, i);
  delay(200);
  buttons = readButtons();
  while (buttons == 0)
  {
    buttons = readButtons();
    pot = constrain(analogRead(A7), 0, 1000);
    pot = map(pot, 0,1000, 0,16);

    switch(pot)
    {
      case 0:
      {
        for (int i=0; i<=7; i++) setDisplay(0, i); break;
      }
      
      case 1:
      {
        for (int i=1; i<=7; i++) setDisplay(0, i);
        setDisplay(0x30, 0); break;
      }
      
      case 2:
      {
        setDisplay(0x36, 0); break;
      }
      
      case 3:
      {
        for (int i=2; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x30, 1); break; 
      }
      
      case 4:
      {
        for (int i=2; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1); break;
      }
      
      case 5:
      {
        for (int i=3; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x30, 2); break;
      }
      
      case 6:
      {
        for (int i=3; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); break;
      }
      
      case 7:
      {
        for (int i=4; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x30, 3); break;
      }
      
      case 8:
      {
        for (int i=4; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3); break;
      }
      
      case 9:
      {
        for (int i=5; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x30, 4); break;
      }
      
      case 10:
      {
        for (int i=5; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); break;
      }
      
      case 11:
      {
        for(int i=6; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); setDisplay(0x30, 5); break;
      }
      
      case 12:
      {
        for (int i=6; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); setDisplay(0x36, 5); break;
      }
      
      case 13:
      {
        for (int i=7; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); setDisplay(0x36, 5);
        setDisplay(0x30, 6); break;
      }
      
      case 14:
      {
        for (int i=7; i<=7; i++) setDisplay(0, i);
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); setDisplay(0x36, 5);
        setDisplay(0x36, 6); break;
      }
      
      case 15:
      {
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); setDisplay(0x36, 5);
        setDisplay(0x36, 6); setDisplay(0x30, 7); break;
      }
      
      case 16:
      {
        setDisplay(0x36, 0); setDisplay(0x36, 1);
        setDisplay(0x36, 2); setDisplay(0x36, 3);
        setDisplay(0x36, 4); setDisplay(0x36, 5);
        setDisplay(0x36, 6); setDisplay(0x36, 7); break;
      }
    }
  }
  for (int i=0; i<=7; i++) setDisplay(0, i);
}


// Scroll text on TM1630
void scrollText()
{
  for (int i=0; i<=7; i++) setDisplay(0, i);
  do
  {
    for (int i=0; i<=4; i++)
    {
      for (int j=0; j<=7; j++)
      {
        buttons = readButtons();
        
        if (buttons == 128)
        {
          setLed(0, j); setDisplay(0, j);
          return;
        }
        
        pot = map(analogRead(A7),0,1023, 50,1000);
        setLed(1, j);
        setDisplay(letter[i], j);
        delay(pot);
        setLed(0, j);
        setDisplay(0, j);
        delay(pot);
      }
    }
    scroll_2021();
  } while(1);
  
  for (int i=0; i<=7; i++) setDisplay(0, i);
}


// 8-bit Binary Count on TM1630
//============================
void binaryCount()
{
  for (int i=0; i<=7; i++) setDisplay(0, i);
  do
  {
    for (int i=0; i<=1; i++)
    {
      for (int j=0; j<=1; j++)
      {
        for (int k=0; k<=1; k++)
        {
          for (int l=0; l<=1; l++)
          {
            for (int m=0; m<=1; m++)
            {
              for (int n=0; n<=1; n++)
              {
                for (int o=0; o<=1; o++)
                {
                  for (int p=0; p<=1; p++)
                  {
                    buttons = readButtons();
                    if (buttons == 128)
                    {
                      for (int i=0; i<=7; i++) setLed(0, i);
                      for(int j=0; j<=7; j++) setDisplay(0, j);
                      return;
                    }
                    
                    setLed(i, 0); setLed(j, 1);
                    setLed(k, 2); setLed(l, 3);
                    setLed(m, 4); setLed(n, 5);
                    setLed(o, 6); setLed(p, 7);
                    
                    setDisplay(digit[i], 0);
                    setDisplay(digit[j], 1);
                    setDisplay(digit[k], 2);
                    setDisplay(digit[l], 3);
                    setDisplay(digit[m], 4);
                    setDisplay(digit[n], 5);
                    setDisplay(digit[o], 6);
                    setDisplay(digit[p], 7);
                    delay(map(analogRead(A7),0,1023, 50,1000));
                  }
                }
              }
            }
          }
        }  
      }
    }
  } while(1);
  
  for (int i=0; i<=7; i++) setDisplay(0, i);
}

Header file "scroll_2021.h":

// scroll "2021"
void scroll_2021()
{
  setDisplay(digit[1], 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(digit[2], 0); setDisplay(digit[1], 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(digit[0], 0); setDisplay(digit[2], 1); setDisplay(digit[1], 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(digit[2], 0); setDisplay(digit[0], 1); setDisplay(digit[2], 2); setDisplay(digit[1], 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(digit[2], 1); setDisplay(digit[0], 2); setDisplay(digit[2], 3);
  setDisplay(digit[1], 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(digit[2], 2); setDisplay(digit[0], 3);
  setDisplay(digit[2], 4); setDisplay(digit[1], 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(digit[2], 3);
  setDisplay(digit[0], 4); setDisplay(digit[2], 5); setDisplay(digit[1], 6); setDisplay(0, 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(digit[2], 4); setDisplay(digit[0], 5); setDisplay(digit[2], 6); setDisplay(digit[1], 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(digit[2], 5); setDisplay(digit[0], 6); setDisplay(digit[2], 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(digit[2], 6); setDisplay(digit[0], 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(digit[2], 7);
  delay(pot*2);
  
  setDisplay(0, 0); setDisplay(0, 1); setDisplay(0, 2); setDisplay(0, 3);
  setDisplay(0, 4); setDisplay(0, 5); setDisplay(0, 6); setDisplay(0, 7);
  delay(pot*2);
}


Header file "TM1638_Initialization.h":

// TM1638 Initialization
void TM1638_Initialization()
{
  // activate TM1638 & set brightness of display to max
  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0x8F);
  digitalWrite(stb, HIGH);
  
  // set auto increment mode to reset LEDs and displays
  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0x40);
  digitalWrite(stb, HIGH);
  
  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0xc0);

  for (int i=0; i<16; i++) shiftOut(dio, clk, LSBFIRST, 0x00);
  digitalWrite(stb, HIGH);
  
  
  // set single address mode
  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0x44);
  digitalWrite(stb, HIGH);
}


Header file "readButtons.h":

// read TM1638 button status
uint8_t readButtons()
{
  buttons = 0;

  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0x42);
  pinMode(dio, INPUT);

  for (uint8_t i=0; i<=3; i++)
  {
    uint8_t v = shiftIn(dio, clk, LSBFIRST) << i;
    buttons |= v;
  }

  pinMode(dio, OUTPUT);
  digitalWrite(stb, HIGH);
  return buttons;
}


Header file "setLED.h":

// Button press, set LED
void setLed(int value, int position)
{
  pinMode(dio, OUTPUT);
  
  // command byte to set single address mode
  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0x44);
  digitalWrite(stb, HIGH);
  
  // turn ON LED due to button press
  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0xC1 + (position<<1));
  shiftOut(dio, clk, LSBFIRST, value);
  digitalWrite(stb, HIGH);
}


Header file "setDisplay.h":


// Press button, set display
void setDisplay(uint8_t value, uint8_t position)
{
  pinMode(dio, OUTPUT);

  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0x44);
  digitalWrite(stb, HIGH);

  digitalWrite(stb, LOW);
  shiftOut(dio, clk, LSBFIRST, 0xC0 + (position<<1));
  shiftOut(dio, clk, LSBFIRST, value);
  digitalWrite(stb, HIGH);
}

