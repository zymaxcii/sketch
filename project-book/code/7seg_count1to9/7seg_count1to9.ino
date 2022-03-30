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

// I/O connections:
// segments A,B,C,D,E,F,G,DP to pins D2,D3,D4,D5,D6,D7,D8,D9
// common cathode 42056W8 pins 3,8 to GND

#include "SevSeg.h"

SevSeg sevseg; 

void setup()
{
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

  // byte segmentPins[] = {6, 9, 2, 3, 4, 7, 8, 5};

  bool resistorsOnSegments = true;

  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}


void loop()
{

//    sevseg.setNumber(5);
//    sevseg.refreshDisplay();
 
  int index;
  for (index=1; index<=9; index++)
  {
    sevseg.setNumber(index);
    sevseg.refreshDisplay();
    delay(1000);        
  }
}
