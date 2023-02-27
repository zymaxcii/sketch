// tft_hello.ino
// Display "Hello, World!" on tft lcd display
// status: compile ok, upload ok

// https://randomnerdtutorials.com/guide-to-1-8-tft-display-with-arduino/

// write_text.ino
/*
 * Rui Santos 
 * Complete Project Details http://randomnerdtutorials.com
*/


// include TFT and SPI libraries
#include <TFT.h>  
#include <SPI.h>

// pin definition for Arduino UNO, Mega as well
// 3 pins
#define cs   10
#define dc   9
#define rst  8

// create an instance
TFT TFTscreen = TFT(cs, dc, rst);


void setup()
{
  // initialize
  TFTscreen.begin();

  // clear screen with a black background
  TFTscreen.background(0, 0, 0);
  // set the text size
  TFTscreen.setTextSize(2);
}


void loop()
{
  // generate a random color
  int redRandom = random(0, 255);
  int greenRandom = random (0, 255);
  int blueRandom = random (0, 255);
  
  // set a random font color
  TFTscreen.stroke(redRandom, greenRandom, blueRandom);
  
  // print Hello, World! in the middle of the screen
  TFTscreen.text("Hello, World!", 6, 57);
  
  // wait 200 miliseconds until change to next color
  delay(200);
}
