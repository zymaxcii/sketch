// 7seg4d_display4999.ino
// display 499.9 on 4-digit 7-segment display

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

// my standard i/o connections for 7 segment 4-digit led:
// bottom CCW pins 1-6, then 7-12
// pins 1-12: E,D,DP,C,G,D4, B,D3,D2,F,A,D1
// segments A,B,C,D,E,F,G,DP to pins D6,D7,D8,D9,D10,D11,D12,D13
// common cathode 3641AS pins D1,D2,D3,D4: D2,D3,D4,D5


#include "SevSeg.h"

SevSeg sevseg; 

void setup()
{
  byte numDigits = 4;
  byte digitPins[]   = {2, 3, 4, 5};
  byte segmentPins[] = {6,7,8,9,10,11,12,13};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn  = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}


void loop()
{
  // 4999,3
  // 2nd parameter is no. of decimal places
  sevseg.setNumber(4999, 2);
  sevseg.refreshDisplay(); 
}
