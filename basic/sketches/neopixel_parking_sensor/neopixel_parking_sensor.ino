/*
 * Neopixel Parking Sensor
 * 
 * learnelectronics
 * 8 FEB 2017
 * 
 * www.youtube.com/c/learnelectronics
 */

//---------------------------------------------------------------
//                          LIBRARIES
//---------------------------------------------------------------
#include <NewPing.h>
#include <Adafruit_NeoPixel.h>


//---------------------------------------------------------------
//                          DEFINES
//---------------------------------------------------------------
#define PIN            13
#define NUMPIXELS      24
#define TRIGGER_PIN    11  
#define ECHO_PIN       12  
#define MAX_DISTANCE  200

//----------------------------------------------------------------
//                      LIBRARY CALLS
//----------------------------------------------------------------
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


//----------------------------------------------------------------
//                         VARIABLES
//----------------------------------------------------------------
int distance = 0;



//----------------------------------------------------------------
//                         SET UP
//----------------------------------------------------------------
void setup() {

  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
}


//----------------------------------------------------------------
//                         MAIN LOOP
//----------------------------------------------------------------
void loop() {

 distance = (sonar.ping_cm());
 Serial.println(distance);

 if (distance > 99 || distance == 0){
  green();
 }
 else if (distance < 60 && distance > 20){
  yellow();
 }
 else if (distance < 20 && distance >10){
  red();
 }
 else if (distance < 10){
  stopp();
 }
 else {
  off();
 }
delay (500);
 
  }


//--------------------------------------------------------------
//                          FUNCTIONS
//--------------------------------------------------------------
void green(){
  for(int c=0;c<256;c++){
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,c,0));
      
    }
    pixels.show();
      delay(10);
  }

}

void yellow(){
  for(int c=0;c<256;c++){
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(c,c,0));
      
    }
    pixels.show();
      delay(5);
  }

}


void red(){
  for(int c=0;c<256;c++){
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(c,0,0));
      
    }
    pixels.show();
      delay(5);
  }
  
}



void stopp(){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(200,0,0));
    pixels.show();
  }
  delay(50);
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
  }
}

void off(){
  for (int i = 0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
  }
}
