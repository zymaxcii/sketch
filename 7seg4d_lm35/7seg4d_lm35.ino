// 7seg4d_lm35.ino
// Display temperature reading from lm35 on 4-digit 7 segment display

// Boards to run the sketch:
// my 7 segment 4-digit led board plus lm35 temperature sensor

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

int val;
int tempPin = A0;   // A0 or 0


void setup()
{
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  bool resistorsOnSegments = true;
  byte hardwareConfig = COMMON_CATHODE;

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  Serial.begin(9600);
}


void loop()
{
  // read temperature
  val = analogRead(tempPin);

  float mv = ( val/1024.0)*5000;
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;

  //  Serial.print("Sensor value = ");
  //  Serial.print(val);
  //  Serial.println();

  //  Serial.print("TEMPRATURE = ");
  //  Serial.print(cel);
  //  Serial.print("*C");
  //  Serial.println();
  //  delay(10);
  
  // uncomment this to get temperature in farenhite
  //  Serial.print("TEMPRATURE = ");
  //  Serial.print(farh);
  //  Serial.print("*F");
  //  Serial.println();


  // timer is display update frequency
  static unsigned long timer = millis();

  if (millis() >= timer)
  {
    timer += 5000;
    sevseg.setNumberF(cel, 2);
  }

  sevseg.refreshDisplay();
}
