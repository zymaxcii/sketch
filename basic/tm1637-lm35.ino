// tm1637-lm35.ino
// https://mytectutor.com/tm1637-4-digit-7-segment-display-with-arduino-digital-clock-example/


#include <TM1637Display.h>
 
const int CLK = 9; //Set the CLK pin connection to the display
const int DIO = 8; //Set the DIO pin connection to the display

const uint8_t blank[] = {0x00, 0x00, 0x00,0x00};

const int tempPin = A0;

// Create degree Celsius symbol:
const uint8_t celsius[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_D | SEG_E | SEG_F   // C
};

// Create degree Fahrenheit symbol:
const uint8_t fahrenheit[]
= {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_E | SEG_F | SEG_G   // F
};

TM1637Display display(CLK, DIO); //set up the 4-Digit Display.
 
void setup()
{
    display.setBrightness(0x0a); //set the diplay to maximum brightness
    display.setSegments(blank);//clear display
}
 
 
void loop()
{
  int value = analogRead(tempPin); // read the value from sensor
  float millivolts = (value / 1024.0) * 5000;
  int t = millivolts / 10;  // temperature in degrees celcius
  int f = (t * 9)/5 + 32;  // convert celcius to fahrenheit
 
  // Show the temperature on the TM1637 display:
  display.showNumberDec(t, false, 2, 0);
  display.setSegments(celsius, 2, 2);
  delay(2000);

  display.showNumberDec(f, false, 2, 0);
  display.setSegments(fahrenheit, 2, 2);
  delay(2000);
 
}
