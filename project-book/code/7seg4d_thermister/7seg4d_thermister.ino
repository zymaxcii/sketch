// 7seg4d_thermister.ino

// What thermister is used here?

// Boards to run the sketch:
// my 7 segment 4-digit led board

// 3641AS:
// 
// pin # Name to Uno Pin
// =====================
// 1  E  D6
// 2  D  D5
// 3  DP D9
// 4  C  D4
// 5  G  D8
// 6  D4 D13
// 7  B  D3
// 8  D3 D12
// 9  D2 D11
//10  F  D7  
//11  A  D2
//12  D1 D10

// bottom CCW pins 1-6, then 7-12
// pins 1-12: E,D,DP,C,G,D4, B,D3,D2,F,A,D1
// segments A,B,C,D,E,F,G,DP to pins D2,D3,D4,D5,D6,D7,D8,D9
// common cathode 3641AS pins D1,D2,D3,D4: D10,D11,D12,D13

#include "SevSeg.h"

SevSeg sevseg;

// connected to A0
int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup()
{
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  bool resistorsOnSegments = true;
  byte hardwareConfig = COMMON_CATHODE;

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
}


void loop()
{
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  T = T - 273.15;
  T = (T * 9.0) / 5.0 + 32.0; //Comment out for Celsius

  static unsigned long timer = millis();

  if (millis() >= timer) {
    timer += 300;
    sevseg.setNumber(T, 2);
  }

  sevseg.refreshDisplay();
}
