/*
 * Arduino Aquarium Lighting System
 * 
 * learnelectronics
 * 13 MAR 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */


//---------------------------------------------------------------------------------------------------------------
//                                                      LIBRARIES
//---------------------------------------------------------------------------------------------------------------
#include <Adafruit_NeoPixel.h>                                                          //neopixel library
#include <avr/power.h>                                                                  //power library


//---------------------------------------------------------------------------------------------------------------
//                                                       DEFINES
//---------------------------------------------------------------------------------------------------------------
#define PIN            6                                                                //data pin
#define NUMPIXELS      10                                                               //number of ws2812b


/*
 * Modes are:                                                                           //listing of modes & delays
 * 
 * wakeup     6am-8am        2 hours          delay of 7,200,000 miliseconds
 * morning    8am-noon       4 hours          delay of 14,400,000 miliseconds      
 * noon       12pm-4pm       4 hours          delay of 14,400,000 miliseconds
 * evening    4pm-8pm        4 hours          delay of 14,400,000 miliseconds
 * night      8pm-10pm       2 hours          delay of 7,200,000 miliseconds
 * sleepy     10pm-11pm      1 hour           delay of 3,600,000 miliseconds
 * off        11pm-6am       7 hours          delay of 25,200,000 miliseconds
 */

//---------------------------------------------------------------------------------------------------------------
//                                                 LIBRARY OBJECTS
//---------------------------------------------------------------------------------------------------------------
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);     //neopixel library object setup

//---------------------------------------------------------------------------------------------------------------
//                                                       SETUP
//---------------------------------------------------------------------------------------------------------------
void setup() {
 

  pixels.begin();                                                                       // This initializes the NeoPixel library.                 
}


//---------------------------------------------------------------------------------------------------------------
//                                                  MAIN LOOP
//---------------------------------------------------------------------------------------------------------------
void loop() {
wakeUp();                                                                               //first mode @ 6am - 2 hours
delay(7200000);                                                                           //delay of 7,200,000 miliseconds
morning();                                                                              //second mode @ 8am - 4 hours
delay(14400000);                                                                           //delay of 14,400,000 miliseconds
noon();                                                                                 //third mode @ noon - 4 hours
delay(14400000);                                                                           //delay of 14,400,000 miliseconds
evening();                                                                              //fourth mode @ 4pm - 4 hours
delay(14400000);                                                                           //delay of 14,400,000 miliseconds
night();                                                                                //sixth mode @ 8pm - 2 hours
delay(3600000);                                                                           //delay of 3,600,000 miliseconds
sleepy();                                                                               //final mode @10pm - ` hour
delay(25200000);                                                                           //delay of 25,200,000 miliseconds
}


//---------------------------------------------------------------------------------------------------------------
//                                                  FUNCTIONS
//---------------------------------------------------------------------------------------------------------------
void wakeUp(){
  pixels.setPixelColor(0, pixels.Color(50,0,0));                                        //low brightness red
  pixels.setPixelColor(1, pixels.Color(50,0,0));                                        //low brightness red
  pixels.setPixelColor(2, pixels.Color(50,0,0));                                        //low brightness red
  pixels.setPixelColor(3, pixels.Color(50,0,0));                                        //low brightness red
  pixels.setPixelColor(4, pixels.Color(50,0,0));                                        //you get the idea
  pixels.setPixelColor(5, pixels.Color(50,0,0));
  pixels.setPixelColor(6, pixels.Color(50,0,0));
  pixels.setPixelColor(7, pixels.Color(50,0,0));
  pixels.setPixelColor(8, pixels.Color(50,0,0));
  pixels.setPixelColor(9, pixels.Color(50,0,0));
  pixels.show();
}


void morning(){
  pixels.setPixelColor(0, pixels.Color(127,0,0));                                       //medium brightness red
  pixels.setPixelColor(1, pixels.Color(0,0,127));                                       //medium brightness blue
  pixels.setPixelColor(2, pixels.Color(127,0,0));
  pixels.setPixelColor(3, pixels.Color(0,0,127));
  pixels.setPixelColor(4, pixels.Color(127,0,0));
  pixels.setPixelColor(5, pixels.Color(0,0,127));
  pixels.setPixelColor(6, pixels.Color(127,0,0));
  pixels.setPixelColor(7, pixels.Color(0,0,127));
  pixels.setPixelColor(8, pixels.Color(127,0,0));
  pixels.setPixelColor(9, pixels.Color(0,0,127));
  pixels.show();
}


void noon(){
  pixels.setPixelColor(0, pixels.Color(255,255,255));                                   //full brightness white
  pixels.setPixelColor(1, pixels.Color(0,0,127));                                       //medium brightness blue
  pixels.setPixelColor(2, pixels.Color(255,255,255));
  pixels.setPixelColor(3, pixels.Color(0,0,127));
  pixels.setPixelColor(4, pixels.Color(255,255,255));
  pixels.setPixelColor(5, pixels.Color(0,0,127));
  pixels.setPixelColor(6, pixels.Color(255,255,255));
  pixels.setPixelColor(7, pixels.Color(0,0,127));
  pixels.setPixelColor(8, pixels.Color(255,255,255));
  pixels.setPixelColor(9, pixels.Color(0,0,127));
  pixels.show();
}

void evening(){
  pixels.setPixelColor(0, pixels.Color(127,127,127));                                   //medium brightness white
  pixels.setPixelColor(1, pixels.Color(0,0,127));                                       //medium brightness blue
  pixels.setPixelColor(2, pixels.Color(127,127,127));
  pixels.setPixelColor(3, pixels.Color(0,0,127));
  pixels.setPixelColor(4, pixels.Color(127,127,127));
  pixels.setPixelColor(5, pixels.Color(0,0,127));
  pixels.setPixelColor(6, pixels.Color(127,127,127));
  pixels.setPixelColor(7, pixels.Color(0,0,127));
  pixels.setPixelColor(8, pixels.Color(127,127,127));
  pixels.setPixelColor(9, pixels.Color(0,0,127));
  pixels.show();
}

void night(){
  pixels.setPixelColor(0, pixels.Color(0,0,255));                                       //full brightness blue
  pixels.setPixelColor(1, pixels.Color(0,0,255));
  pixels.setPixelColor(2, pixels.Color(0,0,255));
  pixels.setPixelColor(3, pixels.Color(0,0,255));
  pixels.setPixelColor(4, pixels.Color(0,0,255));
  pixels.setPixelColor(5, pixels.Color(0,0,255));
  pixels.setPixelColor(6, pixels.Color(0,0,255));
  pixels.setPixelColor(7, pixels.Color(0,0,255));
  pixels.setPixelColor(8, pixels.Color(0,0,255));
  pixels.setPixelColor(9, pixels.Color(0,0,255));
  pixels.show();
}

void sleepy(){
  pixels.setPixelColor(0, pixels.Color(0,0,50));                                        //low brightness blue
  pixels.setPixelColor(1, pixels.Color(127,0,0));                                       //medium brightness red
  pixels.setPixelColor(2, pixels.Color(0,0,50));
  pixels.setPixelColor(3, pixels.Color(0,0,0));
  pixels.setPixelColor(4, pixels.Color(0,0,50));
  pixels.setPixelColor(5, pixels.Color(127,0,0));
  pixels.setPixelColor(6, pixels.Color(0,0,50));
  pixels.setPixelColor(7, pixels.Color(0,0,0));
  pixels.setPixelColor(8, pixels.Color(0,0,50));
  pixels.setPixelColor(9, pixels.Color(127,0,0));
  pixels.show();
}
