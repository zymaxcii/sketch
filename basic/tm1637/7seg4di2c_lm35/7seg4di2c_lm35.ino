// 7seg4di2c_lm35.ino
//
// displayTempLM35.ino
// https://mytectutor.com/tm1637-4-digit-7-segment-display-with-arduino-digital-clock-example/

// Boards to run this sketch
// tm1637 7 segment 4 digit led display I2C version (software implementation)
// plus lm35 temperature sensor

// pin # Name to Uno Pin
// =====================
// 1  CLK	D2
// 2  DIO	D3
// 3  VCC	VCC
// 4  GND	GND
// 
// lm35 temperature sensor
// pin # Name to Uno Pin
// =====================
// 1  VCC	+5V
// 2  V0	A0
// 3  GND	GND


#include <TM1637Display.h>
 
const int CLK = 2;
const int DIO = 3;

const uint8_t blank[] = {0x00, 0x00, 0x00,0x00};

const int tempPin = A0;    // temperature sensor

// Create degree Celsius symbol
const uint8_t celsius[] =
{
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_D | SEG_E | SEG_F   // C
};

// Create degree Fahrenheit symbol
const uint8_t fahrenheit[] =
{
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_E | SEG_F | SEG_G   // F
};

TM1637Display display(CLK, DIO); // set up display
 
void setup()
{
  display.setBrightness(0x0a); // set to maximum brightness
  display.setSegments(blank);  // clear display
}


void loop()
{
  int value = analogRead(tempPin); // read temperature sensor
  
  float millivolts = (value / 1024.0) * 5000;
  int t = millivolts / 10;         // temperature in degrees celcius
  int f = (t * 9)/5 + 32;          // convert celcius to fahrenheit
 
  // Show temperature on display
  display.showNumberDec(t, false, 2, 0);
  display.setSegments(celsius, 2, 2);
  delay(5000);

  display.showNumberDec(f, false, 2, 0);
  display.setSegments(fahrenheit, 2, 2);
  delay(5000);
}
