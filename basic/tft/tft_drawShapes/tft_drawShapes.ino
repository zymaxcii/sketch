// tft_drawShapes.ino
// status: compile ok, upload ok


// https://randomnerdtutorials.com/guide-to-1-8-tft-display-with-arduino/


// draw_shapes.ino
/*
 * Rui Santos 
 * Complete Project Details http://randomnerdtutorials.com
*/


// include TFT and SPI libraries
#include <TFT.h>  
#include <SPI.h>

// pin definition for Arduino UNO
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
}


void loop()
{

  // generate a random color
  int redRandom = random(0, 255);
  int greenRandom = random (0, 255);
  int blueRandom = random (0, 255);
  
  // set color
  TFTscreen.stroke(redRandom, greenRandom, blueRandom);

  // light up a single point
  TFTscreen.point(80, 64);
  // wait 200 ms until change to next figure
  delay(500);

  // draw a line
  TFTscreen.line(0, 64, 160, 64);
  delay(500);

  // draw a square
  TFTscreen.rect(50, 34, 60, 60);
  delay(500);
    
  // draw a circle
  TFTscreen.circle(80, 64, 30);
  delay(500);

  // erase all figures
  TFTscreen.background(0, 0, 0);
}
