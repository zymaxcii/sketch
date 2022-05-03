// 7seg_count1to9.ino
// Count from 1 to 9
//
// Boards to run the sketch:
// my 7 segment led board

// pin # Name to Uno Pin
// =====================
// 1  E	D6
// 2  D	D5
// 3  COM	GND
// 4  C	D4
// 5  DP	D9
// 6  B	D3
// 7  A	D2
// 8  COM	GND
// 9  F	D7
//10  G	D8	
//

// My standard I/O connections:
// segments A,B,C,D,E,F,G,DP to digital pins 6,7,8,9,10,11,12,13
// common cathode 42056W8 pins 3,8 to GND
// pins 0,1 for serial
// pins 2,3,4,5 for switches

#include "SevSeg.h"

SevSeg sevseg; 

void setup()
{
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = true;

  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}


void loop()
{

  // sevseg.setNumber(5);
  // sevseg.refreshDisplay();
 
  int index;
  for (index=0; index<=9; index++)
  {
    sevseg.setNumber(index);
    sevseg.refreshDisplay();
    delay(500);        
  }
}
