// 8ledsr_binaryCount.ino
// Count in binary MSB first and display output to 8 leds
// https://dronebotworkshop.com/shift-registers/


/*
  74HC595 Shift Register Demonstration 1
  74hc595-demo.ino
  Count in Binary and display on 8 LEDs
  Modified from "Hello World" example by Carlyn Maw,Tom Igoe and David A. Mellis
  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/

// 74HC595 pins DS, ST_CP, SH_CP: 14, 12, 11 (data, storage, shift register)
// pin headers bottom to top:
// 11 SH_CP D8
// 12 ST_CP D7
// 14 DS    D6
int clockpin = 8;
int latchpin = 7;
int datapin  = 6;     // bottom pin


// Define Connections to 74HC595
void setup ()
{
  // Setup pins as Outputs
  pinMode(latchpin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(datapin, OUTPUT);
}


void loop()
{
  // Count from 0 to 255 and display in binary

  for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++)
  {
    // ST_CP LOW to keep LEDs from changing while reading serial data
    digitalWrite(latchpin, LOW);

    // Shift out the bits
    shiftOut(datapin, clockpin, MSBFIRST, numberToDisplay);

    // ST_CP HIGH change LEDs
    digitalWrite(latchpin, HIGH);
    delay(500);
  }
}
